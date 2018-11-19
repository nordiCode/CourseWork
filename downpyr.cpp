#include <iostream>

using std::cout;

int main(){
    int lines;
    cout<<"How many lines do you want\n";
    std::cin>>lines;
    int spaces=0;
    int i = lines;
    for(i; i>0;i=i-2){
        for(int k = 0; k<=spaces; k++){
            cout<<" ";
         }
        for(int j = i; j>0;j--){
             cout<<"#";
        }
     spaces +=1;
     cout<<"\n";
     }
    return 0;
}

