#include "Bureaucrat.hpp"

int main() {
    std::cout << std::endl;
    std::cout << "---INITIAL GRADE TOO HIGH---" << std::endl;
    try
    {
        Bureaucrat hanna("Hanna", -42);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "---INITIAL GRADE TOO LOW---" << std::endl;
    try
    {
        Bureaucrat john("John", 200);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "---DECREMENT/INCREMENT---" << std::endl;
    Bureaucrat sarah("Sarah", 42);
    std::cout << sarah;
    try
    {
        sarah.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << sarah;
    try
    {
        sarah.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << sarah;
    std::cout << "---DECREMENT ERROR---" << std::endl;;
    Bureaucrat phill("Phill", 150);
    std::cout << phill;
    try
    {
        phill.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "---INCREMENT ERROR---" << std::endl;;
    Bureaucrat jo("Jo", 1);
    std::cout << jo;
    try
    {
        jo.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;

    return 0;
}