#include<stdio.h>

int main(){
  int pass;
  float gas;
  float total= 0.0;

  scanf("%d%f",&pass,&gas);

  if(pass>=1){
      total = gas + 1.0;
      total = total/(pass+1);
  }
  else{total = gas;}

  printf("The total: %0.2f\n",total);


}
