#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>


class BitcoinExchange {
private:
	std::map<std::string, float>	_data;

   
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	std::map<std::string, float>	getData() const;
	void	processInput(std::ifstream& file);
};


#endif