#include <stdio.h>
#define PLUS(x, y) ((x) + (y))
//#define FACT(n) ( n==0 ? 1 : FACT(n-1)*n) fungerar inte


int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int plus(int x, int y) {
  return x + y;
}

int main(){
	int val;
	int n = 4;
	val = FACT(n);
	printf("%d\n",val);
	return 0;
}
