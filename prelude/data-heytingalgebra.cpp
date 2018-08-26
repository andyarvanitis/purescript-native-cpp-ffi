#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_HeytingAlgebra )

exports["boolConj"] = [](const boxed& b1_) -> boxed {
    const auto b1 = unbox<bool>(b1_);
    return [=](const boxed& b2) -> boxed {
        return b1 && unbox<bool>(b2);
    };
};

exports["boolDisj"] = [](const boxed& b1_) -> boxed {
    const auto b1 = unbox<bool>(b1_);
    return [=](const boxed& b2) -> boxed {
        return b1 || unbox<bool>(b2);
    };
};

exports["boolNot"] = [](const boxed& b) -> boxed {
    return !unbox<bool>(b);
};

FOREIGN_END
