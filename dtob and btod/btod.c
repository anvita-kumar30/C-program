// convert binary to decimal
#include<stdio.h>
#include<math.h>
int convert(long);

int main() {
  long n;
  printf("Enter a binary number: ");
  scanf("%11d", &n);
  printf("%d in binary =  %d in decimal", n, convert(n));
  return 0;
}

int convert(long n) {
  int dec=0, rem, i = 0;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem *pow(2,i);
    ++i;
  }

  return dec;
}