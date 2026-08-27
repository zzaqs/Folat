// Interpreter Utils Header
#ifndef FINUT_H
#define FINUT_H

#define Fiu_err(msg) do { fprintf(stderr, "folc [X]: %s\n", msg); exit(1); } while(0)

// error to instruction
#define Fiu_errI(ist, msg, idx, lin) do { fprintf(stderr, "folc.%s [X] %s\n %zu | %s\n", ist, msg, idx, lin); exit(1) } while(0)

// error with only message, index and line
#define Fiu_errMNL(msg, idx, lin) do { fprintf(stderr, "folc [X]: %s\n %zu | %s\n", msg, idx, lin); exit(1); } while(0)

#define Fiu_warn(msg) fprintf(stderr, "folc [!]: %s\n", msg)

// error to instruction
#define Fiu_warnI(ist, msg, idx, lin) fprintf(stderr, "folc.%s [!] %s\n %zu | %s\n", ist, msg, idx, lin)

// error with only message, index and line
#define Fiu_warnMNL(msg, idx, lin) fprintf(stderr, "folc [X]: %s\n %zu | %s\n", msg, idx, lin)

unsigned short fiu_istID(const char *str);
unsigned char fiu_toNum(char *fld, size_t idx, char *lin);

#endif
