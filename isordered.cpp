#include <iostream>
#include <time.h>

using std::cout;

bool inorder(int arr[], int size){
  // int start = arr[0];
  for(int i = 1; i < size; i++){
    if(arr[i-1] > arr[i])
      return false;
  }
  return true;
}

void printArr(int arr[], int size){
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<"\n";
  }
}

int main(){
  srand (time(NULL));
  const int SIZE = 10;
  int arr[SIZE];
  int test[]={1,2,3,4,5,6,7,8,9,10};

  for(int i = 0; i< SIZE; i++){
    arr[i] = rand() % 100;
  }
  printArr(arr,SIZE);
  if(inorder(arr,SIZE) == true)
    cout<<"array in order\n";
  else
    cout<<"not in order\n";
  if (inorder(test,10)==true)
    cout<<"of course\n";
  return 0;
}
