typedef struct {
 char type[3];
 int nrOfOpr;
 int num;
} BizarreNumber_t;


struct stackNode {
 BizarreNumber_t data;
 struct stackNode *nextPtr;
};

typedef struct stackNode *StackNodePtr;

int isPrime(int num);
int isAbundantNumber(int num);
int isPerfectSquare(int num);
void push(StackNodePtr *topPtr, BizarreNumber_t info);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);
