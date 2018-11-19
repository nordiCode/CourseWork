#include <iostream>

using std::cout;

int main(){
    int lines;
    cout<<"How many lines do you want\n";
    std::cin>>lines;
  
    for(int i = lines; lines>0; lines--){
        for(int j = lines; j>0; j--){
            cout<<"#";
        }
     cout<<"\n";
     }
    return 0;
}
