#include <functional>
#include "purescript.h"

// Tested with package v2.0.0

FOREIGN_BEGIN( Effect_Uncurried )

exports["mkEffectFn1"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&)>>(
        [=](const boxed& a) -> boxed {
            return fn(a)();
        }
    );
};

exports["mkEffectFn2"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&, const boxed&)>>(
        [=](const boxed& a, const boxed& b) -> boxed {
            return fn(a)(b)();
        }
    );
};

exports["mkEffectFn3"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c) -> boxed {
            return fn(a)(b)(c)();
        }
    );
};

exports["mkEffectFn4"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d) -> boxed {
            return fn(a)(b)(c)(d)();
        }
    );
};

exports["mkEffectFn5"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e) -> boxed {
            return fn(a)(b)(c)(d)(e)();
        }
    );
};

exports["mkEffectFn6"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e,
            const boxed& f) -> boxed {
            return fn(a)(b)(c)(d)(e)(f)();
        }
    );
};

exports["mkEffectFn7"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e,
            const boxed& f,
            const boxed& g) -> boxed {
            return fn(a)(b)(c)(d)(e)(f)(g)();
        }
    );
};

exports["mkEffectFn8"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e,
            const boxed& f,
            const boxed& g,
            const boxed& h) -> boxed {
            return fn(a)(b)(c)(d)(e)(f)(g)(h)();
        }
    );
};

exports["mkEffectFn9"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e,
            const boxed& f,
            const boxed& g,
            const boxed& h,
            const boxed& i) -> boxed {
            return fn(a)(b)(c)(d)(e)(f)(g)(h)(i)();
        }
    );
};

exports["mkEffectFn10"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d,
            const boxed& e,
            const boxed& f,
            const boxed& g,
            const boxed& h,
            const boxed& i,
            const boxed& j) -> boxed {
            return fn(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)();
        }
    );
};

// runEffectFn

exports["runEffectFn1"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=]() -> boxed {
            return unbox<std::function<boxed(const boxed&)>>(fn)(a);
        };
    };
};

exports["runEffectFn2"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=]() -> boxed {
                return unbox<std::function<boxed(const boxed&, const boxed&)>>(fn)(a, b);
            };
        };
    };
};

exports["runEffectFn3"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=]() -> boxed {
                    return unbox<std::function<boxed(const boxed&,
                                                     const boxed&,
                                                     const boxed&)>>(fn)(a, b, c);
                };
            };
        };
    };
};

exports["runEffectFn4"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=]() -> boxed {
                        return unbox<std::function<boxed(const boxed&,
                                                         const boxed&,
                                                         const boxed&,
                                                         const boxed&)>>(fn)(a, b, c, d);
                    };
                };
            };
        };
    };
};

exports["runEffectFn5"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=]() -> boxed {
                            return unbox<std::function<boxed(const boxed&,
                                                             const boxed&,
                                                             const boxed&,
                                                             const boxed&,
                                                             const boxed&)>>(fn)(a, b, c, d, e);
                        };
                    };
                };
            };
        };
    };
};

exports["runEffectFn6"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=]() -> boxed {
                                return fn(a)(b)(c)(d)(e)(f);
                                return unbox<std::function<boxed(const boxed&,
                                                                 const boxed&,
                                                                 const boxed&,
                                                                 const boxed&,
                                                                 const boxed&,
                                                                 const boxed&)>>(fn)(a, b, c, d, e, f);
                            };
                        };
                    };
                };
            };
        };
    };
};

exports["runEffectFn7"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=]() -> boxed {
                                    return unbox<std::function<boxed(const boxed&,
                                                                     const boxed&,
                                                                     const boxed&,
                                                                     const boxed&,
                                                                     const boxed&,
                                                                     const boxed&,
                                                                     const boxed&)>>(fn)(a, b, c, d, e, f, g);
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};

exports["runEffectFn8"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=]() -> boxed {
                                        return unbox<std::function<boxed(const boxed&,
                                                                         const boxed&,
                                                                         const boxed&,
                                                                         const boxed&,
                                                                         const boxed&,
                                                                         const boxed&,
                                                                         const boxed&,
                                                                         const boxed&)>>(fn)(a, b, c, d, e, f, g, h);
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};

exports["runEffectFn9"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return [=]() -> boxed {
                                            return unbox<std::function<boxed(const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&,
                                                                             const boxed&)>>(fn)(a, b, c, d, e, f, g, h, i);
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};

exports["runEffectFn10"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return [=](const boxed& j) -> boxed {
                                            return [=]() -> boxed {
                                                return unbox<std::function<boxed(const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&,
                                                                                 const boxed&)>>(fn)(a, b, c, d, e, f, g, h, i, j);
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};

FOREIGN_END
