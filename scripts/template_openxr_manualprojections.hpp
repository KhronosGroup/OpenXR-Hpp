
namespace OPENXR_HPP_NAMESPACE {

class Duration {
   public:
    OPENXR_HPP_CONSTEXPR Duration() = default;
    OPENXR_HPP_CONSTEXPR explicit Duration(XrDuration t) : val_(t) {}

    OPENXR_HPP_CONSTEXPR XrDuration get() const noexcept { return val_; }

    XrDuration* put() noexcept {
        val_ = 0;
        return &val_;
    }

    Duration& operator-=(Duration d) noexcept {
        val_ -= d.val_;
        return *this;
    }
    Duration& operator+=(Duration d) noexcept {
        val_ += d.val_;
        return *this;
    }

    static OPENXR_HPP_CONSTEXPR Duration infinite() noexcept { return Duration{XR_INFINITE_DURATION}; }

    static OPENXR_HPP_CONSTEXPR Duration minHaptic() noexcept { return Duration{XR_MIN_HAPTIC_DURATION}; }

   private:
    XrDuration val_{};
};

OPENXR_HPP_CONSTEXPR inline XrDuration get(Duration d) noexcept { return d.get(); }

inline XrDuration* put(Duration& d) noexcept { return d.put(); }
OPENXR_HPP_CONSTEXPR inline Duration operator+(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() + rhs.get()}; }
OPENXR_HPP_CONSTEXPR inline Duration operator-(Duration lhs, Duration rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }

class Time {
   public:
    OPENXR_HPP_CONSTEXPR Time() = default;
    OPENXR_HPP_CONSTEXPR explicit Time(XrTime t) : val_(t) {}

    OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ == 0; }
    OPENXR_HPP_CONSTEXPR XrTime get() const noexcept { return val_; }

    XrTime* put() noexcept {
        val_ = 0;
        return &val_;
    }

    Time& operator-=(Duration d) noexcept {
        val_ -= d.get();
        return *this;
    }
    Time& operator+=(Duration d) noexcept {
        val_ += d.get();
        return *this;
    }

   private:
    XrTime val_{};
};

OPENXR_HPP_CONSTEXPR inline XrTime get(Time t) noexcept { return t.get(); }

inline XrTime* put(Time& t) noexcept { return t.put(); }

OPENXR_HPP_CONSTEXPR inline Duration operator-(Time lhs, Time rhs) noexcept { return Duration{lhs.get() - rhs.get()}; }

OPENXR_HPP_CONSTEXPR inline Time operator-(Time lhs, Duration rhs) noexcept { return Time{lhs.get() - rhs.get()}; }

OPENXR_HPP_CONSTEXPR inline Time operator+(Time lhs, Duration rhs) noexcept { return Time{lhs.get() + rhs.get()}; }

//# for type in ("Duration", "Time")
//# set raw_type = "Xr" + type
//# for op in ('<', '>', '<=', '>=', '==', '!=')
//! @brief /*{op}*/ comparison between /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{type}*/ const &rhs) { return lhs.get() /*{- op -}*/ rhs.get(); }
//! @brief /*{op}*/ comparison between /*{type}*/ and raw /*{raw_type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{raw_type}*/ rhs) { return lhs.get() /*{- op -}*/ rhs; }
//! @brief /*{op}*/ comparison between raw /*{raw_type}*/ and /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{raw_type}*/ lhs, /*{type}*/ const &rhs) { return lhs /*{- op -}*/ rhs.get(); }
//# endfor
//# endfor

//# for type, invalid in (("SystemId", "XR_NULL_SYSTEM_ID"), ("Path", "XR_NULL_PATH"))
//# set raw_type = "Xr" + type
class /*{ type }*/ {
   public:
    OPENXR_HPP_CONSTEXPR /*{ type }*/() = default;
    OPENXR_HPP_CONSTEXPR explicit /*{ type }*/(/*{ raw_type }*/ v) : val_(v) {}
    OPENXR_HPP_CONSTEXPR explicit operator bool() const noexcept { return val_ == /*{ invalid }*/; }

    OPENXR_HPP_CONSTEXPR /*{ raw_type }*/ get() const noexcept { return val_; }

    /*{ raw_type }*/* put() noexcept {
        val_ = /*{ invalid }*/;
        return &val_;
    }

   private:
    /*{ raw_type }*/ val_{/*{ invalid }*/};
};

OPENXR_HPP_CONSTEXPR inline /*{ raw_type }*/ get(/*{type}*/ v) noexcept { return v.get(); }

inline /*{ raw_type }*/* put(/*{type}*/ & v) noexcept { return v.put(); }

//# for op in ('==', '!=')
//! @brief `/*{op}*/` comparison between /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{type}*/ const &rhs) { return lhs.get() /*{- op -}*/ rhs.get(); }
//! @brief `/*{op}*/` comparison between /*{type}*/ and raw /*{raw_type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{type}*/ const &lhs, /*{raw_type}*/ rhs) { return lhs.get() /*{- op -}*/ rhs; }
//! @brief `/*{op}*/` comparison between raw /*{raw_type}*/ and /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{raw_type}*/ lhs, /*{type}*/ const &rhs) { return lhs /*{- op -}*/ rhs.get(); }
//# endfor

//## end of loop over atoms
//# endfor

using BilateralPaths = std::array<Path, SIDE_COUNT>;

}  // namespace OPENXR_HPP_NAMESPACE
