#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Show )

exports["showIntImpl"] = [](const boxed& n) -> boxed {
    return std::to_string(unbox<int>(n));
};

exports["showNumberImpl"] = [](const boxed& n) -> boxed {
    return std::to_string(unbox<double>(n));
};

exports["showStringImpl"] = [](const boxed& s) -> boxed {
    return "\"" + unbox<string>(s) + "\"";
};

FOREIGN_END;
