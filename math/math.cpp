#include <cmath>
#include "purescript.h"

// Tested with package v2.1.1

FOREIGN_BEGIN( Math )

exports["abs"] = [](const boxed& x) -> boxed {
    return std::fabs(unbox<double>(x));
};

exports["pow"] = [](const boxed& n_) -> boxed {
    const auto n = unbox<double>(n_);
    return [=](const boxed& p) -> boxed {
        return std::pow(n, unbox<double>(p));
    };
};

FOREIGN_END
