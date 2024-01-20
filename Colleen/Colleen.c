#include <stdio.h>

 /*
  this is comment1
 */

void quine() {
	char *src_code = "#include <stdio.h>%1$c%1$c /*%1$c  this is comment1%1$c */%1$c%1$cvoid quine() {%1$c	char *src_code = %2$c%s%2$c;%1$c	printf(src_code, 10, 34, src_code);%1$c}%1$c%1$cint main() {%1$c%1$c /*%1$c  this is comment2%1$c */%1$c%1$c	quine();%1$c%1$c	return 0;%1$c}%1$c";
	printf(src_code, 10, 34, src_code);
}

int main() {

 /*
  this is comment2
 */

	quine();

	return 0;
}
