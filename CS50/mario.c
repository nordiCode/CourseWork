#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

  int i;
  int j;
  int k;
  int l;
  int rows;

 
  if(argc >=2){
     rows = atoi( argv[1]);
  while(rows <=0 | rows >23){
    printf("Enter a row number between 0 and 23: ");
    scanf("%d", &rows);
    printf("This is your rows%d\n",rows);
  }
  for(k = 0; k < rows ; k++){
    for(l = 0; l < rows; l++)
      if(l  < (rows - k)-1){printf(" ");}
        else{printf("#");}
    printf("  ");
    for(j = 0; j<k+1; j++)
      printf("#");
    printf("\n");
    }
  }
}
