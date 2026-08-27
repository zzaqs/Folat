// Main Instructions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "inc/fmain.h"

void fmi_outIst(char *trg, char *dat){
    if (*trg != '-') { if (*trg == '\\') putchar('\n'); else putchar(*trg); }
    trg++;
    if (*trg != '-') { if (*trg == '\\') putchar('\n'); else putchar(*trg); }
    trg++;
    if (*trg != '-') { if (*trg == '\\') putchar('\n'); else putchar(*trg); }

    if (*dat != '-') { if (*dat == '\\') putchar('\n'); else putchar(*dat); }
    dat++;
    if (*dat != '-') { if (*dat == '\\') putchar('\n'); else putchar(*dat); }
    dat++;
    if (*dat != '-') { if (*dat == '\\') putchar('\n'); else putchar(*dat); }
}

void fmi_extIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    if (datN > 1 && noWarn == false){ 
        Fiu_warnI("ext", "Data must be the break line permission (000|001), converting to boolean.", idx, lin);
        datN = (bool)datN;
    }

    if (datN == 0) putchar('\n');

    exit(trgN);
}

void fmi_cmpIst(char *trg, char *dat, size_t idx, char *lin, bool *flg, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    *flg = (mem[trgN] == datN);
}

void fmi_addIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    if (mem[trgN] == 255 && datN != 0 && noWarn == false) Fiu_warnI("add", "Overflow detected, wrapping around.", idx, lin);

    mem[trgN] = (mem[trgN] + datN) % 256;
}

void fmi_subIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    if (mem[trgN] == 0 && datN != 0 && noWarn == false) Fiu_warnI("sub", "Underflow detected, wrapping around.", idx, lin);

    mem[trgN] = (mem[trgN] - datN) % 256;
}

void fmi_divIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    unsigned char resl = (mem[trgN] / datN) % 256;

    mem[trgN] = (unsigned char)resl;
}

void fmi_mulIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    unsigned char resl = (mem[trgN] * datN) % 256;

    mem[trgN] = (unsigned char)resl;
}


void fmi_modIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = (mem[trgN] % datN) % 256;
}

void fmi_setIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = datN;
}

void fmi_lshIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = (mem[trgN] << datN) % 256;
}

void fmi_rshIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = (mem[trgN] << datN) % 256;
}

void fmi_andIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = (mem[trgN] & datN) % 256;
}

void fmi_orrIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    mem[trgN] = (mem[trgN] | datN) % 256;
}

void fmi_mslIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]){
    unsigned char trgN = fiu_toNum(trg, idx, lin);
    unsigned char datN = fiu_toNum(dat, idx, lin);

    unsigned char start = (trgN < datN) ? trgN : datN;
    unsigned char end   = (trgN > datN) ? trgN : datN;

    for (unsigned char i = start; i <= end; i++){
        if (mem[i] < 31){
            printf("\\%02x", mem[i]);
        } else {
            putchar(mem[i]);
        }
    }
}

