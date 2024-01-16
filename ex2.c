#include <stdio.h>

void quine() {
	char *s = "#include <stdio.h>%c%cvoid quine() {%c	char *s = %c%s%c;%c	printf(s, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main() {%c	quine();%c	return 0;%c}%c";
	printf(s, 10, 10, 10, 34, s, 34, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main() {
	quine();
	return 0;
}
