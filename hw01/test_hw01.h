#ifndef TEST_HW01_H
#define TEST_HW01_H

#include <vector> // header for std::vector
#include <iostream> // stream objects for input/output
#include "part1.h"
#include "part2.h"
#include "part3.h"
#include "part4.h"

bool run_all_test()
{
    // a variable that control if all tests are passed
    bool all_passed = true;

    // PART1 - TEST 1:
    // initialize input vectors
    std::vector<double> p1 {1.3, 0, 3.4};
    std::vector<double> p2 {0, 2.5, 1.9};
  
    // test: sum of {1.3, 0, 3.4} and {0, 2.5, 1.9}, answer is {1.3, 2.5, 5.3}
    std::vector<double> test_p1 = sum(p1, p2);
    std::vector<double> real_answer_p1 = {1.3, 2.5, 5.3};
    for(int i = 0; i < test_p1.size(); ++i){
        if (test_p1[i] != real_answer_p1[i]){
            all_passed = false;
            std::cout<<"sum func test is failed \n";
        } else {
   
        std::cout<<"sum func test is passed \n";
        }
    }

    // PART2 - TEST 2:
    // initialize input vectors
    std::vector<double> p3 {1.3, 0, 2.5};
    std::vector<double> p4 {2.9, 2.5, 1.8};
  
    // test: dot production of {1.3, 0, 2.5} and {2.9, 2.5, 1.8}, answer is 8.27
    if (dot(p3,p4) != 8.27){

        all_passed = false;
            std::cout<<"dot func test is failed \n";
    } else {
   
        std::cout<<"dot func test is passed \n";
    }

    // PART3 - TEST 3:
    // initialize inputs
    double one = 12;
    double two = 26;
    int num = 8;

    // test: a vector of linearly spaced values starting from 12.01, stop at 26.08 with num_points 8, 
    // answer is {12, 14, 16, 18, 20, 22, 24, 26}
    
    std::vector<double> test_p3 = linspace(one, two, num);
    std::vector<double> real_answer_p3 = {12, 14, 16, 18, 20, 22, 24, 26};
    for(int j = 0; j < test_p3.size(); ++j){
        if (test_p3[j] != real_answer_p3[j]){
            all_passed = false;
            std::cout<<"linspace func test is failed \n";
        } else {
   
        std::cout<<"linspace func test is passed \n";
        }
    }

    // PART4 - TEST 4:
    // initialize input vectors
    std::vector <double> xa {0, 1, 2};
    std::vector <double> ya {3, 1, 2};
  
    // test: integral for y=f(x) of x = {0, 1, 2} and y = {3, 1, 2}, answer is 3.5
    if (integrate(xa,ya) != 3.5){
  
        all_passed = false;
            std::cout<<"integrate func test is failed \n";
    } else {
   
        std::cout<<"integrate func test is passed \n";
    }

    // print if all test are passed or not
    (all_passed) ? std::cout<<"all_tests are passed \n" : std::cout<< "there is a failure in our tests! \n";

    return all_passed;
}

#endif