#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"

int main() {
	// std::cout << std::endl;
	// std::cout << INVERSE << "   Attempting to sign form with low grade   \n" << RESET << std::endl;
	// try {
	// 	AForm form("Application AForm", 50, 25);

	// 	Bureaucrat bureaucrat("Jon Snow", 55);

	// 	std::cout << BOLD << "AForm details:" << RESET << std::endl;
	// 	std::cout << form << std::endl;

	// 	std::cout << BOLD << "Attempting to sign the form..." << RESET << std::endl;
	// 	bureaucrat.signForm(form);

	// 	std::cout << BOLD << "AForm details:" << RESET << std::endl;
	// 	std::cout << form << std::endl;

	// } catch (std::exception& e) {
	// 	std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// }
	// std::cout << std::endl;
	// std::cout << INVERSE << "\n   Attempting to sign form with high grade   \n" << RESET << std::endl;
	// try {
	// 	AForm form2("Approval AForm", 5, 10);

	// 	Bureaucrat bureaucrat2("Cersei", 2);

	// 	std::cout << BOLD << "AForm details:" << RESET << std::endl;
	// 	std::cout << form2 << std::endl;

	// 	std::cout << BOLD << "Attempting to sign the form..." << RESET << std::endl;
	// 	bureaucrat2.signForm(form2);

	// 	std::cout << BOLD << "AForm details:" << RESET << std::endl;
	// 	std::cout << form2 << std::endl;

	// } catch (std::exception& e) {
	// 	std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	// }
	// std::cout << std::endl;
	// std::cout << INVERSE << "\n   Attempting to create a form with invalids grades   \n" << RESET << std::endl;
	// try {
	// 	AForm form3("Wrong AForm", 0, 10);
	// } catch (std::exception& e) {
	// 	std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	// }
	// try {
	// 	AForm form4("Wrong AForm 2", 10, 155);
	// } catch (std::exception& e) {
	// 	std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	// }

	Bureaucrat jaime("Jaime", 10);
    std::cout << jaime << std::endl;

    RobotomyRequestForm robot("home");
    std::cout << robot << std::endl;
	 try
    {
        jaime.signForm(robot);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	 try
    {
        jaime.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }



	std::cout << std::endl;

	Bureaucrat claire("Claire", 100);
    std::cout << claire << std::endl;

    ShrubberyCreationForm shrwabs("home");
    std::cout << shrwabs << std::endl;
	 try
    {
        claire.signForm(shrwabs);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	 try
    {
        claire.executeForm(shrwabs);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}
