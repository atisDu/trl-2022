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

int kontrolpunkts1(), kontrolpunkts2(), kontrolpunkts3(), kontrolpunkts4(), kontrolpunkts5(), kontrolpunkts6(), kontrolpunkts7(), kontrolpunkts8(), kontrolpunkts9(), kontrol;

int palidzība();

int punkti = 0;
int pareizi_kp = 0, punktiparpareizukontrolpunktu = 1; 
int punktiparpareizu = 5;
int nobrauktie_km;
int km;


char ievadne[20];

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
     printf("\n ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬   ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ ");
     printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");  
     printf("\n┃********************************** Karte ***********************************┃ ┃   Pilsēta    ┃      Apskates objekti      ┃   EU Stacija  ┃");  
     printf("\n┃----------------------------------------------------------------------------┃ ┃              ┃                            ┃               ┃");   
     printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃              ┃                            ┃               ┃");
     printf("\n┃           *  /             _/     ^___/   /                          `^    ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
     printf("\n┃             |           __/              |                             |   ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃              ^___  ____/          .*    |                              |   ┃ ┃     Rīga     ┃       1      ┃      2      ┃       A       ┃");  
     printf("\n┃                _||                      /     ___________            _/    ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃               / /                       |___/             ^        /       ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃              /_/                       /                  ^   ___/         ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃                                       |                    ^_/   |         ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃                    .        *          |                          |_       ┃ ┃    Tukums    ┃       3      ┃      4      ┃       B       ┃");  
     printf("\n┃                __/  |                  |                            `      ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃             __/      `_                 |                           |      ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃ Ventspils /X            `               |                            |     ┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃          /  |` _   Talsi `_             |                             |    ┃ ┃              ┃              ┃             ┃               ┃");                                                            
     printf("\n┃         |    |  ` X__       `          /                               `_  ┃ ┃    Talsi     ┃       5      ┃      6      ┃       C       ┃");  
     printf("\n┃         |     |      `       `        /   __X Sigulda                    | ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃       /Kuldīga X      X Tukums` _____/  _/                               | ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃     /           |     `_       _X______/                                  |┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃    |             `     `_     /  Rīga                                    | ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃   | Liepāja   ____`X______`X_/                                           | ┃ ┃   Ventspils  ┃       7      ┃      8      ┃       D       ┃");
     printf("\n┃   |X_________/  Saldus       Jelgava       ^                              |┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃   |                                      /  ^                            | ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃   |          _________ ___________  ____/     ^___                      |__┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");  
     printf("\n┃   |      _/ `         `           ``              `__                 _/  ^┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃    |  __/                                            `__             /     ┃ ┃   Liepāja    ┃       9      ┃      10     ┃       E       ┃");  
     printf("\n┃    | /                                                   `___   ___/       ┃ ┃              ┃              ┃             ┃               ┃");  
     printf("\n┃    |'                                                        `|`           ┃ ┃              ┃              ┃             ┃               ┃");
     printf("\n┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃ ┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬┃▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬┃");
    char izv[1][1];

    printf("\nIzvēlies nākamo staciju: ");  
    scanf("%s",izv);  
  
    switchs(izv)  {  
        icases("A")  
        main();  
        break; 
  
        icases("B")       
        palidzība();  
        break;  

        icases("C")  
        main();  
        break; 
  
        icases("D")       
        palidzība();  
        break; 

        icases("E")  
        main();  
        break; 
  
        icases("1")       
        palidzība();  
        break;  

        icases("2")  
        main();  
        break; 
  
        icases("3")       
        palidzība();  
        break;  

        icases("4")  
        main();  
        break; 
  
        icases("5")       
        palidzība();  
        break;  

        icases("6")  
        main();  
        break; 
  
        icases("7")       
        palidzība();  
        break;  

        icases("8")  
        main();  
        break; 
  
        icases("9")       
        palidzība();  
        break;  

        icases("10")       
        palidzība();  
        break;
  
          defaults  
          printf("Kļūdaina ievade, ieraksti jebkuru burtu vai skaitli, kas rādīts tabulā.");
          karte_plans();
          break;  
    } switchs_end;

}








int kontrolpunkts1 () {
    clearscr();
    for (int i = 0; i < 4; i++) {
    printf("                                                    Kontrolpunkti:%d/7\n", i + 1);
    printf("                                                            %d punkti \n", punkti);
    printf("%s ", jautajumi_liepaja[i]);
    scanf("%s", ievadne);
    
    if ( strcasecmp( ievadne, atbildes_liepaja[i] ) == 0) {
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
printf("Tu šobrīd pareizi esi atbildējis uz %d no 4 jautajumiem,\n\n", pareizi_kp);
sleep(7);

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
