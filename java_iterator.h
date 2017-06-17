#pragma once
#ifndef JAVA_ITERATOR_H
#define JAVA_ITERATOR_H

#include <type_traits>
#include <iterator>

namespace std {

// defaulted to const types
template<class Container, typename = void>
class JavaIterator {
    using container_pointer_t = typename add_pointer<Container>::type;
    using container_lreference_t = typename add_lvalue_reference<Container>::type;
    using citerator_t = typename Container::const_iterator;
    using return_val_t = typename iterator_traits<citerator_t>::value_type;

    const container_lreference_t v_;
    citerator_t current;
public:
    JavaIterator(const Container& v) : v_(v) {
        current = v_.cbegin();
    };
    const return_val_t& next() {return *current++;};
    bool hasNext() const {return current != v_.end(); }
};

// non-const specialization
template<typename Container>
class JavaIterator <Container,
                    typename std::enable_if<
                        std::is_same< Container,
                                      typename std::remove_const<Container>::type
                                      >::value
                        >::type
                    > {
    using container_pointer_t = typename add_pointer<Container>::type;
    using container_lreference_t = typename add_lvalue_reference<Container>::type;
    using iterator_t = typename Container::iterator;
    using return_val_t = typename iterator_traits<iterator_t>::value_type;

    container_lreference_t v_;
    iterator_t current;
public:
    JavaIterator(Container& v) : v_(v) {
        current = v_.begin();
    };
    return_val_t& next() { return *current++;};
    bool hasNext() const {return current != v_.end(); }
};


template <typename Container>
JavaIterator<Container> make_java_iter(Container& v) {
    return JavaIterator<Container>(v);
}

template <typename Container>
JavaIterator<const Container> make_java_citer(const Container& v) {
    return JavaIterator<const Container>(v);
}

}
#endif
