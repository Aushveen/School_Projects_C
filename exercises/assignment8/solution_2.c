#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Item{
	char name[50];
	char label[2];
	double price;
	int qty;
};

struct Item create(char *name, char *label, double price, int qty){
	struct Item tmp;
	strcpy(tmp.name, name);
	strcpy(tmp.label,label);
	tmp.price = price;
	tmp.qty = qty;
	return tmp;
}


int main(){
	// array of items, 3 x 3
	struct Item items[3][3];
	struct Item item1 = create("Coke","A1",2,4); items[0][0] = item1;
       	struct Item item2 = create("Sprite","A2",3,2); items[0][1] = item2;
	struct Item item3 = create("Fanta","A3",3,12); items[0][2] = item3;
	struct Item item4 = create("Sparkling water","B1",3,1); items[1][0] = item4;
	struct Item item5 = create("Water","B2",3,2); items[1][1] = item5;
	struct Item item6 = create("7-up","B3",3,7); items[1][2] = item6;
	struct Item item7 = create("Diet Coke","C1",3,7); items[2][0] = item7;
	struct Item item8 = create("Sprite-Zero","C2",3,1); items[2][1] = item8;
	struct Item item9 = create("Coke-Zero","C3",3,6); items[2][2] = item9;

	for(int i = 0; i <3;i++){
		for(int j = 0; j < 3; j++){
			printf("%s\n",items[i][j].name);
			printf("%s\n",items[i][j].label);
		}
	}

	printf("[1] Insert money\n[2] Check balance\n[3] Check price\n[4] Purchase\n[5] Return change\n[6] Owner menu\n[7] Exit\n");
	int option;
	printf("Choose an option: \n");
	scanf("%d",&option);
	int bal = 0;
	switch(option){
		case 1:
			int amt;
			printf("Amount: \n");
			scanf("%d",&amt);
			bal += amt;
		case 2:
			printf("Curr bal %d\n",%bal);
		case 3:



}
