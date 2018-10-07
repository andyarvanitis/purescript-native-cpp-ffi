#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Foldable )


exports["foldrArray"] = [](const boxed& f) -> boxed {
    return [=](const boxed& init) -> boxed {
        return [=](const boxed& xs_) -> boxed {
            auto acc = init;
            const auto& xs = unbox<array_t>(xs_);
            for (auto it = xs.crbegin(), end = xs.crend(); it != end ; it++) {
                acc = f(*it)(acc);
            }
            return acc;
        };
    };
};

exports["foldlArray"] = [](const boxed& f) -> boxed {
    return [=](const boxed& init) -> boxed {
        return [=](const boxed& xs_) -> boxed {
            auto acc = init;
            const auto& xs = unbox<array_t>(xs_);
            for (auto it = xs.cbegin(), end = xs.cend(); it != end ; it++) {
                acc = f(acc)(*it);
            }
            return acc;
        };
    };
};

FOREIGN_END
