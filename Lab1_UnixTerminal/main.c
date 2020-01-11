
// Add your program here!
//
#include <stdio.h>

double power (double base, double n) {
	double result = base;
	int i = 0;

	for (i =1; i<n+1; i++) {
	result = result * base;
	}
	return result;
}

int main() {
	int i =0;
	for (i =1; i<11; i++) {
	int result = power (10, i);
	printf ("The %dth power of 10 is %d\n" , i,  result);  
	}
}
