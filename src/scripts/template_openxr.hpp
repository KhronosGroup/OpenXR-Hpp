#ifndef OPENXR_HPP_
#define OPENXR_HPP_ 1

/*
** Copyright (c) 2017-2019 The Khronos Group Inc.
** Copyright (c) 2019 Collabora, Ltd.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/

/*% macro forwardCommandArgs(cur_cmd) %*/ /*{ cur_cmd.params | map(attribute="name") | join(", ") }*/ /*% endmacro %*/

/*% include('template_openxr_nongenerated.hpp')%*/
/*% include('template_openxr_dispatchstatic.hpp')%*/
/*% include('template_openxr_handleclasses.hpp')%*/
/*% include('template_openxr_dispatchdynamic.hpp')%*/
/*% include('template_openxr_methodimpls.hpp')%*/

#endif
