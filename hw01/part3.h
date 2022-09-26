#ifndef PART3_H
#define PART3_H
//
// Created by Sunah O on 9/25/2022
//
// SNU-ID: 2020-16586
//
// Homework 01 - Part 3
//
// Wrote a function to generate a vector of linearly spaced values.

#include <vector> // header for std::vector
#include <iostream> // stream objects for input/output

// function prototype
const std::vector<double> linspace(const double &start, const double &stop,const int &num_points);

// input : 2 double and 1 positive int 
// output : 1 new vector<double> which is same size with input int
//
const std::vector<double> linspace(const double &start, const double &stop,const int &num_points)
{
    // create a vector a, size of num_points
    std::vector<double> a(num_points);

    // A loop to initialize the values of the elements of a, starting with start & ends with stop in (num_points-1) intervals
    for(int i = 0; i < num_points; ++i){
        a[i] = start + ((stop - start) / (num_points-1)) * i; 
    }
    
    return a;

}

#endif