#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define	SUB_PROG(cmd, n) sprintf(cmd, "clang -o Sully_%1$d Sully_%1$d.c && ./Sully_%1$d", n)

void	Quine(int i) {
	char filename[50];
	char cmd[50];

	if (i == 0)
		Quine(6);

	sprintf(filename, "Sully_%d.c", i - 1);

	int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0777);

	char *program = "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <fcntl.h>%1$c%1$c#define	SUB_PROG(cmd, n) sprintf(cmd, %2$cclang -o Sully_%%1$d Sully_%%1$d.c && ./Sully_%%1$d%2$c, n)%1$c%1$cvoid	Quine(int i) {%1$c	char filename[50];%1$c	char cmd[50];%1$c%1$c	if (i == 0)%1$c		Quine(6);%1$c%1$c	sprintf(filename, %2$cSully_%%d.c%2$c, i - 1);%1$c%1$c	int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0777);%1$c%1$c	char *program = %2$c%3$s%2$c;%1$c%1$c	dprintf(fd, program, 10, 34, program, i - 1);%1$c%1$c	if (i == 6)%1$c	{%1$c		system(%2$cclang -o Sully_5 Sully_5.c%2$c);%1$c		exit(0);%1$c	}%1$c%1$c	if (i > 0)%1$c	{%1$c		SUB_PROG(cmd, i - 1);%1$c		system(cmd);%1$c	}%1$c}%1$c%1$cint main() {%1$c	int i = %4$d;%1$c%1$c	Quine(i);%1$c%1$c	return (0);%1$c}%1$c";

	dprintf(fd, program, 10, 34, program, i - 1);

	if (i == 6)
	{
		system("clang -o Sully_5 Sully_5.c");
		exit(0);
	}

	if (i > 0)
	{
		SUB_PROG(cmd, i - 1);
		system(cmd);
	}
}

int main() {
	int i = 5;

	Quine(i);

	return (0);
}
