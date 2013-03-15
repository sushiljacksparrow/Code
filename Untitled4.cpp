#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char S[]="ABAAMA????MAZON????????";
    char p[]="AMAZON";
     printf("%s  \n",S);
     int i,j,flag=0;
     i=i=strlen(S)-1;
     while(i>=0)
     {
    	int k=i;
    	for(j=strlen(p)-1;j>=0;j--)
    	{
    		if(S[k]==p[j] || S[k]=='?')
    		{
    			   k--;
                   flag=1;
            }else
            {
    		    flag=0;
	            break;
		 	}		
    	}
        int m=i;
        if(flag==1)
        {
        	for(j=strlen(p)-1;j>=0;j--)
        	{
            	if(S[m]=='?')
        			S[m]=p[j];
                m--;
        	}
        }
        else
        {
        	if(S[i]=='?')
        	   S[i]='A';
        }
        i--;
    }
    printf("%s\n",S);
    system("pause");
}
