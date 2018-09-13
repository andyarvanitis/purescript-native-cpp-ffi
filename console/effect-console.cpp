#include <iostream>
#include "purescript.h"

// Tested with package v4.1.0

FOREIGN_BEGIN( Effect_Console )

exports["log"] = [](const boxed& s) -> boxed {
    return [=]() -> boxed {
        std::cout << unbox<string>(s) << std::endl;
        return boxed();
    };
};

exports["warn"] = [](const boxed& s) -> boxed {
    return [=]() -> boxed {
        std::cout << unbox<string>(s) << std::endl;
        return boxed();
    };
};

FOREIGN_END
