/*************************************************************************
    > File Name: gtk4.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月26日 星期四 23时04分10秒
    > Function: 在按钮构件中插入图像
************************************************************************/
#include <stdlib.h>
#include <gtk/gtk.h>

GtkWidget *xpm_label_box(gchar *xpm_filename,gchar *label_text)
{
	GtkWidget *box;
	GtkWidget *label;
	GtkWidget *image;
	
	box=gtk_hbox_new(FALSE,0);
	gtk_container_set_border_width(GTK_CONTAINER(box),2);
	
	image=gtk_image_new_from_file(xpm_filename);
	gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
	
	gtk_widget_show(image);

	return box;
	
}
void callback(GtkWidget *widegt,gpointer data)
{
	g_print("Hello again - %s was pressed\n",(char *)data);
}
int main(int argc,char **argv)
{	
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box;

	gtk_init(&argc,&argv);

	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Pixmap 'd button!");

	g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	gtk_container_set_border_width(GTK_CONTAINER(window),100);

	button=gtk_button_new();
	
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(callback),(gpointer)"cool button");

	box=xpm_label_box("/home/wangyao/文档/gtk/W3.jpg","cool button");

	gtk_widget_show(box);
	gtk_container_add(GTK_CONTAINER(button),box);
	
	gtk_widget_show(button);
	gtk_container_add(GTK_CONTAINER(window),button);

	gtk_widget_show(window);

	gtk_main();

	return 0;
}
