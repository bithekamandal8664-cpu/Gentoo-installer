#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void guru() {
	system("eselect repository enable guru");
	system("emaint sync -R guru");
}
void hyproverlay() {
	system("eselect repository enable hyproverlay");
	system("emaint sync -R hyproverlay");
}

int main() {
	char eselect[100];

	system("emerge eselect-repository");

	printf("select repos please?:-\n");
	printf("this is all i know :(\n");
	printf("1. GURU\n");
	printf("2. hyproverlay\n");
	printf("3. both\n");

	printf("type here in numbers:- ");
	fgets(eselect, sizeof(eselect), stdin);
	eselect[strlen(eselect) -1 ] = '\0';

	switch (eselect[0]) {
		case '1' :
			guru();
			break;
		case '2' :
			hyproverlay();
			break;
		case '3' :
			guru();
			hyproverlay();
			break;
	}
	return 0;
}


