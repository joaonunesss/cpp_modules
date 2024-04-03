/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:13:37 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/26 15:00:59 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){
    return(Account::_nbAccounts);
}
int	Account::getTotalAmount( void ){
    return(Account::_totalAmount);
}
int	Account::getNbDeposits( void ){
    return(Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ){
    return(Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void ){

    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << std::flush;
    std::cout << ";total:" << _totalAmount << std::flush;
    std::cout << ";deposits:" << _totalNbDeposits << std::flush;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ){
    
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
}

Account::~Account( void ){
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    if (deposit > 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << std::flush;
        std::cout << ";p_amount:" << _amount << std::flush;
        std::cout << ";deposit:" << deposit << std::flush;
        _totalAmount += deposit;
        _nbDeposits++;
        _totalNbDeposits += _nbDeposits;
        _amount += deposit;
        std::cout << ";amount:" << _amount << std::flush;
        std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool	Account::makeWithdrawal( int withdrawal )
{
   _displayTimestamp();
    std::cout << "index:" << _accountIndex << std::flush;
    std::cout << ";p_amount:" << _amount << std::flush;
    if (_amount - withdrawal > 0)
    {
        _totalNbWithdrawals++;   
        _totalAmount = _totalAmount - withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal << std::flush;
        std::cout << ";amount:" << _amount << std::flush;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const {
    return(_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
     std::cout << "index:" << _accountIndex << std::flush;
     std::cout << ";amount:" << _amount << std::flush;
     std::cout << ";deposits:" << _nbDeposits << std::flush;
     std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t t = time(NULL);
    tm *ltm = localtime(&t);

    std::cout << "[" << std::flush;
    std::cout << 1900 + ltm->tm_year << std::flush;
    if (ltm->tm_mon < 10) { std::cout << "0" << std::flush; }
    std::cout << 1 + ltm->tm_mon << std::flush;
    if (ltm->tm_mday < 10) { std::cout << "0" << std::flush; }
    std::cout << ltm->tm_mday << std::flush;
    std::cout << "_" << std::flush;
    if (ltm->tm_hour < 10) { std::cout << "0" << std::flush; }
    std::cout << ltm->tm_hour << std::flush;
    if (ltm->tm_min < 10) { std::cout << "0" << std::flush; }
    std::cout << ltm->tm_min << std::flush;
    if (ltm->tm_sec < 10) { std::cout << "0" << std::flush; }
    std::cout << ltm->tm_sec << std::flush;
    std::cout << "] " << std::flush;
}
