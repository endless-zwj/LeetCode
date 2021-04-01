#define _CRT_SECURE_NO_WARNINGS

typedef struct Stack
{
	int _top;
	int* _array;
}Stack;

typedef struct {
	Stack* st_in;
	Stack* st_out;
} MyQueue;

int myQueuePeek(MyQueue* obj);