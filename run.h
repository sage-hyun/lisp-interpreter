#ifndef RUN_H
#define RUN_H

/* Token codes */
#define INT_LIT 10      // 0 1 2...
#define IDENT 11        // X Y Z...

//#define KEYWORD 12
#define FUNC_TYPE1 12
#define FUNC_TYPE2 13
#define FUNC_TYPE3 14
#define FUNC_TYPE4 15

#define STRING 16     // "X" "Y" "GOOD" (추가해야 함)
#define ATOM 17     // 'X 'Y 'GOOD (추가해야 함)
#define NIL 18      // (추가해야 함)

#define ADD_OP 21       // +
#define SUB_OP 22       // -
#define MULT_OP 23      // *
#define DIV_OP 24       // /
#define LEFT_PAREN 25   // (
#define RIGHT_PAREN 26  // )
#define LESS_COMP 27    // <
#define GREATER_COMP 28 // >
#define EQUAL_COMP 29   // =
#define NOT_COMP 30     // !
#define APOSTROPHE 31   // '
#define BACKSLASH 32    // "\"
#define HASH 33         // #
#define DOUBLE_QUOT 34  // "
#define DOT 35          // .
#define SEMI_COL 40     // ;

#define LIST_CODE 50        // 리스트임을 의미하는 token code (편의상 추가)

typedef struct element {
	int code;
	union {
		char lexeme[100];   // 기본
		struct element* listElem[100]; //code가 LIST_CODE인 경우에만 사용!
	};
} element;

typedef struct TreeNode {
	element key;
	struct TreeNode* child1, * child2, * child3;
} TreeNode;

typedef enum
{
	REVERSE = 100,
	LENGTH,
	_ATOM,
	_NULL,
	NUMBERP,
	ZEROP,
	MINUSP,
	STRINGP,
} Keyword1;	// func_type1에 속하는 함수

void run(const struct TreeNode* const);

void func_type1(const struct TreeNode* const);

#endif
