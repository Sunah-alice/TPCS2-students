#ifndef PART4_H
#define PART4_H
//
// Created by Sunah O on 9/25/2022
//
// SNU-ID: 2020-16586
//
// Homework 01 - Part 4
//
// Wrote a function to compute the integral for two vectors x and y (y=f(x))

#include <vector> // header for std::vector
#include <iostream> // stream objects for input/output

// function prototype
double integrate(const std::vector<double> &x, const std::vector<double> &y);

// input : 2 vector<double> which have same size, x vector sorted in right order
// output : 1 double
// 
double integrate(const std::vector<double> &x, const std::vector<double> &y)
{
    int x_size = x.size();
    int y_size = y.size();

    double sumup = 0;

    // A loop to compute the integral for y=f(x), sum up all interval areas
    for(int i = 0; i < x_size-1; ++i){
        double inv_wid = x[i+1] - x[i]; // interval width determined as two x-vector's element (consisting each interval) difference
        double inv_hei = (y[i] + y[i+1])/2; // interval height determined as two y-vector's element (consisting each interval) average
        sumup += inv_wid * inv_hei; // accumulating the area of each interval computed by interval width & interval height
    }
    
    return sumup;

}

#endif