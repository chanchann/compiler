#include <stdio.h>
#include "LinkList.h"

int main(){
    linklist* head = createLink();
    traverse(head);
    push_back(head, 'a');
    push_back(head, 'b');
    push_back(head, 'c');
    traverse(head);
    linklist* last = lastNode(head);
    printf("%c\n", last->val);
}