#ifndef USER_H
#define USER_H
#include <stdint.h>
#include <pthread.h>

#include "queue.h"

enum brushtype { B_ELLIPSE, B_SQUARE, B_TRIANGLE };

struct user
{
	int id;

	int socket;
	const char *host;
	int port;
	long int lastping;

	enum brushtype brush;
	int brushsize[2];
	int selection[3];
	uint32_t deco;

	struct queue;
	pthread_mutex_t antiread, antiwrite;
};

#endif
