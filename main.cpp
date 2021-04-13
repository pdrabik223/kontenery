//
// Created by studio25 on 13.04.2021.
//

// cargo width = 8
//      length = 40
//      height = max 5 cargo

// cargo true size width = 10
//                length = 44




#include <iostream>

#define CARGO_WIDTH  10
#define CARGO_LENGTH  44 // these values are described in true cargo sizes
#define CARGO_STACK  5
#define UPPER_MARGIN  2
#define RIGHT_MARGIN  4

int div_up(int x, double y) {

    double solution = x/y;

            if(solution!=(int) solution)solution += 1;


    return (int) solution;

}


struct plane {
    plane(unsigned width, unsigned length) : width(width), length(length) {};

    plane() : width(0), length(0) {};
    //      here:
    unsigned width;     // ####   width = 2
    unsigned length;    // ####   length = 4
    // these values are described in true cargo sizes


    friend std::ostream &operator<<(std::ostream &os, const plane &dt) {

        os << dt.length << "\t" << dt.width << "\t" << dt.length * dt.width << "\n";
        os << (dt.length*44 + RIGHT_MARGIN) << " x " << (dt.width*10 + UPPER_MARGIN)  << " = ";
        os << (dt.length*44 + RIGHT_MARGIN) * (dt.width*10 + UPPER_MARGIN)  << "\n";

        return os;
    }
};

plane first_try_using_quadratic_formula(int number_of_cargo);

plane eghh_why_so_boring_is_so_good(int number_of_cargo);


int main() {

    std::cout << eghh_why_so_boring_is_so_good(6);


    return 0;
}

plane first_try_using_quadratic_formula(int number_of_cargo) {
    int number_of_stacks = number_of_cargo / CARGO_STACK;
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





    return plane();
}


plane eghh_why_so_boring_is_so_good(int number_of_cargo) {
    int number_of_stacks = number_of_cargo / CARGO_STACK;
    if (number_of_cargo % CARGO_STACK != 0) number_of_stacks++; // in case of division with leftovers (good show btw)
    // the lowest capacity : area ratio has circle
    // here we use squares and rectangles
    // btw did you know that egypt is the "squarest" country on the planet ?
    // anyway we know that the area must be square like
    // and we're given n (number_of_cargo) n = w*l    w (width) l(length)
    // so we need to find  suck w and l that the :
    // 1.    w*l = n
    // 2.    |w-l| is the lowest


    // now for the upper and left margin
    // there's a margin soo.. yeah
    // 1. w*l+w*4+l*2 = n
    // 2. |(w+w*2)-(l+l*4)| is the lowest


    int l = div_up(number_of_stacks , 4.4*2);
    int w = number_of_stacks / l;


    return plane(w, l);

}