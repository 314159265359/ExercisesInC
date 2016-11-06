#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FALSE 0
#define TRUE !FALSE

struct stock_data{
    char name[30];
    float buy_price; 
    float current_price; 
    };

void write_info(void);
void read_info(void);
void replace_info(void);

int main()
{
    char c; 
    int done = FALSE; 
    while(!done)
    {
        puts("\nStock Portfolio \n");
        puts("A - Add new stock\n");
        puts("L - List stocks\n"); 
        puts("R - Replace stock\n");
        puts("Q - Quit\n");
        printf("Your choice: "); 
        c = getchar();
      //  fflush(stdin); 
      //  c = toupper(c);
        switch(c)
        {
            case('A'):
                puts("Add new stock\n");
                write_info();
                break; 
            case('L'): 
                puts("List stocks"); 
                read_info();
                break; 
            case('R'):
                puts("Replace stock");
                replace_info();
                break;
            case('Q'):
                puts("Quit\n");
                done = TRUE;
                break; 
      //      default:
      //        puts("?");
      //          break;
         }
     }
    
     return 0;
}

void write_info()
{
    FILE *stocks; 
    struct stock_data stock; 
    printf("Enter stock name:\n"); 
    fgets(stock.name, sizeof(stock.name), stdin);
    printf("What did you buy it for? $");
    scanf("%f", &stock.buy_price);
    stock.current_price = stock.buy_price/11;
    stocks = fopen("stock.dat", "a");
    if(stocks==NULL)
    {
        puts("Error opening file");
        exit(1); 
    }
    fwrite(&stock, sizeof(stock),1,stocks); 
    fclose(stocks); 
    puts("Stock added!");
    fflush(stdin); 
}

void read_info()
{
    FILE *stocks; 
    struct stock_data stock;
    int x; 
    stocks = fopen("stock.dat","r"); 
    if(stocks==NULL)
    {
        puts("No data in file"); 
        return; 
    }

    while(TRUE)
    {
        x = fread(&stock, sizeof(stock),1,stocks);
        if(x==0)break;
        printf("\nStock name: %s\n", stock.name);
        printf("Purchased for $%.2f\n", stock.buy_price);
        printf("Current price: $%.2f\n", stock.current_price);
    }

    return;
    fclose(stocks);
}


void replace_info()
{
    FILE *stocks; 
    struct stock_data stock;
    
    int record, x; 
    long offset; 
    printf("Which record number do you want to find? "); 
    scanf("%d", &record); 
    stocks = fopen("stock.dat", "r"); 

    if(stocks==NULL)
    {
        puts("Error opening file"); 
        return; 
    }
    offset = (long)(record-1) *sizeof(stock); 
    x = fseek(stocks, offset, SEEK_SET); 
    if(x!=0)
    {
        puts("Error reading from file"); 
        return;
    }
    x = fread(&stock, sizeof(stock), 1, stocks);
    if(x==0)
    {
        puts("Error reading record"); 
        return; 
    }

    printf("\nRecord: %d\n", record);
    printf("Stock name: %s\n", stock.name); 
    printf("Purchased for $%.2f\n", stock.buy_price); 
    printf("Current price: $%.2f\n", stock.current_price);

    fclose(stocks);

    fflush(stdin);
}

       

























































