#include <stdio.h>

void main() {
    printf("Izvēlne");
    
   int a,b,c;
   printf( "\nIevadi skaitli 1 : ");

    a = scanf("%d", &a);
   
   if (a == 1) {

       int upe;
       printf("\nAtbilde ir 1.");
       system("clear"); //*nix
       
       printf("Kāda ir garākā upe Latvijā?");
        upe = scanf("%d", &upe);
            if (upe == "Gauja") {
                printf("Pareizi.");
                return 0;

            } else {
                printf("Nepareizi!");
            }

   }

    if (a > 1) {

        printf("\nAtbilde ir lielāka par 1. %d", a);

        return 0;
    }
}