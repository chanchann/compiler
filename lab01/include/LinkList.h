#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

//声明节点结构
// typedef struct Token token; //注意这里结构体引用的问题

typedef struct Linklist{
    token* elem;          //存储char元素
    struct Linklist *next;  //指向直接后继元素的指针
}linklist;

//创建链表的函数
linklist* createLink(){
    //由于头节点本身不用于存储数据，因此在实现对链表中数据的"增删查改"时要引起注意
    //虚头结点
    linklist* head =(linklist*)malloc(sizeof(linklist));
    head->next = NULL;
    return head;
}

//遍历输出遍历结点元素
void traverse(linklist* head){
    if(head == NULL){
        printf("head is NULL");
        return;
    }
    linklist* tmp = head->next;
    while(tmp != NULL){
        printf("%s\n", tmp->elem->val);
        tmp = tmp->next;
    }
    
}

//返回链表最后一个结点
linklist* lastNode(linklist* head){
    if(head == NULL){
        printf("head is null");
        return NULL;
    }
    linklist* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    return tmp;
}

//往后添加结点
void push_back(linklist* head, token* elem){
    linklist* last = lastNode(head);
    linklist* newNode = (linklist*)malloc(sizeof(linklist));
    newNode->elem = elem;
    last->next = newNode;
    newNode->next = NULL;
}

#endif