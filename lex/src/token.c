//
// Created by Frank on 2020-02-28.
//
#include "../include/token.h"
#include <string.h>
void handle(const char* str, Dfstate* state, const linklist* head){
    int i = 0;
    for(i = 0; i < strlen(str); i++){
        handleState(str[i], state, head);
    }
}

void handleState(const char ch, Dfstate* state, const linklist* head){
    switch(*state){
        case Initial:
            initToken(ch, state, head);
            break;
        case Indentifier:
            if(isAlpha(ch) == 0){
                add_ch(head, ch);
            }else{
                initToken(ch, state, head);
            }
            break;
        case GT:
            if(ch == '='){
                add_ch(head, ch);
                *state = GE;
            }else{
                initToken(ch, state, head);
            }
            break;
        case GE:
            initToken(ch, state, head);
            break;
        case IntLiteral:
            if(isDigit(ch) == 0){
                add_ch(head, ch);
            }else{
                initToken(ch, state, head);
            }
            break;
    }
}

void initToken(const char ch, Dfstate* state, const linklist* head){
    *state = Initial;
    struct Token* newToken = (struct Token*)malloc(sizeof(struct Token));
    newToken->val = (char*)malloc(sizeof(char) * VAL_NUM);
    if(isAlpha(ch) == 0){
        *state = Indentifier;
        newToken->type = Identifier_Type;
    }else if(isDigit(ch) == 0){
        *state = IntLiteral;
        newToken->type = IntLiteral_Type;
    }else if(ch == '>'){
        *state = GT;
        newToken->type = GT_Type;
    }
    if(*state != Initial){
        push_back(head, newToken);
        add_ch(head, ch);
    }else{
        free(newToken->val);
        newToken->val = NULL;
        free(newToken);
        newToken = NULL;
    }

}

//判断是否为字母
//如果是返回0否则返回-1
int isAlpha(const char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z'))
        return 0;
    return -1;
}

int isDigit(const char ch){
    if(ch >= '0' && ch <= '9')
        return 0;
    return -1;
}

void add_ch(const linklist* head, const char ch){
    linklist* last = lastNode(head);
    size_t tokenLen = strlen(last->elem->val);
    last->elem->val[tokenLen++] = ch;
    last->elem->val[tokenLen] = 0;
}

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
