#include "purescript.h"

// Tested with package v4.?.?

namespace Data_Ord {
    using namespace purescript;
    template <typename T>
    static auto ordImpl(const boxed& lt) -> boxed {
        return [=](const boxed& eq) -> boxed {
            return [=](const boxed& gt) -> boxed {
                return [=](const boxed& x_) -> boxed {
                    const auto x = unbox<T>(x_);
                    return [=](const boxed& y_) -> boxed {
                        const auto y = unbox<T>(y_);
                        return x < y ? lt : x == y ? eq : gt;
                    };
                };
            };
        };
    }
}

FOREIGN_BEGIN( Data_Ord )

exports["ordBooleanImpl"] = ordImpl<bool>;
exports["ordIntImpl"]     = ordImpl<int>;
exports["ordNumberImpl"]  = ordImpl<double>;
exports["ordStringImpl"]  = ordImpl<string>;
exports["ordCharImpl"]    = ordImpl<string>;

FOREIGN_END
