#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <ctype.h>
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


//functions
typedef int (*ScanFunction)();
typedef int (*TokenFunction)();

typedef struct parser {
	//Variables
	int line;
	int putback;
	//Functions
	ScanFunction scan_function_ptr;
	TokenFunction token_function_ptr;
}Parser;


Parser * t_parser_create(ScanFunction scan_function_ptr, TokenFunction token_function_ptr) {
	Parser * parser = malloc(sizeof * parser);
	parser->line = 0;
	parser->putback = 0;
	parser->scan_function_ptr = scan_function_ptr;
	parser->token_function_ptr = token_function_ptr;
	return parser;
}

int t_parser_loop(Parser * parser) {
	int ch;
	while((ch = t_parser_next_char(parser)) != EOF)
	{
		int token = t_parser_next_token(parser, ch);
		
	}
}

int t_parser_next_char(Parser * parser) {
	int ch;

	if (parser->putback) {
		ch = parser->putback;
		parser->putback = 0;
		return ch;
	}

	ch = parser->scan_function_ptr();
	if('\n' == ch)
		parser->line++;
	return ch;
}

int t_parser_next_token(Parser * parser, int ch) {

	return 0;
}

void t_parser_putback(Parser * parser, int ch) {
	parser->putback = ch;
}
void t_parser_print_state(Parser * parser) {
	printf("Line: %i, Putback: %c\n", parser->line, parser->putback);
}


void t_parser_parse_word(Parser * parser, int ch){
	do {
		if (isspace(ch)) {
			t_parser_putback(parser, ch);
			break;
		}
		
		switch (ch) {
			case ';':
				t_parser_putback(parser, ';');
				break;
			case '0' ... '9':
			case 'a' ... 'z':
			case 'A' ... 'Z':
				printf("%c", (char)ch);
				continue;
			default:
				return;
		}
	} while ((ch = t_parser_scanner_next_char(parser)) != EOF);
}
void t_parser_parse_number(Parser * parser, int ch){
	do {
		if (isspace(ch)) {
			t_parser_putback(parser, ch);
			break;
		}
		if (ch == ';') {
			t_parser_putback(parser, ';');
			break;
		}
		printf("%c", (char)ch);
		switch (ch) {
			case '0' ... '9':
			case 'a' ... 'f':
			case 'A' ... 'F':
				continue;
			default:
				break;
		}
	} while ((ch = t_parser_scanner_next_char(parser)) != EOF);
}

void t_parser_parse_whitespace(Parser * parser, int ch) {
	do {
		if (!isspace(ch)) {
			t_parser_putback(parser, ch);
			break;
		}
		if (ch == ';') {
			t_parser_putback(parser, ';');
			break;
		}
	} while ((ch = t_parser_scanner_next_char(parser)) != EOF);
}

void t_parser_parse_string(Parser * parser, int ch) {
	while ((ch = t_parser_scanner_next_char(parser)) != EOF) {
		if (ch == '\\') {
			//ESCAPES
			//t_parser_putback(parser, ch);
			continue;
		}
		if (ch == '"') {
			break;
		}
		printf("%c", (char)ch);
	}
}

void t_parser_parse_string_escapes(Parser * parser, int ch) {
	while ((ch == t_parser_
}



