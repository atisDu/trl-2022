#ifndef __SWITCHS_H__
#define __SWITCHS_H__

#include <string.h>
#include <regex.h>
#include <stdbool.h>

/** Sāk switchu stringam x */
#define switchs(x) \
    { char *ss__sw = (x); bool ss__done = false; bool ss__cont = false; \
        regex_t ss__regex; regcomp(&ss__regex, ".*", 0); do {

/** Pārbauda vai vērtība atbilst slēdzim (kapitalizācijas jūtīgs) */
#define cases(x)    } if ( ss__cont || !strcmp ( ss__sw, x ) ) \
                        { ss__done = true; ss__cont = true;

/** Pārbauda vai vērtība atbilst i_slēdzim (kapitalizācijas nejūtīgs) */
#define icases(x)    } if ( ss__cont || !strcasecmp ( ss__sw, x ) ) { \
                        ss__done = true; ss__cont = true;

/** Parbauda vai atbilst parastajai ar regcomp(3) trakums */
#define cases_re(x,flags) } regfree ( &ss__regex ); if ( ss__cont || ( \
                              0 == regcomp ( &ss__regex, x, flags ) && \
                              0 == regexec ( &ss__regex, ss__sw, 0, NULL, 0 ) ) ) { \
                                ss__done = true; ss__cont = true;

/** Noklusējuma darbība */
#define defaults    } if ( !ss__done || ss__cont ) {

/** Aizstaisa slēdzi */
#define switchs_end } while ( 0 ); regfree(&ss__regex); }

#endif // __SWITCHS_H__
// Paldies @Andrea Carron