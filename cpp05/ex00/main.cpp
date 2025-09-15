
//add header

#include <iostream>
#include "Bureaucrat.hpp"

void successPath(void)
{
    std::cout << "\n1) success path test" << std::endl;
    try
    {
        Bureaucrat shawn("Shawn", 3);
        std::cout << shawn << std::endl;
        shawn.incrementGrade();
        std::cout << "After incrementing: " << shawn << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void gradeTooHigh(void)
{
    std::cout << "\n2) creating with too high grade" << std::endl;
    try
    {
        Bureaucrat pete("Pete", 0);
        std::cout << pete << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void tooHighWhenIncreased(void)
{
    std::cout << "\n3) too high grade after increasing" << std::endl;
    try
    {
        Bureaucrat marti("Marti", 1);
        std::cout << marti << std::endl;
        marti.incrementGrade();
        std::cout << "After incrementing: " << marti << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void gradeTooLow(void)
{
    std::cout << "\n4) creating with too low grade" << std::endl;
    try
    {
        Bureaucrat rick("Rick", 151);
        std::cout << rick << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void tooLowWhenDecreased(void)
{
    std::cout << "\n5) too low grade after decreasing" << std::endl;
    try
    {
        Bureaucrat pablo("Pablo", 150);
        std::cout << pablo << std::endl;
        pablo.decrementGrade();
        std::cout << "After decrementing: " << pablo << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    successPath();
    gradeTooHigh();
    tooHighWhenIncreased();
    gradeTooLow();
    tooLowWhenDecreased();

    return (0);
}
