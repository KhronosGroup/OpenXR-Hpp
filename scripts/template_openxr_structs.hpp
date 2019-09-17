
// BLOCK Structure Impl definitions
namespace OPENXR_HPP_NAMESPACE {

namespace traits {

template <typename Type>
class TypedStructTraits {
   protected:
    TypedStructTraits(StructureType type_) : type(type_) {}

   public:
    StructureType type;
    const void* next{nullptr};
};

}  // namespace traits

struct EventDataBaseHeader : public traits::TypedStructTraits<EventDataBaseHeader> {
private:
    using Parent = traits::TypedStructTraits<EventDataBaseHeader>;

protected:
    EventDataBaseHeader(StructureType type_) : Parent(type_) { }
};
static_assert(sizeof(EventDataBaseHeader) == sizeof(XrEventDataBaseHeader), "struct and wrapper have different size!");

struct SwapchainImageBaseHeader : public traits::TypedStructTraits<SwapchainImageBaseHeader> {
private:
    using Parent = traits::TypedStructTraits<SwapchainImageBaseHeader>;

protected:
    SwapchainImageBaseHeader(StructureType type_) : Parent(type_) { }
};
static_assert(sizeof(SwapchainImageBaseHeader) == sizeof(XrSwapchainImageBaseHeader), "struct and wrapper have different size!");

struct HapticBaseHeader : public traits::TypedStructTraits<HapticBaseHeader> {
private:
    using Parent = traits::TypedStructTraits<HapticBaseHeader>;

protected:
    HapticBaseHeader(StructureType type_) : Parent(type_) { }
};
static_assert(sizeof(HapticBaseHeader) == sizeof(XrHapticBaseHeader), "struct and wrapper have different size!");

struct CompositionLayerBaseHeader : public traits::TypedStructTraits<CompositionLayerBaseHeader> {
private:
    using Parent = traits::TypedStructTraits<CompositionLayerBaseHeader>;

protected:
    CompositionLayerBaseHeader(
        StructureType type_,
        const CompositionLayerFlags& layerFlags_,
        const Space& space_)
        : Parent(type_), layerFlags(layerFlags_), space(space) { }

public:
    CompositionLayerFlags layerFlags;
    Space space;
};
static_assert(sizeof(CompositionLayerBaseHeader) == sizeof(XrCompositionLayerBaseHeader),
    "struct and wrapper have different size!");

//# for struct in gen.api_structures if not struct.name.startswith("XrBase") and not struct.name.endswith("BaseHeader")
//#     set projected_type = project_type_name(struct.name)
//#     set typed_struct = is_tagged_type(struct.name)
//#     set member_count = struct_member_count(struct)
//#     set intermediate_type = is_base_only(struct)
//#     set derived_type = struct.name in struct_parents
//#     set parent_type = "traits::TypedStructTraits<" + projected_type + ">"
//#     set parent_fields = {}
//#     if derived_type
//#         set parent_type = project_type_name(struct_parents[struct.name])
//#         set parent_fields = struct_fields[struct_parents[struct.name]]
//#     endif
/*{ protect_begin(struct) }*/
//#  if typed_struct
struct /*{projected_type }*/ : public /*{ parent_type }*/ {
   private:
    using Parent = /*{ parent_type }*/;

   public:
    //# else
    struct /*{projected_type }*/ {
        //# endif

        //# if typed_struct
        //#     set struct_type = get_tag(struct.name)
        //# endif

        // ctor
        //# if struct.returned_only
        /*{projected_type }*/ ()
            : Parent(/*{struct_type}*/){}

              //# elif struct.name == 'XrEventDataBuffer'
              /*{projected_type }*/ ()
            : Parent(StructureType::EventDataBuffer){}

              //# elif struct.intermediate_type
              /*{projected_type }*/ (StructureType type_)
            : Parent(type_){}

              //# else
              /*{projected_type }*/ (
                  //# for member in struct.members if not cpp_hidden_member(member)
                  //# set projected_member_type = project_type_name(member.type)
                  //# set param_decl = project_cppdecl(struct, member, defaulted=True, suffix="_", input=True)
                  /*{param_decl}*/ /*{- "," if not loop.last }*/
                  //# endfor
                  )
            :

        //# if typed_struct

              Parent(/*{ struct_type }*/
        //# for member in struct.members if not cpp_hidden_member(member) and not is_static_length_string(member) and member.name in parent_fields
              , /*{ member.name + "_"}*/
        //# endfor
              ) /*{ "," if member_count > 2 }*/

        //# endif
        //# for member in struct.members if not cpp_hidden_member(member) and not is_static_length_string(member) and member.name not in parent_fields
              /*{ member.name }*/ {/*{ member.name + "_"}*/} /*{ "," if not loop.last }*/
        //# endfor
        {
            //# for member in struct.members if not cpp_hidden_member(member) and is_static_length_string(member)
            if (nullptr != /*{ member.name + "_" }*/) {
                // FIXME what is the safe way to do this?
                strncpy(/*{ member.name }*/, /*{ member.name + "_" }*/, /*{member.array_count_var}*/);
            }
            //# endfor
        }
        //# endif

        operator const /*{ struct.name }*/&() const { return *reinterpret_cast<const /*{ struct.name }*/*>(this); }
        /*{ "operator " + struct.name }*/ &() {
            return *reinterpret_cast</*{ struct.name }*/*>(this);
        }

        // member decl
        //# for member in struct.members if not cpp_hidden_member(member) and member.name not in parent_fields
        /*{ project_cppdecl(struct, member) }*/;
        //# endfor
    };
    static_assert(sizeof(/*{projected_type }*/) == sizeof(/*{struct.name}*/), "struct and wrapper have different size!");

    //! @brief Free function accessor for /*{projected_type}*/ const reference as a raw /*{struct.name}*/ const pointer
    //! @relates /*{projected_type}*/
    OPENXR_HPP_INLINE /*{struct.name}*/ const* get(/*{projected_type}*/ const& h) {
        return &(h./*{"operator " + struct.name}*/ const&());
    }

    //! @brief Free function accessor for passing /*{projected_type}*/ as the address of a raw /*{struct.name}*/
    //! @relates /*{projected_type}*/
    OPENXR_HPP_INLINE /*{struct.name}*/* put(/*{projected_type}*/ &h) { return &(h./*{"operator " + struct.name}*/&()); }

    /*{ protect_end(struct) }*/

    //# endfor

}  // namespace OPENXR_HPP_NAMESPACE
