#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat trump("trump", 150);

    try
    {
        trump.decrementGrade();
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception caught" << std::endl;
    }

    return (0);
}
