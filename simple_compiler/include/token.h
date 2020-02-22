#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

#define STRNUM 20
//先定义一些枚举值来代表不同的状态
typedef enum{
    Initial = 1,
    Indentifier,
    GT, 
    GE,
    IntLiteral
}Dfstate;

typedef enum{
    Identifier_Type = 1,
    IntLiteral_Type,
    GT_Type,
    GE_Type,
    None_Type,
}TokenType;

typedef struct Token{
    TokenType type;
    char val[30];
}token;

int isAlpha(const char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    return -1;
}

int isDigit(const char c){
    if(c >= '0' && c <='9')
        return 0;
    return -1;
}

void handleState(const char c, Dfstate* state, linklist* res);
void initToken(const char c, Dfstate* state, linklist* res);

char* type2str(const TokenType type){
    char* res = (char*)malloc(sizeof(char) * STRNUM);//注意返回后free掉
    switch(type){
        case Identifier_Type:
            strcpy(res, "Identifier");
            break;
        case IntLiteral_Type:
            strcpy(res, "IntLiteral");
            break;
        case GT_Type:
            strcpy(res, "GT");
            break;
        case GE_Type:
            strcpy(res, "GE");
            break;
        default:
            strcpy(res, "None");
            break;
    }
    return res;
}
 
void handle(const char* src, const Dfstate* initialState, linklist* res) {
    Dfstate newState = *initialState;
    int i;
    for (i = 0; i < strlen(src); i++) {
        handleState(src[i], &newState, res);
    }
}

void addLastChar(linklist* last, char c){
    char* strtmp = last->elem->val;
    int len = strlen(strtmp);
    strtmp[len] = c;
    strtmp[len+1] = 0;
}

void handleState(const char c, Dfstate* state, linklist* res) {
    switch (*state) {
        case Initial:
            initToken(c, state, res);
            break;
        case Indentifier:
            if (isAlpha(c) || isDigit(c)) {
                linklist* last = lastNode(res);
                addLastChar(last, c);
            } else {
                *state = Initial;
                initToken(c, state, res);
            }
            break;
        case GT:
            if (c == '=') {
                *state = GE;
                linklist* last = lastNode(res);
                last->elem->type = GE_Type;
                addLastChar(last, c);
            } else {
                *state = Initial;
                initToken(c, state, res);
            }
            break;
        case GE:
            *state = Initial;
            initToken(c, state, res);
            break;
        case IntLiteral:
            if (isDigit(c)) {
                linklist* last = lastNode(res);
                addLastChar(last, c);
            } else {
                *state = Initial;
                initToken(c, state, res); 
            }
            break;
    }
}


void initToken(const char c, Dfstate* state, linklist* res) {
    if (*state != Initial)
        return;
    token* tk;
    if (isAlpha(c)) {
        *state = Indentifier;
        tk->type = Identifier_Type;
    } else if (isDigit(c)) {
        *state = IntLiteral;
        tk->type = IntLiteral_Type;
    } else if (c == '>') {
        *state = GT;
        tk->type = GT_Type;
    } else {
        return;
    }

    tk->val[0] = c;
    push_back(res, tk);
}


#endif