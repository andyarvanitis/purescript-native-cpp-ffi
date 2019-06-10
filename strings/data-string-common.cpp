#include <locale>
#include <regex>
#include "utf8.h"

#include "purescript.h"

// Tested with package v4.0.1

static constexpr auto kRegexOpts =
  std::regex_constants::ECMAScript | std::regex_constants::collate;


FOREIGN_BEGIN( Data_String_Common )

exports["_localeCompare"] = [](const boxed& lt) -> boxed {
    return [=](const boxed& eq) -> boxed {
        return [=](const boxed& gt) -> boxed {
            return [=](const boxed& s1_) -> boxed {
                return [=](const boxed& s2_) -> boxed {
                    const auto& s1 = unbox<string>(s1_);
                    const auto& s2 = unbox<string>(s2_);
                    // TODO: more testing needed
                    const auto& collate = std::use_facet<std::collate<char>>(std::locale());
                    const auto result = collate.compare(s1.c_str(), s1.c_str() + s1.size(),
                                                        s2.c_str(), s2.c_str() + s2.size());
                    return result < 0 ? lt : result > 0 ? gt : eq;
                };
            };
        };
    };
};

exports["replace"] = [](const boxed& s1_) -> boxed {
    return [=](const boxed& s2_) -> boxed {
        return [=](const boxed& s3_) -> boxed {
            const auto& s1 = unbox<string>(s1_);
            const auto& s2 = unbox<string>(s2_);
            const auto& s3 = unbox<string>(s3_);
            string s(s3);
            const auto found = s.find(s1);
            return found == string::npos ? s : s.replace(found, s1.size(), s2);
        };
    };
};

exports["replaceAll"] = [](const boxed& s1_) -> boxed {
    return [=](const boxed& s2_) -> boxed {
        return [=](const boxed& s3_) -> boxed {
            const auto& s1 = unbox<string>(s1_);
            const auto& s2 = unbox<string>(s2_);
            const auto& s3 = unbox<string>(s3_);
            string s(s3);
            for (string::size_type pos = 0, found = string::npos;
                 (found = s.find(s1, pos)) != string::npos;
                 pos += s2.size()) {
              s.replace(found, s1.size(), s2);
            }
            return s;
        };
    };
};

exports["split"] = [](const boxed& sep_) -> boxed {
    return [=](const boxed& str_) -> boxed {
        const auto& sep = unbox<string>(sep_);
        const auto& str = unbox<string>(str_);
        const char * strc = str.c_str();
        array_t result;
        if (not sep.empty()) {
            const auto sepsz = sep.size();
            const char * sepc = sep.c_str();
            for (const char * subc = strstr(strc, sepc); 
                subc != nullptr;
                strc = subc + sepsz, subc = strstr(strc, sepc)) {
                result.emplace_back(string(strc, subc - strc));
            }
            result.emplace_back(string(strc));
        } else {
            utf8_int32_t n = 0;
            for (const char * subc = (char *)utf8codepoint(strc, &n);
                subc != nullptr and n != 0;
                strc = subc, subc = (char *)utf8codepoint(strc, &n)) {
                result.emplace_back(string(strc, subc - strc));
            }
        }
        return result;
    };
};

exports["toLower"] = [](const boxed& s) -> boxed {
    char * buf = strdup(unbox<string>(s).c_str());
    utf8lwr(buf);
    string result(buf);
    free(buf);
    return result;
};

exports["toUpper"] = [](const boxed& s) -> boxed {
    char * buf = strdup(unbox<string>(s).c_str());
    utf8upr(buf);
    string result(buf);
    free(buf);
    return result;
};

exports["trim"] = [](const boxed& s) -> boxed {
    static const auto expr = std::regex("^\\s+|\\s+$", kRegexOpts);
    return std::regex_replace(unbox<string>(s), expr, "");
};

FOREIGN_END
