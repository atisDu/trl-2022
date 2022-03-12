#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

int sakt();  
void palidziba();  
int punkti();

char jautajumi[4][20] = {
    "Kur gauja?",
     "Kur liepāja?",
      "Kur porziņģis",
       "Kur Ventspils"
};

char atbildes[4][20] = {
    "Sigulda",
     "Liepājā",
      "ASV",
       "Ventspilī"
};

char ievadne[20];

int main() {
    
     printf("\n -------------------------------------------------------------------------");  
     printf("\n\n ************************* Tūrisma rallijs Liepāja 2022 ****************** \n");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n\n");  
     printf("\n                                _.-.____'.                     ");
     printf("\n                               |  _      _`-.                  ");
     printf("\n  -  -  -  -  -  -  -  -  -  - '-(_)----(_)--` - - - - - - - - - - - - - - -  ");  
     printf("\n                                                              Veidoja: Atis Dubrovskis un Kārlis Ulmis");  
  

       
       
    int izv;  
  
    printf("\nSpied: \n 1 lai sāktu spēli\n 2 lai redzētu spēles pamācību\n 0 lai izietu \n : ");  
    scanf("%d",&izv);  
  
    switch(izv)  {  
        case 1:  
        sakt();  
        break; 
  
        case 2:  
        palidziba();  
        break;  
  
          default:  
          exit(1);  
    }
      }


// funkcija lai notīrītu ekrānu ( katrai operētājsistēmai ir mazliet savādāka metode)
void clearscr() {
// ja windows
#ifdef _WIN32
    system("cls");
//ja unix - linux, mac os vai citi.
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
// ja nav atbalstīts - vai nu nav definēta vai nav atbalstīta
#else
    #error "OS nav atbalstīta"
#endif
}   


int sakt () {
    clearscr();
    for (int i = 0; i < 4; i++) {
    printf("                                                    Kontrolpunkti:%d/10\n", i + 1);
    //int rando = rand() % 3 + 0;
    printf("%s ", jautajumi[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildes[i] ) == 0) {
                clearscr();
                printf("                                                    Kontrolpunkti:%d/10\n", i + 1);
                printf("Pareizi. + punkti \n");
                sleep(1.5);
                clearscr();
                int punkti = punkti + 1;
    } else {
        clearscr();
        printf("Nepareizi!\n"); // \nAtbilde - %s, Ievadne - %s", jautajumi[1], ievadne);
        sleep(1.5);
        clearscr();
    }
    }
}


//Sāk spēli
/*int sakt () {
     clearscr();
       char upe[10];
       
       printf("Kāda ir garākā upe Latvijā?  \n:");
       scanf("%s",upe);
            if ( strcasecmp( upe, "gauja" ) == 0) {
                printf("Pareizi.");
                clearscr();

                printf("\nNākamais jautājums:");
                    
            } else {
                printf("Nepareizi! Atbilde - gauja, Upe - %s", upe);
            }
    return 0;
} */






// Spēles pamācība, šobrīd peieejama tikai no galvenā ekrāna, bet vajadzētu implementēt keybindu....
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


