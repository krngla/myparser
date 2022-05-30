#include "p_parser.h"
#include "p_testkit.h"
#include "p_tools.h"
#include <stdbool.h>
#include <stdio.h>


//const char g_file[] = "abcdefghijklmnopqrstuvwxyz\nrerjewiorjewoi";
FILE * infile;
//char * ch = (char*)g_file;
//char * check = (char*)g_file;
int t_getch() {
	return fgetc(infile);
	//return *ch++;
}


int test_func(int a, int b, int c) {
	return a + b + c;
}


int main() {
	int ch;
	infile = fopen("test/parser_test.txt", "r");
	assert(infile != NULL);
	Parser * parser = t_parser_create(t_getch, NULL);	
	while ((ch = t_parser_scanner_next_char(parser)) != EOF) {
		switch (ch) {
			case 'a' ... 'z':
			case 'A' ... 'Z':
				//letter
				printf("LITERAL(");
				t_parser_parse_word(parser, ch);
				printf(") ");
				break;
			case '0' ... '9':
				//number
				printf("NUMBER(");
				t_parser_parse_number(parser, ch);
				printf(") ");
				break;
			case '=':
			case '-':
			case '+':
			case '/':
			case '%':
				printf("OP(%c) ", (char)ch);
				break;
			case ';':
				printf("\n");
				break;
			case '"':
				printf("STRING(\"");
				t_parser_parse_string(parser, ch);
				printf("\") ");
				break;
			case ' ':
			case '\n':
			case '\t':
			case '\r':
				t_parser_parse_whitespace(parser, ch);
				break;

			default:
				break;
		}
		//printf("%c", (char)ch);
	}
	printf("\n");
	t_parser_putback(parser, (int)'t');
	t_parser_print_state(parser);	
	
	
	return 0;
}

