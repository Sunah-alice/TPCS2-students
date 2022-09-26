#ifndef PART2_H
#define PART2_H
//
// Created by Sunah O on 9/24/2022
//
// SNU-ID: 2020-16586
//
// Homework 01 - Part 2
//
// Wrote a function to compute the dot production of two vectors.

#include <vector> // header for std::vector
#include <iostream> // stream objects for input/output

// function prototype
double dot(const std::vector<double> &a, const std::vector<double> &b);

// input : 2 vector<double> which have same size
// output : 1 double
//
double dot(const std::vector<double> &a, const std::vector<double> &b)
{
    int a_size = a.size();
    int b_size = b.size();
    double s = 0;

    // A loop to compute the dot production by accumulating product of two input vectors' element on same index.
    for(int i = 0; i < a_size; ++i){
        s += a[i] * b[i]; 
    }
    
    return s;
}

#endif