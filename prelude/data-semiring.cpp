#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Semiring )

exports["intAdd"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<int>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<int>(y_);
        return x + y;
    };
};

exports["intMul"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<int>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<int>(y_);
        return x * y;
    };
};

exports["numAdd"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<double>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<double>(y_);
        return x + y;
    };
};

exports["numMul"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<double>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<double>(y_);
        return x * y;
    };
};

FOREIGN_END
