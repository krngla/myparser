#pragma once
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include "p_tools.h"
//Useful tools

typedef void Parser;
typedef int (*ScanFunction)();
typedef int (*TokenFunction)();

Parser * t_parser_create(ScanFunction scan_function_ptr, TokenFunction token_function_ptr);
int t_parser_next_char(Parser * parser);

void t_parser_putback(Parser * parser, int ch);
void t_parser_print_state(Parser * parser);

void t_parser_parse_word(Parser * parser, int ch);
void t_parser_parse_number(Parser * parser, int ch);
void t_parser_parse_whitespace(Parser * parser, int ch);
void t_parser_parse_string(Parser * parser, int ch);
