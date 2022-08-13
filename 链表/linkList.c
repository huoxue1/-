/*
    单链表
*/
#include<stdio.h>
#include<stdlib.h>

/// <summary>
/// 
/// </summary>
typedef struct LinkLists
{
    int data;
    int size;
    struct LinkLists* next;
}LinkList;


/// <summary>
/// 初始化链表头的内容
/// </summary>
/// <param name="l">链表指针对象</param>
void initLinkList(LinkList* l) {
    l->data = -1;
    l->size = 0;
    l->next = NULL;
}

/// <summary>
/// 插入数据到链表中
/// </summary>
/// <param name="l">链表指针对象</param>
/// <param name="data">需要插入的数据</param>
/// <param name="position">插入的位置，从0开始，0代表插入到队首，-1代表插入到结尾</param>
/// <returns></returns>
int insert(LinkList* l,int data,int position) {
    LinkList* temp = l;
    if (position > l->size) {
        return 0;
    }
    if (position == -1)
    {
        position = l->size;
    }
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    LinkList *node = (LinkList *)malloc(sizeof(struct LinkLists));
    // 检查是否分配成功
    if (!node) {
        return 0;
    }
    node->data = data;
    node->next = temp->next;
    node->size = -1;
    temp->next = node;
    l->size++;
    return 1;
}


int delete(LinkList* l, int position) {
    LinkList* temp = l;
    if (position > l->size-1) {
        return 0;
    }
    if (position == -1)
    {
        position = l->size-1;
    }
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    LinkList* node = temp->next;
    temp->next = node->next;

    free(node);
    l->size--;
    return 1;
}

/// <summary>
/// 
/// </summary>
/// <param name="l"></param>
/// <param name="data"></param>
/// <param name="position"></param>
/// <returns></returns>
int update(LinkList* l, int data,int position) {
    LinkList* temp = l;
    if (position > l->size - 1) {
        return 0;
    }
    if (position == -1)
    {
        position = l->size - 1;
    }
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    LinkList* node = temp->next;
    node->data = data;
    return 1;
}

/// <summary>
/// 
/// </summary>
/// <param name="l"></param>
void forEach(LinkList *l) {
    LinkList* temp = l;

    for (int i = 0; i < l->size; i++)
    {
        temp = temp->next;
        printf("%d  ", temp->data);
    }
    printf("\n");
}

/// <summary>
/// 
/// </summary>
/// <param name="l"></param>
/// <param name="data"></param>
/// <returns></returns>
int query(LinkList *l,int data) {
    LinkList* temp = l;

    for (int i = 0; i < l->size; i++)
    {
        temp = temp->next;
        if (temp->data = data) {
            return i+1;
       }
    }
    return -1;
}



int main1() {
     LinkList list;
     printf("链表操作：\n");
     printf("链表下标从0开始\n");
    initLinkList(&list);
    insert(&list, 1, -1);
    insert(&list, 2, -1);
    insert(&list, 3, -1);
    insert(&list, 4, -1);
    printf("依次插入四个元素:\n");
    forEach(&list);
    insert(&list, 10, 2);
    printf("在位置2插入元素:\n");
    forEach(&list);

    delete(&list, 2);
    printf("删除位置2的元素:\n");
    forEach(&list);
    delete(&list, -1);
    printf("删除末尾的元素:\n");
    forEach(&list);
    update(&list, 11, 2);
    printf("修改位置2的元素为11:\n");
    forEach(&list);
    printf("元素2的位置在：\n%d", query(&list, 2));
    return 0;
}