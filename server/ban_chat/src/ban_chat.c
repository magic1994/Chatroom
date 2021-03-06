#include "../../include/my_head.h"

int ban_chat_callback(void *para, int columncount, char **columnvalue, char **columnname)
{
    Link msg = (Link )para;
    msg->action = SUCCESS_BAN_CHAT;

    return 0;
}

void ban_chat(Link msg, int new_fd)
{
    char sql[1024];
    char *errmsg;
    
    sqlite3 *db;

    msg->action = FAILED_NOBODY;

    sqlite3_open("users.db", &db);
    sprintf(sql, "select name,answer,state from user where name='%s'", msg->target_user);

    sqlite3_exec(db, sql, ban_chat_callback, msg, &errmsg);

    if(msg->action == SUCCESS_BAN_CHAT)
    {
        memset(sql, 0, sizeof(sql));

        sprintf(sql, "update user set state='%d' where name='%s'", msg->online_sfd, msg->target_user);

        sqlite3_exec(db, sql, NULL, NULL, &errmsg);

        int target_sfd = link_search_name(msg);

        write(target_sfd, msg, sizeof(Node));

        Link p = online_user->next;

        msg->action = BAN_CHAT;

    while(p != NULL)
    {
        if(my_strcmp(p->name, msg->target_user) != 0)
	{
	    printf("%s\n",p->name);
            write(p->online_sfd, msg, sizeof(Node));
        }
	p = p->next;
    }
     }
    else
    {
        write(new_fd, msg, sizeof(Node));
    }
    sleep(1);

    sqlite3_close(db);
}
