
namespace OPENXR_HPP_NAMESPACE {

//# include "template_openxr_version.hpp"
//# include "template_openxr_duration.hpp"
//# include "template_openxr_time.hpp"

//## loop over atoms
//# set comparison_operators = ('==', '!=')
//# for type, invalid in (("SystemId", "XR_NULL_SYSTEM_ID"), ("Path", "XR_NULL_PATH"))
//#     include "template_openxr_wrapperclass.hpp"
//# endfor

using BilateralPaths = std::array<Path, SIDE_COUNT>;

}  // namespace OPENXR_HPP_NAMESPACE
