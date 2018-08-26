#include <limits>
#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Bounded )

exports["topInt"] = std::numeric_limits<int>::max();
exports["bottomInt"] = std::numeric_limits<int>::min();

exports["topChar"] = 0x10FFFF; // unicode limit
exports["bottomChar"] = 0;

exports["topNumber"] = std::numeric_limits<double>::max();
exports["bottomNumber"] = std::numeric_limits<double>::min();

FOREIGN_END
