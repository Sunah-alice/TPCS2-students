#ifndef PART1_H
#define PART1_H
//
// Created by Sunah O on 10/28/2022
//
// SNU-ID: 2020-16586
//
// Homework 03 - Part1
//
// Using templates, write a function to add two containers.

#include <iostream> // stream objects for input/output
#include <type_traits>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <list>
#include <string>

// Some aliases for convenience
template <typename T, typename U>
using Value_t = typename std::common_type<typename T::value_type, typename U::value_type>::type;
template <typename T, typename U>
using Vector_t = typename std::vector<Value_t<T, U>>;

// function prototype
template <typename T, typename U>
auto sum_of_containers(const T& c1, const U& c2) -> Vector_t<T, U>;

// input: 2 containers (type T, U)
// output: 1 container (type MyType)

template <typename T, typename U>
auto sum_of_containers(const T& c1, const U& c2) -> Vector_t<T, U> {

    // Get rid of template parameters using aliases
    using MyType = Value_t<T,U>;
    using MyVector = Vector_t<T, U>;

    // store the result on result (type MyVector)
    MyVector result{};

    typename T::const_iterator c1_iterator = std::begin(c1);
    typename U::const_iterator c2_iterator = std::begin(c2);
   
    // Add, as long as there are the same number of elements
    while ((c1_iterator != std::end(c1)) and (c2_iterator != std::end(c2))) 
        result.push_back(static_cast<MyType>(*c1_iterator++) + static_cast<MyType>(*c2_iterator++));
        
    // If there should still be elements in one of the containers, then just put them to the resulting vector
    while (c1_iterator != std::end(c1))
        result.push_back(static_cast<MyType>(*c1_iterator++));
    while (c2_iterator != std::end(c2))
        result.push_back(static_cast<MyType>(*c2_iterator++));
        
    return result;
}

#endif