//
// Created by Sunah O on 10/27/2022
//
// SNU-ID: 2020-16586
//
// Homework 03
//

// Write a function to find the largest value in a container (use template types).

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <list>
#include <string>

template <typename Container>
typename Container::value_type max(const Container &a){

    typename Container::const_iterator first = a.begin();
    typename Container::const_iterator last = a.end();
    
    // get *max_element of Container a and save as result
    typename Container::value_type result = *std::max_element(first, last);

    return result;
}

int main( ) {
    std::vector<double> v = {2.3, 1.1, 5.2, 0.5, 3};
    std::cout << "max element: " << max(v) << std::endl;
}
