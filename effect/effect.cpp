#include "purescript.h"

// Tested with package v2.0.0

FOREIGN_BEGIN( Effect )

exports["pureE"] = [](const boxed& a) -> boxed {
    return [=]() -> boxed {
        return a;
    };
};

exports["bindE"] = [](const boxed& a) -> boxed {
    return [=](const boxed& f) -> boxed {
        return [=]() -> boxed {
            return f(a())();
        };
    };
};

exports["foreachE"] = [](const boxed& as_) -> boxed {
    return [=](const boxed& f) -> boxed {
        return [=]() -> boxed {
            const auto& as = unbox<array_t>(as_);
            for (auto it = as.cbegin(), end = as.cend(); it != end ; it++) {
                f(*it)();
            }
            return boxed();
        };
    };
};

FOREIGN_END
