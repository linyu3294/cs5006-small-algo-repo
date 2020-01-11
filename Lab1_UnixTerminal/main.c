
// Add your program here!
//
#include <stdio.h>

double power (double base, double n) {
	double result = base;
	int i = 0;

	for (i =0; i<n; i++) {
	result = result * base;
	}
	return result;
}

int main() {
	int i =0;
	for (i =0; i<10; i++) {
	int result = power (2, i);
	printf ("The %dth power of 2 is %d\n" , i+1,  result);  
	}
}
