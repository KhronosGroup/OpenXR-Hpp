
// BLOCK Structure Impl definitions
namespace OPENXR_HPP_NAMESPACE {

namespace traits {

template <typename Type>
class TypedStructTraits {
   protected:
    TypedStructTraits(StructureType type_) : type(type_) {}

   private:
    const StructureType type;

   public:
    const void* next;
};

}  // namespace traits

struct CompositionLayerBaseHeader {
    StructureType type;
    const void* next;
    CompositionLayerFlags layerFlags;
    Space space;
};

//# for struct in gen.api_structures if not struct.name.endswith("BaseHeader") and not struct.name.startswith("XrBase")
//#     set projected_type = project_type_name(struct.name)
//#     set typed_struct = struct.members[0].name == "type"
//#     set member_count = struct_member_count(struct)
/*{ protect_begin(struct) }*/
//#  if typed_struct
struct /*{projected_type }*/ : public traits::TypedStructTraits</*{projected_type }*/> {
   private:
    using Parent = traits::TypedStructTraits</*{projected_type }*/>;

   public:
    //# else
    struct /*{projected_type }*/ {
        //# endif

        //# if struct.name == "XrEventDataBuffer"
        EventDataBuffer()
            : Parent(StructureType::EventDataBuffer){}

              //# elif not struct.returned_only

              /*{projected_type }*/ (
                  //# for member in struct.members if not cpp_hidden_member(member)
                  //# set projected_member_type = project_type_name(member.type)
                  //# set param_decl = project_cppdecl(member, defaulted=True, suffix="_", input=True)
                  /*{param_decl}*/ /*{- "," if not loop.last }*/
                  //# endfor
                  )
            :

              //#  if typed_struct

              Parent(StructureType::/*{create_enum_value(struct.members[0].values, "XrStructureType")}*/)
              /*{- "," if  member_count > 2 }*/
              //#  endif

              //# for member in struct.members if not cpp_hidden_member(member) and not is_static_length_string(member)
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

        //# for member in struct.members if not cpp_hidden_member(member)
        /*{ project_cppdecl(member) }*/;
        //# endfor
    };
    static_assert(sizeof(/*{projected_type }*/) == sizeof(/*{struct.name}*/), "struct and wrapper have different size!");
    /*{ protect_end(struct) }*/

    //# endfor

}  // namespace OPENXR_HPP_NAMESPACE
