#include "Serializer.hpp"
#include "Colors.hpp"

int	main() {
	Data	*player = new Data();

	player->nickname = "Zorro";
	player->level = 7;
	player->points = 42;

	std::cout << INVERSE << "   Data before serialize   " << RESET << std::endl;
	std::cout << BOLD << "Nickname: " << YELLOW << player->nickname << RESET << std::endl;
	std::cout << BOLD << "Level: " << YELLOW << player->level << RESET << std::endl;
	std::cout << BOLD << "Points: " << YELLOW << player->points << RESET << std::endl;

	uintptr_t	ptr;
	ptr = Serializer::serialize(player);

	std::cout << INVERSE << "   Data after serialize   " << RESET << std::endl;
	std::cout << BOLD << "Nickname: " << YELLOW << player->nickname << RESET << std::endl;
	std::cout << BOLD << "Level: " << YELLOW << player->level << RESET << std::endl;
	std::cout << BOLD << "Points: " << YELLOW << player->points << RESET << std::endl;

	Data	*testPlayer;
	testPlayer = Serializer::deserialize(ptr);

	std::cout << INVERSE << "   Data after deserialize   " << RESET << std::endl;
	std::cout << BOLD << "Nickname: " << YELLOW << testPlayer->nickname << RESET << std::endl;
	std::cout << BOLD << "Level: " << YELLOW << testPlayer->level << RESET << std::endl;
	std::cout << BOLD << "Points: " << YELLOW << testPlayer->points << RESET << std::endl;

	delete player;
	return (0);
}
