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
int laika_apst;
unsigned int punkti = 0;

int atlikus_bt_km; 

int uzvara();
int izvele;
int stasts();
int atved();

int pareizi_kp = 0, pp_pareizu_kp = 1; 
int p_par_pareizu = 5;
int nobrauktie_km;
int km;
char ievadne[20];
int saulains;
char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E', k1 = '1', k2 = '2', k3 = '3', k4 = '4', k5 = '5', k6 = '6', k7 = '7', k8 = '8', k9 = '9';


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
       
       
       // lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
       // printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
     //   printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }
    printf("%d km", atlikus_bt_km);

    int izv;  
  
    printf("\nSpied: \n 1, lai sāktu spēli\n 2, lai redzētu spēles pamācību\n 0, lai izietu \n : ");  
    scanf("%d",&izv);  
  
    switch(izv)  {  
        case 1:  
        stasts();  
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
    if (sakums == bijis && k1 == bijis && k2 == bijis && k3 == bijis && k4 == bijis && k5 == bijis && k6 == bijis && k7 == bijis && k8 == bijis && k9 == bijis && a == bijis && b == bijis && c == bijis && d == bijis && e == bijis) {
        uzvara();
    }
    if (atlikus_bt_km == 0) {
        atved();
    }
        for (int i = 0; i < 15; i++) {

        printf("\n ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬   ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ");
        printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");  
        printf("\n┃********************************** Karte ***********************************┃ ┃   Pilsēta    ┃      Apskates objekts      ┃   EU Stacija  ┃");  
        printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");   
        printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃              ┃                            ┃               ┃");
        printf("\n┃           *  /             _/     ^___/   /                          `^    ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
        printf("\n┃             |           __/              |                             |   ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃              ^___  ____/          .*    |                              |   ┃ ┃   Sigulda    ┃    %c         ┃  %c (25)     ┃    %c (30)     ┃", sakums, k1, a);  
        printf("\n┃                _||                      /     ___________            _/    ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃               / /                       |___/             ^        /       ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃              /_/                       /                  ^   ___/         ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
        printf("\n┃                                       |                    ^_/   |         ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃                    .        *          |                          |_       ┃ ┃    Tukums    ┃    %c (30)    ┃  %c (45)     ┃    %c (40)     ┃", k2, k3, b);  
        printf("\n┃                __/  |                  |                            `      ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃             __/      `_                 |                           |      ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃ Ventspils /X            `               |                            |     ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
        printf("\n┃          /  |` _   Talsi `_             |                             |    ┃ ┃              ┃              ┃             ┃               ┃");                                                            
        printf("\n┃         |    |  ` X__       `          /                               `_  ┃ ┃    Talsi     ┃    %c (35)    ┃  %c (15)     ┃    %c (15)     ┃", k4, k5, c);  
        printf("\n┃         |     |      `       `        /   __X Sigulda                    | ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃       /Kuldīga X      X Tukums` _____/  _/                               | ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃     /           |     `_       _X______/                                  |┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
        printf("\n┃    |             `     `_     /  Rīga                                    | ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃   | Liepāja   ____`X______`X_/                                           | ┃ ┃   Ventspils  ┃    %c (45)    ┃  %c (15)     ┃    %c (25)     ┃", k6, k7, d);
        printf("\n┃   |X_________/  Saldus       Jelgava       ^                              |┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃   |                                      /  ^                            | ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃   |          _________ ___________  ____/     ^___                      |__┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
        printf("\n┃   |      _/ `         `           ``              `__                 _/  ^┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃    |  __/                                            `__             /     ┃ ┃   Liepāja    ┃    %c (20)    ┃  %c (10)     ┃    %c (55)     ┃", k8, k9, e);  
        printf("\n┃    | /                                                   `___   ___/       ┃ ┃              ┃              ┃             ┃               ┃");  
        printf("\n┃    |'                                                        `|`           ┃ ┃              ┃              ┃             ┃               ┃");
        printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
        
        
        if (saulains = 0) {
        printf("                      Laikapstākļi ir lietaini un tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        } else {
        printf("                      Laikapstākļi ir saulaini un tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        }
        
        
        char izv[1];

    
        printf("\nIzvēlies nākamo staciju: ");  
        scanf("%s",izv);  
  
    switchs(izv)  {  
        icases("A")  
        if (a != bijis) {
        a = bijis;
        atlikus_bt_km = atlikus_bt_km - 30;
        jaut_a();
        break; 
} 
        icases("B")
        if (b != bijis) {
        b = bijis; 
        atlikus_bt_km = atlikus_bt_km - 40;     
        jaut_b(); 
        break;  
}
     
        icases("C")
        if (c != bijis) {
        c = bijis; 
        atlikus_bt_km = atlikus_bt_km - 15;      
        jaut_c();  
        break;  
}
    
        icases("D")
        if (d != bijis) {
        d = bijis; 
        atlikus_bt_km = atlikus_bt_km - 25;     
        jaut_d();  
        break;  
}
     
        icases("E")
        if (e != bijis) {
        e = bijis; 
        atlikus_bt_km = atlikus_bt_km - 55;       
        jaut_e();  
        break;  
}
     
        icases("1")
        if (k1 != bijis) {
        k1 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 25;       
        jaut_k1();  
        break;  
}    
     
        icases("2")
        if (k2 != bijis) {
        k2 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 30;     
        jaut_k2();  
        break;  
}
     
        icases("3")
        if (k3 != bijis) {
        k3 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 45;      
        jaut_k3();  
        break;  
}
     
        icases("4")
        if (k4 != bijis) {
        k4 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 35;      
        jaut_k4();  
        break;  
}
     
        icases("5")
        if (k5 != bijis) {
        k5 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 15;      
        jaut_k5();  
        break;  
}
     
        icases("6")
        if (k6 != bijis) {
        k6 = bijis;       
        jaut_k6();
        atlikus_bt_km = atlikus_bt_km -45;  
        break;  
} 
     
        icases("7")
        if (k7 != bijis) {
        k7 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 15;     
        jaut_k7();  
        break;  
}
    
        icases("8")
        if (k8 != bijis) {
        k8 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 20;    
        jaut_k8();  
        break;  
}
     
        icases("9")
        if (k9 != bijis) {
        k9 = bijis; 
        atlikus_bt_km = atlikus_bt_km - 10;     
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
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_liepaja[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_liepaja[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Kebabs saņemts! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_k2 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_kultura2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();
        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
        
    }
}

printf("** Pica saņemta! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);


sleep(5);
karte_plans();
}

int jaut_a () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_sports1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_sports1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tava baterija tika uzpildīta!\n");
// lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
        printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
        printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }

sleep(5);
karte_plans();
}

int jaut_k3 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_muzika1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_muzika1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Karstais suns saņemts! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_k4 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_muzika2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_muzika2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;

        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Sklandrauši saņemti! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_b () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_kultura3[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura3[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tava baterija tika uzpildīta!\n");
// lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
        printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
        printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }

sleep(5);
karte_plans();
}

int jaut_k5 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_daba[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_daba[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Kartupeļu salāti saņemti!  ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_k6 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_politika[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_politika[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Rosols saņemts! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_c () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_arhitektura[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_arhitektura[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tava baterija tika uzpildīta!\n");
// lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
        printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
        printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }

sleep(5);
karte_plans();
}

int jaut_k7 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_sports2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_sports2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Lasis saņemts! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_k8 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_karosta1[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_karosta1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Menca saņemta! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_d () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_karosta2[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_karosta2[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);

        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tava baterija tika uzpildīta!\n");
// lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
        printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
        printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}

int jaut_k9 () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_kaapas[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kultura1[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** Zelta zivtiņa saņemta! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
sleep(5);
karte_plans();
}


int jaut_e () {
    clearscr();
    for (int i = 0; i < 2; i++) {
    printf("                                                            %d punkti \n", punkti);
    printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
    printf("%s ", jautajumi_kaapas[i]);
    scanf("%s", ievadne);

    if ( strcasecmp( ievadne, atbildes_kaapas[i] ) == 0) {
                clearscr();
                punkti = punkti + p_par_pareizu;
                pareizi_kp = pareizi_kp + pp_pareizu_kp;
            ;
        
                printf("                                                            %d punkti \n", punkti);
                printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
                printf("Pareizi! \n");
                sleep(1.5);
                clearscr();
    } else {
        clearscr();

        printf("                                                            %d punkti \n", punkti);
        printf("                                           Tev ir atlikusi baterija %d kilometriem! \n", atlikus_bt_km);
        printf("Nepareizi!\n");
        clearscr();
        sleep(1.5);
    }
}

printf("** kontrolpunkta beigas! ** \n\n");
printf("Tavs punktu skaits ir %d \n", punkti);
printf("Tava baterija tika uzpildīta!\n");
// lietus laikā 70 km, sauulainā 140 km
        int lower = 0, upper = 1;
    srand(time(0));
    int saulains = (rand() % (upper - lower + 1)) + lower;
    if (saulains = 0) {
        atlikus_bt_km = 70;
        printf("Laikapstākļi ir lietaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);

    } else {
        atlikus_bt_km = 140;
        printf("Laikapstākļi ir saulaini vai mākoņaini, tava atlikusī baterija ir %d km!", atlikus_bt_km);
    }

sleep(5);
karte_plans();
}
















// Spēles pamācība, šobrīd peieejama tikai no galvenā ekrāna, bet vajadzētu implementēt keybindu....
int palidzība () {  
     
     int izvele;  
  
     printf("\n\n ************************* Spēles pamācība *************************");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n .................... Spēle (aizvietot)...........\n");  
     printf("\n >> Spēlē ir tūrisma apskates punkti un uzlādes stacijas, kurās ir jātbild uz jautājumu, lai saņemu punktus un uzlādētu elektroauto un tiktu tālāk. \n");
     printf("\n >> Uz jautajumiem ir jāatbild vai nu apskates objektos vai uzlādes stacijās. Jautājumi var būt gan ar izvēles variantiem, piemēram, A, gan ar rakstisku atbildi. \n");\
     printf("\n >> Ja nepaspēj tikt līdz EU (Elektro uzlādes) stacijas un tavam auto izbeidzas baterija, tad tev ir jāsauc auto evakuators, par ko zaudēsi punktus.    \n");
     printf("\n >> Uz jautajumiem jāatbild ievadot pareizās atbildes burtu. Atbildes ir kapitalizācijas(a un A) nejutīgas. \n"); 
     printf("\n >> Spēles sākumā bus nejauši laikapstākļi un pēc katras uzlādes stacijas ir iespējama laikapstākļu maiņa. \n");  
     printf("\n >> Elektroauto bez uzlādes saulainos vai mākoņainos laikapstākļos spēj nobraukt 140 km un lietainos vai vētrainos spēj nobraukt 70 km.");
     printf("\n >> Kontrolpunktu izvēles sadaļā tu vari izvēlēties tikai redzamos kontrolpunktus. Tu vari izvēlēties jebkādu kontrolpunktu, ko redzi."); 
     printf("\n >> Tabulā iekavās blakus kontrolpunkta id ir norādīts attālums km, līdz šim kontrolpunktam.");
     printf("\n >> Spēle beidzas, kad spēlētājs ir izgājis visus kontrolpunktus."); 
  
    printf("\n\n ************************* Veiksmi! *************************\n\n");  
  
  
    printf("\n Turpināt vai iziet? 1, lai turpinātu, 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
    if(izvele==1) {  
        stasts();  
    }  
    else  {  
        exit(1);  
    }
  
}  


int uzvara () {
    clearscr();
     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n ************************ Tu es pieveicis izaicinājumus! ************************ \n  ");  
     printf("\n -------------------------------------------------------------------------       ");  
     printf("\n\n Tu ieguvi %u punktus un tev atlika baterija %u kilometriem!                   ", punkti, atlikus_bt_km);  
     printf("\n        _    ___  ________                                                       ");
     printf("\n         _-_- |_/|___|___`._                                                     ");
     printf("\n       _-_-__  / ,-. -|-  ,-.`-.         - _  -  - _<_                           ");  
     printf("\n          _-_- `( o )----( o )-'        _-_-  _____|___`._                       ");  
     printf("\n- - - - - - - - - - - - - - - - - - -_-____ / ,-. -|-  ,-.`-. - - - - - - - -   Veidoja: Atis Dubrovskis un Kārlis Ulmis");
     printf("\n                                       _-_- `( o )----( o )-'                     ");
     printf("\n                              Paldies par spēlēšanu!                              ");
     printf("\n Spied 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
    if(izvele==1) {  
        karte_plans();  
    }  
    else  {  
        exit(1);  
    }

}
int atved () {
    clearscr();
     punkti - 15;
     printf("\n  Tev beidzās baterija, tapēc tav evakuators ielēja baterija");
     printf("\n\n  Mīnus 15 punkti, tagad ir %u punkti", punkti);  
     if(saulains == 1){
         atlikus_bt_km = 140;
     }
    if(saulains == 0){
         atlikus_bt_km = 70;
     }
     
     sleep(3);
     karte_plans(); 


}

int stasts () {
        clearscr();
    printf("Porziņgis ir atbraucis atpakaļ uz Liepāju, bet viņam gribas ēst.\n");
    printf("Tavs uzdevums ir sāgādāt Porziņģim vairumu ēdienu no restorāniem, kas atrodas viskautkur apkārt Kurzemei un viens Siguldā - slavenais Siguldas kebabs.\n");
    printf("Bet restorāni netic, ka tu gādā ēdienu Porziņģim un nevēlas dod tev viņa pasūtijumus,\n tāpēc viņi tev jautā viskautkādus jautājumus par Liepāju, lai tu pierādītu, ka tu tiešām esi viņa kurjers.\n");
    printf("ja uz jautājuma neatbildi pareizi, tad tev būs pašam jāmaksā par ēdienu ar saviem punktiem, ja tev punktu nav, tad tev tos neatņems, bet tu par piegādi nenopelnīsi punktus.\n");
    printf("Šis ir rallijs, jo daudzi citi cilvēki dara to pašu ko tu - mēģina Porziņģim piegādāt ēdienu, tāpēc esi atjautīgs un atceries, ka galvenais nav ne tikai ātrums,\n bet precizitāte un pareizi atbildēto kontrolpunktu skaits.\n");   
    printf("\n                                      Veiksmi un atjautību!\n");
     printf("\n Turpināt vai iziet? 1, lai turpinātu, 0, lai izietu \n: ");  
    scanf("%d",&izvele);  
    if(izvele==1) {  
        karte_plans();  
    }  
    else  {  
        exit(1);  
    }
    karte_plans();
    
}
