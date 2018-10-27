#include <cmath>
#include <cassert>
#include <limits>
#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Int )

exports["toNumber"] = [](const boxed& n) -> boxed {
    return static_cast<double>(unbox<int>(n));
};

exports["pow"] = [](const boxed& n_) -> boxed {
    const auto n = unbox<int>(n_);
    return [=](const boxed& p) -> boxed {
        const auto r = std::lround(std::pow(n, unbox<int>(p)));
        assert(r >= std::numeric_limits<int>::min() &&
               r <= std::numeric_limits<int>::max());
        return static_cast<int>(r);
    };
};

FOREIGN_END
