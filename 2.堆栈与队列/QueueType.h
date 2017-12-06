# define MAX 100
typedef struct
{ ElemType  queue[MAX];
  int front;                // 队头指针
int count;               // 计数器
        }QueueType;

void InitQueue_Type(QueueType &Q){
	if(!Q.queue) exit(1);
	Q.front=0;
	Q.count=0;
}

bool QueueEmpty_Sq(QueueType Q){
	//队空返回true，非空返回false 
	return Q.count==0; 
}

bool EnQueue_Type(QueueType &Q,ElemType e){
	if(Q.count>=MAX)
		return false;
	int rear=(Q.front+Q.count)%MAX;
	Q.queue[rear]=e;
	Q.count++;
	return true;
}

bool DeQueue_Type(QueueType &Q,ElemType &e){
	if(Q.count==0)
		return false;
	e=Q.queue[Q.front];
	Q.front=(Q.front+1)%MAX;
	Q.count--;
	return true;
}

ElemType GetHead_Type(QueueType Q){
	if(Q.count==0)
		return false;
	return Q.queue[Q.front];
}

