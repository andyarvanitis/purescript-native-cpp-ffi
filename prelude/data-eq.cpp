#include "purescript.h"

// Tested with package v4.?.?

FOREIGN_BEGIN( Data_Eq )

exports["eqStringImpl"] = [](const boxed& s1) -> boxed {
    return [=](const boxed& s2) -> boxed {
        return unbox<string>(s1) == unbox<string>(s2);
    };
};

FOREIGN_END;
