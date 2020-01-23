// Add your program here!
#include <stdio.h>
#include <stdlib.h> 

int main () {
        // initializing the reults of each game.
	int score[] = {0,0,0,0,0};

		int i = 0;
	        for (i =0; i <5; i++) {
        	// initializing random number.
        	int rand_num = (rand() % 10) + 1;
		

		// for each i, start the game.	
		printf ("\n=========================\n");
        	printf ("CPU Says: Pick a number 1-10\n");
		printf ("%d \n", rand_num );		
		printf ("=========================");
		int guess = 0;
		int num_of_guesses = 0;
		while (guess != rand_num) {
		// Prompt user to guess.
		printf ("\nMake a guess: ");
		int guess = 0;
		
		scanf("%d", &guess);
	
		// printf ("Random Number = %d  and Your guess = %d ", rand_num, guess);
			// Check conditions and print hints.
			// If a guess is correct, break out of while loop.
			if (rand_num > guess)
			{
				printf("No guess higer!");
			}
			if (rand_num < guess)
                        {
                                printf("No guess lower!");
                        }
			if (rand_num == guess)
                        {
                                printf("You got it!");
				num_of_guesses++;
				score [i] = num_of_guesses;
                        	break;
			}
		num_of_guesses++;
		}
		}
		// Print out final results from the five games played.
	        printf ("\n=========================\n");
                printf ("Here are the results of your gussing abilities\n");
                printf ("=========================");
		int j = 0;
		for (j =0; j<5; j++) {
		printf ("Game %d took \n%d guesses", j, score[j]);
		}
		printf("\n");
