/*                            ___  
 _      _____  _____ ______   ___     ___   ___   _____                          
| |    |_   _||  ___|| ___ \ / _ \   |_  | / _ \ /  ___|                         
| |      | |  | |__  | |_/ // /_\ \    | |/ /_\ \\ `--.                          
| |      | |  |  __| |  __/ |  _  |    | ||  _  | `--. \                         
| |____ _| |_ | |___ | |    | | | |/\__/ /| | | |/\__/ /                         
\_____/ \___/ \____/ \_|    \_| |_/\____/ \_| |_/\____/                          
                                                                                 
        _____                                                                         
 _____  _   _ ______  _____  _____ ___  ___  ___                                 
|_   _|| | | || ___ \|_   _|/  ___||  \/  | / _ \                                
  | |  | | | || |_/ /  | |  \ `--. | .  . |/ /_\ \                               
  | |  | | | ||    /   | |   `--. \| |\/| ||  _  |                               
  | |  | |_| || |\ \  _| |_ /\__/ /| |  | || | | |                               
  \_/   \___/ \_| \_| \___/ \____/ \_|  |_/\_| |_/                               
                                                                                 
                                                                                 
______   ___   _      _      _____    ___  _____      _____  _____  _____  _____ 
| ___ \ / _ \ | |    | |    |_   _|  |_  |/  ___|    / __  \|  _  |/ __  \/ __  \
| |_/ // /_\ \| |    | |      | |      | |\ `--.     `' / /'| |/' |`' / /'`' / /'
|    / |  _  || |    | |      | |      | | `--. \      / /  |  /| |  / /    / /  
| |\ \ | | | || |____| |____ _| |_ /\__/ //\__/ /    ./ /___\ |_/ /./ /___./ /___
\_| \_|\_| |_/\_____/\_____/ \___/ \____/ \____/     \_____/ \___/ \_____/\_____/

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h> 
#include "jautajumi_un_atbildes.h" 
#include "switcheroo.h"             // Slēdža funkcija stringiem gan jau overkill bet nav nemaz tik traki

//

int karte_plans(), edit();
int palidzība();
int jaut_a(), jaut_b(), jaut_c();
int jaut_d();
int jaut_e(), jaut_k1();
int jaut_k2(), jaut_k3(), jaut_k4();
int jaut_k5(), jaut_k6(), jaut_k7();
int jaut_k8(), jaut_k9(), jaut_k10();
int lietus = 1;
int punkti = 0;
int pareizi_kp = 0, pp_pareizu_kp = 1; 
int p_par_pareizu = 5;
int nobrauktie_km;
int km;
char ievadne[20];
int num;
char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E', k1 = '1', k2 = '2', k3 = '3', k4 = '4', k5 = '5', k6 = '6', k7 = '7', k8 = '8', k9 = '9';

char* k10 = {
    "10"
};

char* bijiss = {
    "*"
};

char bijis = '*';

char sakums = '#';

int main() {

    // Sāk laika uzskaiti
    time_t start_t, end_t;
   int diff_t;
   time(&start_t);

     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n ************************* Tūrisma rallijs Liepāja 2022 ****************** \n  ");  
     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n                                                                               ");  
     printf("\n        _    ___  ________                                                       ");
     printf("\n         _-_- |_/|___|___`._                                                     ");
     printf("\n       _-_-__  / ,-. -|-  ,-.`-.         - _  -  - _<_                           ");  
     printf("\n          _-_- `( o )----( o )-'        _-_-  _____|___`._                       ");  
     printf("\n- - - - - - - - - - - - - - - - - - -_-____ / ,-. -|-  ,-.`-. - - - - - - - -   Veidoja: Atis Dubrovskis un Kārlis Ulmis");
     printf("\n                                       _-_- `( o )----( o )-'                     ");
       
       
    int izv;  
  
    printf("\nSpied: \n 1, lai sāktu spēli\n 2, lai redzētu spēles pamācību, 3, lai izveidotu savus jautājumus un atbildes\n 0 lai izietu \n : ");  
    scanf("%d",&izv);  
  
    switch(izv)  {  
        case 1:  
        karte_plans();  
        break; 
  
        case 2:         
        palidzība();  
        break;  

        case 3:
        edit();
        break;

          default:  
          exit(1);  
    }

    //beidz laika uzskaiti
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    int stundas = diff_t / 3600;
    int minutes = ( diff_t % 3600) / 60;
            printf("Tu spēlē pavadīji %d minūtes un %d sekundes\n", minutes, diff_t); 

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

int karte_plans() {

    for (int i = 0; i < 15; i++) {

     printf("\n ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬   ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ");
     printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");  
     printf("\n┃********************************** Karte ***********************************┃ ┃   Pilsēta    ┃      Apskates objekts      ┃   EU Stacija  ┃");  
     printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");   
     printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃              ┃                            ┃               ┃");
     printf("\n┃           *  /             _/     ^___/   /                          `^    ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
     printf("\n┃             |           __/              |                             |   ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃              ^___  ____/          .*    |                              |   ┃ ┃   Sigulda    ┃       %c      ┃      %c      ┃       %c       ┃", sakums, k1, a);  
     printf("\n┃                _||                      /     ___________            _/    ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃               / /                       |___/             ^        /       ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃              /_/                       /                  ^   ___/         ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃                                       |                    ^_/   |         ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃                    .        *          |                          |_       ┃ ┃    Tukums    ┃       %c     ┃       %c      ┃       %c       ┃", k2, k3, b);  
     printf("\n┃                __/  |                  |                            `      ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃             __/      `_                 |                           |      ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃ Ventspils /X            `               |                            |     ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃          /  |` _   Talsi `_             |                             |    ┃ ┃              ┃              ┃             ┃               ┃");                                                            
     printf("\n┃         |    |  ` X__       `          /                               `_  ┃ ┃    Talsi     ┃       %c      ┃      %c      ┃       %c       ┃", k4, k5, c);  
     printf("\n┃         |     |      `       `        /   __X Sigulda                    | ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃       /Kuldīga X      X Tukums` _____/  _/                               | ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃     /           |     `_       _X______/                                  |┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃    |             `     `_     /  Rīga                                    | ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃   | Liepāja   ____`X______`X_/                                           | ┃ ┃   Ventspils  ┃       %c      ┃      %c      ┃       %c       ┃", k6, k7, d);
     printf("\n┃   |X_________/  Saldus       Jelgava       ^                              |┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃   |                                      /  ^                            | ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃   |          _________ ___________  ____/     ^___                      |__┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃   |      _/ `         `           ``              `__                 _/  ^┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃    |  __/                                            `__             /     ┃ ┃   Liepāja    ┃       %c      ┃      %c      ┃       %c       ┃", k8, k9, e);  
     printf("\n┃    | /                                                   `___   ___/       ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃    |'                                                        `|`           ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
     char izv[1];
     if (a != bijis) {
         printf("\n Nav vienādi!\n");
         printf("\nA = %c", a);
         a = bijis;
     printf("\nbijis = %c\n", bijis );
     }else {
     printf("\nA = %c", a);
     printf("\nbijis = %c\n", bijis );
     }



    printf("\nIzvēlies nākamo staciju: ");  
    scanf("%s",izv);  
  
    switchs(izv)  {  
    if (a != bijis) {
        icases("A")  
        a = bijis;
        num = 1;
        jaut_a();
        break; 
} 
    if (b != bijis) {
        icases("B")
        b = bijis;       
        jaut_b();  
        break;  
}
     if (c != bijis) {
        icases("C")
        c = bijis;       
        jaut_c();  
        break;  
}
     if (d != bijis) {
        icases("D")
        d = bijis;       
        jaut_d();  
        break;  
}
     if (e != bijis) {
        icases("E")
        e = bijis;       
        jaut_e();  
        break;  
}
     if (k1 != bijis) {
        icases("1")
        k1 = bijis;       
        jaut_k1();  
        break;  
}
     if (k2 != bijis) {
        icases("2")
        k2 = bijis;       
        jaut_k2();  
        break;  
}
     if (k3 != bijis) {
        icases("3")
        k3 = bijis;       
        jaut_k3();  
        break;  
}
     if (k4 != bijis) {
        icases("4")
        k4 = bijis;       
        jaut_k4();  
        break;  
}
     if (k5 != bijis) {
        icases("5")
        k5 = bijis;       
        jaut_k5();  
        break;  
}
     if (k6 != bijis) {
        icases("6")
        k6 = bijis;       
        jaut_k6();  
        break;  
}
     if (k7 != bijis) {
        icases("7")
        k7 = bijis;       
        jaut_k7();  
        break;  
}
     if (k8 != bijis) {
        icases("8")
        k8 = bijis;       
        jaut_k8();  
        break;  
}
     if (k9 != bijis) {
        icases("9")
        k9 = bijis;       
        jaut_k9();  
        break;  
}
          defaults  
          clearscr();
          printf("Kļūdaina ievade, šajā lauciņā jau esi bijis! Ieraksti jebkuru burtu vai skaitli,kas rādīts tabulā.\n (Zvaigznītes parāda vietas kur jau esi bijis.");
          sleep(3.5);
          karte_plans();
          break;  
    } switchs_end;
    }
}





int jaut_k1 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_liepaja[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_liepaja[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k2 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_kultura2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();
        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_a () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_sports1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_sports1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k3 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_muzika1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_muzika1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k4 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_muzika2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_muzika2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_b () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_kultura3[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura3[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k5 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_daba[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_daba[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k6 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_politika[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_politika[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_c () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_arhitektura[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_arhitektura[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k7 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_sports2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_sports2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k8 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_karosta1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_karosta1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_d () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_karosta2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_karosta2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}

int jaut_k9 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_kaapas[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}


int jaut_e () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_kaapas[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kaapas[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("Nepareizi!\n");
        sleep(1.5);
        clearscr();
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
karte_plans();
}
















// Spēles pamācība, šobrīd peieejama tikai no galvenā ekrāna, bet vajadzētu implementēt keybindu....
int palidzība () {  
     
     int izvele;  
  
     printf("\n\n ************************* Spēles pamācība *************************");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n .................... Spēle (aizvietot)...........\n");  
     printf("\n >> Spēlē ir tūrisma apskates punkti un uzlādes stacijas, kurās ir jātbild uz jautājumu, lai uzlādētu elektroauto un tiktu tālāk. \n");
     printf("\n >> Uz jautajumiem ir jāatbild vai nu apskates objektos vai uzlādes stacijās. A \n");\
     printf("\n >> ja nepaspēj tikt līdz EU (Elektro uzlādes) stacijas un tavam auto izbeidzas baterija, tad tev ir jāsauc auto evakuators, par ko zaudēsi punktus.    \n");
     printf("\n >> Uz jautajumiem jāatbild ievadot atbildes burtu. Atbildes ir kapitalizācijas nejutīgas. \n"); 
     printf("\n >> Pēc katras uzlādes stacijas ir iespējama laikapstākļu maiņa. \n");  
     printf("\n >> Elektroauto bez uzlādes saulainos vai mākoņainos laikapstākļos spēj nobraukt 140 km un lietainos vai vētrainos spēj nobraukt 80 km.");
     printf("\n >> Kontrolpunktu izvēles sadaļā tu vari izvēlēties tikai redzamos kontrolpunktus. Tu vari izvēlēties kontrolpunktus 1 rūts rādiusā apkārt šobrīdējajai atrašanās vietai, jeb kontrolpunktam. "); 
     printf("\n >> Ir iespējams atgriezties iepriekš bijušā kontrolpunktā, uz jautājumiem būs jāatbild "); 
  
    printf("\n\n ************************* Veiksmi! *************************\n\n");  
  
  
    printf("\n Turpināt vai iziet? 1, lai turpinātu, 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
    if(izvele==1) {  
        karte_plans();  
    }  
    else  {  
        exit(1);  
    }
  
}  

int edit() {
    clearscr();
    printf("\n                            Jautājumu rediģētājs                \n");
    printf("Ievadi jautājumu:");




}
