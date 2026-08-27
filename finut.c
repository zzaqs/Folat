// Interpreter Utils
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include "inc/finut.h"

// associates an instruction with a unique number that fits in unsigned short.
// it's possible to use only 36 charaters ([a-z], 0-9 (26 letters + 10 digits))
unsigned short fiu_istID(const char *str){
    return ((str[0] << 16) | (str[1] << 8) | str[2]);
}

// field evaluation
unsigned char fiu_toNum(char *fld, size_t idx, char *lin){
    if (fld[0] == 't' && fld[1] == 'r' && fld[2] == 'u') return 1;
    if (fld[0] == 'f' && fld[1] == 'a' && fld[2] == 'l') return 0;

    if (isdigit(fld[0]) && isdigit(fld[1]) && isdigit(fld[2])){
        return (unsigned char)(atoi(fld) % 256);
    } else {
        Fiu_errMNL("Error while casting.", idx, lin);
    }
}
