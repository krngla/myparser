#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include "p_tools.h"


typedef enum tokenType{
	none = 0,
	type,
	operator,
	identifier,
	value_int,
	value_string,
	value_float
} TokenType;


typedef struct lexerToken{
	TokenType type;
	char * value;
}LexerToken;

typedef int (*ScanFunction)();

typedef struct scanner{
	ScanFunction scan_function_ptr;
	int putback;
	int line;
}Scanner;

typedef struct lexer{
	LexerToken * tokens;
}Lexer;

Scanner * t_parser_scanner_create(ScanFunction scan_function_ptr) {
	Scanner * scanner = malloc(sizeof * scanner);
	scanner->scan_function_ptr = scan_function_ptr;
	scanner->line = 0;
	scanner->putback = 0;
	return scanner;
}

int t_parser_scanner_next_char(Scanner * scanner) {
	int ch;

	if (scanner->putback) {
		ch = scanner->putback;
		scanner->putback = 0;
		return ch;
	}

	ch = scanner->scan_function_ptr();
	if('\n' == ch)
		scanner->line++;
	return ch;
}



int lexerToken(char ch) {
	return 0;
}


