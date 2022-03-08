#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
        
        //
        // funkcijas
        //
        
        //Lai dzēstu ekrānu pēc izvades
        void clearscr(void) {
// ja windows
#ifdef _WIN32
    system("cls");
//ja unix, linux vai mac os
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
// ja nav atbalstīts - vai nu nav definēta vai nav atbalstīta
#else
    #error "OS nav atbalstīta"
#endif
}






        void sakt();   

       void palidziba() {  
     
     int izvele;  
  
     printf("\n\n ************************* Spēles pamācība *************************");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n .................... Spēle (aizvietot)...........\n");  
     printf("\n >> Spēlē ir tūrisma apskates punkti un uzlādes stacijas, kurās ir jātbild uz jautājumu, lai uzlādētu elektroauto un tiktu tālāk. \n");
     printf("\n >> Uz jautājumiem ir jāatbild vai nu apskates objektos vai uzlādes stacijās. \n");
     printf("\n >> Uz jautājumiem jāatbild ievadot atbildi vai atbildes ciparu, ja dotas. \n"); 
     printf("\n >> Pēc katras otrās uzlādes stacijas ir iespējama laikapstākļu maiņa.  ");  
     printf("\n >> Elektroauto bez uzlādes saulainos vai mākoņainos laikapstākļos spēj nobraukt 140 km un lietainā vai vētrā spēj nobraukt 80 km");  
  
    printf("\n\n ************************* Veiksmi! *************************\n\n");  
  
  
    printf("\n Turpināt vai iziet? 1, lai turpinātu, 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
  
    if(izvele==1)  
    {  
        start();  
    }  
    else  
    {  
        exit(1);  
    }  
  
}  
       
       
    palidziba();   
       
       
       
       
       
       
       
       char upe[10];
       
       printf("Kāda ir garākā upe Latvijā?  \n:");
       scanf("%s",upe);
            if ( strcasecmp( upe, "gauja" ) == 0) {
                printf("Pareizi.");
                    
         //char upe[10];
       
       printf("Kāda ir garākā upe Latvijā?  \n:");
       scanf("%s",upe);
            if ( strcasecmp( upe, "gauja" ) == 0) {
                printf("Pareizi.");
                clearscr();

            } else {
                printf("Nepareizi! Atbilde - gauja, Upe - %s", upe);
                return 0;
            };


