#include<gtk/gtk.h>
void usr_info(GtkWidget* button) {  
	GtkWidget *window_usrinfo;
    GtkWidget *image_usrhead;
	GtkWidget *box_usrinfor;
	GtkWidget *box_usrname;
	GtkWidget *box_usrid;
	GtkWidget *box_usrsex;
	GtkWidget *box_usrsignature;
	GtkWidget *label1_usrname;
	GtkWidget *label2_usrname;
	GtkWidget *label1_usrid;
	GtkWidget *label2_usrid;
	GtkWidget *label1_usrsex;
	GtkWidget *label2_usrsex;
	GtkWidget *label1_usrsignature;
	GtkWidget *label2_usrsignature;
	GtkWidget *label_flag;
	GtkWidget *label_block1;
	GtkWidget *label_block2;
	GtkWidget *label_block3;
	GtkWidget *label_block4;

	char *usrname = "jienijieni";
	char *usrid = "665789";
	char *usrsex = "male";
	char *usrsignature = "xixi";
	gchar *title;

	window_usrinfo = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// g_signal_connect(G_OBJECT(window_usrinfo),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_window_set_title(GTK_WINDOW(window_usrinfo),"My Information");   
	gtk_window_set_position(GTK_WINDOW(window_usrinfo),GTK_WIN_POS_CENTER);  

    image_usrhead = gtk_image_new_from_file("usrheadimage.jpeg");
	box_usrinfor = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window_usrinfo),box_usrinfor);
	gtk_box_pack_start(GTK_BOX(box_usrinfor),image_usrhead,FALSE,FALSE,0);  
	
	label_block1 = gtk_label_new(" ");	
	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block1,FALSE,FALSE,5);
	label_block2 = gtk_label_new(" ");	
	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block2,FALSE,FALSE,5);

	label_flag = gtk_label_new(NULL);
	title = "<span><big><i>    Personal Information:</i></big></span>";  	
	gtk_label_set_markup(GTK_LABEL(label_flag),title);	
	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_flag,FALSE,FALSE,5);
	
	box_usrname = gtk_hbox_new(FALSE,0); 
	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrname,FALSE,FALSE,5);  

	box_usrid = gtk_hbox_new(FALSE,0);  
	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrid,FALSE,FALSE,5);

	box_usrsex = gtk_hbox_new(FALSE,0);  
	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrsex,FALSE,FALSE,5);

    box_usrsignature = gtk_hbox_new(FALSE,0);  
	gtk_box_pack_start(GTK_BOX(box_usrinfor),box_usrsignature,FALSE,FALSE,5);
	
	label1_usrname = gtk_label_new("                                                                     Name: ");  
	label2_usrname = gtk_label_new(usrname);  
	gtk_box_pack_start(GTK_BOX(box_usrname),label1_usrname,FALSE,FALSE,5);  
	gtk_box_pack_start(GTK_BOX(box_usrname),label2_usrname,FALSE,FALSE,5); 	

	label1_usrid = gtk_label_new("                                                                     Id: ");  
	label2_usrid = gtk_label_new(usrid);  
	gtk_box_pack_start(GTK_BOX(box_usrid),label1_usrid,FALSE,FALSE,5);  
	gtk_box_pack_start(GTK_BOX(box_usrid),label2_usrid,FALSE,FALSE,5); 

	label1_usrsex = gtk_label_new("                                                                     Gender: ");  
	label2_usrsex = gtk_label_new(usrsex);  
	gtk_box_pack_start(GTK_BOX(box_usrsex),label1_usrsex,FALSE,FALSE,5);  
	gtk_box_pack_start(GTK_BOX(box_usrsex),label2_usrsex,FALSE,FALSE,5); 

	label1_usrsignature = gtk_label_new("                                                                     Personal Signature: ");  
	label2_usrsignature = gtk_label_new(usrsignature);  
	gtk_box_pack_start(GTK_BOX(box_usrsignature),label1_usrsignature,FALSE,FALSE,5);  
	gtk_box_pack_start(GTK_BOX(box_usrsignature),label2_usrsignature,FALSE,FALSE,5); 

	label_block3 = gtk_label_new(" ");	
	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block3,FALSE,FALSE,5);
	label_block4 = gtk_label_new(" ");	
	gtk_box_pack_start(GTK_BOX(box_usrinfor),label_block4,FALSE,FALSE,5);

    gtk_widget_show_all(window_usrinfo);
}
