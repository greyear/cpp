
#pragma once

#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _num;
    public:
        Span() = delete;
        Span(unsigned int n);
        Span(const Span& other) = default;
        Span& operator=(const Span& other) = default;
        ~Span() = default;

        void addNumber(int);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};
