#include "Bureaucrat.hpp"

int main(void)
{

    try
    {
        Bureaucrat trump("trump", 200);
        // trump.incrementGrade();
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
