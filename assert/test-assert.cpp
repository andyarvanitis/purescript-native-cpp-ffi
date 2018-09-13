#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Test_Assert )

exports["assert'"] = [](const boxed& message) -> boxed {
    return [=](const boxed& success_) -> boxed {
        const auto success = unbox<bool>(success_);
        return [=]() -> boxed {
            if (!success) throw std::runtime_error(unbox<string>(message));
            return boxed();
        };
    };
};

FOREIGN_END
