#include <stdio.h>


int num_length(long credit){
  int count=0;
  int num =2;

  while (credit >0) {
    num = credit%10;
    credit = credit/10;
    //printf("The credit nums %d\n",num);
    count = count +1;
    }

  return count;
}
int check(long credit, int length){
  int i;
  int num;
  int check = 0;
  int sum = 0;
  int dub;
  int ones;
  for(i = 0; i < length; i++){
    num=credit%10;
    if((length - i)%2==0 && length%2 != 0 || length%2==0 && (length - i)%2!=0){
  //    printf("Every other num: %d\n", num);
      dub = num*2;
      if(dub>10){
      //  printf("This is dub: %d\n",dub);
        ones = dub%10;
        dub = dub/10;
      //  printf("this is ones, dub %d,%d\n",ones,dub);
        sum = sum + (ones + dub);
      }
      else{sum= sum + dub;}
    }
    else{sum = sum + num;}
    credit = credit/10;

  }
//  printf("This is our checksum: %d\n", sum);
  if(sum%10 == 0){check = 1;}
  return check;
}
int credit_comp(long credit, int length){
  int comp_num;
  int i;
  printf("the credit num in here %ld\n",credit);
  if(length == 15){
  //  printf("Possibly AE ");
    comp_num = (credit/10000000000000);
    if(comp_num ==34 || comp_num ==37){printf("AMEX\n");}
    }
  else if(length==16){
    comp_num = (credit/100000000000000);
  //  printf("Comp num %d",comp_num);
    if(comp_num>=51 &&comp_num<=55){printf("MC\n");}
    else if((credit/1000000000000000)==4){printf("VISA\n");}
  }
  else if(length ==13){
    comp_num=(credit/1000000000000);
    if(comp_num ==4){printf("VISA\n");}
  }
  else{printf("INVALID\n");}
  return  0;
}

int main(){
  long credit_num;

  printf("Number: ");
  scanf("%ld", &credit_num);
//  printf("This is the credit card number: %ld\n",credit_num);

  int length  = num_length(credit_num);
//  printf("This is the credit card length %d\n", length);

  int check_num = check(credit_num,length);
//  printf("Here is the check digit: %d\n", check_num);

  if(check_num ==1){
    printf("This is a valid credit card num \n");
    credit_comp(credit_num, length);
    }
  else{printf("INVALID\n");}
}
