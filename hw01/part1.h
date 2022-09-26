#ifndef PART1_H
#define PART1_H
//
// Created by Sunah O on 9/24/2022
//
// SNU-ID: 2020-16586
//
// Homework 01 - Part1
//
// Wrote a function to sum two vectors.

#include <vector> // header for std::vector
#include <iostream> // stream objects for input/output

//function prototype
std::vector<double> sum(const std::vector<double> &a, const std::vector<double> &b);

// input : 2 vector<double> which have same size
// output : 1 new vector<double> which is same size with input
// 
std::vector<double> sum(const std::vector<double> &a, const std::vector<double> &b)
{
    int a_size = a.size();
    int b_size = b.size();

    // create a vector s of doubles which has the same size as input vectors
    std::vector<double> s(a_size);

    // A loop to initialize the values of the elements of s by sum of two input vectors' element of same index.
    for(int i = 0; i < a_size; ++i){
        s[i] = a[i]+b[i]; 
    }
    
    return s;

}

#endif