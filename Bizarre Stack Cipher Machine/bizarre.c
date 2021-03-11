#include "bizarre.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void push(StackNodePtr *topPtr, BizarreNumber_t info){
  StackNodePtr root=malloc(sizeof(struct stackNode));
  root->nextPtr=*topPtr;
  root->data=info;
  *topPtr=root;
}

BizarreNumber_t pop(StackNodePtr *topPtr){
  StackNodePtr temp = *topPtr;
  BizarreNumber_t data1 = temp->data;
  *topPtr = temp->nextPtr;
  free(temp);
  return data1;
}

int isEmpty(StackNodePtr topPtr){
  if (topPtr==NULL)
    return 1;
  return 0;
}

StackNodePtr reverseStack(StackNodePtr currentPtr){
  StackNodePtr different=NULL;
  while(!isEmpty(currentPtr))
    push(&different, pop(&currentPtr));
  return different;
}

void printStack(StackNodePtr currentPtr){
  printf("TOP -->");
  while (currentPtr!=NULL){
    if(currentPtr->data.num==-1)
      printf(" NULL -->");
    else
      printf(" %d -->", currentPtr->data.num);
    currentPtr=currentPtr->nextPtr;
  }
  printf(" BOTTOM\n\n");
}


void printStackDetailed(StackNodePtr currentPtr){
  printf("%s\n", "***TOP***");
  while(currentPtr != NULL){
    printf("%d, %d, %s\n", currentPtr->data.num, currentPtr->data.nrOfOpr, currentPtr->data.type);
      currentPtr=currentPtr->nextPtr;
    }
  printf("%s\n\n", "***BOTTOM***");
}


int isAbundantNumber(int num){
  int sum=0;
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      sum = sum + i;
    }
  }
  int abundance = sum-num;
  return abundance;
}


int isPrime(int num){
  if (num <= 1) 
    return 0;
     if (num % 2 == 0 && num > 2)
      return 0;
     for(int i = 3; i < num / 2; i+= 2){
        if (num % i == 0)
          return 0;
     }
     return 1;
}

int isPerfectSquare(int num){
  for(int i = 0; i <= num; i++){
    if(num == i*i)
       return 1;
  }
  return 0;
}


StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack){
    StackNodePtr recovered=NULL;
    while (mainStack != NULL){
      BizarreNumber_t m=mainStack->data;
      BizarreNumber_t h=helperStack->data;

      if(strcmp(m.type, "PR")==0){
          BizarreNumber_t current={"PR", 0, sqrt(m.num)};
          push(&recovered, current);
      }
      else if(strcmp(m.type, "SQ")==0){
        int result=m.num;
        for(int i=0; i< m.nrOfOpr; i++)
          result*=result;
        BizarreNumber_t current={"SQ", m.nrOfOpr, result};
        push(&recovered, current);
      }else if(strcmp(h.type, "DF")==0){
        BizarreNumber_t current={"DF", 0, h.num};
        push(&recovered, current);
      }else if(strcmp(m.type, "PF")==0){
        push(&recovered, m);
      }
      else {
        BizarreNumber_t current={"AB", 0, m.num+h.num};
        push(&recovered, current);
      }

      mainStack=mainStack->nextPtr;
      helperStack=helperStack->nextPtr;
    }
    return recovered;
}