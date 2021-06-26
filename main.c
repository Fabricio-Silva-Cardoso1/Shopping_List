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

itemsList* itemHead = NULL;
itemsList* newItem = NULL;
itemsList* prevItem = NULL;
itemsList* item = NULL;

itemHead =(itemsList*) malloc (sizeof (itemsList));
itemHead -> next = NULL;

while(fgets(row,sizeof(row),fp) != NULL){

    newItem = (itemsList*) malloc (sizeof (itemsList));
    newItem -> next = NULL;
    strcpy(newItem -> item, row);

        if(itemHead -> next == NULL){
            itemHead -> next = newItem;
        }else{
            prevItem -> next = newItem;
        }
        prevItem = newItem;

    totalItems++;   
}

item = itemHead -> next;

while(item -> item != NULL){
    printf("%s\n", item -> item);
    item = item -> next;
}

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