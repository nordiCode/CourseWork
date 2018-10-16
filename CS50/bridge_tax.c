#include<stdio.h>

int main(){
  int x,y;
  int total;
  scanf("%d%d",&x,&y);

  if(x+y >=10){
    printf("Special tax\n");
    printf("%d",36);
  }
  else{
    printf("Regular Tax\n");
    printf("%d\n",(x+y)*2);
  }
}
