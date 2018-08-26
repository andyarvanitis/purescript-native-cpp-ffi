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

exports["showArrayImpl"] = [](const boxed& f) -> boxed {
    return [=](const boxed& xs_) -> boxed {
    const auto& xs = unbox<array_t>(xs_);
    string s("[");
    auto count = xs.size();
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
        s.append(unbox<string>(f(*it)));
        if (--count > 0) {
          s.push_back(',');
        }
    }
    s.push_back(']');
    return s;
    };
};

FOREIGN_END
