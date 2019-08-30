#include <gtk/gtk.h>
#include <stdio.h>
#include<string.h>
// #include "setting.h"

GtkWidget *userinfo_window;
GtkWidget *online_state_window;
GtkWidget *background_window;
GtkWidget *alter_password_window;

char* USERINFO = "修改个人信息";
char* ONLINE_STATE = "修改在线状态";
char* BACKGROUND = "修改聊天背景";
char* ALTER_PASSWORD = "修改密码";

static void menuitem_response(gchar *string)
{

    printf("%s\n",string);
    
    if(strcmp(string, USERINFO) == 0){
        userinfo_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(userinfo_window),"修改个人信息");
        gtk_window_set_position(GTK_WINDOW(userinfo_window), GTK_WIN_POS_MOUSE);
        gtk_widget_show(userinfo_window);
    }
    else if(strcmp(string, ONLINE_STATE) == 0){
        online_state_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(online_state_window),"修改在线状态");
        gtk_window_set_position(GTK_WINDOW(online_state_window), GTK_WIN_POS_MOUSE);
        gtk_widget_show(online_state_window);
    }
    else if(strcmp(string, BACKGROUND) == 0){
        background_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(background_window),"修改聊天背景");
        gtk_window_set_position(GTK_WINDOW(background_window), GTK_WIN_POS_MOUSE);
        gtk_widget_show(background_window);
    }
    else if(strcmp(string, ALTER_PASSWORD) == 0){
        alter_password_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(alter_password_window),"修改密码");
        gtk_window_set_position(GTK_WINDOW(alter_password_window), GTK_WIN_POS_MOUSE);
        gtk_widget_show(alter_password_window);
    }
    
}
 
static int button_press(GtkWidget *widget,GdkEvent *event)
{
    if(event->type == GDK_BUTTON_PRESS){
        GdkEventButton *bevent = (GdkEventButton *)event;
        gtk_menu_popup(GTK_MENU(widget),NULL,NULL,NULL,NULL,bevent->button,bevent->time);
        /*告诉调用代码我们已经处理这个事件，*/
        return TRUE;
    }
    /*else  未处理*/
    return FALSE;
}
 
void setting_menu(GtkWidget* window, GtkWidget* button)
{
    /* GtkWidget 是构件的存储类型 */
    GtkWidget *menu;
    GtkWidget *menu_bar;
    GtkWidget *root_menu;
    GtkWidget *menu_items;
    GtkWidget *vbox;
    GtkWidget *image;
    GtkWidget *table;
    char buf[128];
    int i;
    

    /***********************
     * 初始化菜单构件
     * 记住这里永远不要用gtk_widget_show()函数来显示菜单控件
     * 这个是包含菜单项的菜单，运行程序时点击会弹出来
     **********************/
    menu = gtk_menu_new();
 
    /*****************××××××××××
     *
     *
     * *********************/
    for(i = 0; i < 4; i++){
        /*将名称复制到buf*/
        if(i == 0){
            sprintf(buf,"修改个人信息");
        }
        else if(i == 1){
            sprintf(buf,"修改在线状态");
        }
        else if(i == 2){
            sprintf(buf,"修改聊天背景");
        }
        else if(i == 3){
            sprintf(buf,"修改密码");
        }
        
 
        /*创建一个菜单项*/
        menu_items = gtk_menu_item_new_with_label(buf);
 
        /*将它添加到菜单*/
        gtk_menu_shell_append(GTK_MENU_SHELL(menu),menu_items);
 
        /*当菜单被选中时的回调函数*/
        g_signal_connect_swapped(G_OBJECT(menu_items),"activate",G_CALLBACK(menuitem_response),g_strdup(buf));
 
        /*显示构件*/
        gtk_widget_show(menu_items);
    }
 
    /*******************************
     *这个是根菜单，将成为现实在菜单栏上的标签
     *这里不会附上信号处理函数，因为它只是在被按下时弹出的其余的菜单
     *******************************/
    root_menu = gtk_menu_item_new_with_label("根菜单");
    gtk_widget_show(root_menu);
 
    /****************************
     *指定想要穿件的menu成为根菜单
     ***************************/
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(root_menu),menu);
    /*将一个菜单和一个按钮放到纵向盒子里面*/
    vbox = gtk_vbox_new(FALSE,0);


    /*创建一个新的table*/
    table= gtk_table_new(1000,750,FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(table),10);
	//为所有的行和列之间设置相同的空白，均为5个像素
	gtk_table_set_row_spacings(GTK_TABLE(table),5);
	gtk_table_set_col_spacings(GTK_TABLE(table),5);
    gtk_container_add(GTK_CONTAINER(window), table);
    gtk_table_attach(GTK_TABLE(table),vbox,170,178,0,9,GTK_FILL,GTK_FILL,0,0);
    gtk_widget_show(vbox);

    /********************************
     *创建一个菜单栏，并添加到主窗口
     * *****************************/
    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox),menu_bar,FALSE,FALSE,2);
    gtk_widget_show(menu_bar);


    image = gtk_image_new_from_file("setting.png");
    gtk_container_add(GTK_CONTAINER(button),image);
    
    g_signal_connect_swapped(G_OBJECT(button),"event",G_CALLBACK(button_press),menu);
    gtk_box_pack_end(GTK_BOX(vbox),button,TRUE,TRUE,2);

    gtk_widget_show(image);
    gtk_widget_show(button);
   
    // gtk_widget_show(image);
    /**************************
     *最后把菜单项添加到菜单栏上
     * ***************************/
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),root_menu);
 }
