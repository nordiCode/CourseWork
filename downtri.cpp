#include <iostream>

using std::cout;

int main(){
    int lines;
    cout<<"How many lines do you want\n";
    std::cin>>lines;
    int spaces;
   
    for(int i = lines; i>0;i--){
        spaces = lines - i;
        for(int k = 0; k<=spaces; k++){
            cout<<" ";
         }
        for(int j = i; j>0; j--){
             cout<<"#";
        }
     cout<<"\n";
     }
    return 0;
}

