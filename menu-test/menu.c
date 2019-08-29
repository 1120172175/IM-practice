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

void usr_info(GtkWidget* button);
void show_userinfo();

int main( int   argc, char *argv[] )
{
    /* GtkWidget 是构件的存储类型 */
    GtkWidget *window;
    GtkWidget *menu;
    GtkWidget *menu_bar;
    GtkWidget *root_menu;
    GtkWidget *menu_items;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *image;
    GtkWidget *table;
    GtkWidget *image_button;
    GtkWidget *avatar;
    GtkWidget *avatar_box;
    char buf[128];
    int i;
    
    /* 这个函数在所有的 GTK 程序都要调用。参数由命令行中解析出来并且送到该程序中*/
    gtk_init (&argc, &argv);
        /* 创建一个新窗口 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 
    /*设置窗口标题*/
    gtk_window_set_title(GTK_WINDOW(window),"设置界面");
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


    
    /*生成一个头像按钮，可以查看信息*/
    avatar = gtk_image_new_from_file("usrheadimage.jpeg");
    image_button = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(image_button), avatar);
    gtk_widget_set_size_request(image_button, 15, 15);
    g_signal_connect(G_OBJECT(image_button), "clicked", G_CALLBACK(usr_info), image_button);
    // gtk_widget_show(avatar);
    // gtk_widget_show(image_button);

    /*创建一个新的table*/
    table= gtk_table_new(1000,750,FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(table),10);
	//为所有的行和列之间设置相同的空白，均为5个像素
	gtk_table_set_row_spacings(GTK_TABLE(table),5);
	gtk_table_set_col_spacings(GTK_TABLE(table),5);
    gtk_container_add(GTK_CONTAINER(window), table);
    gtk_table_attach(GTK_TABLE(table),vbox,170,178,0,9,GTK_FILL,GTK_FILL,0,0);
    gtk_table_attach(GTK_TABLE(table),image_button, 10, 25, 0, 15, GTK_FILL, GTK_FILL, 0, 0);

    gtk_widget_show(vbox);
    gtk_widget_show(image_button);
    /********************************
     *创建一个菜单栏，并添加到主窗口
     * *****************************/
    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox),menu_bar,FALSE,FALSE,2);
    gtk_widget_show(menu_bar);


    button = gtk_button_new();
    image = gtk_image_new_from_file("setting.png");
    gtk_container_add(GTK_CONTAINER(button),image);
    // gtk_table_attach(GTK_TABLE(table),button,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
    
    gtk_widget_set_size_request(GTK_WIDGET(button), 10, 10);
    g_signal_connect_swapped(G_OBJECT(button),"event",G_CALLBACK(button_press),menu);
    gtk_box_pack_end(GTK_BOX(vbox),button,TRUE,TRUE,2);

    gtk_widget_show(image);
    gtk_widget_show(button);

    
    
    
    
    // gtk_widget_show(image);
    /**************************
     *最后把菜单项添加到菜单栏上
     * ***************************/
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),root_menu);
 
    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}

// void usr_info(GtkWidget* button) {  
// 	GtkWidget *window_usrinfo;
//     GtkWidget *image_usrhead;
// 	GtkWidget *box_usrinfor;
// 	GtkWidget *box_usrname;
// 	GtkWidget *box_usrid;
// 	GtkWidget *box_usrsex;
// 	GtkWidget *box_usrsignature;
// 	GtkWidget *label1_usrname;
// 	GtkWidget *label2_usrname;
// 	GtkWidget *label1_usrid;
// 	GtkWidget *label2_usrid;
// 	GtkWidget *label1_usrsex;
// 	GtkWidget *label2_usrsex;
// 	GtkWidget *label1_usrsignature;
// 	GtkWidget *label2_usrsignature;
// 	GtkWidget *label_flag;
// 	GtkWidget *label_block1;
// 	GtkWidget *label_block2;
// 	GtkWidget *label_block3;
// 	GtkWidget *label_block4;

// 	char *usrname = "jienijieni";
// 	char *usrid = "665789";
// 	char *usrsex = "male";
// 	char *usrsignature = "xixi";
// 	gchar *title;

// 	window_usrinfo = gtk_window_new(GTK_WINDOW_TOPLEVEL);
// 	// g_signal_connect(G_OBJECT(window_usrinfo),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
// 	gtk_window_set_title(GTK_WINDOW(window_usrinfo),"My Information");   
// 	gtk_window_set_position(GTK_WINDOW(window_usrinfo),GTK_WIN_POS_CENTER);  

//     	image_usrhead = gtk_image_new_from_file("usrheadimage.jpeg");
// 	box_usrinfor = gtk_vbox_new(FALSE,0);
// 	gtk_container_add(GTK_CONTAINER(window_usrinfo),box_usrinfor);
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),image_usrhead,FALSE,FALSE,0);  
	
// 	label_block1 = gtk_label_new(" ");	
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block1,FALSE,FALSE,5);
// 	label_block2 = gtk_label_new(" ");	
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block2,FALSE,FALSE,5);

// 	label_flag = gtk_label_new(NULL);
// 	title = "<span><big><i>    Personal Information:</i></big></span>";  	
// 	gtk_label_set_markup(GTK_LABEL(label_flag),title);	
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_flag,FALSE,FALSE,5);
	
// 	box_usrname = gtk_hbox_new(FALSE,0); 
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrname,FALSE,FALSE,5);  

// 	box_usrid = gtk_hbox_new(FALSE,0);  
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrid,FALSE,FALSE,5);

// 	box_usrsex = gtk_hbox_new(FALSE,0);  
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrsex,FALSE,FALSE,5);

//     	box_usrsignature = gtk_hbox_new(FALSE,0);  
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrsignature,FALSE,FALSE,5);
	
// 	label1_usrname = gtk_label_new("                                                                     Name��");  
// 	label2_usrname = gtk_label_new(usrname);  
// 	gtk_box_pack_start(GTK_BOX(box_usrname),label1_usrname,FALSE,FALSE,5);  
// 	gtk_box_pack_start(GTK_BOX(box_usrname),label2_usrname,FALSE,FALSE,5); 	

// 	label1_usrid = gtk_label_new("                                                                     Id��");  
// 	label2_usrid = gtk_label_new(usrid);  
// 	gtk_box_pack_start(GTK_BOX(box_usrid),label1_usrid,FALSE,FALSE,5);  
// 	gtk_box_pack_start(GTK_BOX(box_usrid),label2_usrid,FALSE,FALSE,5); 

// 	label1_usrsex = gtk_label_new("                                                                     Sex��");  
// 	label2_usrsex = gtk_label_new(usrsex);  
// 	gtk_box_pack_start(GTK_BOX(box_usrsex),label1_usrsex,FALSE,FALSE,5);  
// 	gtk_box_pack_start(GTK_BOX(box_usrsex),label2_usrsex,FALSE,FALSE,5); 

// 	label1_usrsignature = gtk_label_new("                                                                     Personal Signature��");  
// 	label2_usrsignature = gtk_label_new(usrsignature);  
// 	gtk_box_pack_start(GTK_BOX(box_usrsignature),label1_usrsignature,FALSE,FALSE,5);  
// 	gtk_box_pack_start(GTK_BOX(box_usrsignature),label2_usrsignature,FALSE,FALSE,5); 

// 	label_block3 = gtk_label_new(" ");	
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block3,FALSE,FALSE,5);
// 	label_block4 = gtk_label_new(" ");	
// 	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block4,FALSE,FALSE,5);

//     gtk_widget_show_all(window_usrinfo);
// }
