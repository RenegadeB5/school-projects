#include <stdio.h>
int main() {
	char name[10];
	printf("Hello, what\'s your name? ");
	scanf("%s", name);
	printf("Hi %s! It's nice to meet you.\n", name);
	return(0);
}
