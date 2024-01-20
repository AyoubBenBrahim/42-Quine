#include <stdio.h>

 /*
  Some Comment
 */

#define PROGRAM "#include <stdio.h>%1$c%1$c /*%1$c  Some Comment%1$c */%1$c%1$c#define PROGRAM %2$c%3$s%2$c%1$c%1$c#define WRITE_PROGRAM() fprintf(fp, PROGRAM, 10, 34, PROGRAM)%1$c#define FT(X) int main() { FILE *fp = fopen(X, %2$cw%2$c); if (fp != NULL) { WRITE_PROGRAM(); fclose(fp); } return 0; }%1$c%1$cFT(%2$cGrace_kid.c%2$c)%1$c"

#define WRITE_PROGRAM() fprintf(fp, PROGRAM, 10, 34, PROGRAM)
#define FT(X) int main() { FILE *fp = fopen(X, "w"); if (fp != NULL) { WRITE_PROGRAM(); fclose(fp); } return 0; }

FT("Grace_kid.c")
