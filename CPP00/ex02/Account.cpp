/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:21:53 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/05 13:21:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//static (global) variables should be initialized once not inside the constructor, they don't depend on an object created
int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

//constructor
Account::Account(int initial_deposit):
	_accountIndex(_nbAccounts),//private fields, initializer list in constructor realization
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	++_nbAccounts; //increase static variables
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

//destructor
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	getNbAccounts(void)
{
	return (_nbAccounts);
}
static int	getTotalAmount(void)
{
	return (_totalAmount);
}
static int	getNbDeposits(void)
{
	return (_totalNbDeposits);
}
static int	getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	_displayTimestamp(void) //[19920104_091532]
{
	std::time_t now = std::time(nullptr); //seconds since 1.01.1970
	std::tm* tm_ptr = std::localtime(&now); //struct with year, month, day, hour, minute, second
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm_ptr); //allowed?
	std::cout << "[" << buffer << "]" << std::endl;
}

static void	displayAccountsInfos(void)
{
	
}

void	makeDeposit(int deposit)
{
	_totalAmount += deposit;
}
bool	makeWithdrawal(int withdrawal)
{
	
}
int		checkAmount(void) const
{

}
void	displayStatus(void) const
{

}
