#include "../../include/my_head.h"

int ch_psd_callback(void *para, int columncount, char **columnvalue, char **columnname)
{
    Link msg = (Link )para;
    msg->action = SUCCESS_CHANGE_PSD;

    return 0;
}

void change_password(Link msg, int new_fd)
{
    char sql[1024];
    char *errmsg;
    
    sqlite3 *db;

    msg->action = FAILED_CHANGE_PSD;

    sqlite3_open("users.db", &db);
    sprintf(sql, "select name,answer,state from user where id='%s' and password='%s'", msg->id, msg->password);

    sqlite3_exec(db, sql, ch_psd_callback, msg, &errmsg);

    if(msg->action == SUCCESS_CHANGE_PSD)
    {
        memset(sql, 0, sizeof(sql));

        sprintf(sql, "update user set password='%s' where id='%s'", msg->target_user, msg->id);

        sqlite3_exec(db, sql, NULL, NULL, &errmsg);
     }

    sleep(1);

    write(new_fd, msg, sizeof(Node));

    sqlite3_close(db);
}
