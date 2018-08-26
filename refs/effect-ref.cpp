#include "purescript.h"

// Tested with package v4.1.0

FOREIGN_BEGIN( Effect_Ref )

exports["new"] = [](const boxed& val) -> boxed {
    return [=]() -> boxed {
        return dict_t{ {"value", val} };
    };
};

exports["read"] = [](const boxed& ref) -> boxed {
    return [=]() -> boxed {
        return ref["value"];
    };
};

exports["modify'"] = [](const boxed& f) -> boxed {
  return [=](const boxed& ref) -> boxed {
    return [=]() -> boxed {
      boxed t = f(ref["value"]);
      dict_t& mutableRef = *static_cast<dict_t*>(ref.get());
      mutableRef["value"] = t["state"];
      return t["value"];
    };
  };
};

exports["write"] =  [](const boxed& val) -> boxed {
  return [=](const boxed& ref) -> boxed {
    return [=]() -> boxed {
      dict_t& mutableRef = *static_cast<dict_t*>(ref.get());
      return mutableRef["value"] = val;
    };
  };
};

FOREIGN_END
