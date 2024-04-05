#include <iostream>
#include "o_1_cracked_stack.h"
#include "o_n_cracked_stack.h"

int main() {
    o1::stack s;

    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(3);
    s.push(5);
    s.push(9);

    s.increment(1, 4);
    s.increment(3, 2);
    s.increment(6, 2);


    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";

    return 0;
}
