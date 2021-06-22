#include <stdlib.h>
#include <stdio.h>

int main(){

FILE *fp;
char c[200];
char s[30];
int i=0;

while(1){
   fscanf(fp,"%[^\n]",c);
    if(feof(fp)){
    break;
    }
    i++;
}
printf("%d",i);
/*fp = fopen("List.txt","r");
fscanf(fp,"%[^\n]",c);
printf("%s",c);
fclose(fp);*/

return 0;

}