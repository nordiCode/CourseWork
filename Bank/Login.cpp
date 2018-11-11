#include <iostream>
#include "Login.h"
using namespace std;

void Login::display(){
  cout<<"----------------------\n";
  cout<<"Please Enter your Pin: ";
}
void Login::displaySuccess(){
  cout<<"Pin Verified\n";
}
void Login::displayRetry(int pin){
  int tries = 0;
  int enteredpin;
  while(pin != enteredpin  && tries <3 )
  {
       cout<<"---Pin Verification Failed---\n";
       cout<<"Please Re-enter your pin: ";
       cin>>enteredpin;
       tries++;
       if(tries == 2){
           cout<<"---One try remaining---"<<endl;
       }else if(tries ==3)
           cout<<"You can leave the bank now"<<endl;
  }
}
void Login::displayOptions(){
    cout<<"---Press 1 for WithDrawl---\n";
    cout<<"---Press 2 for Deposit-----\n";
    cout<<"---Press 3 to End Transaction---\n";
}
