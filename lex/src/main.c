#include <stdio.h>
#include "../include/link.h"
#include "../include/token.h"

int main() {

    // test link
    linklist* head = createLink();
    if(head != NULL){
        printf("head is not null\n");
    }
    struct Token* tk1 = (struct Token*)malloc(sizeof(struct Token));
    tk1->type = GT_Type;
    tk1->val = (char*)malloc(sizeof(char) * VAL_NUM);
    strcpy(tk1->val, "tk1");
    printf("tk1->val : %s\n", tk1->val);
    push_back(head, tk1);

    struct Token* tk2 = (struct Token*)malloc(sizeof(struct Token));
    tk2->type = Identifier_Type;
    tk2->val = (char*)malloc(sizeof(char) * VAL_NUM);
    strcpy(tk2->val, "tk2");
    push_back(head, tk2);

    traverse(head);

    linklist* last = lastNode(head);
    printf("last->elem->val : %s\n", last->elem->val);

    // test isalpha()
    char ch1 = 'a', ch2 = 'A';
    while(isAlpha(ch1) == 0){
        ch1++;
    }
    printf("%c is alpha\n", --ch1);
    while(isAlpha(ch2) == 0){
        ch2++;
    }
    printf("%c is alpha\n", --ch2);

    // test isDigit
    char ch3 = '0';
    while(isDigit(ch3) == 0){
        ch3++;
    }
    printf("%c is digit\n", --ch3);

    // test add_ch
    add_ch(head, 't');
    linklist* last1 = lastNode(head);
    printf("%s\n", last1->elem->val);

    //test char* malloc
    char* cp = (char*)malloc(sizeof(char)*10);
    printf("cp len %lu\n", strlen(cp));

    printf("---------------\n");

    //test tokenize process
    char* str1 = "age >= 45";
    Dfstate state = Initial;
    linklist* res = createLink();
    handle(str1, &state, res);
    linklist* tmp = res->next;
    while(tmp != NULL){
        printf("%s : %s\n", type2str(tmp->elem->type), tmp->elem->val);
        tmp = tmp->next;
    }
    return 0;
}