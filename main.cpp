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

using l_size_t = long unsigned int;

struct plane {
    plane(l_size_t length, l_size_t width) : width(width), length(length) {



    };

    plane() : width(0), length(0) {};
    //      here:
    l_size_t length;    // ####   length = 4
    l_size_t width;     // ####   width = 2
    // these values are described in true cargo sizes


    friend std::ostream &operator<<(std::ostream &os, const plane &dt) {

        l_size_t x = (dt.length * CARGO_LENGTH + RIGHT_MARGIN);
        l_size_t y = (dt.width * CARGO_WIDTH + UPPER_MARGIN);

        if(x<y) std::swap(x,y);
        os << x << " x " << y << " = ";
        os << x * y << "\n";

        return os;
    }
};

l_size_t func(l_size_t l, l_size_t w) {
    return (8 * (55 * w * l + 11 * l + 5 * w + 1));
}

l_size_t func(plane p) {
    return (8 * (55 * p.width * p.length + 11 * p.length + 5 * p.width + 1));
}

plane div(l_size_t number_of_cargo);

int main() {

    l_size_t number_of_cases;
    std::cin >> number_of_cases;

    l_size_t current_case;
    for (int i = 0; i < number_of_cases; i++) {

        std::cin >> current_case;
        std::cout << div(current_case);

    }
    return 0;
}


plane div(l_size_t number_of_cargo) {
    l_size_t number_of_stacks = number_of_cargo / CARGO_STACK;
    if (number_of_cargo % CARGO_STACK != 0)
        number_of_stacks++;     // in case of division with leftovers (good show btw)
    // we need to add one more stack

    // this idea is good
    // but it's boring
    // personally i prefer gradient descent, even tho it's shit and useless and doesn't work
    // but i cant argue with facts
    // here's my answer
    plane current(number_of_stacks, 1);  // set starting value's
    l_size_t best_for_now = -1;

    for (l_size_t i = 1; i <= sqrt(number_of_stacks); i++) { // go thru all of the dividers

        if (number_of_stacks % i == 0) {        // if there is no leftovers
            l_size_t a = i;
            l_size_t b = number_of_stacks / a; // create cash to not have to divide anymore

            // a must always be bigger than b

            if(b<a) {
                std::swap(a, b);

            }

                if (func(a, b) < best_for_now) { // if current result is better than previous one
                    best_for_now = func(a, b); // update previous
                    current.length = a;   // update best proportions of width to length
                    current.width = b;
                }


       }
    }

    return current;
}

