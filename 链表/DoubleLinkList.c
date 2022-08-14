/*
	双向链表
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct DoubleLinkLists {
	int data;
	struct DoubleLinkLists* font;
	struct DoubleLinkLists* next;
	int size;
}DoubleLinkList;


/// <summary>
/// 初始化双向链表
/// </summary>
/// <param name="list"></param>
void initDoubleLinkList(DoubleLinkList* list) {
	list->data = 0;
	list->font = NULL;
	list->next = NULL;
	list->size = 0;
}


void DoubleListForEach(DoubleLinkList* list) {
	DoubleLinkList* temp = list;
	for (int i = 0; i < list->size; i++)
	{
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");

}

/// <summary>
/// 双链表插入数据
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="position"></param>
/// <returns></returns>
int DoubleLinkListInsert(DoubleLinkList* list, int data, int position) {
	DoubleLinkList* temp = list;
	if (position > list->size) {
		return 0;
	}
	if (position == -1)
	{
		position = list->size;
	}
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	DoubleLinkList* node = (DoubleLinkList*)malloc(sizeof(struct DoubleLinkLists));
	// 检查是否分配成功
	if (!node) {
		return 0;
	}
	// 初始化新增的节点
	node->data = data;
	node->font = temp;
	node->next = NULL;
	node->size = -1;
	// 将节点挂载到temp节点
	temp->next = node;
	list->size++;
	return 1;
}

/// <summary>
/// 双链表删除数据
/// </summary>
/// <param name="list"></param>
/// <param name="position"></param>
/// <returns></returns>
int DoubleLinkListDelete(DoubleLinkList* list, int position) {
	DoubleLinkList* temp = list;
	if (position > list->size-1) {
		return 0;
	}
	if (position == -1)
	{
		position = list->size-1;
	}
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}

	DoubleLinkList* node = temp->next;
	temp->next = node->next;
	node->next->font = temp;
	free(node);
	list->size--;
	return 1;
}

int DoubleLinkListUpdate(DoubleLinkList* list, int data, int position) {
	DoubleLinkList* temp = list;
	if (position > list->size - 1) {
		return 0;
	}
	if (position == -1)
	{
		position = list->size - 1;
	}
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	temp->next->data = data;
	return 1;
}

int DoubleLinkListGetData(DoubleLinkList* list, int position) {
	DoubleLinkList* temp = list;
	if (position > list->size - 1) {
		return 0;
	}
	if (position == -1)
	{
		position = list->size - 1;
	}
	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	return temp->next->data;
}

int main() {
	system("chcp 65001");
	DoubleLinkList list;
	initDoubleLinkList(&list);
	for (int i = 0; i < 20; i++)
	{
		DoubleLinkListInsert(&list, i, i);
	}
	DoubleListForEach(&list);
	for (int i = 0; i < 10; i++)
	{
		DoubleLinkListDelete(&list, 0);
	}
	printf("删除前十个元素后:\n");
	DoubleListForEach(&list);
	DoubleLinkListUpdate(&list, 100, 0);
	printf("修改第一个元素后:\n");
	DoubleListForEach(&list);
	printf("获取到第一个元素：%d\n",DoubleLinkListGetData(&list,0));
}