#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Functor )


exports["arrayMap"] = [](const boxed& f) -> boxed {
    return [=](const boxed& arr_) -> boxed {
        const auto& arr = unbox<array_t>(arr_);
        array_t result;
        for (auto it = arr.cbegin(), end = arr.cend(); it != end; it++) {
            result.emplace_back(f(*it));
        }
        return result;
    };
};

FOREIGN_END
