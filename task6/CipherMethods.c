#include "CipherMethods.h"

char* encryptCaesar(const char *original){
  int len=strlen(original);
  char* encrypted = malloc((len) * sizeof(char));

  for (int i=0; i<len;i++){
    if (strchr(CIPHER_SPECIAL_CHARS, original[i]) != NULL){
      encrypted[i]=original[i];
    }else{
      char n;
      if(isupper(original[i])!=0)
        n = ((original[i] - 'A' + CAESAR_SHIFT) % NUMBER_OF_LETTERS) + 'A';
      else if(islower(original[i])!=0)
        n = ((original[i] - 'a' +CAESAR_SHIFT) % NUMBER_OF_LETTERS) + 'a';
      else
        n= ((original[i] - '0' +CAESAR_SHIFT) % NUMBER_OF_DIGITS) + '0';
      encrypted[i]=n;
    }
  }

  return encrypted;
}

char* decryptCaesar(const char *original){
  int len=strlen(original);
  char* encrypted = malloc((len) * sizeof(char));

  for (int i=0; i<len;i++){
    if (strchr(CIPHER_SPECIAL_CHARS, original[i]) != NULL){
      encrypted[i]=original[i];
    }else{
      char n;
      if(isupper(original[i])!=0)
        n = ((original[i] - 'Z' - CAESAR_SHIFT) % NUMBER_OF_LETTERS) + 'Z';
      else if(islower(original[i])!=0)
        n = ((original[i] - 'z' -CAESAR_SHIFT) % NUMBER_OF_LETTERS) + 'z';
      else
        n= ((original[i] - '9'- CAESAR_SHIFT) % NUMBER_OF_DIGITS) + '9';
      encrypted[i]=n;
    }
  }

  return encrypted;
}