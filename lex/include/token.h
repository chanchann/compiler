//
// Created by Frank on 2020-02-28.
//
#ifndef LAB1_TOKEN_H
#define LAB1_TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#define VAL_NUM 20
#define STRNUM 20

typedef struct Linklist linklist;

//先定义一些枚举值来代表不同的状态
typedef enum{
    Initial = 1,
    Indentifier,
    GT,
    GE,
    IntLiteral
}Dfstate;

//token的类型
typedef enum{
    Identifier_Type = 1,
    IntLiteral_Type,
    GT_Type,
    GE_Type,
    None_Type,
}TokenType;

struct Token{
    TokenType type;
    char* val;
};

//处理str的入口
void handle(const char* str, Dfstate* state, const linklist* head);
//判断每一个状态的后续状态
void handleState(const char ch, Dfstate* state, const linklist* head);
//从初始状态开始确定
void initToken(const char ch, Dfstate* state, const linklist* head);
//判断是否为字母
int isAlpha(const char ch);
//判断是否为数字
int isDigit(const char ch);
//token追加一个ch
void add_ch(const linklist* head,const char ch);
//type转换为str
char* type2str(const TokenType type);
#endif //LAB1_TOKEN_H
