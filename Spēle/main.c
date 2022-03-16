#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h> 


int karte_plān;

int kontrolpunkts1(), kontrolpunkts2(), kontrolpunkts3(), kontrolpunkts4(), kontrolpunkts5(), kontrolpunkts6(), kontrolpunkts7();

int palidzība();

int punkti = 0;
int pareizi_kp = 0, punktiparpareizukontrolpunktu = 1; 
int punktiparpareizu = 5;
int nobrauktie_km;
int km;

// Bez izvēles variantiem
 char jautajumibi1[10][40] = {
    "Kur gauja?",
     "Kur liepāja?",
      "Kur porziņģis",
       "Kur Ventspils"
};



char atbildesbi1[10][40] = {
    "Sigulda",
     "Liepājā",
      "ASV",
       "Ventspilī"
};
//
char jautajumibi2[10][40] = {
    "Kur gaujaaa?",
     "Kur liepājaaa?",
      "Kur porziņģisss",
       "Kur Ventspilsss"
};



char atbildesbi2[10][40] = {
    "Sigulda",
     "Liepājā",
      "ASV",
       "Ventspilī"
};
//
// Beidzas sadaļa
// 


// Ar izvēles variantiem
char jautajumiai1[10][100] = {
    "Kurā gadā tika dibināta liepāja?\n A - 1294, B - 1536, C - 1625, D - 1754",
    "Kāds ir Liepājas himnas nosaukums? Liepāja ir pilsēta kurā __\n A - jūra saplūst ar debesīm, B - piedzimst vējš, C - jūra iekš zemē"
};

char atbildesai1[10][100] = {
    "C",
    "B",
};
//
char jautajumiai2[10][100] = {
    "Kāds ir Liepājas himnas autors?\n A - I. Kalniņš, B - E. Dārziņš, C - R. Pauls, D - A. Ašmanis"
    "Kāds ir Liepājas leilākās koncertzāles nosaukums?\n A - Lielā Skuja, B - Dzintarmols , C - Jūraszāle, D - Lielais Dzintars, E - Lielais Kristaps",
    "Kurā gadā tika uzcelta šī koncertzāle?\n A - 2011, B - 2014, C - 2015, D - 2018",
    "Liepājas Svētās Trīsvienības katedrālē atrodas pasaulē lielākās mehāniskās ērģeles, cik stabuļu ir šīm ērģelēm?\n A - 1, B - 2, C - 3, D - 4"
};

char atbildesai2[10][100] = {
    "A",
    "D",
    "C"
};
//
char jautajumiai3[10][100] = {
    "Kurā gadā tika dibināta liepāja?\n A - 1625, B - 394, C - 1624, D - 1854",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4"
};

char atbildesai3[10][100] = {
    "A",
    "B",
    "C"
};
//
char jautajumiai4[10][100] = {
    "Kurā gadā tika dibināta liepāja?\n A - 1625, B - 394, C - 1624, D - 1854",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4"
};

char atbildesai4[10][100] = {
    "A",
    "B",
    "C"
};
//

char jautajumiai5[10][100] = {
    "Kurā gadā tika dibināta liepāja?\n A - 1625, B - 394, C - 1624, D - 1854",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4",
    "balahaahhahahha?\n A - 1, B - 2, C - 3, D - 4"
};

char atbildesai5[10][100] = {
    "A",
    "B",
    "C"
};
//
//Beidzas sadaļa
// 






char ievadne[20];

int main() {

    // Sāk laika uzskaiti
    time_t start_t, end_t;
   int diff_t;
   time(&start_t);

     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n ************************* Tūrisma rallijs Liepāja 2022 ****************** \n  ");  
     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n");  
     printf("\n                                _.-.____'.                                       ");
     printf("\n                               |  _      _`-.                                    ");
     printf("\n  -  -  -  -  -  -  -  -  -  - '-(_)----(_)--` - - - - - - - - - - - - - - -     ");  
     printf("\n                                                              Veidoja: Atis Dubrovskis un Kārlis Ulmis");  
  

       
       
    int izv;  
  
    printf("\nSpied: \n 1 lai sāktu spēli\n 2 lai redzētu spēles pamācību\n 0 lai izietu \n : ");  
    scanf("%d",&izv);  
  
    switch(izv)  {  
        case 1:  
        kontrolpunkts1();  
        break; 
  
        case 2:         
        palidzība();  
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


int kontrolpunkts1 () {
    clearscr();
    for (int i = 0; i < 4; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumiai1[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai1[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Pirmā kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d no 20 punktiem\n", punkti);
printf("Tu šobrīd pareizi esi atbildējis uz %d no 4 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas otrā daļa ar variantiem.
int kontrolpunkts2 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumibi1[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesbi1[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Otrās kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas trešā daļa ar variantiem.
int kontrolpunkts3 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumiai2[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai2[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** trešā kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas ceturtā daļa ar variantiem.
int kontrolpunkts4 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumiai3[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai3[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Ceturtā kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas piektā daļa ar variantiem.
int kontrolpunkts5 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumibi2[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesbi2[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Piektā kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas sestā daļa ar variantiem.
int kontrolpunkts6 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumiai4[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai4[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Otrās kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}

// Sākas septītā daļa ar variantiem.
int kontrolpunkts7 () {
      clearscr();
    for (int i = 0; i < 3; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumiai5[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildesai5[i] ) == 0) {
                clearscr();
                punkti = punkti + punktiparpareizu;
                pareizi_kp = pareizi_kp + punktiparpareizukontrolpunktu;
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

printf("** Septītā kontrolpunkta beigas! **\n\n");
printf("Tavs punktu skaits ir %d no 35 punktiem\n", punkti);
printf("Tu pareizi esi atbildējis uz %d no 7 jautājumiem,\n\n", pareizi_kp);
sleep(7);

}





// Spēles pamācība, šobrīd peieejama tikai no galvenā ekrāna, bet vajadzētu implementēt keybindu....
int palidzība () {  
     
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
        kontrolpunkts1();  
    }  
    else  {  
        exit(1);  
    }
  
}  


