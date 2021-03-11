#include <stdio.h>
#include "bizarre.h"
#include <math.h>


int main(void) {
  StackNodePtr mainStack= NULL;
  StackNodePtr helperStack= NULL;
  
  printf("Enter an integer number to push:\n");
  int number;
  int i=scanf("%d", &number);
  while (i != EOF){
    BizarreNumber_t empty={"", 0, -1};
    printf("Enter an integer number to push:\n");
    if (isPrime(number)==1){
       BizarreNumber_t n={"PR", 0, number*number};
       push(&mainStack, n);
       push(&helperStack, empty);
    }
    else if(isPerfectSquare(number)==1) {
      int nrOfOpr=0;
      int squareroot=number;
      while(isPerfectSquare(squareroot)==1){
        squareroot=sqrt(squareroot);
        nrOfOpr++;
      }
      BizarreNumber_t n={"SQ",nrOfOpr, squareroot};
      push(&mainStack, n);
      push(&helperStack, empty);
    }
    else {
      int abundance = isAbundantNumber(number);
      if(abundance < 0){
        BizarreNumber_t n={"DF", 0, number};
        push(&helperStack, n);
        push(&mainStack, empty);
      }
      else if(abundance == 0){
        BizarreNumber_t n={"PF", 0, number};
        push(&mainStack, n);
        push(&helperStack, empty);
      }else{
        BizarreNumber_t n={"AB", 0, abundance};
        push(&helperStack, n);
        BizarreNumber_t t={"AB", 0, number-abundance};
        push(&mainStack, t);
      }
    }
   
      i=scanf("%d", &number);

  }
  
  printf("\n\nThe main stack is:\n");
  printStack(mainStack);
  printf("The helper stack is:\n");
  printStack(helperStack);
  StackNodePtr recovered = recoverCipher(mainStack, helperStack);
  recovered=reverseStack(recovered);
  printStackDetailed(recovered);

  
}