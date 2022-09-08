#include <stdio.h>
#include <math.h>

#define MIN(i,j) (((i) < (j)) ? (i) : (j))

int main(){
	double sal;
	char type;
	char mar;
	double prod;
	double weekly;
	double hourly;
	char vacay;
	double ot;
	double otHourly;
	double otWeek;
	double post;
	double pre;
	double hoursWork;
	printf("Enter Employee Type: \n");
	scanf("%c", &type);
	printf("Input monthly or weekly or hourly  salary depending on employee type: \n");
	scanf("%lf",&sal);
	if(type == 'S'){
		printf("Input overtime each month: \n");
		scanf("%lf",&ot);
		ot = MIN(ot, 10);
		printf("Is this employee married? \n");
		scanf(" %c", &mar);
		pre = (ot * 1.5 * (sal / 4 / 40))*12 + (sal * 12);
	}else if(type == 'E'){
		printf("Input overtime each day: \n");
		scanf("%lf",&otHourly);
		otHourly = MIN(1,otHourly);
		printf("Is this employee going to take a vacation? \n");
		scanf(" %c",&vacay);
		double sub = 0;
		if(vacay == 'y')
			sub = sal / 2;
		printf("Input products sold this year: \n");
		scanf("%lf",&prod);
		printf("Is this employee married? \n");
		scanf(" %c", &mar);
		pre = (12 * sal) - sub + (otHourly * 20 * 1.35 * (sal / 4 / 40) * 12) + 600 * prod;
	}else if(type == 'P'){
		printf("Input overtime each week: \n");
		scanf("%lf",&otWeek);
		otWeek = MIN(10,otWeek);
		printf("Input products sold this year: \n");
		scanf("%lf",&prod);
		printf("Is this employee married? \n");
		scanf(" %c",&mar);
		pre = (sal * 4 * 12)+ (otWeek * (sal / 40) * 4 * 12) + 600 * prod;
	}else if(type == 'H'){
		printf("Input hours worked each week: \n");
		scanf("%lf",&hoursWork);
		if(hoursWork > 10)
			otWeek = hoursWork - 10;
		printf("Is this employee married? \n");
		scanf(" %c", &mar);
		if(hoursWork > 10)
			hoursWork = 10;
		pre = (hoursWork * sal * 4 * 12) + (otWeek * 1.25 * sal * 4 * 12);
	}else if(type == 'A'){
		ot = 0;
		printf("Is this employee married? \n");
		scanf(" %c", &mar);
		pre = sal * 12;
	}

	if(mar == 'y'){
		if(pre > 32000)
			post = pre * 0.75;
		else
			post = pre * 0.9;
	}else{
		if(pre > 64000)
			post = pre * 0.75;
		else
			post = pre * 0.9;
	}

	printf("This employee's annual income is $%.2lf before tax and $%.2lf after tax.\n", pre, post);

	return 0;
}

