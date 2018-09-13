#include <functional>
#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Function_Uncurried )

exports["mkFn0"] = [](const boxed& f) -> boxed {
    return [=]() -> boxed {
        return f(boxed());
    };
};

exports["mkFn2"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&, const boxed&)>>(
        [=](const boxed& a, const boxed& b) -> boxed {
            return fn(a)(b);
        }
    );
};

exports["mkFn3"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c) -> boxed {
            return fn(a)(b)(c);
        }
    );
};

exports["mkFn4"] = [](const boxed& fn) -> boxed {
    return box<std::function<boxed(const boxed&,
                                   const boxed&,
                                   const boxed&,
                                   const boxed&)>>(
        [=](const boxed& a,
            const boxed& b,
            const boxed& c,
            const boxed& d) -> boxed {
            return fn(a)(b)(c)(d);
        }
    );
};

exports["mkFn5"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e);
        }
    );
};

exports["mkFn6"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e)(f);
        }
    );
};

exports["mkFn7"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e)(f)(g);
        }
    );
};

exports["mkFn8"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e)(f)(g)(h);
        }
    );
};

exports["mkFn9"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e)(f)(g)(h)(i);
        }
    );
};

exports["mkFn10"] = [](const boxed& fn) -> boxed {
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
            return fn(a)(b)(c)(d)(e)(f)(g)(h)(i)(j);
        }
    );
};

//--------------------------------- runFn -----------------------------------//

exports["runFn0"] = [](const boxed& fn) -> boxed {
    return fn();
};

exports["runFn2"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return unbox<std::function<boxed(const boxed&, const boxed&)>>(fn)(a, b);
        };
    };
};

exports["runFn3"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return unbox<std::function<boxed(const boxed&,
                                                 const boxed&,
                                                 const boxed&)>>(fn)(a, b, c);
            };
        };
    };
};

exports["runFn4"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return unbox<std::function<boxed(const boxed&,
                                                     const boxed&,
                                                     const boxed&,
                                                     const boxed&)>>(fn)(a, b, c, d);
                };
            };
        };
    };
};

exports["runFn5"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
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

exports["runFn6"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
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

exports["runFn7"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
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

exports["runFn8"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
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

exports["runFn9"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
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

exports["runFn10"] = [](const boxed& fn) -> boxed {
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

FOREIGN_END
