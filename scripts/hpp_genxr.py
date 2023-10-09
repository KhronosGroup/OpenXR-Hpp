#!/usr/bin/python3
#
# Copyright (c) 2013-2017 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import os
import re
import sys
import time
import typing
import subprocess
from collections.abc import Iterable

OPENXR = os.getenv("OPENXR_REPO")
if not OPENXR:
    OPENXR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'OpenXR-SDK-Source'))
sys.path.append(os.path.join(OPENXR, 'src', 'scripts'))
sys.path.append(os.path.join(OPENXR, 'specification', 'scripts'))

from automatic_source_generator import AutomaticSourceGeneratorOptions
from cpp_generator import CppGenerator
from generator import write
from reg import Registry
from xrconventions import OpenXRConventions


def makeREstring(strings: Iterable[str], default: typing.Optional[str] = None) -> str:
    """Turn a list of strings into a regexp string matching exactly those strings."""
    if strings or default is None:
        return f"^({'|'.join(re.escape(s) for s in strings)})$"
    return default


errWarn: typing.TextIO = sys.stderr
diag: typing.TextIO = None


def get_headers() -> typing.List[str]:
    lines = []
    with open(os.path.join('headers.txt'), 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f.readlines() if re.match('^openxr.*', line) is not None]
    return lines


def genTarget(args) -> typing.Tuple[CppGenerator, AutomaticSourceGeneratorOptions]:
    """
    Create an API generator and corresponding generator options based on
    the requested target and command line options.

    This is encapsulated in a function so it can be profiled and/or timed.
    The args parameter is an parsed argument object containing the following
    fields that are used:
    - target - target to generate
    - directory - directory to generate it in
    - protect - True if re-inclusion wrappers should be created
    - extensions - list of additional extensions to include in generated interfaces"""

    # Create generator options with specified parameters
    header = args.target
    if 'dispatch' in args.target:
        # Don't omit anything when generating dispatchers.
        removeExtensions = None
    else:
        removeExtensions = makeREstring((
            # Atom not projecting right?
            "XR_MSFT_controller_model",
            # Projection of static string fails
            "XR_MSFT_spatial_graph_bridge",
            "XR_MSFT_spatial_anchor_persistence",
            "XR_MSFT_holographic_window_attachment",
            # Projection of UuidMSFT fails
            "XR_MSFT_scene_understanding",
            "XR_MSFT_scene_understanding_serialization",
        ))

    # Turn lists of names/patterns into matching regular expressions
    emitExtensionsPat = makeREstring(args.emitExtensions, '.*')
    featuresPat = makeREstring(args.feature, '.*')
    options = AutomaticSourceGeneratorOptions(
        conventions=OpenXRConventions(),
        filename=header,
        directory=args.directory,
        apiname='openxr',
        profile=None,
        versions=featuresPat,
        emitversions=featuresPat,
        defaultExtensions='openxr',
        addExtensions=None,
        removeExtensions=removeExtensions,
        emitExtensions=emitExtensionsPat)

    if not args.quiet:
        write('* Building', options.filename, file=sys.stderr)
        write('* options.versions          =', options.versions, file=sys.stderr)
        write('* options.emitversions      =', options.emitversions, file=sys.stderr)
        write('* options.defaultExtensions =', options.defaultExtensions, file=sys.stderr)
        write('* options.addExtensions     =', options.addExtensions, file=sys.stderr)
        write('* options.removeExtensions  =', options.removeExtensions, file=sys.stderr)
        write('* options.emitExtensions    =', options.emitExtensions, file=sys.stderr)

    gen = CppGenerator(errFile=errWarn,
                       warnFile=errWarn,
                       diagFile=diag,
                       quiet=args.quiet)
    return (gen, options)


# -feature name
# -extension name
# For both, "name" may be a single name, or a space-separated list
# of names, or a regular expression.
def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('-defaultExtensions', action='store',
                        default='openxr',
                        help='Specify a single class of extensions to add to targets')
    parser.add_argument('-extension', action='append',
                        default=[],
                        help='Specify an extension or extensions to add to targets')
    parser.add_argument('-removeExtensions', action='append',
                        default=[],
                        help='Specify an extension or extensions to remove from targets')
    parser.add_argument('-emitExtensions', action='append',
                        default=[],
                        help='Specify an extension or extensions to emit in targets')
    parser.add_argument('-feature', action='append',
                        default=[],
                        help='Specify a core API feature name or names to add to targets')
    parser.add_argument('-format', action='store_true', default=False,
                        help='Format the generated output using clang-format')
    parser.add_argument('-diagfile', action='store',
                        default=None,
                        help='Write diagnostics to specified file')
    parser.add_argument('-errfile', action='store',
                        default=None,
                        help='Write errors and warnings to specified file instead of stderr')
    parser.add_argument('-registry', action='store',
                        default='xr.xml',
                        help='Use specified registry file instead of xr.xml')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')
    parser.add_argument('target', metavar='target', nargs='?',
                        help='Specify target')
    parser.add_argument('-quiet', action='store_true', default=False,
                        help='Suppress script output during normal execution.')
    parser.add_argument('-verbose', action='store_false', dest='quiet', default=True,
                        help='Enable script output during normal execution.')

    args = parser.parse_args()

    # This splits arguments which are space-separated lists
    args.feature = [name for arg in args.feature for name in arg.split()]
    args.extension = [name for arg in args.extension for name in arg.split()]

    # create error/warning & diagnostic files
    if args.errfile:
        global errWarn
        errWarn = open(args.errfile, 'w', encoding='utf-8')

    if args.diagfile:
        global diag
        diag = open(args.diagfile, 'w', encoding='utf-8')

    if args.target is not None:
        # Replicate pre-existing behavior
        generate_header(args, args.target)
    else:
        # if no target is specified, execute all targets
        for line in get_headers():
            generate_header(args, line)


def generate_header(args, header):
    args.target = header

    # Create the API generator & generator options
    (gen, options) = genTarget(args)

    # Create the registry object with the specified generator and generator
    # options. The options are set before XML loading as they may affect it.
    reg = Registry(gen, options)

    # Parse the specified registry XML into an ElementTree object
    reg.loadFile(args.registry)

    reg.apiGen()
    if not args.quiet:
        write('* Generated', options.filename, file=sys.stderr)

    if args.format:
        outputfile = os.path.join(args.directory, options.filename)
        subprocess.run(['clang-format', '-style=file', '-i', outputfile], check=True)


if __name__ == '__main__':
    main()
