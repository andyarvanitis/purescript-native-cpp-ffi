#include <cmath>
#include <algorithm>
#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_EuclideanRing )

exports["intDegree"] = [](const boxed& x) -> boxed {
    return std::min(std::abs(unbox<int>(x)), 2147483647);
};

// See the Euclidean definition in
// https://en.m.wikipedia.org/wiki/Modulo_operation.
exports["intDiv"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<int>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<int>(y_);
        if (y == 0) return 0;
        return int( y > 0 ? std::floor(x / y) : -std::floor(x / -y) );
    };
};


exports["intMod"] = [](const boxed& x_) -> boxed {
    const auto x = unbox<int>(x_);
    return [=](const boxed& y_) -> boxed {
        const auto y = unbox<int>(y_);
        if (y == 0) return 0;
        const int yy = std::abs(y);
        return ((x % yy) + yy) % yy;
    };
};


FOREIGN_END
