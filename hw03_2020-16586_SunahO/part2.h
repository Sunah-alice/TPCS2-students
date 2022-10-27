#ifndef PART2_H
#define PART2_H
//
// Created by Sunah O on 10/28/2022
//
// SNU-ID: 2020-16586
//
// Homework 03 - Part2
//
// Write a function to find the largest value in a container (use template types).

#include <iostream> // stream objects for input/output
#include <algorithm> // for max_element method
#include <type_traits>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <list>
#include <string>

// function prototype
template <typename Container>
typename Container::value_type max(const Container &a);

// input: 1 Container
// output: 1 specific value of input Container

template <typename Container>
typename Container::value_type max(const Container &a){

    typename Container::const_iterator first = a.begin();
    typename Container::const_iterator last = a.end();
    
    // get *max_element of Container a and save as result
    typename Container::value_type result = *std::max_element(first, last);

    return result;
}

#endif