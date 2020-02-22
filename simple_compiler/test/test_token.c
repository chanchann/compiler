#include <stdio.h>
#include "token.h"
#include "LinkList.h"

int main(){
    char* res;
    TokenType type = GT_Type;
    res = type2str(GT_Type);
    printf("%s\n", res);
}