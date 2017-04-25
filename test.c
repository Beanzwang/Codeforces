#include <sys/types.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
        regex_t regex;
        int reti, i = 0;
        char msgbuf[100];
/* Compile regular expression */
        reti = regcomp(&regex, "[[:upper:]][[:digit:]]", 0);
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }
        while (i < 2) {
                i++;
                char line[20];
                scanf("%s", line);
                /* Execute regular expression */
                reti = regexec(&regex, line, 0, NULL, 0);
                if( !reti ){
                        puts("Match");
                }
                else if( reti == REG_NOMATCH ){
                        puts("No match");
                }
                else{
                        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                        exit(1);
                }

        }

/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);

        return 0;
}