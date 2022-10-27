#ifndef PART3_H
#define PART3_H
//
// Created by Sunah O on 10/28/2022
//
// SNU-ID: 2020-16586
//
// Homework 03 - Part3
//
// Write a function to find the largest value in a container (use template types).

#include <iostream> // stream objects for input/output
#include <type_traits>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <list>
#include <string>

// function prototype
template <typename Container,typename ring>
auto evaluate(const Container &y, const ring &x);

// input: 1 Container y for coefficients of polynomial, 1 scalar x for input
// output: result of y(x)

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

#endif