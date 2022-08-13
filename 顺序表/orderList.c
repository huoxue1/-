#include<stdio.h>
#include<stdlib.h>



typedef struct OrderLists {
	int *datas;
	int maxsize;
	int size;

}OrderList;

void expansion(OrderList* list);

void initOrderList(OrderList* list,int maxsize) {
	list->datas = (int*)malloc(maxsize * sizeof(int));
	list->maxsize = maxsize;
	list->size = 0;
}


/// <summary>
/// 顺序表插入数据
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="position"></param>
/// <returns></returns>
int OrderListInsert(OrderList *list,int data,int position) {
	if (list->size == list->maxsize) {
		expansion(list);
	}
	if (position == -1) {
		list->datas[list->size] = data;
		list->size++;
		return 0;
	}
	for (int i = list->size - 1; i >= position; i--)
	{
		list->datas[i + 1] = list->datas[i];
	}
	list->datas[position] = data;
	list->size++;
	return 0;
}

/// <summary>
/// 顺序表扩容，扩容为原来内容的两倍
/// </summary>
/// <param name="list"></param>
void expansion(OrderList *list) {
	int* new_data = malloc(2 * list->maxsize * sizeof(int));
	if (!new_data)
	{
		printf("申请内存失败\n");
		return;
	}
	for (int i = 0; i < list->size; i++)
	{
		new_data[i] = list->datas[i];
	}
	free(list->datas);
	list->datas = new_data;
	list->maxsize = 2 * list->maxsize;
	printf("顺序表已扩容，扩容后大小 ==》 %d\n", list->maxsize);
}

/// <summary>
/// 更新某个位置的数据
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="position"></param>
/// <returns></returns>
int OrderUpdate(OrderList* list, int data, int position) {
	if (position > list->size-1) {
		return 0;
	}
	list->datas[position] = data;
	return 1;
}

/// <summary>
/// 遍历顺序表
/// </summary>
/// <param name="list"></param>
void OderForEach(OrderList* list) {
	for (int i = 0; i < list->size; i++)
	{
		printf("%d ", list->datas[i]);
	}
}

/// <summary>
/// 获取某个位置的数据
/// </summary>
/// <param name="list"></param>
/// <param name="position"></param>
/// <returns></returns>
int OderGetData(OrderList* list, int position) {
	if (position > list->size - 1) {
		return -1;
	}
	else
	{
		return list->datas[position];
	}
}

int OrderDelete(OrderList* list,int position) {
	if (position > list->size - 1) {
		return 0;
	}
	for (int i = position; i <= list->size-2; i++)
	{
		list->datas[i] = list->datas[i+1];
	}
	list->size--;
}

int main() {
	OrderList list;
	initOrderList(&list,10);
	for (int i = 0; i < 40; i++)
	{
		OrderListInsert(&list, i+1, i);
	}
	OderForEach(&list);
	for (int i = 0; i < 20; i++)
	{
		OrderDelete(&list, 0);
	}
	printf("\n删除前20个元素\n");
	OderForEach(&list);
	return 0;
}
