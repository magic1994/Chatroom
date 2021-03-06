#include "../../include/my_head.h"

void handle_client(void * arg)
{
    int new_fd = *((int *)arg);

    Node msg;

    memset(&msg, 0, sizeof(Node));
    
    //printf("aa\n");
    
    while(1)
    {
        memset(&msg, 0, sizeof(Node));

        if(read(new_fd, &msg, sizeof(Node)) == 0)
	{
	    printf("%d quit\n", new_fd);
	    break;
        }
        
	//printf("aaaaa\n");
	/*printf("%d %d %s\n",msg.action, msg.id, msg.message);
	msg.action = 8;
	write(new_fd, &msg, sizeof(Node));
	break;*/

	switch(msg.action)
	{
	    case REGISTER:
	    {
	        
		my_register(&msg, new_fd);

		break;
	    }
	    case LOG:
	    {
	        //printf("aaa\n");
	        my_log(&msg, new_fd);

		user_function(new_fd, &msg);

	        break;
	    }
	    case FORGET_PASSWORD:
	    {
	        //printf("aaa\n");
	        forget_password(&msg, new_fd);

	        break;
	    }
	    case QUIT:
	    {
	        printf("%d quit\n", new_fd);
	        
		goto EXIT_THREAD;

	        break;
	    }
	    default:
	    {
	        msg.action = WRONG_INPUT;

	        write(new_fd, &msg, sizeof(Node));

	    }
	}
    }

    EXIT_THREAD:
    close(new_fd);
}
