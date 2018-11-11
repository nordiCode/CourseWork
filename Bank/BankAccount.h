#include <iostream>
using std::cout;

using namespace std;

class BankAccount
{
    private:
        float mBalance;
        int mAccountNum;
        int mPin;

    public:
      BankAccount();
      BankAccount(float,int,int);
      void deposit(float);
      void withDrawl(float);
      float getBalance();
      float setBalance(float);
      int getAccountNum();
      void setAccountNum(int);
      void display();
      void setPin(int);
      int getPin();
};
