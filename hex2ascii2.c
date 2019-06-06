#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024

int hex_to_int(char c){
        int first = c / 16 - 3;
        int second = c % 16;
        int result = first*10 + second;
        if(result > 9) result--;
        return result;
}

int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}

void stringConversion(char*buf) 			//function to detect and change hex values in string
{
int count=0,flag = 0,cnt=0;
long int i;
char ch,c[3]={0};
	do{
	ch = getchar();
	if(count > (LEN-1)) {				//limit to string
 		printf("ERROR:characters exceeded!!");
		exit(0);
	}
	if(ch == '%')					//hex detection
	{	flag=1;
		continue;
	}
	if(!flag)
	buf[count++] = ch;
	else
 	 {
	   if(cnt<2)
              c[cnt++]=ch;
           if(cnt==2)	   
 	    {
	      flag=0;
              c[cnt]= '\0';
              if(c[0] > 96)
		c[0] -= 32;
	       if(c[1] > 96)
  		c[1] -= 32;
	      sprintf(c,"%c", hex_to_ascii(c[0],c[1]));
              buf[count++]=c[0];
	      //buf[count++]=ch;
	      cnt=0;
	    }
	   }
	}while(ch != '\n');
	buf[--count]='\0';
	return;

}


int main()
{
	char *str;
	str = (char *)malloc(LEN*sizeof(char));
	printf("STRING : ");
	stringConversion(str);
	printf("%s\n",str);
	free(str);
}
