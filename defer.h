#ifndef DEFER_H
#define DEFER_H


#define CONCAT_HELPER_INTERNAL(f, line) f ## line
#define CONCAT_HELPER(f, line) CONCAT_HELPER_INTERNAL(f, line)

#define defer_helper(x, l) defer_internal<void()> l(x)
#define defer(x) defer_helper(x, CONCAT_HELPER(__FUNC__, __LINE__))

template <class T>
class defer_internal {
public:
    defer_internal(T& in): functor(in){	}
    ~defer_internal(){ functor(); }
private:
    T& functor;
};

#endif //DEFER_H