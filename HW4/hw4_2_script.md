## HW4_2

### KeyBuffer operations
#### IsEmpty()
- buffer가 비어있으면 1을 반환하고, 아니면 0을 반환.
```c
int IsEmpty(KeyBuffer *buffer)
{
	if(buffer->in == buffer->out)
		return 1;
	return 0;
}
```

#### IsFull()
- buffer가 꽉 차있으면 1을 반환하고, 아니면 0을 반환.
```c
int IsFull(KeyBuffer *buffer)
{
	if(((buffer->in)+1)%buffer->size == buffer->out)
		return 1;
	return 0;
}
```

#### InsertKey()
- key를 버퍼에 넣음.
- buffer가 꽉 차있으면 아무것도 안함.
```c
void InsertKey(KeyBuffer *buffer, int key)
{
        while(IsFull(buffer));
        buffer->buffer[buffer->in] = key;
        buffer->in = ((buffer->in)+1)%buffer->size;
}
```

#### DeleteKey()
- buffer에서 key를 삭제하고 삭제된 key를 반환.
- buffer가 비었으면 0을 반환.
```c
int DeleteKey(KeyBuffer *buffer)
{
	int key;
	if(!IsEmpty(buffer)) {
		key = buffer->buffer[buffer->out];
		buffer->out = ((buffer->out)+1)%buffer->size;
    return key;
	}
  return 0;
}
```
