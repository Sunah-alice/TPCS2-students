//
// Created by Sunah O on 7/10/2022
//
// SNU-ID: 2020-16586
//
// Homework 02
//

// Wrote a function to generate a list of all primes up to a number N.

#include <iostream> // stream objects for input/output
#include <list> // header for std::list
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
void listPrime(int n)
{
    std::list <int> prime; // initialize list
	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
            prime.push_back(i); // add new prime elements in list prime
	}
    for (auto const &i : prime) {
        std::cout << i << " "; // print every prime elements (give space between elements)
    }
}

int main()
{
    time_t start, finish;
    double duration;

    start = time(NULL);

	int n = 100000;
    listPrime(n);

    finish = time(NULL);
    duration = (double)(finish - start);
    std::cout << duration << "sec" << std::endl; // check the time spent of the code

}

