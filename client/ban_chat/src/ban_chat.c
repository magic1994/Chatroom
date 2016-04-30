#include "../../include/my_head.h"

void ban_chat(int new_fd)
{
    int ch;
    int flag = 1;
    char str[100];

    Node msg;

    char *wday1[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    
    memset(str, 0, sizeof(str[100]));

    memset(&msg, 0, sizeof(Node));
    msg.action = BAN_CHAT;
    msg.online_sfd = msg1.online_sfd;
    msg.state = msg1.state;
    my_strcpy(msg.id, msg1.id);
    my_strcpy(msg.name, msg1.name);
    my_strcpy(msg.password, msg1.password);

    curs_set(1);

    mvwaddstr(ch_window3, 1, 4, "TO      :");
    mvwaddstr(ch_window3, 3, 1, "=>禁言       解禁");
    wmove(ch_window3, 1, 14);
    wrefresh(ch_window3);

    echo();
    wscanw(ch_window3, "%s", msg.target_user);
    
    wmove(ch_window3, 2, 14);
    wrefresh(ch_window3);
    
    keypad(ch_window3,true);

    cbreak();

    curs_set(0);
    noecho();

        while((ch = wgetch(ch_window3)) != '\n')
	{
	    if(ch == KEY_RIGHT)
	    {
		mvwaddstr(ch_window3, 3, flag, "  ");

	        if(flag == 12)
		{
		    flag = 1;
		}
		else
		{
                    flag = 12;
		}

		mvwaddstr(ch_window3, 3, flag, "=>");
	    }
	    if(ch == KEY_LEFT)
	    {
		mvwaddstr(ch_window3, 3, flag, "  ");
                 
	        if(flag == 1)
		{
		    flag = 12;
		}
		else
		{
                    flag = 1;
		}

		mvwaddstr(ch_window3, 3, flag, "=>");
	        
	    }

	    wrefresh(ch_window3);
	}

	switch(flag)
	{
	    case 1:
	    {
                msg.online_sfd = 2;
                break;
	    }
	    case 12:
	    {
                msg.online_sfd = 1;
         break;
	    }
	}
    sprintf(msg.message, "(%d/%d/%d %s %d:%d:%d)", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday, wday1[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
    if(msg.online_sfd == 1)
    {
        wprintw(ch_window2, "我 将 %s 解除禁言%s\n", msg.target_user, msg.message);
    }
    else
    {
        wprintw(ch_window2, "我 将 %s 禁言%s\n", msg.target_user, msg.message);
    }
    wrefresh(ch_window2);

    write(new_fd, &msg, sizeof(Node));

    mvwaddstr(ch_window3, 1, 4, "                                                                  ");
    mvwaddstr(ch_window3, 2, 4, "                                                                  ");
    mvwaddstr(ch_window3, 3, 1, "                                                                  ");
    mvwaddstr(ch_window3, 4, 1, "                                                                  ");
    wrefresh(ch_window3);
}
