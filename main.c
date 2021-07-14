#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct itemsList{
    char item[20];
   struct itemsList *next;
} itemsList;

int Menu();
int readFileItems(FILE *);
void createList(FILE *);
void editList(FILE *);
void insertList(FILE *);
void removeList(FILE*);



int main(){

FILE *fp, *listcreated;
int option;

fp = fopen("List.txt","r");

printf("Para sair digite qualquer outro valor\n");

do  {
    option = Menu();

    switch (option)
        {
        case 1:
            readFileItems(fp);
                break;

        case 2:
            createList(listcreated);
                break;

        case 3:
            editList(listcreated);
                break;

        default:
        return 0;
        }
    }

while(option > 0 || option < 3 );

/*fseek(fp, 0, SEEK_SET); /* Return the file pointer to the beggining*/
/*fscanf(fp,"%[^\n]",c); /* Read each line of the file*/

    fclose(fp);
return 0;
}

/*int totalItems(FILE *file){
    return 0;
}*/

int Menu(){

    int escolha;


    printf("Escolha uma opcao:\n");
    printf("1 - Ler TODOS os itens já cadastrados\n");
    printf("2 - Crie uma lista de compra\n");
    printf("3 - Edite a lista criada\n");
    printf("4 - Sair do programa\n");

    scanf("%d", &escolha);
    fflush(stdin);

        return escolha;

}

int readFileItems(FILE * list){

int totalItems = 0;
char row[30];

itemsList* itemHead = NULL, *newItem = NULL, *prevItem = NULL, *item = NULL;

itemHead =(itemsList*) malloc (sizeof (itemsList));
itemHead -> next = NULL;

while(fgets(row,sizeof(row),list) != NULL){

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
free(itemHead);
fclose(list);

    return 0;
}

void createList(FILE *createdlist){

    itemsList * headList = NULL, *prevList = NULL, *itemList;
    char nameItem[20];
    char exit[] = "sair";
    int sair = 2;

    createdlist = fopen("Shopping_List.txt","w");
    headList = (itemsList*) malloc (sizeof(itemsList));
    headList -> next = NULL;

    system("clear");
    printf("Para cancelar a criação da lista, digite 'sair'\n\n");

    while(1){

        printf("Digite o item da lista\n");
        scanf("%s",nameItem);
        fflush(stdin);

        if(strcmp(nameItem, exit) == 0)
        break;

        fputs(nameItem,createdlist);
        fputs("\n",createdlist);

        itemList = (itemsList*) malloc (sizeof(itemsList));

        strcpy(itemList -> item, nameItem);
        itemList -> next = NULL;

        if(headList -> next == NULL){
            headList -> next = itemList;
        }else{
            prevList -> next = itemList;
        }

        prevList = itemList;

    }

    system("clear");
    printf("Itens colocados na lista\n");

    itemList = headList -> next;
    
        while(itemList -> item != NULL)
        {
            printf("%s\n", itemList -> item);
            itemList = itemList -> next;
        }
    
    system("clear");

}

void editList(FILE* createList)
{

int edit_option;

    printf("Escolha uma opção\n");
    printf("1- Inserir item na lista\n");
    printf("2- Remover item da lista\n");

    switch (edit_option)
    {
    case 1:
        editList(createList);
        break;

    case 2:
        removeList(createList);
        break;
    
    default:
        return;
        break;
    }


}

void insertList(FILE * createList)
{

    char rows[20], newItem[20];
    itemsList * headcreatedList = NULL, * prevcreatedListItem = NULL, *createListItem = NULL;

    createList = fopen("ShoppingList.txt", "a+");

    printf("Digite um item para ser inserido na lista\n");
    scanf("%s",newItem);
    fflush(stdin);
    fputs(newItem, createList);



    headcreatedList = (itemsList*) malloc (sizeof (itemsList));
    headcreatedList -> next = NULL;

    while(fgets(rows,sizeof(rows),createList) != NULL)
    {

    createListItem = (itemsList*) malloc (sizeof (itemsList));
    createListItem -> next = NULL;
    strcpy(createListItem -> item, rows);

        if(headcreatedList -> next == NULL)
        {
            headcreatedList -> next = newItem;
        }
        else
        {
            prevcreatedListItem -> next = newItem;
        }
        prevcreatedListItem = newItem;
    }

createListItem = headcreatedList -> next;


while(createListItem -> item != NULL)
{
    printf("%s\n", createListItem -> item);
    createListItem = createListItem -> next;
}

free(createListItem);
free(prevcreatedListItem);
free(headcreatedList);

fclose(createList);

    return 0;
}


void removeList(FILE * createList){

    return;
}