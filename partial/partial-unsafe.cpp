#include "purescript.h"

// Tested with package v2.0.0

FOREIGN_BEGIN( Partial_Unsafe )

exports["unsafePartial"] = [](const boxed& f) -> boxed {
    return f(boxed());
};

FOREIGN_END
