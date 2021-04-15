//
// Created by studio25 on 13.04.2021.
//

// cargo width = 8
//      length = 40
//      height = max 5 cargo

// cargo true size width = 10
//                length = 44
#include <vector>
#include <iostream>

#define CARGO_WIDTH  10
#define CARGO_LENGTH  44 // these values are described in true cargo sizes
#define CARGO_STACK  5
#define UPPER_MARGIN  2
#define RIGHT_MARGIN  4


struct plane {
    plane(size_t length, size_t width) : width(width), length(length) {};

    plane() : width(0), length(0) {};
    //      here:
    size_t length;    // ####   length = 4
    size_t width;     // ####   width = 2
    // these values are described in true cargo sizes


    friend std::ostream &operator<<(std::ostream &os, const plane &dt) {

        os << (dt.length * CARGO_LENGTH + RIGHT_MARGIN) << " x " << (dt.width * CARGO_WIDTH + UPPER_MARGIN) << " = ";
        os << (dt.length * CARGO_LENGTH + RIGHT_MARGIN) * (dt.width * CARGO_WIDTH + UPPER_MARGIN) << "\n";

        return os;
    }
};

size_t func(size_t l, size_t w) {

    return (8 * (55 * w * l + 11 * l + 5 * w + 1));
}

size_t func(plane p) {
    return (8 * (55 * p.width * p.length + 11 * p.length + 5 * p.width + 1));
}

plane div(size_t number_of_cargo);

int main() {

    size_t number_of_cases;
    std::cin >> number_of_cases;

    size_t current_case;
    for (int i = 0; i < number_of_cases; i++) {

        std::cin >> current_case;
        std::cout << div(current_case);

    }

    return 0;
}


plane div(size_t number_of_cargo) {
    size_t number_of_stacks = number_of_cargo / CARGO_STACK;
    if (number_of_cargo % CARGO_STACK != 0)
        number_of_stacks++;     // in case of division with leftovers (good show btw)
    // we need to add one more stack

    // this idea is good
    // but it's boring
    // personally i prefer gradient descent, even tho it's shit and useless and doesn't work
    // but i cant argue with facts
    // here's my answer
    plane current(1, number_of_stacks);  // set starting value's
    size_t best_for_now = func(current);

    for (int i = 1; i <= sqrt(number_of_stacks); i++) { // go thru all of the dividers

        if (number_of_stacks % i == 0) {        // if there is no leftovers
            size_t rest = number_of_stacks / i; // create cash to not have to divide anymore

            size_t cash1 = func(i, rest); // create cash for function result
            size_t cash2 = func(rest, i);

            if (cash1 <
                cash2) {                // in case where we have divisors  2 and 50 we have to check what happens when 2 is width
                // and what happens when 50 is in width
                // then chose best out of two
                if (cash1 < best_for_now) { // if current result is better than previous one
                    best_for_now = cash1; // update previous
                    current.length = i;   // update best proportions of width to length
                    current.width = rest;
                }


            } else if (cash2 < best_for_now) {
                best_for_now = cash2;
                current.length = rest;
                current.width = i;
            }


        }
    }

    return current;
}

