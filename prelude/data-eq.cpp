#include "purescript.h"

// Tested with package v4.?.?

FOREIGN_BEGIN( Data_Eq )

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

FOREIGN_END;
