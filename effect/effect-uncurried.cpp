#include "purescript.h"

// Tested with package v2.0.0

FOREIGN_BEGIN( Effect_Uncurried )

exports["mkEffectFn1"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn2"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn3"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn4"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn5"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn6"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn7"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn8"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn9"] = [](const boxed& f) -> boxed {
    return f();
};

exports["mkEffectFn10"] = [](const boxed& f) -> boxed {
    return f();
};

// runEffectFn

exports["runEffectFn1"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=]() -> boxed {
            return fn(a);
        };
    };
};

exports["runEffectFn2"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=]() -> boxed {
                return fn(a)(b);
            };
        };
    };
};

exports["runEffectFn3"] = [](const boxed& fn) -> boxed {
    return [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=]() -> boxed {
                    return fn(a)(b)(c);
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
                        return fn(a)(b)(c)(d);
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
                            return fn(a)(b)(c)(d)(e);
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
                                    return fn(a)(b)(c)(d)(e)(f)(g);
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
                                        return fn(a)(b)(c)(d)(e)(f)(g)(h);
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
                                            return fn(a)(b)(c)(d)(e)(f)(g)(h)(i);
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
                                                return fn(a)(b)(c)(d)(e)(f)(g)(h)(i)(j);
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
