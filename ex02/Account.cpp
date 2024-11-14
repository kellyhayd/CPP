#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account:: _nbAccounts = 0;
int Account:: _totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(0), _nbDeposits(0), _nbWithdrawals(0){
	_accountIndex = _nbAccounts;
	_amount += initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts(void){
	return (_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (_totalAmount);
}

int	Account::getNbDeposits(void){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << _totalAmount
		<< ";deposit:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit){
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal){
	if (_totalAmount < withdrawal){
		std::cout << "index:" << _accountIndex << ";withdrawal:refused" << std::endl;
		return (false);
	}
	int	amount = _totalAmount;
	_totalAmount -= withdrawal;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";withdrawal:" << withdrawal
		<< ";p_amount:" << _totalAmount << ";withdrawals:" << _totalNbWithdrawals
		<< ";amount:" << amount << ";nb_withdrawls:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const{
	return (_amount);
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposit:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void){
	char timestamp[20];
	std::time_t now;

	std::time(&now);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << timestamp << "] ";
}
