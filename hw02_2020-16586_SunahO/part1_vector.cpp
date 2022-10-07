//
// Created by Sunah O on 7/10/2022
//
// SNU-ID: 2020-16586
//
// Homework 02
//

// Wrote a function to generate a vector of all primes up to a number N.

#include <iostream> // stream objects for input/output
#include <vector> // header for std::vector
#include <ctime> // header for time measure

// function check whether a number is prime or not
bool isPrime(int n)
{
	// Corner cases; prime starts from 2, 3, ...
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// Check some numbers (ex. even nums) first so that we can skip middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// Function to generate list of all primes using isPrime function
std::vector <int> listPrime(int n)
{
    std::vector <int> prime; // initialize vector
	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
            prime.push_back(i); // add new prime elements in vector prime
	}
    return prime;
}

int main()
{
    time_t start, finish;
    double duration;

    start = time(NULL);

    std::vector<int> prime = listPrime(100000);
	for (auto const &i : prime) {
        std::cout << i << " "; // print every prime elements (give space between elements)
    }

    finish = time(NULL);
    duration = (double)(finish - start);
    std::cout << duration << "sec" << std::endl; // check the time spent of the code

}

