//
// Created by Frank on 2020-02-28.
//

#ifndef LAB1_LINK_H
#define LAB1_LINK_H

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

//声明节点结构
typedef struct Linklist{
    struct Token* elem;          //存储struct token元素
    struct Linklist *next;  //指向直接后继元素的指针
}linklist;

//创建链表的函数
linklist* createLink();

//返回链表最后一个结点
linklist* lastNode(linklist* head);

//往后添加结点
void push_back(linklist* head, struct Token* elem);

//遍历输出遍历结点元素
void traverse(linklist* head);

#endif //LAB1_LINK_H
