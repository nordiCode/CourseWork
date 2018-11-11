#include <iostream>
#include "BankAccount.h"
#include "Login.h"
using namespace std;

int main(){
    cout<<"\n";
    cout << "\033[1;34m  Grant's Command Line bank\033[0m\n";
    BankAccount p1 = {65.95,87656,7567};
    Login user;
    user.display();

    int pin;
    cin>>pin;
    if(p1.getPin()!=pin){
        user.displayRetry(p1.getPin());
      }else{
        user.displaySuccess();
        int userResponse = -1;
        while (userResponse != 3){
            user.displayOptions();
            cin >> userResponse;
            switch(userResponse)
            {
              case 1:
                  float withDrawlAmount;
                  cout<<"\n";
                  cout<<"---WithDrawl Selected----\n";
                  cout<<"Enter WithDrawl Amount: ";
                  cin>>withDrawlAmount;
                  p1.withDrawl(withDrawlAmount);
                  cout<<"New Balance is: "<<p1.getBalance()<<endl;
                  break;
              case 2:
                  float depositAmount;
                  cout<<"---Deposit Selected---\n";
                  cout<<"Enter Deposit Amount\n";
                  cin>> depositAmount;
                  p1.deposit(depositAmount);
                  cout<<"New Balance is: "<<p1.getBalance()<<endl;
                  break;
            }
      }

      }
    return 0;
}
