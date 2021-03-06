#include <stdio.h>

#include "Console.h"
#include "KeyBuffer.h"

#define TRUE 1
#define FALSE 0

void InitKeyBuffer(KeyBuffer *buffer)
{
	buffer->in = buffer->out = 0;
	buffer->size = BUFFER_SIZE;
}

int IsEmpty(KeyBuffer *buffer)
{
	if(buffer->in == buffer->out)
		return 1;
	return 0;
}

int IsFull(KeyBuffer *buffer)
{
	if(((buffer->in)+1)%buffer->size == buffer->out)
		return 1;
	return 0;
}

void InsertKey(KeyBuffer *buffer, int key)
{
	if(!IsFull(buffer)) {
		buffer->buffer[buffer->in] = key;
		buffer->in = ((buffer->in)+1)%buffer->size;
	}
}

int DeleteKey(KeyBuffer *buffer)
{
	int key;
	if(!IsEmpty(buffer)) {
		key = buffer->buffer[buffer->out];
		buffer->out = ((buffer->out)+1)%buffer->size;
	}
	return key;
}

int GetKey(KeyBuffer *buffer, int idx)
{
	return buffer->buffer[idx];
}


void DisplayKeyBuffer(int x, int y, KeyBuffer *buffer)
{
	gotoxy(x, y);

	printf("Key Buffer = [");
	for(int i = buffer->out; i != buffer->in; i = (i + 1) % buffer->size)
		printf("%c", GetKey(buffer, i));

	printf("] ");
}

