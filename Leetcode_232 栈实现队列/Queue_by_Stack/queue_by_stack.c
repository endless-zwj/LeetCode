#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>

#include"text.h"



Stack* CreateStack(int capacity)
{
	Stack* st = (Stack*)malloc(sizeof(Stack));
	st->_array = (int*)malloc(sizeof(int) * capacity);
	st->_top = 0;
	return st;
}

void PushStack(Stack* st, int val)
{
	assert(st);

	st->_array[st->_top++] = val;
}

void PopStack(Stack* st)
{
	assert(st);
	st->_top--;
}
bool IsEmpty(Stack* st)
{
	return st->_top == 0 ? true : false;
}

int StackPeek(Stack* st)
{
	return st->_array[st->_top - 1];
}




/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* myqueue = (MyQueue*)malloc(sizeof(MyQueue));

	myqueue ->st_in =  CreateStack(100);
	myqueue->st_out  =  CreateStack(100);

	return myqueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	//定义栈1入数据
	PushStack( obj->st_in, x);
}

void Remove(MyQueue* obj)
{
	while ( ! IsEmpty(obj -> st_in))
	{
		PushStack(obj->st_out , StackPeek(obj->st_in));
		PopStack(obj->st_in);
	}
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (IsEmpty((obj->st_out)))
	{
		Remove(obj);
	}
		int ret = myQueuePeek(obj);
		PopStack(obj->st_out);
		return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (IsEmpty((obj->st_out)))
	{
		Remove(obj);
	}
	return (obj->st_out)->_array[(obj->st_out)->_top - 1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return IsEmpty(obj->st_in) && IsEmpty(obj->st_out);
}

void myQueueFree(MyQueue* obj) 
{
	free(obj->st_in);
	free(obj->st_out);	
	free(obj);
	obj = NULL;
}

int main()
{
	
	MyQueue* obj =  myQueueCreate();
	printf("\n");
	myQueuePush(obj, 10);
	printf("%d ", myQueuePeek(obj));
	myQueuePush(obj, 25);
	printf("%d ", myQueuePeek(obj));
	myQueuePop(obj);
	printf("%d ", myQueuePeek(obj));
	return 0;
}