/*************************************************************************
    > File Name: gtkwin.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月22日 星期日 15时41分38秒
    > Function: gtk用法 
 ************************************************************************/
#include <gtk/gtk.h>

void hello(GtkWidget *widget,gpointer *data)
{
	g_print("button clicked and data=%s\n",(char *)data);
}
void destory(GtkWidget *widget,gpointer *data)
{
	gtk_main_quit();
}
int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *button;
	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(GTK_OBJECT(window),"destory",GTK_SIGNAL_FUNC(destory),NULL);
	gtk_container_border_width(GTK_CONTAINER(window),20);
	
	button=gtk_button_new_with_label("Hello World");
	g_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(hello),"I am from button");

	gtk_container_add(GTK_CONTAINER(window),button);

	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
