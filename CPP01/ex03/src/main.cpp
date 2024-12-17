#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
	{
		std::cout << BOLD << INVERSE << "\n     HUMAN A     \n" << RESET << std::endl;
		std::cout << BOLD << "Creating weapon type 'club'" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << BOLD << RED << "BOB ATTACKS" << RESET << std::endl;
		bob.attack();
		std::cout << BOLD << "\nChanging weapon type to 'some other type of club'" << RESET << std::endl;
		club.setType("some other type of club");
		std::cout << BOLD << RED << "BOB ATTACKS" << RESET << std::endl;
		bob.attack();
	}

	{
		std::cout << BOLD << INVERSE << "\n     HUMAN B     \n" << RESET << std::endl;
		std::cout << BOLD << "\nMaking Human B an Attacking" << RESET << std::endl;
		HumanB jim("Jim");
		jim.attack();
		std::cout << BOLD << "\nCreating weapon type 'club'" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB Jim("Jim");
		std::cout << BOLD << RED << "JIM ATTACKS WITH NO WEAPON" << RESET << std::endl;
		jim.attack();
		std::cout << BOLD << "\nGiving Jim a weapon" << RESET << std::endl;
		jim.setWeapon(club);
		std::cout << BOLD << RED << "JIM ATTACKS" << RESET << std::endl;
		jim.attack();
		std::cout << BOLD << "\nChanging weapon type to 'some other type of club'" << RESET << std::endl;
		club.setType("some other type of club");
		std::cout << BOLD << RED << "JIM ATTACKS" << RESET << std::endl;
		jim.attack();
		std::cout << BOLD << "\nTaking away Human B weapon" << RESET << std::endl;
		club.setType("");
		std::cout << BOLD << RED << "JIM ATTACKS" << RESET << std::endl;
		jim.attack();
	}

	return 0;
}
