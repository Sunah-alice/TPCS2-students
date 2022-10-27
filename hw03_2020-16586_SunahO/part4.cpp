//
// Created by Sunah O on 10/28/2022
//
// SNU-ID: 2020-16586
//
// Homework 03 - Part4
//
// test hw03's all functions

/*
a. need more test functions to test different types of container
b. for part1, I would like to add two different type of containers
ex. std::deque<float> fl1 { 0.1f, 0.2f, 0.3f };
    std::deque<double> dbl1 { 0.1, 0.2, 0.3, 0.4, 0.5 };

	auto test_ex = sum_of_containers(fl1, dbl1);
	std::vector<double> real_answer = { 0.2, 0.4, 0.6, 0.4, 0.5 };

	for(int i = 0; i < test_ex.size(); ++i){
        if (test_ex[i] != real_answer[i]){
            all_passed = false;
            std::cout<<"part1 test1 is failed \n";
        } else {
		std::cout<<"part1 test1 is passed \n";
        }
    }
c. break example
ex. std::list<double> dbl{4.1, 1.8, 1.5};
    int ran = 1;
	// test: evaluate y(1) where y(x) = 4.1 + 1.8 * x + 1.5 * (x^2), answer is 7.4
	if (evaluate(dbl, ran) != 7.4){
        all_passed = false;
            std::cout<<"evaluation func test is failed \n";
    } else {
        
        std::cout<<"evaluation func test is passed \n";
    }

	-> result of this code : evaluation func test is failed
		but in reality, evaluate(dbl, ran) is 7.4, so it is wrong return.
		7.4 on the right side of != is recognized as 7.400000000000000355 by computer (why?) 

*/

#include "test_hw03.h"

int main()
{
	run_all_test();
	return 0;
}