#include <iostream>
#include <time.h>

using std::cout;

int compareFunc(const void * voidA, const void * voidB){
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}

int main(){
  srand (time(NULL));  //seed for random
  const int SIZE = 10;
  int arr[SIZE];

  for(int i = 0; i < SIZE; i++){
    arr[i] = rand() % 100;
  }

  qsort(arr, SIZE, sizeof(int), compareFunc);
  for(int k = 0; k < SIZE; k++){
    cout<<arr[k]<<" ";
  }
  cout<<"\n";
  int length = sizeof(arr)/sizeof(int);

  int median;
  if(length % 2 == 0){
    int middle = (length/2) - 1;
    median = arr[middle];
  }else{
    int mid = (length - 1)/2;
    int mid2 = mid + 1;
    median = (arr[mid]+arr[mid2])/2;
  }
  cout<<"The median:"<<median<<"\n";
  return 0;
}
