#include <stdio.h>

#define PROGRAM "#include <stdio.h>%1$c%1$c#define PROGRAM %2$c%3$s%2$c%1$c%1$c#define WRITE_PROGRAM() fprintf(fp, PROGRAM, 10, 34, PROGRAM)%1$c#define EXECUTE_PROGRAM() int main() { FILE *fp = fopen(%2$cGrace_kid.c%2$c, %2$cw%2$c); if (fp != NULL) { WRITE_PROGRAM(); fclose(fp); } return 0; }%1$c%1$cEXECUTE_PROGRAM()%1$c"

#define WRITE_PROGRAM() fprintf(fp, PROGRAM, 10, 34, PROGRAM)
#define EXECUTE_PROGRAM() int main() { FILE *fp = fopen("Grace_kid.c", "w"); if (fp != NULL) { WRITE_PROGRAM(); fclose(fp); } return 0; }

EXECUTE_PROGRAM()
