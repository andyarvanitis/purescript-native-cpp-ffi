#include <cmath>
#include "purescript.h"

// Tested with package v4.0.0

using namespace purescript;

static auto array1(const boxed& a) -> boxed {
  return array_t{ a };
}

static auto array2(const boxed& a) -> boxed {
  return [=](const boxed& b) -> boxed {
    return array_t{ a, b };
  };
}

static auto array3(const boxed& a) -> boxed {
  return [=](const boxed& b) -> boxed {
    return [=](const boxed& c) -> boxed {
      return array_t{ a, b, c };
    };
  };
}

static auto concat2(const boxed& xs) -> boxed {
  return [=](const boxed& ys_) -> boxed {
    array_t result(unbox<array_t>(xs));
    const auto& ys = unbox<array_t>(ys_);
    result.insert(result.end(), ys.cbegin(), ys.cend());
    return result;
  };
}

static auto go(const long bot,
               const long top,
               const boxed& apply,
               const boxed& map,
               const boxed& pure,
               const boxed& f,
               const array_t& array) -> boxed {
  switch (top - bot) {
    case 0: return pure(array_t{});
    case 1: return map(array1)(f(array[bot]));
    case 2: return apply(map(array2)(f(array[bot])))(f(array[bot + 1]));
    case 3: return apply(apply(map(array3)(f(array[bot])))(f(array[bot + 1])))(f(array[bot + 2]));
    default:
      // This slightly tricky pivot selection aims to produce two
      // even-length partitions where possible.
      long pivot = bot + static_cast<long>(std::floor((top - bot) / 4)) * 2;
      return apply(map(concat2)(go(bot, pivot, apply, map, pure, f, array)))(go(pivot, top, apply, map, pure, f, array));
  }
}

FOREIGN_BEGIN( Data_Traversable )

exports["traverseArrayImpl"] = [](const boxed& apply) -> boxed {
    return [=](const boxed& map) -> boxed {
        return [=](const boxed& pure) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& array_) -> boxed {
                  const auto& array = unbox<array_t>(array_);
                  return go(0,
                            array.size(),
                            apply,
                            map,
                            pure,
                            f,
                            array);
                };
            };
        };
    };
};

FOREIGN_END
