#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    std::time_t now = std::time(0);
    std::tm* timeinfo = std::localtime(&now);
    
    	std::cout << "[" << std::setw(2)  << timeinfo->tm_mday
		<< std::setfill('0') << "-" << std::setw(2) << (timeinfo->tm_mon + 1)
		<< "-" << (timeinfo->tm_year + 1900)
		<< "  "
		<< std::setw(2) << timeinfo->tm_hour << ":"
		<< std::setw(2) << timeinfo->tm_min << ":"
		<< std::setw(2) << timeinfo->tm_sec
		<< "] ";
}
//Constructor privado
Account::Account() {
	//Constructor por defecto
}
//Constructor inicial
Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "Indice: " << _accountIndex 
              << "; Cantidad: " << _amount 
              << "; Creado" << std::endl;
}
Account::~Account() {
    _displayTimestamp();
    std::cout << " Indice: " << _accountIndex 
              << "; Cantidad: " << _amount 
              << "; Cerrado " << std::endl;}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "Cuentas: " << _nbAccounts
			  << "; Total: " << _totalAmount
			  << "; Depositos: " << _totalNbDeposits
			  << "; Retirados: " << _totalNbWithdrawals
			  << std::endl;
}
void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "Indice: " << _accountIndex 
			  << "; Cantidad: " << _amount 
			  << "; Depositado: " << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "; Cantidad actualizada: " << _amount 
			<< "; Numero de depositos: " << _nbDeposits 
			<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ){
	if (withdrawal > _amount || withdrawal <= 0)
	{
		std::cout << "No se ha podido retirar la cantidad deseada" << std::endl;
		return false;
	} else {
		  std::cout << "Indice: " << _accountIndex 
			  << "; Cantidad: " << _amount 
			  << "; Retirado: " << withdrawal;
		_amount =- withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
			std::cout << "; Cantidad actualizada: " << _amount 
			<< "; Numero de retiradas: " << _nbWithdrawals 
			<< std::endl;
		}
		return true;
}

int	Account::checkAmount( void ) const{
	return _amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "Indice: " << _accountIndex 
			  << "; Cantidad: " << _amount 
			  << "; Depositos: " << _nbDeposits 
			  << "; Retiradas: " << _nbWithdrawals 
			  << std::endl;
}