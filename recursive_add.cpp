#include <iostream>
#include <time.h>

using std::cout;

int compute(int arr[], int size){
  if(size == 0) return 0;
//  cout<<"Number to sum: "<<arr[size-1]<<"\n";
  int sum = compute(arr, size - 1);
  return sum += arr[size - 1];
}
void printArr(int arr[], int size){
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<"\n";
  }
}
int main(){
  srand (time(NULL));
  int const SIZE = 10;
  int arr[SIZE]  ;

  for(int i = 0; i < SIZE; i++){
    arr[i] = rand() % 100;
  }
  printArr(arr, SIZE);
  int count = compute(arr,SIZE);
  cout<<"The count: "<<count<<"\n";
  return 0;
}
