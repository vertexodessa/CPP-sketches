#include <iostream>

#include "defer.h"

namespace my{
    void deferred1() {
        std::cout << "deferred1\n";
    }
}

void deferred(){
    defer(my::deferred1);
    std::cout << "deferred print\n";
}

int main() {
    defer(deferred);

    std::cout << "in main()\n";
    return 0;
}