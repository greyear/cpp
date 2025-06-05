// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; //it's a pseudonym for an account
	//static methods only can access static fields (needs more clarification???)
	//static function belongs to the class itself, not to an object of the class.
	static int	getNbAccounts( void ); //number of accounts
	static int	getTotalAmount( void ); //total sum in all accounts
	static int	getNbDeposits( void ); //number of +
	static int	getNbWithdrawals( void ); //number of -
	static void	displayAccountsInfos( void ); //info about all accounts

	Account( int initial_deposit ); //account creation with some amount
	~Account( void ); //destruction

	void	makeDeposit( int deposit ); //+ sum
	bool	makeWithdrawal( int withdrawal ); //- sum
	int		checkAmount( void ) const; // check amount of particular account
	void	displayStatus( void ) const; //status of an account?


private:

	static int	_nbAccounts; //number of accounts
	static int	_totalAmount; //total sum
	static int	_totalNbDeposits; //total + on all accounts
	static int	_totalNbWithdrawals; //total - on all accounts

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void ); //prohibits to create account without starting amount

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
