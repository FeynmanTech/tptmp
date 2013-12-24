#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void queue_init(struct queue *q)
{
	q->head = NULL;
	q->tail = NULL;
	pthread_mutex_init(&q->mutex, NULL);
}

void queue_send(struct queue *q, const void *data, size_t length)
{
	void *d = malloc(length);
	memcpy(d, data, length);
	struct queue_element *qe = malloc(sizeof(struct queue_element));
	qe->data = d;
	qe->length = length;
	qe->next = NULL;
	pthread_mutex_lock(&q->mutex);
		if(q->head)
			q->tail->next = qe;
		else
			q->head = qe;
		q->tail = qe;
	pthread_mutex_unlock(&q->mutex);
}

struct queue_element queue_receive(struct queue *q)
{
	struct queue_element qe;
	qe.data = NULL;
	qe.length = 0;
	pthread_mutex_lock(&q->mutex);
		if(q->head)
		{
			qe = *(q->head);
			if(q->tail == q->head)
				q->tail = NULL;
			q->head = qe.next;
		}
	pthread_mutex_unlock(&q->mutex);
	qe.next = NULL;
	return qe;
}

void queue_free_element(struct queue_element qe)
{
	free(qe.data);
}

void queue_destroy(struct queue *q)
{
	pthread_mutex_lock(&q->mutex);
		struct queue_element *qe = q->head;
		while(qe)
		{
			queue_free_element(*qe);
			qe = qe->next;
		}
	pthread_mutex_unlock(&q->mutex);
	pthread_mutex_destroy(&q->mutex);
}
