#include<stdio.h>
#include<stdlib.h>
int len(char str[]) //(5)
    {
        int i;
        for (i = 0; str[i] != '\0'; ++i);
        return i;
    }

void replace(char str[],int strLen, char sub[],int subLen, char new[], int newLen){
	int i,j,k;
	int flag=0,start,end;
	for(i=0;i<strLen;i++)
	{
		flag=0;                                      //looking for the substring's start and end in the main string(7)
		start=i;
		for(j=0;str[i]==sub[j];j++,i++)
			if(j==subLen-1)
				flag=1;
		end=i;
		if(flag==0)
			i-=j;
		else
		{
			for(j=start;j<end;j++)
			{
				for(k=start;k<strLen;k++)
					str[k]=str[k+1];               //making space to replace(8)
					strLen--;
					i--;
			}

			for(j=start;j<start+newLen;j++)
			{
				for(k=strLen;k>=j;k--)
					str[k+1]=str[k];
					str[j]=new[j-start];           //replacing the string(9)
					strLen++;
					i++;
			}
		}
	}
	
}
char *input(FILE *fp, int size){
	char *str = malloc(sizeof(char) * size); //(3)
	int c;
	int len=0;
	while(EOF != (c = fgetc(fp)) && c != '\n'){
		str[len++]=c;
		if(len==size){
			str = realloc(str, sizeof(char) * (size *= 2));
		}
	}
	str[len++] = '\0';
	return realloc(str, sizeof(char) * len);
}

int main(){
	char *string, *substring, *new_string;   //execution starts(1)
	int strLen,subLen,newLen;
	printf("\nEnter a string: ");
	string=input(stdin,100); //flow shifts to input() function.(2)
	printf("\nEnter the sub string: ");
	substring=input(stdin,100);
	printf("\nEnter the new substring: ");
	new_string=input(stdin,100);
	strLen=len(string); //(4)
	subLen=len(substring);
	newLen=len(new_string);
	replace(string, strLen, substring,subLen, new_string, newLen);  //(6)
	printf("\nThe string after replacing : %s\n",string); //(10)
	return 0;
}

