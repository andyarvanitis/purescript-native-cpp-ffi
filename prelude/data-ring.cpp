#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Ring )

exports["intSub"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<int>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<int>(y_);
        return x - y;
    };
};


FOREIGN_END
