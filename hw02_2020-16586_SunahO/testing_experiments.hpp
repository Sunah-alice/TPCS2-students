//
// Created by Sunah O on 7/10/2022
//
// SNU-ID: 2020-16586
//
// Homework 02
//

// document some of experiments

#include <iostream>
using namespace std;

// change in isPrime - function to check if a given number is prime or not

// 1. basic one - too slow
bool isPrime(int n)
{
	// Except 0,1 which is not prime
	if(n == 1 || n == 0) return false;

	// Run a loop from 2 to n-1
	for(int i = 2; i < n; i++)
	{
		// if n is divisible by i, then it is not a prime number.
		if(n % i == 0) return false;
	}
	// Otherwise n is a prime number.
	return true;
}

// 2. checking to n/2 is enough
bool isPrime(int n)
{
	if(n == 1 || n == 0) return false;

	// Run a loop from 2 to n/2.
	for(int i = 2; i <= n / 2; i++)
	{
		if(n % i == 0) return false;
	}

	return true;
}

// 3. checking to square n is enough
bool isPrime(int n)
{
    if(n == 1 || n == 0)return false;

	// Run a loop from 2 to square n.
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)return false;
    }

    return true;
}

// 4. except even & multiple of 3 first (using sieve of eratosthenes)
// much faster
bool isPrime(int n)
{
	// Corner cases; prime starts from 2, 3, ...
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	// Check multiple of 2 & 3 first so that we can skip middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return false;

    // Can check whether n is divisible by other primes (except 2, 3)
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

// change in listPrime to see which data type is faster

// 1. list - 10sec to number 100000
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
    int n = 100000; 
    listPrime(n); // print every prime to number 100000
}

// 2. vector - 11sec to number 100000
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

    std::vector<int> prime = listPrime(100000);
	for (auto const &i : prime) {
        std::cout << i << " "; // print every prime to number 100000
    }
}

/* 
Using sieve of eratosthenes in checking whether the number is prime or not + Using list data type to print 
= 10sec to print all primes up to a number '100000'
/*