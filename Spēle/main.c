#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h> 



int sakt();  
void palidziba();  
int punkti = 0;
int pareizikontrolpunkti = 0, punktiparpareizikontrolpunktu = 1; 
int punktiparpareizu = 5;

/*
int jautajumufails() {
      FILE *fp;
  char chunk[400];

  
   fp = fopen("jautajumi.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   
   while(fgets(chunk, sizeof(chunk), fp) != NULL) {
        fputs(chunk, stdout);
         fputs("\n", stdout);  // marker string used to show where the content of the chunk array has ended
     }
   
   fclose(fp);
   }

char jautajumi[10][40] = jautajumufails();
*/

// bi - bez izvēles variantiem ai - ar izvēles variantiem
 char jautajumibi[10][40] = {
    "Kur gauja?",
     "Kur liepāja?",
      "Kur porziņģis",
       "Kur Ventspils"
};



char atbildesbi[10][40] = {
    "Sigulda",
     "Liepājā",
      "ASV",
       "Ventspilī"
};

char jautajumiai[10][100] = {
    "Kurā gadā tika dibināta liepāja?\n A - 1625, B - 394, C - 1624, D - 1854",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4"
};

char atbildesai[10][100] = {
    "A",
    "B",
    "C"
};

char ievadne[20];

int main() {

    // Sāk laika uzskaiti
    time_t start_t, end_t;
   int diff_t;
   time(&start_t);

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

    //beidz laika uzskaiti
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    if (diff_t >= 60) {
    printf("Tu spēlē pavadīji %d sekundes  \n", diff_t);
    } 
    
    return 0;
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
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    //int rando = rand() % 3 + 0;
    printf("%s ", jautajumibi[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesbi[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizikontrolpunkti = pareizikontrolpunkti + punktiparpareizikontrolpunktu;
                printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();
        printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        clearscr();
    }
}

printf("** Pirmās daļas beigas! ** \n\n");
printf("Tavs punktu skaits ir %d no 20 punktiem\n", punkti);
printf("Tu šobrīd pareizi esi atbildējis uz %d no 4 jautājumiem,\n\n", pareizikontrolpunkti);
sleep(7);

// Sākas otrā daļa ar variantiem.
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    //int rando = rand() % 3 + 0;
    printf("%s ", jautajumiai[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizikontrolpunkti = pareizikontrolpunkti + punktiparpareizikontrolpunktu;
                printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();
        printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        clearscr();
    }
}

printf("** Otrās daļas beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizikontrolpunkti);
sleep(7);

}





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


