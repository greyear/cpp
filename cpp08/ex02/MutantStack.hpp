
#pragma once

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
    private:
    public:
        MutantStack() = default;
        MutantStack(const MutantStack& other) = default;
        MutantStack& operator=(const MutantStack& other) = default;
        ~MutantStack() = default;

        

        
};

#include "MutantStack.tpp"