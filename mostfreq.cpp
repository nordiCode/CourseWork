#include <iostream>

using std::cout;

int compareFunc(const void * voidA, const void * voidB){
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;

}

int main(){
    const int SIZE = 10;
    int arr[SIZE] = {1,2,5,5,5,5,5,6,5,9};
    
    qsort(arr,SIZE,sizeof(int),compareFunc);
    
    int current = 0;
    int count = 1;
    int mostfreq = 0;
     
    int start = arr[0];

    for(int i = 1; i < SIZE; i++)
    {
        if (arr[i] == arr[i-1]){
            count += 1;}
        else{count = 1;}
        if (count > current){
            current = count;
            mostfreq = arr[i];
        } 
        cout<<arr[i]<<"\n";
    }
    cout<<"Most freq: "<< mostfreq << " this many times " << current << "\n";
    return 0;
}
