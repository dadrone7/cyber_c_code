#include <stdlib.h>
#include <stdio.h>

int test_pw() {
		char password[10];
		printf("Password address: %p\n", password);
		printf("Enter password: ");
		fgets(password, 50, stdin);
		return 1;
}

void win() {
		printf("You win!\n");
}

void main() {
		if (test_pw()) printf("Fail!\n");
		else win();
}
