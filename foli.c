// Interpreter
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inc/finut.h"
#include "inc/fmain.h"

#define LINSIZ 100

// foli main.f
int main(int argc, char *argv[]){
    bool noWarn = false;
    short ms = 0;

    if (argc < 2){
        fputs("foli [X]: Unspecified file.\n", stderr);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL){
        fputs("foli [X]: Error while opening the file.\n", stderr);
        return 1;
    }

    for (int i = 2; i < argc; i++){
        if (strcmp(argv[i], "-nw") == 0){
            noWarn = true;
            continue;
        } else if (strcmp(argv[i], "-ms") == 0){
            ms = atoi(argv[++i]) % 256;
            if (ms == 0) ms = 256;
            continue;
        } else if (strcmp(argv[i], "-v") == 0){
            puts("Folat Interpreter 0.3.0-alpha");
            puts("Copyright (C) 2025, @zzaqs");
            puts("This software is under MOT license");
            return 0;
        } else if (strcmp(argv[i], "-h") == 0){
            puts("Usage: foli <file> [options]");
            puts("\nOptions:");
            puts(" -ms <int>  set the memory size.");
            puts(" -nw        disable the warnings.");
            puts(" -h         show this help.");
            puts(" -v         show the actual version.");
            return 0;
        } else {
            fprintf(stderr, "foli [X]; Unknown option '%s'.", argv[i]);
            return 1;
        }
    }

    char lin[LINSIZ];
    unsigned char mem[257] = {0};
    bool flg = 0;
    bool exc = true;
    char seg[4] = {0};
    size_t idx = 0;
    short ist = 0;
    char trg[4] = {0}, dat[4] = {0};
    bool hasExt = false;

    while (fgets(lin, LINSIZ, file) != NULL){
        idx++;

        if (lin[0] == '#' || lin[0] == '\n' || lin[0] == '\t'){
            continue;
        }

        if (strlen(lin) < 11){
            fclose(file);
            Fiu_errMNL("Line does not meet the minimum character limit (11).", idx, lin);
        }

        memset(trg, 0, 4);
        memset(dat, 0, 4);
        char t[4] = {0};
        memcpy(t, lin, 3);
        ist = fiu_istID(t);
        memcpy(trg, lin+4, 3);
        memcpy(dat, lin+8, 3);

        if (ist == fiu_istID("---")){
            if (strcmp(seg, trg) == 0){
                exc = true;
            }
        } else if (ist == fiu_istID("jwc")){
            unsigned char datN = fiu_toNum(dat, idx, lin) % 2;

            if (flg == datN){
                memcpy(seg, trg, 3);
                exc = false;
            }
        } else {
            if (exc){
                if (ist == fiu_istID("out")){
                    fmi_outIst(trg, dat);
                    continue;
                } else if (ist == fiu_istID("ext")){;
                    hasExt = true;
                    fmi_extIst(noWarn, trg, dat, idx, lin);
                } else if (ist == fiu_istID("cmp")){
                    fmi_cmpIst(trg, dat, idx, lin, &flg, mem);
                    continue;
                } else if (ist == fiu_istID("add")){
                    fmi_addIst(noWarn, trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("sub")){
                    fmi_subIst(noWarn, trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("div")){
                    fmi_divIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("mul")){
                    fmi_mulIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("mod")){
                    fmi_modIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("set")){
                    fmi_setIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("lsh")){
                    fmi_lshIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("rsh")){
                    fmi_rshIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("and")){
                    fmi_andIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("orr")){
                    fmi_orrIst(trg, dat, idx, lin, mem);
                    continue;
                } else if (ist == fiu_istID("msl")){
                    fmi_mslIst(trg, dat, idx, lin, mem);
                    continue;
                } else {
                    fclose(file);
                    Fiu_errMNL("Unknown Instruction.", idx, lin);
                }
                fclose(file);
                Fiu_errMNL("Exit instruction not found.", idx, lin);
            }
        }
    }

    fclose(file);
    if (!hasExt) Fiu_errMNL("Exit instruction not found.", idx, lin);
    return 0;
}