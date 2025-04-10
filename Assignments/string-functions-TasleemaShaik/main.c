#include "functions.h"
#include "solutions.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char *strs[10] = {
  "Binghamton",
  "Bing\0hamton",
  "DETERMINISM",
  "powerlessly",
  "censorious",
  "BADC0FFEE0ddf00d",
  "concurrently",
  "abaft",
  "lexicon truculent wherewithal zenith",
  "down-and-out"
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char* ch = argv[1];
    printf("myisalnum: %s", myisalnum(ch) ? "true" : "false");
    printf("\n");

    printf("myisalpha: %s", myisalpha(ch) ? "true" : "false");
    printf("\n");

    printf("myislower: %s", myislower(ch) ? "true" : "false");
    printf("\n");
   
    printf("myisupper: %s", myisupper(ch) ? "true" : "false");
    printf("\n");

    printf("myisdigit: %s", myisdigit(ch) ? "true" : "false");
    printf("\n");
  
    printf("myisxdigit: %s", myisxdigit(ch) ? "true" : "false");
    printf("\n");
   
    printf("myiscntrl: %s", myiscntrl(ch) ? "true" : "false");
    printf("\n");
   
    printf("myisspace: %s", myisspace(ch) ? "true" : "false");
    printf("\n");

    printf("myispunct: %s", myispunct(ch) ? "true" : "false");
    printf("\n");
  
    printf("myisprint: %s", myisprint(ch) ? "true" : "false");
    printf("\n");
   
    return 0;
}
