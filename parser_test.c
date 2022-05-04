#include "p_parser.h"
#include "p_tools.h"



const char g_file[] = "abcdefghijklmnopqrstuvwxyz";
char * ch = (char*)g_file;
char * check = (char*)g_file;
int t_getch() {
	return *ch;
	//return *ch;
}

int main() {
	int ch;
	while ((ch = t_getch()) != '\0') {
		assert(ch == *check++);
		printf("%c", (char)ch);
	}
	printf("\n");
	return 0;
}


