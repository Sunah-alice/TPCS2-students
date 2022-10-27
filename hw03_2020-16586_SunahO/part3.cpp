//
// Created by Sunah O on 10/27/2022
//
// SNU-ID: 2020-16586
//
// Homework 03
//

// 

#include<iostream>
#include<math.h>
#include<type_traits>
#include<vector>
#include<deque>
#include<forward_list>
#include<array>
#include<list>
#include<string>

template <typename Container,typename ring>
auto evaluate(const Container &y, const ring &x) {
    
    typename Container::const_iterator y_iterator = y.begin();
    int sz = y.size(); // save size of Container y as sz (type int)
    
    double b = 0; // initialize return
    int mul = 0; // Polynomial input's degree (type int)

    // evaluate polynomial Y(x) where Y = a + b*(x^1) + c*(x^2) + ... , y = [a, b, c,...]
    while (y_iterator != y.end()) {
        double a = (*y_iterator++) * pow(x,mul++); // evaluate each term of polynomial and move on to next degree
        b += a; // accumulate each term's result
    }

    return b;
}

int main() {
    
    std::list<double> dbl{4.1, 1.8, 1.5};
    int ran = 1;

    std::cout << evaluate(dbl, ran) << std::endl;
}