
namespace OPENXR_HPP_NAMESPACE {

//# for cur_cmd in sorted_cmds
//#     if gen.isHandle(cur_cmd.params[0].type)
/*{ protect_begin(cur_cmd) }*/
//#         set param_decl_list = member_function_params(cur_cmd) + ["Dispatch const &d"]
template <typename Dispatch>
OPENXR_HPP_INLINE /*{project_type_name(cur_cmd.return_type.text)}*/ /*{cur_cmd.params[0].type | replace("Xr", "") -}*/ ::
    /*{- member_function_name(cur_cmd.name) -}*/ (/*{- project_params_for_definition(cur_cmd) -}*/) const {
    return static_cast</*{project_type_name(cur_cmd.return_type.text)}*/>(
        d./*{ cur_cmd.name -}*/ (/*{ project_params_for_implementation(cur_cmd) }*/));
}
/*{ protect_end(cur_cmd) }*/
//#     endif
//# endfor

//## Must manually provide this one for ease of use.
template <typename Dispatch = DispatchLoaderStatic>
OPENXR_HPP_INLINE XrResult createInstance(const XrInstanceCreateInfo *createInfo, Instance &instance,
                                          Dispatch const &d = Dispatch()) {
    return d.xrCreateInstance(createInfo, instance.put());
}
#if 0
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
  template<typename Dispatch>
  OPENXR_HPP_INLINE ResultValueType<Instance>::type createInstance( const InstanceCreateInfo & createInfo, Optional<const AllocationCallbacks> allocator, Dispatch const &d )
  {
    Instance instance;
    Result result = static_cast<Result>( d.vkCreateInstance( reinterpret_cast<const VkInstanceCreateInfo*>( &createInfo ), reinterpret_cast<const VkAllocationCallbacks*>( static_cast<const AllocationCallbacks*>( allocator ) ), reinterpret_cast<VkInstance*>( &instance ) ) );
    return createResultValue( result, instance, OPENXR_HPP_NAMESPACE_STRING"::createInstance" );
  }
#ifndef OPENXR_HPP_NO_SMART_HANDLE
  template<typename Dispatch>
  OPENXR_HPP_INLINE typename ResultValueType<UniqueHandle<Instance,Dispatch>>::type createInstanceUnique( const InstanceCreateInfo & createInfo, Optional<const AllocationCallbacks> allocator, Dispatch const &d )
  {
    Instance instance;
    Result result = static_cast<Result>( d.vkCreateInstance( reinterpret_cast<const VkInstanceCreateInfo*>( &createInfo ), reinterpret_cast<const VkAllocationCallbacks*>( static_cast<const AllocationCallbacks*>( allocator ) ), reinterpret_cast<VkInstance*>( &instance ) ) );

    ObjectDestroy<NoParent,Dispatch> deleter( allocator, d );
    return createResultValue<Instance,Dispatch>( result, instance, OPENXR_HPP_NAMESPACE_STRING"::createInstanceUnique", deleter );
  }
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/
#endif

}  // namespace OPENXR_HPP_NAMESPACE
