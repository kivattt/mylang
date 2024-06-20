#ifndef TOKENIZER_H
#define TOKENIZER_H

#define TOKEN_LIST_MACRO \
	X(EOF_TOKEN)\
	X(INVALID)\
	\
	X(MULTILINE_COMMENT)\
	X(LINE_COMMENT)\
	\
	X(EQUALS)\
	X(NOT_EQUALS)\
	X(LESS_THAN)\
	X(GREATER_THAN)\
	X(LESS_THAN_EQUALS)\
	X(GREATER_THAN_EQUALS)\
	\
	X(BOOLEAN_NOT)\
	X(BOOLEAN_AND)\
	X(BOOLEAN_OR)\
	\
	X(INCREMENT)\
	X(DECREMENT)\
	\
	X(ADDITION)\
	X(SUBTRACTION)\
	X(ASTERISK)\
	X(DIVITION)\
	X(MODULUS)\
	\
	X(LOGICAL_NOT)\
	X(EXCLUSIVE_OR)\
	X(LOGICAL_AND)\
	X(LOGICAL_OR)\
	\
	X(PERIOD)\
	X(ARROW)\
	X(COMMA)\
	\
	X(SHIFT_LEFT)\
	X(SHIFT_RIGHT)\
	\
	X(SEMICOLON)\
	X(COLON)\
	X(QUESTION_MARK)\
	X(AT_SYMBOL)\
	\
	X(ASSIGN)\
	\
	X(ASSIGN_ADDITION)\
	X(ASSIGN_INCREMENT)\
	X(ASSIGN_SUBTRACTION)\
	X(ASSIGN_DECREMENT)\
	X(ASSIGN_ASTERISK)\
	X(ASSIGN_DIVITION)\
	X(ASSIGN_MODULUS)\
	\
	X(ASSIGN_LOGICAL_NOT)\
	X(ASSIGN_EXCLUSIVE_OR)\
	X(ASSIGN_LOGICAL_AND)\
	X(ASSIGN_LOGICAL_OR)\
	\
	X(LPAREN)\
	X(RPAREN)\
	X(LCURLY)\
	X(RCURLY)\
	X(LSQUARE)\
	X(RSQUARE)\
	\
	X(IDENTIFIER)\
	X(KEYWORD)\
	\
	X(INT_LITERAL)\
	X(HEX_LITERAL)\
	X(STRING_LITERAL)\
	X(CHAR_LITERAL)\

#define X(name) name,
enum TokenType {
TOKEN_LIST_MACRO
	TokenTypeCount
};
#undef X

struct Token {
	char *pos;
	size_t len;
	enum TokenType type;
};

const char *TokenGetStringRep(struct Token *token);

int TokenGetPrecedence(struct Token *token);

#endif /* TOKENIZER_H */

