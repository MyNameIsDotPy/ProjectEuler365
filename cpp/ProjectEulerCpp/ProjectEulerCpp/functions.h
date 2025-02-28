﻿#ifndef  FUNCTIONS_H
#define FUNCTIONS_H
#include <set>
#include <string>

int factorial(int n);
std::set<int> generate_n_primes(int n);
std::set<int> generate_primes_below_n(int n);
bool is_prime(int n);
bool is_prime(int n, std::set<int> primes);
int num_lenght(int x);
bool is_palindromic(int x);
bool is_palindromic(int x, int length);
bool is_palindromic(std::string x);
int triangular_num(int n);
#endif