#ifndef QUEUE_H
#define QUEUE_H
#include <pthread.h>

struct queue_element
{
	void *data;
	size_t length;
	struct queue_element *next;
};

struct queue
{
	struct queue_element *head, *tail;
	pthread_mutex_t mutex;
};

#endif
