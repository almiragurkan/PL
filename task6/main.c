#include <stdio.h>
#include <stdlib.h>
#include "CipherMethods.h"
#define TRACE_ORG_DEC

int enterPasscode(){
  char passcode[9]= "ceng2002";
  char enteredcode[9];
  scanf("%s", enteredcode);
  for (int i=0; i<3;i++){
    if(strcmp(passcode,enteredcode)==0)
      return 1;
    else {
      printf("Wrong passcode. Enter again:");
      scanf("%s", enteredcode);
    }
  }
  printf("Number of allowed attempts has been reached without successful entry!Your IP has been blacklisted by us. Good luck!!\n");
  return 0;
}
int YesOrNo(){
  char ans;
  scanf("\n%c", &ans);
  if(ans=='y' || ans=='Y')
    return 1;
  else if(ans=='n' || ans=='N')
    return 0;
  printf("Please answer with Y or N\n");
  return YesOrNo();
}
char* getinteger();
int main(void) {
  char text[500];
  char* encrypted;
  char * decrypted;
  printf("** You are about to enter a very secret cryptography service called CENG 2002 CSecret Coded System **\n");
  printf("Enter your text: ");
  fgets(text, 500, stdin);
  text[strlen(text)-1] = '\0';
  system ("CLS");
  printf("In order to see the encrypted message, enter your passcode:");
  if(enterPasscode()==1){
    encrypted=encryptCaesar(text);
    printf("Cipher: %s\n", encrypted);
  }
  printf("Would you like to convert the cipher to original text (Y/N)?\n");
  if(YesOrNo()==1){
    decrypted=decryptCaesar(encrypted);
    printf("%s\n", decrypted);
  }

#ifdef TRACE_ORG_DEC
  if(strcmp(text, decrypted)==0){
    printf("Original text and the decrypeted text match.\n");
  }
  else
    printf("There is something wrong. Original text and the decrypted text do not match.\n");
#endif
  return 0;
}