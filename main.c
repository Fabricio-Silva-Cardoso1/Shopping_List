#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

typedef struct itemsList{
    char item[20];
   struct itemsList *next;
} itemsList;

FILE *fp;
char c[30];
char s[30];
int totalItems = 0;

char row[30];

fp = fopen("List.txt","r");

itemsList* itemList = NULL;
itemList =(itemsList *)malloc(sizeof(itemsList));

while(fgets(row,sizeof(row),fp) != NULL){

    strcpy(itemList -> item, row);
    totalItems++;   
}

strcpy(itemList->item, row);
printf("%s\n", itemList->item);
itemList->next = NULL;


/*printf("%s\n", itemList[0]);*/

/*printf("%d\n",i);*/

/*fseek(fp, 0, SEEK_SET); /* Return the file pointer to the beggining*/
/*fscanf(fp,"%[^\n]",c); /* Read each line of the file*/

/*
printf("%s",c);
printf("%d",i);
*/


fclose(fp);
return 0;

}

/*int totalItems(FILE *file){


    return 
}*/