#include <gtk/gtk.h>
#include <stdio.h>
#include<string.h>
// #include "setting.h"

gint delete_event( GtkWidget *widget,GdkEvent  *event,gpointer   data )
{
    /* 如果你的 "delete_event" 信号处理函数返回 FALSE，GTK 会发出 "destroy" 信号。
     * 返回 TRUE，你不希望关闭窗口。
     * 当你想弹出“你确定要退出吗?”对话框时它很有用。*/
    g_print ("delete event occurred\n");
    /* 改 TRUE 为 FALSE 程序会关闭，关闭时调用destroy()。*/
    return FALSE;
}

/* 另一个回调函数 */
void destroy( GtkWidget *widget,gpointer   data )
{
    gtk_main_quit ();
}
static int button_press(GtkWidget *widget,GdkEvent *event);
void setting_menu(GtkWidget* window, GtkWidget* button);

int main( int   argc, char *argv[] )
{
    /* GtkWidget 是构件的存储类型 */
    GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *button2;
    
    /* 这个函数在所有的 GTK 程序都要调用。参数由命令行中解析出来并且送到该程序中*/
    gtk_init (&argc, &argv);
        /* 创建一个新窗口 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 
    /*设置窗口标题*/
    gtk_window_set_title(GTK_WINDOW(window),"主界面");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
    /* 当窗口收到 "delete_event" 信号 (这个信号由窗口管理器发出，通常是“关闭”
     * 选项或是标题栏上的关闭按钮发出的)，我们让它调用在前面定义的 delete_event() 函数。
     * 传给回调函数的 data 参数值是 NULL，它会被回调函数忽略。*/
    g_signal_connect (G_OBJECT (window), "delete_event",G_CALLBACK (delete_event), NULL);
    
    /* 在这里我们连接 "destroy" 事件到一个信号处理函数。  
     * 对这个窗口调用 gtk_widget_destroy() 函数或在 "delete_event" 回调函数中返回 FALSE 值
     * 都会触发这个事件。*/
    g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (destroy), NULL);
    
    /* 设置窗口边框的宽度。*/
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
   /*创建窗口宽度*/
    gtk_widget_set_size_request(GTK_WIDGET(window),1000,750);

    button1 = gtk_button_new_with_label("设置按钮");
    // gtk_widget_set_size_request(GTK_WIDGET(button1), )
    gtk_container_add(GTK_CONTAINER(window), button1);
    g_signal_connect(G_OBJECT (button1), "clicked", G_CALLBACK(setting_menu), (window, button1));
    gtk_widget_show(button1);
    
    

    
 
    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}

