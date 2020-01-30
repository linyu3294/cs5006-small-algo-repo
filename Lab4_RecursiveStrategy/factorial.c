// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(int n){
    int i =0;
    int fact =1;
    for (i=1; i<n; i++){
        fact = i* fact;
    }
  return fact;
};

// TODO: Implement recursive solution here
int factorial_rec(int n){
    if (n==1) {
        return (1);
    }
    return (n * factorial_rec(n-1));
}

int main(){

  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));


  return 0;
}

