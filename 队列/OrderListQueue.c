/*
	顺序队
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct OrderListQueues{
	int* datas;
	int maxsize;
	int size;
}OrderListQueue;

/// <summary>
/// 顺序表扩容，扩容为原来内容的两倍
/// </summary>
/// <param name="list"></param>
void OrderListQueueExpansion(OrderListQueue* queue) {
	int* new_data = malloc(2 * queue->maxsize * sizeof(int));
	if (!new_data)
	{
		printf("申请内存失败\n");
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		new_data[i] = queue->datas[i];
	}
	free(queue->datas);
	queue->datas = new_data;
	queue->maxsize = 2 * queue->maxsize;
	printf("顺序表已扩容，扩容后大小 ==》 %d\n", queue->maxsize);
}

/// <summary>
/// 初始化顺序队
/// </summary>
/// <param name="queue"></param>
/// <param name="maxsize"></param>
void initOrderListQueue(OrderListQueue* queue,int maxsize) {
	queue->datas = (int*)malloc(maxsize * sizeof(int));
	queue->maxsize = maxsize;
	queue->size = 0;
}

/// <summary>
/// 顺序队入队，从顺序表尾部插入
/// </summary>
/// <param name="queue"></param>
/// <param name="data"></param>
/// <returns></returns>
int OrderListQueuePush(OrderListQueue* queue, int data) {
	// 检查扩容
	if (queue->size == queue->maxsize) {
		OrderListQueueExpansion(queue);
	}
	queue->datas[queue->size] = data;
	queue->size++;
	return 1;
}

/// <summary>
/// 顺序队出队
/// </summary>
/// <param name="queue"></param>
/// <returns></returns>
int OrderListQueuePop(OrderListQueue* queue) {
	if (queue->size == 0)
	{
		return -1;
	}
	int data = queue->datas[0];
	for (int i = 0; i < queue->size-2; i++)
	{
		queue->datas[i] = queue->datas[i + 1];
	}
	queue->size--;
	return data;
}


void OrderListQueueForEach(OrderListQueue* queue) {
	for (int i = 0; i < queue->size-1; i++)
	{
		printf("%d ");
	}printf("\n");
}