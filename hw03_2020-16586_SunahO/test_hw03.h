#ifndef TEST_HW03_H
#define TEST_HW03_H

#include <iostream> // stream objects for input/output
#include <algorithm> // for max_element method
#include <math.h>
#include <type_traits>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <list>
#include <string>
#include "part1.h"
#include "part2.h"
#include "part3.h"

bool run_all_test()
{
    // a variable that control if all tests are passed
    bool all_passed = true;

    // PART1 - TEST 1:
    // initialize input vectors
    std::vector<double> v1 {1.3, 0, 3.4};
    std::vector<double> v2 {0, 2.5, 1.9};
  
    // test: sum of {1.3, 0, 3.4} and {0, 2.5, 1.9}, answer is {1.3, 2.5, 5.3}
    std::vector<double> test1_1 = sum_of_containers(v1, v2);
    std::vector<double> real_answer1_1 = {1.3, 2.5, 5.3};
    for(int i = 0; i < test1_1.size(); ++i){
        if (test1_1[i] != real_answer1_1[i]){
            all_passed = false;
            std::cout<<"part1 test1 is failed \n";
        } else {
   
        std::cout<<"part1 test1 is passed \n";
        }
    }

    // PART1 - TEST 2:
    // initialize input arrays
    std::array<double,3> a1{1.3, 0, 3.4};
    std::array<double,3> a2{0, 2.5, 1.9};
  
    // test: sum of {1.3, 0, 3.4} and {0, 2.5, 1.9}, answer is {1.3, 2.5, 5.3}
    auto test1_2 = sum_of_containers(a1, a2);
    std::array<double,3> real_answer1_2 = {1.3, 2.5, 5.3};
    for(int i = 0; i < test1_2.size(); ++i){
        if (test1_2[i] != real_answer1_2[i]){
            all_passed = false;
            std::cout<<"part1 test2 is failed \n";
        } else {
   
        std::cout<<"part2 test1 is passed \n";
        }
    }

    // PART2 - TEST 1:
    // initialize input vector
    std::vector<double> v {2.3, 1.1, 5.2, 0.5, 3};
  
    // test: largest value of {2.3, 1.1, 5.2, 0.5, 3}, answer is 5.2
    if (max(v) != 5.2){
        all_passed = false;
            std::cout<<"max func test is failed \n";
    } else {

        std::cout<<"max func test is passed \n";
    }

    // PART2 - TEST 2:
    // initialize input array
    std::array<int, 6> a {6, 9, 2, 0, 17, -2};
  
    // test: largest value of {6, 9, 2, 0, 17, -2}, answer is 17
    if (max(a) != 17){
        all_passed = false;
            std::cout<<"max func test is failed \n";
    } else {
        
        std::cout<<"max func test is passed \n";
    }

    // PART3 - TEST 1:
    // initialize input
    std::list<double> dbl{4.1, 1.4, 1.5};
    int ran = 1;

    // test: evaluate y(1) where y(x) = 4.1 + 1.4 * x + 1.5 * (x^2), answer is 7
    if (evaluate(dbl, ran) != 7){
        all_passed = false;
            std::cout<<"evaluation func test is failed \n";
    } else {
        
        std::cout<<"evaluation func test is passed \n";
    }

    // PART3 - TEST 2:
    // initialize input
    std::array<int,3> last {1, 2, 3};
    double x = 0.1;

    // test: evaluate y(0.1) where y(x) = 1 + 2 * x + 3 * (x^2),
    // answer is 1.23
    if (evaluate(last, x) != 1.23){
        all_passed = false;
            std::cout<<"evaluation func test is failed \n";
    } else {
        
        std::cout<<"evaluation func test is passed \n";
    }

    // print if all test are passed or not
    (all_passed) ? std::cout<<"all_tests are passed \n" : std::cout<< "there is a failure in our tests! \n";

    return all_passed;
}

#endif