#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Control_Monad_ST_Internal )

exports["map_"] = [](const boxed& f) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=]() -> boxed {
            return f(a());
        };
    };
};

exports["bind_"] = [](const boxed& a) -> boxed {
    return [=](const boxed& f) -> boxed {
        return [=]() -> boxed {
            return f(a())();
        };
    };
};

exports["run"] = [](const boxed& f) -> boxed {
    return f();
};

exports["while"] = [](const boxed& f) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=]() -> boxed {
            while (unbox<bool>(f())) {
              a();
            }
            return boxed();
        };
    };
};

exports["new"] = [](const boxed& val) -> boxed {
    return [=]() -> boxed {
        return dict_t{{ "value", val }};
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

exports["write"] =  [](const boxed& a) -> boxed {
  return [=](const boxed& ref) -> boxed {
    return [=]() -> boxed {
      dict_t& mutableRef = *static_cast<dict_t*>(ref.get());
      return mutableRef["value"] = a;
    };
  };
};

FOREIGN_END
