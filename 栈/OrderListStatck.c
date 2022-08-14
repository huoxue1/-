/*
	顺序栈
	先进后出
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct OrderListStacks {
	int* datas;
	int maxsize;
	int size;
}OrderListStack;

/// <summary>
/// 顺序栈扩容，扩容为原来内容的两倍
/// </summary>
/// <param name="list"></param>
void OrderListStackExpansion(OrderListStack* stack) {
	int* new_data = malloc(2 * stack->maxsize * sizeof(int));
	if (!new_data)
	{
		printf("申请内存失败\n");
		return;
	}
	for (int i = 0; i < stack->size; i++)
	{
		new_data[i] = stack->datas[i];
	}
	free(stack->datas);
	stack->datas = new_data;
	stack->maxsize = 2 * stack->maxsize;
	printf("顺序栈已扩容，扩容后大小 ==》 %d\n", stack->maxsize);
}

/// <summary>
/// 初始化顺序栈
/// </summary>
/// <param name="queue"></param>
/// <param name="maxsize"></param>
void initOrderListStack(OrderListStack* stack, int maxsize) {
	stack->datas = (int*)malloc(maxsize * sizeof(int));
	stack->maxsize = maxsize;
	stack->size = 0;
}

/// <summary>
/// 顺序栈入栈，从顺序栈尾部插入
/// </summary>
/// <param name="queue"></param>
/// <param name="data"></param>
/// <returns></returns>
int OrderListStackPush(OrderListStack* stack, int data) {
	// 检查扩容
	if (stack->size == stack->maxsize) {
		OrderListQueueExpansion(stack);
	}
	stack->datas[stack->size] = data;
	stack->size++;
	return 1;
}


/// <summary>
/// 顺序栈入栈，从顺序栈尾部插入
/// </summary>
/// <param name="queue"></param>
/// <param name="data"></param>
/// <returns></returns>
int OrderListStackPop(OrderListStack* stack) {
	if (stack->size == 0) {
		return -1;
	}
	int data = stack->datas[stack->size - 1];
	stack->datas[stack->size - 1] = 0;
	stack->size--;
	return data;
}

void OrderListStackForEach(OrderListStack* stack) {
	for (int i = 0; i < stack->size - 1; i++)
	{
		printf("%d ", stack->datas[i]);
	}printf("\n");
}


int main4() {
	OrderListStack statck;
	initOrderListQueue(&statck,10);

	for (int i = 0; i < 10; i++)
	{
		OrderListStackPush(&statck, i);
	}
	OrderListStackForEach(&statck);
	for (int i = 0; i < 5; i++)
	{
		printf("出栈结果：%d\n", OrderListStackPop(&statck));
	}
	OrderListStackForEach(&statck);
}