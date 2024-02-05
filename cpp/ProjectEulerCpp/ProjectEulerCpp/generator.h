#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

template <typename T>

class generator
{
public:
    virtual ~generator() {}
    virtual T next() = 0;
};

template <typename T>
class GeneradorPares : public generator<T> {
    private:
        T valor_actual;

    public:
        GeneradorPares() {
            valor_actual = 0;
        }

        T next() override {
            T valor = valor_actual;
            valor_actual += 2;
            return valor;
        }
};

template <typename T>
class GeneratorPrimes : public generator<T>
{
    private:
        std::vector<int> primes;
        int prime;
        int idx;
    public:

        GeneratorPrimes()
        {
            prime = 2;
            idx = 0;
        }
    
        T next() override
        {
            int i;
            while(true)
            {
                for(i = 0; i<idx; i++)
                {
                    if(prime%primes[i]==0)
                    {
                        break;
                    }
                }
                if(i==idx)
                {
                    idx++;
                    primes.push_back(prime);
                    return prime;
                }
                prime++;
            }
        }
};

// Complete failure
class GeneratorPandigital : public generator<int>
{
private:
    std::stack<int> digits;
    std::stack<int> factors;
    int size;
    
public:
    
    GeneratorPandigital(int size)
    {
        this->size = size;
        GenerateFactors(size);
        for(int i = size; i > 0; i--)
        {
            digits.push(i%10);
        }
    }
    void GenerateFactors(int n)
    {
        if(n==1)
        {
            return;
        }
        for(int i = 0; i < n-1; i++)
        {
            factors.push(n);
            GenerateFactors(n-1);
        }
    }
    int next() override
    {
        std::queue<int> temp;
        int factor = factors.top();
        factors.pop();
        std::cout << factor << std::endl;
        
        for(int i = 0; i < factor; i++)
        {
            temp.push(digits.top());
            digits.pop();
        }
        for(int i = 0; i < factor; i++)
        {
            digits.push(temp.front());
            temp.pop();
        }
        std::stack<int> digits_copy = digits;

        for(int i = 0; i < size; i++)
        {
            std::cout << digits_copy.top();
            digits_copy.pop();
        }
        std::cout << "\n";
        return 99;
    }
};