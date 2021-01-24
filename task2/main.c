#include<stdio.h>
#include<stdbool.h>

int main (void)
{
    int number;
    int count;
    printf("Enter a pas int");
    scanf("%d" , &number);
    count = nrDigits(number);
    printf("Digits of a number %d\n", count);
    printf("GCD result is %d\n", GCD( 10, 20));
    printf("Prime number is %d", Prime(8));
    return(0);
}
int nrDigits(int num)
{
    static int count = 0;

    if (num > 0) {
        count ++;
        nrDigits(num/10);
    }
    else
        return count;
}


int GCD(int num1, int num2)
{
    static int result;
    if (result == 0)
      result = num1;

    if (num1%result == 0 && num2 % result ==0)
       return result;
       result-- ;
    return GCD(num1,num2);

}


int Prime(int number)
{
    static int i=2;
    if (i==number)
        return true;
    if (number%i==0)
        return false;
    i++;
    return Prime(number);

    return true;
}
