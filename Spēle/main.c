#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sakt();  
void palidziba();  

int main() {
        
        //
        // funkcijas
        //
        
        //Lai dzēstu ekrānu pēc izvades
        


  
       int chc;  
  
    printf("Press 1 to start the game\n2 to see game help\n0 to exit :   ");  
    scanf("%d",&chc);  
  
    switch(chc)  {  
        case 1:  
        sakt();  
        break; 
  
        case 2:  
        palidziba();  
        break;  
  
          default:  
          exit(1);  
    }  };

       
       



void sakt () {

       char upe[10];
       
       printf("Kāda ir garākā upe Latvijā?  \n:");
       scanf("%s",upe);
            if ( strcasecmp( upe, "gauja" ) == 0) {
                printf("Pareizi.");
                clearscr();

            } else {
                printf("Nepareizi! Atbilde - gauja, Upe - %s", upe);
                return 0;
            }
};





void palidziba() {  
     
     int izvele;  
  
     printf("\n\n ************************* Spēles pamācība *************************");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n .................... Spēle (aizvietot)...........\n");  
     printf("\n >> Spēlē ir tūrisma apskates punkti un uzlādes stacijas, kurās ir jātbild uz jautājumu, lai uzlādētu elektroauto un tiktu tālāk. \n");
     printf("\n >> Uz jautājumiem ir jāatbild vai nu apskates objektos vai uzlādes stacijās. \n");
     printf("\n >> Uz jautājumiem jāatbild ievadot atbildi vai atbildes ciparu, ja dotas. \n"); 
     printf("\n >> Pēc katras otrās uzlādes stacijas ir iespējama laikapstākļu maiņa. \n");  
     printf("\n >> Elektroauto bez uzlādes saulainos vai mākoņainos laikapstākļos spēj nobraukt 140 km un lietainos vai vētrainos spēj nobraukt 80 km");  
  
    printf("\n\n ************************* Veiksmi! *************************\n\n");  
  
  
    printf("\n Turpināt vai iziet? 1, lai turpinātu, 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
  
    if(izvele==1) {  
        sakt();  
    }  
    else  {  
        exit(1);  
    }  
  
}  

