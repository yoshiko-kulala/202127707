// キューのプログラム本体を作成せよ


#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int QueueAlloc(Queue *q, int max) {
  if ((q->que = calloc(max, sizeof(int))) == NULL) {
    q->max = 0;
    return -1;
  }
  q->max = max;
  q->front = 0;
  q->rear = 0;
  q->num = 0;
  return 0;
}

void QueueFree(Queue *q){
	if(q->que != NULL)free(q->que);
}

int QueueEnqueue(Queue *q, int x){
  //バッファがいっぱいかどうかに留意すること
  if(q->num >= q->max)return -1;
  else{
  	if(q->front>=q->max)q->front=0;
  	q->que[q->front]=x;
  	q->front++;
  }

  q->num++;
  return 0;
}

int QueueDequeu(Queue *q, int *x){
  // バッファがからでないかを留意すること
  if(q->num < 0)return -1;
  else{
  	if(q->rear<0)q->rear=q->max-1;
  	*x=q->que[q->rear];
  	q->rear++;
    q->num--;
  }
  return 0;
}

int QueueSize(const Queue *q){
	return q->max;
}

int QueueNo(const Queue *q){
	return q->num;
}

int QueueIsEmpty(const Queue *q){
	return (q->num<=0);
}

int QueueIsFull(const Queue *q){
	return (q->num>=q->max);
}