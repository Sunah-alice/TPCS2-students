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

// function definition
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

int main()
{
    std::vector<double> p1 {1.3, 0, 2.5};
    std::vector<double> p2 {2.9, 2.5, 1.8};
    
    double answer = dot(p1,p2);

    std::cout<< "dot production of two vectors : \n"<< answer << std::endl;

    return 0;
}