#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
private:
	std::vector<int>	_vector;
	std::list<int>		_list;
	std::vector<int>	_jacobsthalNumbers;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	std::vector<int>	jacobsthalNumbers(int maxElements);
	void	addNumber(int number);
	void	printResults();
	void	sortVector(std::vector<int>& _vector);
	void	sortList();
	void	insertSorted(std::vector<int>& pend, std::vector<int>& main);

	std::vector<int>	getVector() const;
	std::list<int>		getList() const;
	int	getJacobsthal(int n) const;
	void	setJacobsthal(int maxElements);

	template <typename T>
	void	printContainer(const T& container) const {
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};

#endif