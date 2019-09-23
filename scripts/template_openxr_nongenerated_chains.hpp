
namespace OPENXR_HPP_NAMESPACE {

template <typename X, typename Y>
struct isStructureChainValid {
    enum { value = false };
};

template <typename P, typename T>
struct TypeList {
    using list = P;
    using last = T;
};

template <typename List, typename X>
struct extendCheck {
    static const bool valid = isStructureChainValid<typename List::last, X>::value || extendCheck<typename List::list, X>::valid;
};

template <typename T, typename X>
struct extendCheck<TypeList<void, T>, X> {
    static const bool valid = isStructureChainValid<T, X>::value;
};

template <typename X>
struct extendCheck<void, X> {
    static const bool valid = true;
};

template <class Element>
class StructureChainElement {
   public:
    explicit operator Element &() { return value; }
    explicit operator const Element &() const { return value; }

   private:
    Element value;
};

template <typename... StructureElements>
class StructureChain : private StructureChainElement<StructureElements>... {
   public:
    StructureChain() { link<void, StructureElements...>(); }

    StructureChain(StructureChain const &rhs) { linkAndCopy<void, StructureElements...>(rhs); }

    StructureChain(StructureElements const &... elems) { linkAndCopyElements<void, StructureElements...>(elems...); }

    StructureChain &operator=(StructureChain const &rhs) {
        linkAndCopy<void, StructureElements...>(rhs);
        return *this;
    }

    template <typename ClassType>
    ClassType &get() {
        return static_cast<ClassType &>(*this);
    }

   private:
    template <typename List, typename X>
    void link() {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
    }

    template <typename List, typename X, typename Y, typename... Z>
    void link() {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x.pNext = &y;
        link<TypeList<List, X>, Y, Z...>();
    }

    template <typename List, typename X>
    void linkAndCopy(StructureChain const &rhs) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        static_cast<X &>(*this) = static_cast<X const &>(rhs);
    }

    template <typename List, typename X, typename Y, typename... Z>
    void linkAndCopy(StructureChain const &rhs) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x = static_cast<X const &>(rhs);
        x.pNext = &y;
        linkAndCopy<TypeList<List, X>, Y, Z...>(rhs);
    }

    template <typename List, typename X>
    void linkAndCopyElements(X const &xelem) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        static_cast<X &>(*this) = xelem;
    }

    template <typename List, typename X, typename Y, typename... Z>
    void linkAndCopyElements(X const &xelem, Y const &yelem, Z const &... zelem) {
        static_assert(extendCheck<List, X>::valid, "The structure chain is not valid!");
        X &x = static_cast<X &>(*this);
        Y &y = static_cast<Y &>(*this);
        x = xelem;
        x.pNext = &y;
        linkAndCopyElements<TypeList<List, X>, Y, Z...>(yelem, zelem...);
    }
};
}  // namespace OPENXR_HPP_NAMESPACE
