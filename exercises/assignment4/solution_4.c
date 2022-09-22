#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();
int getSum(int a, int b);
void checkCraps(int score, int turn);

int main(){
	srand(time(NULL));
	printf("Would you like to play a game of craps? Type y for yes or n for no: \n");
	char z;
	scanf(" %c",&z);
	if(z == 'n')
		return 0;
	printf("Dice is rolling . . .\n");
	int a = rollDice();
	int b = rollDice();
	int sum = getSum(a,b);
	printf("Score on dice are: %d and %d\n",a,b);
	printf("Sum is: %d\n",sum);
	checkCraps(sum,1);

	return 0;
}



int rollDice(){
	return rand() % 6 + 1;
}


int getSum(int a, int b){
	return a + b;
}

void checkCraps(int score, int turn){
	if((score == 7 && turn == 1 ) || (score == 11 && turn == 1))
		printf("Congrats you won!!!\n");
	else if(turn == 1 && (score == 2 | score == 3 || score == 12))
		printf("Sorry you have lost, the house wins.\n");
	else{
		printf("Your point is %d . . .\n",score);
		printf("Dice is rolling . . .\n");
		int f,s;
		f = rollDice();
		s = rollDice();
		printf("Score on dice are: %d and %d\n",f,s);
		int sum = getSum(f,s);
		printf("Sum is: %d\n",sum);
		if(sum == score)
			printf("Consecutive same sum. You won!\n");
		else
			printf("You lost!\n");
	}
}

