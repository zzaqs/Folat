// Main Instructions Header
#ifndef FMAIN_H
#define FMAIN_H

#include <stdbool.h>
#include "finut.h"

void fmi_outIst(char *trg, char *dat);
void fmi_extIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin);
void fmi_cmpIst(char *trg, char *dat, size_t idx, char *lin, bool *flg, unsigned char mem[]);
void fmi_addIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_subIst(bool noWarn, char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_divIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_mulIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_modIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_setIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_lshIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_rshIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_andIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_orrIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);
void fmi_mslIst(char *trg, char *dat, size_t idx, char *lin, unsigned char mem[]);

#endif
