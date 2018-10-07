#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Control_Apply )


exports["arrayApply"] = [](const boxed& fs_) -> boxed {
    return [=](const boxed& xs_) -> boxed {
        const auto& fs = unbox<array_t>(fs_);
        const auto& xs = unbox<array_t>(xs_);
        array_t result;
        for (auto f = fs.cbegin(), fend = fs.cend(); f != fend; f++) {
            for (auto x = xs.cbegin(), xend = xs.cend(); x != xend; x++) {
                result.emplace_back((*f)(*x));
            }
        }
        return result;
    };
};

FOREIGN_END
