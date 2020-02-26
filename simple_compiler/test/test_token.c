#include <stdio.h>
#include "token.h"
#include "LinkList.h"

int main(){
    char* str_type;

    // TEST type2str
    TokenType type = GT_Type;
    str_type = type2str(GT_Type);
    printf("%s\n", str_type);

    // TEST linklist
    linklist* head = createLink();
    token* tk1 = (token*)malloc(sizeof(token));
    tk1->type = GT_Type;
    strcpy(tk1->val, "tk1");
    push_back(head, tk1);
    token* tk2 = (token*)malloc(sizeof(token));
    tk2->type = Identifier_Type;
    strcpy(tk2->val, "tk2");
    push_back(head, tk2);

    traverse(head);


}