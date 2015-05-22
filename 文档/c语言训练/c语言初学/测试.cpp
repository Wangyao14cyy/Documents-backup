
#include <stdio.h>
int main(){
	char c;
	int i=0,j=0,k=0,a=0,b=0;
	while((c=getchar())!=EOF)
	{
		if(('A'<=c&&c<='Z')||('a'<=c&&c<='z'))i++;
		else{
			switch(c){
			case ' ':j++;break;
			case 9:
			case 11:k++;break;
			case 10:a++;break;
			default:b++;break;
			}
		}
	}
	printf("%d %d %d %d %d\n",i,j,k,a,b);
	return 0;
}
