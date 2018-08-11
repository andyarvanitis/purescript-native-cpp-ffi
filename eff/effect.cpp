#include "purescript.h"

// Tested with package v2.0.0

FOREIGN_BEGIN( Effect )

exports["bindE"] = [](const boxed& a) -> boxed {
    return [=](const boxed& f) -> boxed {
        return [=]() -> boxed {
            return f(a())();
        };
    };
};

FOREIGN_END;
