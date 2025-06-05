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
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
constructor
[19920104_091532] index:0;amount:42;created
*/
Account::Account(int initial_deposit):
	_accountIndex(_nbAccounts),//private fields, initializer list in constructor realization
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	++_nbAccounts; //increase static variables
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
destructor
[19920104_091532] index:0;amount:47;closed
*/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
4 getter functions for static variables
*/
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/*
YearMonthDay_HourMinuteSecond
[19920104_091532]
*/
void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL); //seconds since 1.01.1970
	std::tm* tm_ptr = std::localtime(&now); //struct with year, month, day, hour, minute, second
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm_ptr); //allowed?
	std::cout << "[" << buffer << "] ";
}

//general info about all the accounts
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"  << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*
+ operation
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
	<< ";deposit:" << deposit;
	_amount+= deposit;
	++_nbDeposits;
	_totalAmount+= deposit;
	++_totalNbDeposits;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
/*
- operation
[19920104_091532] index:0;p_amount:47;withdrawal:refused OR
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount-= withdrawal;
	++_nbWithdrawals;
	_totalAmount-= withdrawal;
	++_totalNbWithdrawals;
	std::cout << withdrawal
	<< ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

//getter for the amount of particular account
int	Account::checkAmount(void) const
{
	return (_amount);
}

/*
info about 1 particular account
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
