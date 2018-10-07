#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Unsafe_Coerce )

exports["unsafeCoerce"] = [](const boxed& x) -> boxed {
    return x;
};

FOREIGN_END
