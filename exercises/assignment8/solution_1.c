#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numElements 3



struct Address{
    char street[50];
    char city[50];
    char state[10];
    char zip[10];
};

struct Product{
    char name[25];
    double price;
};

struct Items{
    struct Product prod;
    int qty;
};

struct Invoice{
    struct Items * items;
    struct Address address;
};


struct Address createAddress(char * street, char * city, char * state, char * zip){
    // Create a temporary object, set values then return the temp object
    struct Address temp;
    strcpy(temp.street, street);
    strcpy(temp.city, city);
    strcpy(temp.state, state);
    strcpy(temp.zip, zip);
    return temp;
}

struct Product createProducts(char * name, double price){
    // Create a temporary object, set values then return the temp object
    struct Product temp;
    strcpy(temp.name, name);
    temp.price = price;
    return temp;
}

struct Items createLineItem(struct Product prod, int quantity){
    // Create a temporary object, set values then return the temp object
    struct Items temp;
    temp.prod = prod;
    temp.qty = quantity;
    return temp;
}

struct Invoice createInvoice(struct Items * items, struct Address Address){
    // Create a temporary object, set values then return the temp object
    struct Invoice temp;
    temp.items = items;
    temp.address = Address;
    return temp;
}

void printInvoice(struct Invoice invoice){
    // Print the heading with 17 spaces before
    printf("%17sI N V O I C E\n","");
    printf("\nSam's Small Appliances");
    // print the address
    printf("\n%s", invoice.address.street);
    printf("\n%s, %s %s\n\n", invoice.address.city, invoice.address.state, invoice.address.zip);

    // Table header
    printf("\nDesctiption \t\t%s", "Price Qty Total");
    // Variable to store the total amount due for all products
    double amtDue = 0;
    // Loop numElements times and print the table for all products
    for(int i=0; i<numElements; i++){
        // Variables to store current product price, qty and total
        double currPrice = invoice.items[i].prod.price;
        int currQty = invoice.items[i].qty;
        double total = currPrice * currQty;
        // Print formatted output
        printf("\n%s \t%7s %0.2f  %d  %0.2f", invoice.items[i].prod.name, "",currPrice, currQty, total);
        // add to amtDue
        amtDue += total;
    }
    // Display amtDue
    printf("\n\nAMOUNT DUE:  $%0.2f",amtDue);
}
int main(){
	struct Product prod1 = createProducts("Toaster", 29.95);
    	struct Product prod2 = createProducts("Hair Dryer", 24.95);
    	struct Product prod3 = createProducts("Car Vacuum", 19.99);
       	struct Items items[numElements];
       	items[0] = createLineItem(prod1, 3);
        items[1] = createLineItem(prod2, 1);
        items[2] = createLineItem(prod3, 2);
        struct Address address = createAddress("100 Main Street", "Anytown", "CA", "98765");
       	struct Invoice invoice = createInvoice(items, address);
       	printInvoice(invoice);
	printf("\n");

	return 0;
}
