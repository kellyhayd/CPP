#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

typedef struct s_date {
	int	year;
	int	month;
	int	day;

	bool operator<(const s_date& other) const {
		if (year != other.year)
		    return year < other.year;
		if (month != other.month)
		    return month < other.month;
		return day < other.day;
    }
} t_date;

class BitcoinExchange {
private:
	std::map<t_date, float>	_data;
	int		_year;
	int		_month;
	int		_day;
	float	_value;
   
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	std::map<t_date, float>	getData() const;
	void	processInput(std::ifstream& file);
	bool	validateDate(std::string& date);
	bool	validateValue(std::string& value, std::string& line);
	void	printOutput(std::string& date, std::string& value);
	float	findMatch();
};


#endif