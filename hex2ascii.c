#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Readline(char*buf)
{
int count=0,flag = 0,cnt=0,i;
char ch,c[3]={0};
	while((ch = getchar())!= '\n')
	{
	if(count > 1023) {
 		printf("ERROR:characters exceeded!!");
		exit(0);
	}
	if(ch == '%')
	{	flag=1;
		continue;
	}

	if(!flag)
	buf[count++] = ch;
	else
 	 {
	   if(cnt<2)
              c[cnt++]=ch;
	   else
	    {
              c[cnt]= '\0';
	      i=atoi(c);
	      sprintf(c,"%c",i);
              buf[count++]=c[0];
	      buf[count++]=ch;
	      cnt=0;
	      flag=0;
	    }
	   }
	}
	if(flag==1){
              c[cnt]= '\0';
	      i=atoi(c);
	      sprintf(c,"%c",i);
              buf[count++]=c[0];
	      cnt=0;
	      flag=0;
      	    }
	return;

}


int main()
{
char *str;

str = (char *)malloc(1024*sizeof(char));

printf("STRING : ");
Readline(str);
printf("%s\n",str);

}
