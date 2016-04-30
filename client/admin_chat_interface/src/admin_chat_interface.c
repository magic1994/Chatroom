#include "../../include/my_head.h"

void admin_chat_interface(int new_fd)
{
    clear();
    refresh();
    
    int flag = 3;

    int ch;

    WINDOW *new_window1, *new_window2, *new_window5;

    setlocale(LC_ALL, "");
    //initscr();

    //keypad(ch_window4, 1);

    new_window1 = newwin(3, 91,0,22);
    ch_window2 = newwin(13, 68,4,23);
    new_window5 = newwin(15, 70,3,22);
    ch_window3 = newwin(6, 70,18,22);
    ch_window4 = newwin(21, 21,3,92);
    ch_window5 = newwin(6, 20,0,2);
    ch_window1 = newwin(18, 20,6,2);

    box(new_window1, 0, 0);
    box(ch_window4, 0, 0);
    box(ch_window5, 0, 0);
    box(new_window5, 0, 0);
    box(ch_window1, 0, 0);
    box(ch_window2, ' ', ' ');
    box(ch_window3, 0, 0);

    mvwaddstr(ch_window1, 1, 5, "ONLINE-USER");
    mvwaddstr(ch_window1, 2, 5, "===========");

    mvwaddstr(ch_window5, 2, 7, msg1.name);
    mvwaddstr(ch_window5, 3, 6, msg1.id);
    
    mvwaddstr(ch_window4, 1, 6, "FUNCTION");
    mvwaddstr(ch_window4, 2, 5, "===========");
    mvwaddstr(ch_window4, 3, 5, "私聊");
    mvwaddstr(ch_window4, 4, 5, "群聊");
    mvwaddstr(ch_window4, 5, 5, "发送表情");
    mvwaddstr(ch_window4, 6, 5, "查看聊天记录");
    mvwaddstr(ch_window4, 7, 5, "删除聊天记录");
    mvwaddstr(ch_window4, 8, 5, "发送文件");
    mvwaddstr(ch_window4, 9, 5, "修改昵称");
    mvwaddstr(ch_window4, 10, 5, "修改密码");
    mvwaddstr(ch_window4, 11, 5, "切换用户");
    mvwaddstr(ch_window4, 13, 3, "ADMIN-FUNCTION");
    mvwaddstr(ch_window4, 14, 5, "===========");
    mvwaddstr(ch_window4, 15, 5, "禁言");
    mvwaddstr(ch_window4, 16, 5, "封号");

    wrefresh(new_window1);
    wrefresh(ch_window3);
    wrefresh(ch_window5);
    wrefresh(new_window5);
    wrefresh(ch_window1);
    wrefresh(ch_window2);
    wrefresh(ch_window4);
 
    mvwaddstr(ch_window4, flag, 3, "=>");
    wrefresh(ch_window4);

    keypad(ch_window4,true);

    cbreak();

    while(1)
    {
        if(filesend == FILE_SEND)
	{
	    file_receive(new_fd);

	    filesend = 0;
	}

        curs_set(0);
        
        /*mvwaddstr(ch_window4, flag, 3, "  ");
	
	flag = 3;

        mvwaddstr(ch_window4, flag, 3, "=>");
	wrefresh(ch_window4);*/

        noecho();
        while((ch = wgetch(ch_window4)) != '\n')
	{
	    if(ch == KEY_UP)
	    {
		mvwaddstr(ch_window4, flag, 3, "  ");

	        if(flag == 3)
		{
		    flag = 16;
		}
		else if(flag == 15)
                {
                    flag = 11;
                }
                else
		{
		    flag--;
		}

		mvwaddstr(ch_window4, flag, 3, "=>");
	    }
	    if(ch == KEY_DOWN)
	    {
		mvwaddstr(ch_window4, flag, 3, "  ");
                 
	        if(flag == 11)
		{
		    flag = 15;
		}
		else if(flag == 16)
                {
                    flag = 3;
                }
                else
		{
		    flag++;
		}

		mvwaddstr(ch_window4, flag, 3, "=>");
	        
	    }

	    wrefresh(ch_window4);
	}

	switch(flag)
	{
	    case 3:
	    {
	        private_chat(new_fd);
                break;
	    }
	    case 4:
	    {
	        group_chat(new_fd);
	        break;
	    }
	    case 5:
	    {   
	        send_face(new_fd);
	        break;
	    }
	    case 6:
	    {
	        check_history(new_fd);
	        break;
	    }
	    case 7:
	    {
	        delete_history(new_fd);
	        break;
	    }
	    case 8:
	    {
	        file_send(new_fd);
	        break;
	    }
	    case 9:
	    {
	        change_name(new_fd);
	        break;
	    }
	    case 10:
	    {
 
	        change_password(new_fd);

    box(new_window1, 0, 0);
    box(ch_window4, 0, 0);
    box(ch_window5, 0, 0);
    box(new_window5, 0, 0);
    box(ch_window1, 0, 0);
    box(ch_window2, ' ', ' ');
    box(ch_window3, 0, 0);

    mvwaddstr(ch_window1, 1, 5, "ONLINE-USER");
    mvwaddstr(ch_window1, 2, 5, "===========");

    mvwaddstr(ch_window5, 2, 7, msg1.name);
    mvwaddstr(ch_window5, 3, 6, msg1.id);
    
    mvwaddstr(ch_window4, 1, 6, "FUNCTION");
    mvwaddstr(ch_window4, 2, 5, "===========");
    mvwaddstr(ch_window4, 3, 5, "私聊");
    mvwaddstr(ch_window4, 4, 5, "群聊");
    mvwaddstr(ch_window4, 5, 5, "发送表情");
    mvwaddstr(ch_window4, 6, 5, "查看聊天记录");
    mvwaddstr(ch_window4, 7, 5, "删除聊天记录");
    mvwaddstr(ch_window4, 8, 5, "发送文件");
    mvwaddstr(ch_window4, 9, 5, "修改昵称");
    mvwaddstr(ch_window4, 10, 5, "修改密码");
    mvwaddstr(ch_window4, 11, 5, "切换用户");
    mvwaddstr(ch_window4, 13, 3, "ADMIN-FUNCTION");
    mvwaddstr(ch_window4, 14, 5, "===========");
    mvwaddstr(ch_window4, 15, 5, "禁言");
    mvwaddstr(ch_window4, 16, 5, "封号");


    wrefresh(new_window1);
    wrefresh(ch_window3);
    wrefresh(ch_window5);
    wrefresh(new_window5);
    wrefresh(ch_window1);
    wrefresh(ch_window2);
    wrefresh(ch_window4);
 
    mvwaddstr(ch_window4, flag, 3, "=>");
    wrefresh(ch_window4);


                     break;

	    }
	    case 11:
	    {
                clear();
                refresh();
                new_window2 = newwin(13, 50, 5, 30);
                box(new_window2, 0, 0);
                mvwaddstr(new_window2, 3, 22, "GOODBYE");
                mvwaddstr(new_window2, 5, 22, msg1.name);
		wrefresh(new_window2);

		msg1.action = QUIT;
		write(new_fd, &msg1, sizeof(Node));

	        goto EXIT_CHATINTERFACE;
	        break;
	    }
	    case 15:
	    {   
	        ban_chat(new_fd);
	        break;
	    }
	    case 16:
	    {   
	        //ban_user(new_fd);
	        break;
	    }
	}
    }

    EXIT_CHATINTERFACE:

    curs_set(1);
    wgetch(new_window1);

}
