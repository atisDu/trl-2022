#include <stdio.h>

int main() {
    printf("Izvēlne");
    
   int a;
   printf( "\nIevadi skaitli 1 : ");

    a = scanf("%d", &a);
   
   if (a == 1) {

       char gauja =  (int) "gauja";
       char upe[50];
       int result;
       printf("\nAtbilde ir 1.");
       system("clear"); //*nix
       
       printf("Kāda ir garākā upe Latvijā?");
       result = scanf("%s",upe);
            if (result == gauja) {
                printf("Pareizi.");
                return 0;

            } else {
                printf("Nepareizi! Atbilde - %s, Upe - %s", gauja, upe);
            }

   }

    if (a > 1) {

        printf("\nAtbilde ir lielāka par 1. %d", a);

        return 0;
    }
}