#include "room.h"
int main(void)
{
	int x;
	while(TRUE)
	{
	x=menu(x);
	switch(x)
	{
		case 0:
			return 0;
		case 1:
			create_dir();break;
		case 2:
			find_dir();break;
		case 3:
			del_dir();break;
		case 4:
			modify_dir();break;
		case 5:
			insert_dir();break;
		case 6:
			num();break;	
		case 7:
			all();break;	
		default:
			exit(-1);				
	}
	}
	return 0; 
} 
