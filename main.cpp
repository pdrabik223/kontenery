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


int div_up(int x, double y) {

    double solution = x / y;

    if (solution != (int) solution)solution += 1;


    return (int) solution;

}

size_t div_up(size_t x, size_t y) {
    if (y == 0) return 1;

    size_t solution = x / y;

    if (x % y != 0)solution++;


    return solution;

}

struct plane {
    plane(size_t length, size_t width) : width(width), length(length) {};

    plane() : width(0), length(0) {};
    //      here:
    size_t length;    // ####   length = 4
    size_t width;     // ####   width = 2
    // these values are described in true cargo sizes


    friend std::ostream &operator<<(std::ostream &os, const plane &dt) {

        // os << dt.length << "\t" << dt.width << "\t" << dt.length * dt.width << "\n";
        os << (dt.length * 44 + RIGHT_MARGIN) << " x " << (dt.width * 10 + UPPER_MARGIN) << " = ";
        os << (dt.length * 44 + RIGHT_MARGIN) * (dt.width * 10 + UPPER_MARGIN) << "\n";

        return os;
    }
};

size_t func(size_t l, size_t w) {
    if (l == 0 || w == 0) return size_t(-1);

    return (8 * (55 * w * l + 11 * l + 5 * w + 1));
}

size_t func(plane p) {
    return (8 * (55 * p.width * p.length + 11 * p.length + 5 * p.width + 1));
}

plane shitty_gradient_descent(size_t number_of_cargo);

plane requ(size_t l, size_t w, size_t n);

plane div(size_t number_of_cargo);

int main() {

    size_t number_of_cases;
    std::cin>>number_of_cases;

    size_t current_case;
    for(int i=0;i<number_of_cases;i++){

        std::cin>>current_case;
        std::cout<<div(current_case);

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

            if (cash1 < cash2) {                // in case where we have divisors  2 and 50 we have to check what happens when 2 is width
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


enum direction {
    nowhere,
    ml,
    pl,
    mw,
    pw

};

plane shitty_gradient_descent(size_t number_of_cargo) {
    size_t number_of_stacks = number_of_cargo / CARGO_STACK;
    if (number_of_cargo % CARGO_STACK != 0)
        number_of_stacks++;     // in case of division with leftovers (good show btw)
    // we need to add one more stack


    // now f(l,w) = p where   w (width) l(length)
    // p = area
    // f(l,w) = w*l+w*4+l*2
    // n = w*l    n (number_of_cargo)

    // now we only need to find minimum of f
    // given w*l = n n is given
    // easy


    // dl = w+2         dl = f`l
    // dw = l+4         dw = f`w

    // w+2 = 0 w = -2
    //


    // the complete function formula:
    // P = 8(55wl + 11l + 5w + 1) the function is defined in func
    // now we just need to find minimum where
    // w * l >= number_of_stacks
    // also w, l are integers both >=1



    // so we will try primitive method:

    //first blind shot:
    size_t w;
    size_t l;


    l = sqrt((double) (number_of_stacks / 4.4));
    if (l == 0) l++; // l has to be grater or equal to 1;
    w = div_up(number_of_stacks, l);

    return requ(l, w, number_of_stacks);
}

plane requ(size_t l, size_t w, size_t n) {
    size_t curr_lowest = func(l, w);
    direction to_go_to = nowhere;

    //   if (n <= (l - 1) * div_up(n, l - 1))
    if (func(l - 1, div_up(n, l - 1)) < curr_lowest) {
        curr_lowest = func(l - 1, div_up(n, l - 1));
        to_go_to = ml;
    }


    //  if (n <= (l + 1) * div_up(n, l + 1))
    if (func(l + 1, div_up(n, l + 1)) < curr_lowest) {
        curr_lowest = func(l + 1, div_up(n, l + 1));
        to_go_to = pl;
    }

    //   if (n <= div_up(n, w - 1)* (w - 1))
    if (func(div_up(n, w - 1), w - 1) < curr_lowest) {
        curr_lowest = func(div_up(n, w - 1), w - 1);
        to_go_to = mw;
    }
    //  if (n <= div_up(n, w + 1)* (w + 1))
    if (func(div_up(n, w + 1), w + 1) < curr_lowest) {

        to_go_to = pw;
    }

    switch (to_go_to) {
        case nowhere:
            return plane(l, w);
        case ml:
            return requ(l - 1, div_up(n, l - 1), n);
        case pl:
            return requ(l + 1, div_up(n, l + 1), n);
        case mw:
            return requ(div_up(n, w - 1), w - 1, n);
        case pw:
            return requ(div_up(n, w + 1), w + 1, n);
    }
}
