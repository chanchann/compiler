#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "LinkList.h"

int main(int argc, char** argv){
    linklist *res = createLink();
    char* str0 = "age >= 45";
    Dfstate* state;
    *state = Initial;
    handle(str0, state, res);
    linklist* tmp = res->next;
    while(tmp!=NULL){
        printf("%s:%s",type2str(tmp->elem->type), tmp->elem->val);
        tmp = tmp->next;
    }
    return 0;

}