#include "purescript.h"

// Tested with package v4.?.?

FOREIGN_BEGIN( Data_Ord )

exports["ordIntImpl"] = [](const boxed& lt) -> boxed {
    return [=](const boxed& eq) -> boxed {
        return [=](const boxed& gt) -> boxed {
            return [=](const boxed& x_) -> boxed {
                const auto x = unbox<int>(x_);
                return [=](const boxed& y_) -> boxed {
                    const auto y = unbox<int>(y_);
                    return x < y ? lt : x == y ? eq : gt;
                };
            };
        };
    };
};

FOREIGN_END;
