#include "../../include/my_head.h"

//int filesend = 0;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage:./client ip \n");
	exit(1);
    }

    int new_fd = tcp_connect(argv[1], portnumber);

    memset(&msg1, 0, sizeof(Node));
    memset(&msg2, 0, sizeof(Node));

    my_menu1(new_fd);

    /*msg1.action = LOG;
    my_strcpy(msg1.id, "00000000");
    my_strcpy(msg1.password, "123456");
    write(new_fd, &msg1, sizeof(Node));
    read(new_fd, &msg1, sizeof(Node));
    if(msg1.action == SUCCESS_ADMIN)
    {
        printf("success\n");
    }
    printf("%s %s %s %s\n",msg1.id,msg1.name,msg1.password, msg1.answer);

    //pthread_create(&ser_thread, NULL, handle_server,&new_fd);*/

    close(new_fd);

    return 0;
}
