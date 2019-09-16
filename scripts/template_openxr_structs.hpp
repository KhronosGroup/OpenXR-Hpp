
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
    const void* next{nullptr};
};

}  // namespace traits

struct CompositionLayerBaseHeader {
    StructureType type;
    const void* next;
    CompositionLayerFlags layerFlags;
    Space space;
};

//# for struct in gen.api_structures if not struct.name.startswith("XrBase") and not struct.name.endswith("BaseHeader")
//#     set projected_type = project_type_name(struct.name)
//#     set typed_struct = struct.members[0].name == "type"
//#     set member_count = struct_member_count(struct)
//#     set intermediate_type = struct.name.endswith("BaseHeader")
//#     set parent_type = "traits::TypedStructTraits<" + projected_type + ">"
/*{ protect_begin(struct) }*/
//#  if typed_struct
struct /*{projected_type }*/ : public /*{ parent_type }*/ {
   private:
    using Parent = /*{ parent_type }*/;

   public:
    //# else
    struct /*{projected_type }*/ {
        //# endif

        //# set struct_type = "Unknown"
        //# if typed_struct and not intermediate_type
        //#     set struct_type = create_enum_value(struct.members[0].values, "XrStructureType")
        //# endif

        // ctor
        //# if struct.returned_only
        /*{projected_type }*/ ()
            : Parent(StructureType::/*{struct_type}*/){}

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
                  //# set param_decl = project_cppdecl(member, defaulted=True, suffix="_", input=True)
                  /*{param_decl}*/ /*{- "," if not loop.last }*/
                  //# endfor
                  )
            :

              //# if typed_struct

              Parent(StructureType::/*{ struct_type }*/) /*{ "," if member_count > 2 }*/

              //# endif
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

        operator const /*{ struct.name }*/&() const { return *reinterpret_cast<const /*{ struct.name }*/*>(this); }
        /*{ "operator " + struct.name }*/ &() {
            return *reinterpret_cast</*{ struct.name }*/*>(this);
        }

        // member decl
        //# for member in struct.members if not cpp_hidden_member(member)
        /*{ project_cppdecl(member) }*/;
        //# endfor
    };
    static_assert(sizeof(/*{projected_type }*/) == sizeof(/*{struct.name}*/), "struct and wrapper have different size!");
    /*{ protect_end(struct) }*/

    //# endfor

}  // namespace OPENXR_HPP_NAMESPACE
