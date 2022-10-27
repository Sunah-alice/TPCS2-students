//
// Created by Sunah O on 10/27/2022
//
// SNU-ID: 2020-16586
//
// Homework 03
//

// Using templates, write a function to add two containers.

#include <iostream>
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

    return result ;
}

int main() {

    // Test Data 0
    std::deque<float> fl1 { 0.1f, 0.2f, 0.3f };
    std::deque<double> dbl1 { 0.1, 0.2, 0.3, 0.4, 0.5 };

    auto result0 = sum_of_containers(fl1, dbl1);
    for (const auto& x0 : result0)
        std::cout << x0 << '\t';
    std::cout << '\n';


    // Test Data 1
    std::deque<int> dq{ -1,2,-3 };
    std::forward_list<float> fl{ 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };

    auto result1 = sum_of_containers(dq, fl);
    for (const auto& x1 : result1)
        std::cout << x1 << '\t';
    std::cout << '\n';

    // Test Data 2
    std::array<unsigned long, 3> ar1{ 1ul,2ul,3ul };
    std::list<double> dbl{ 0.1, 0.2, 0.3, 0.4, 0.5 };

    auto result2 = sum_of_containers(ar1, dbl);
    for (const auto& x2 : result2)
        std::cout << x2 << '\t';
    std::cout << '\n';
}