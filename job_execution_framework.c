/*
	framework
		listen events
			register callback ( fn(void*, size))
		parse
			&
			execute the event (non blocking)
n events (max)
*/




#include<stdio.h>
#include<fcntl.h>
#include<linux/socket.h>

#define NOT_REGISTERED 	-1
#define REGISTERED 		1
#define MAX_EVENTS 		32
#define MAX_ARG_SIZE 	255

enum event {OPEN, CLOSE, READ, WRITE, TEST};


typedef struct callback {
	int event;
	void (*fn)(void*);
	struct callback *next;
	
}callback_t;

callback_t * head_callback_t;

int register_callback( int event, void (*fn)(void *) );

int execute_callback(int event);
int check_callback (int event);

int fn_open(void*);
int fn_close(void*);
int fn_read(void*);
int fn_write(void*);

int main () {
		
		int fd=0;
		int listen_fd=0;
		int events=0;
		int count=0;
		head_callback_t=NULL;
		
		/* unix domain socket*/
		/* stub code create_socket_and_bind */
		fd=create_socket_and_bind();
		
		
		while (1) {
			listen_fd=listen(fd,IO_NOBLOCK);
			accept(listen_fd);
			/* stub code read_event */			
			if (read_event(listen_fd, events, sizeof(int)) <0) {
				return -1;			
			}
			/* stub code read_args */
			if (read_args(listen_fd, args, sizeof(int*MAX_ARG_SIZE)<0)) {
				return -1;
			}
			events++;
			if (events>MAX_EVENTS) {
				
				return 0;
			}
			
			switch (events) {
				
				case OPEN:
					if (check_callback(OPEN)==NOT_REGISTERED) {
						
						register_callback(OPEN,&fn_open);
					} else {
						execute_callback(OPEN,args);
						
					}
									
				break;
				
				case CLOSE:
					if (check_callback(CLOSE)==NOT_REGISTERED) {
						register_callback(CLOSE,&fn_close);
					} else {
						execute_callback(CLOSE,args);
					}
				break;
				
				case WRITE:
					if (check_callback(WRITE)==NOT_REGISTERED) {
						register_callback(WRITE,&fn_write);
					} else {
						execute_callback(WRITE,args);
					}
				break;
				
				case READ:
					if (check_callback(READ)==NOT_REGISTERED) {
						register_callback(READ,&fn_read);
					} else {
						execute_callback(READ,args);
					}
				break;
				
				case 
				default:
				break;			
				
			};
			
		
		}
	
	return 0;
}


int fn_open(void *) {
	printf("open\n");
	return 0;
}

int fn_read(void *) {
	printf("read\n");
/* Use non blocking read */
	return 0;
}

int fn_write(void *) {
	printf("write\n");
/* use non blocking write */	
	return 0;
}

int fn_close(void *) {
	printf("close\n");
	return 0;
}

/* Registering callback to linked list */

int register_callback( int event, void (fn*)(void *) ) {
	
		callback_t *reg_callback=NULL;
		callback_t *tail_callback=NULL;
		
		if (head_callback_t==NULL) {
			reg_callback=(callback_t*)malloc(sizeof(callback_t));
			reg_callback->event=event;
			reg_callback->f=fn;
			reg_callback->next=NULL;
			return 0;			
		} else {
			
			reg_callback=(callback_t*)malloc(sizeof(callback_t));
			reg_callback->event=event;
			reg_callback->f=fn;
			reg_callback->next=NULL;
			
			tail_callback=head_callback_t;
			
			while(tail_callback->next!=NULL) {
				tail_callback=tail_callback->next;				
			}
			tail_callback=reg_callback;
			
			
		}
		return 0;	
	
}

/* execute the registered function */

int execute_callback(int event, void *args) {
	
	callback_t *reg_callback=NULL;
	
	reg_callback=head_callback_t;
	
	if (reg_callback==NULL) {
		return -1;
	}
	
	while(reg_callback->next!=NULL) {
		if (reg_callback->event==event) {
			reg_callback->fn((void*)args);
			return 0;
		} 
		reg_callback=reg_callback->next;		
	}
	return -1;
	
}


int check_callback (int event) {
	callback_t *reg_callback=NULL;
	
	reg_callback=head_callback_t;
	
	while(reg_callback->next!=NULL) {
		if (reg_callback->event==event) {
			return REGISTERED;
		} 
		reg_callback=reg_callback->next;		
	}
	return NOT_REGISTERED;
	
}






					 

					

								
								
