/*************************************************************************
    > File Name: gtktest_image.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月27日 星期五 11时06分43秒
    > Function: 测试图片背景的添加 
 ************************************************************************/
#include <gtk/gtk.h>

int main(int argc,char **argv)
{
	GtkWidget *window;
	GtkWidget *image;
	GtkWidget *frame;
	
	gtk_init(&argc,&argv);
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);	gtk_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	image=gtk_image_new_from_file("/home/wangyao/文档/gtk/W3.jpg");
	frame=gtk_frame_new("Picture view");

	gtk_container_add(GTK_CONTAINER(frame),image);
	gtk_container_add(GTK_CONTAINER(window),frame);

	gtk_widget_show_all(window);
	
	gtk_main();
	return 0;
}
