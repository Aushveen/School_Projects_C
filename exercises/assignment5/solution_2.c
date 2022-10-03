#include <stdio.h>

void filterStudents(int arr[5][4], int minAge, int minYear, int minGrade);

int main(){
	int arr[5][4] = {{1,18,11,90},{2,16,10,75},{3,15,9,85},{4,10,10,60},{5,11,9,60}};
	int minAge;
	int minGrade;
	int minYear;
	printf("Enter minAge : \n");
	scanf("%d",&minAge);
	printf("Enter minYear: \n");

	scanf("%d",&minYear);
	printf("Enter minGrade: \n");
	scanf("%d",&minGrade);
	filterStudents(arr, minAge, minYear, minGrade);
	printf("\n");
	return 0;
}

void filterStudents(int arr[5][4], int minAge, int minYear, int minGrade){
	for(int i = 0; i < 5; i++)
		if(arr[i][1] > minAge && arr[i][2] > minYear && arr[i][3] > minGrade)
			printf("%d ", arr[i][0]);

}
