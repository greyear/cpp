#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{

}

void RobotomyRequestForm::specificExecution() const
{
    std::cout << "drrrr drrrr! *drilling noises*" << std::endl;

    static std::random_device rd; //source of random numbers from OS
    static std::mt19937 gen(rd()); // generator
    static std::uniform_int_distribution<> dist(0, 1); // 0 or 1

    if (dist(gen) == 1)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed :(" << std::endl;
}
