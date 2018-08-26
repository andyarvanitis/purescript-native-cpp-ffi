#include <cmath>
#include <limits>
#include "purescript.h"

// Tested with package v4.?.?

FOREIGN_BEGIN( Data_Eq )

exports["eqBooleanImpl"] = [](const boxed& b1_) -> boxed {
    const auto b1 = unbox<bool>(b1_);
    return [=](const boxed& b2) -> boxed {
        return b1 == unbox<bool>(b2);
    };
};

exports["eqIntImpl"] = [](const boxed& n1_) -> boxed {
    const auto n1 = unbox<int>(n1_);
    return [=](const boxed& n2) -> boxed {
        return n1 == unbox<int>(n2);
    };
};

exports["eqNumberImpl"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<double>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<double>(y_);
        return std::abs(x-y) <= std::numeric_limits<double>::epsilon() * std::abs(x+y) ||
               std::abs(x-y) < std::numeric_limits<double>::min();
    };
};

exports["eqCharImpl"] = [](const boxed& c1) -> boxed {
    return [=](const boxed& c2) -> boxed {
        return unbox<string>(c1) == unbox<string>(c2);
    };
};

exports["eqStringImpl"] = [](const boxed& s1) -> boxed {
    return [=](const boxed& s2) -> boxed {
        return unbox<string>(s1) == unbox<string>(s2);
    };
};

exports["eqArrayImpl"] = [](const boxed& f) -> boxed {
    return [=](const boxed& xs_) -> boxed {
        return [=](const boxed& ys_) -> boxed {
            const auto& xs = unbox<array_t>(xs_);
            const auto& ys = unbox<array_t>(ys_);
            if (xs.size() != ys.size()) {
                return false;
            }
            for (auto itx = xs.cbegin(), end = xs.cend(), ity = ys.cbegin();
                 itx != end;
                 itx++, ity++) {
                const auto equal = f(*itx)(*ity);
                if (!unbox<bool>(equal)) {
                    return false;
                }
            }
            return true;
        };
    };
};

FOREIGN_END
