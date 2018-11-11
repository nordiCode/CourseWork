#include <iostream>
#include "BankAccount.h"
using std::cout;
using std::endl;


BankAccount::BankAccount()
{
  mBalance = 0;
}
BankAccount::BankAccount(float balance,int accountNum, int pin)
{
  mBalance = balance;
  mAccountNum = accountNum;
  mPin = pin;

}
float BankAccount::getBalance()
{
  return mBalance;
}
float BankAccount::setBalance(float balance)
{
  mBalance = balance;
}
int BankAccount::getAccountNum()
{
  return mAccountNum;
}
void BankAccount::setAccountNum(int accountNum)
{
  mAccountNum = accountNum;
}
int BankAccount::getPin()
{
    return mPin;
}
void BankAccount::setPin(int pin)
{
  mPin = pin;
}
void BankAccount::deposit(float money)
{
  mBalance += money;
}
void BankAccount::withDrawl(float money)
{
  if(money > mBalance)
      cout<<"Sorry insufficient funds"<<endl;
  else
      mBalance -= money;
}
void BankAccount::display(){
    cout<<"--------------------------------------\n";
    cout<<"Welcome to Grant's Bank!\n";
    cout<<"Your Account Number:#"<<getAccountNum()<<endl;
    cout<<"Your Current Balance:"<<getBalance()<<endl;
    cout<<"--------------------------------------\n";
}
