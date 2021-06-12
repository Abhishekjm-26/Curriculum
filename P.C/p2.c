#include<stdio.h>
#include<string.h>
int nfind(char *str,char *pat)
{
  int ends=strlen(str)-1;
  int endp=strlen(pat)-1;
  int endmatch=endp;
  int j,i,start=0;
  for(i=0;endmatch<=ends;start++,endmatch++)
  {
   if(str[endmatch]==pat[endp])
   {
   for(j=0,i=start;j<endp && str[i]==pat[j];i++,j++);
   }
   if(j==endp)
   return start;
   }
   return -1;
  }


void strrem(char *str,int pos,int patlen)
{
int i;
for(i=pos+patlen;str[i]!='\0';i++)
*(str+i-patlen)=*(str+i);
*(str+i-patlen)='\0';
}

void strins(char *str,char *pat,int pos)
{
   char string[30]=" ",*temp=string;
   strncpy(temp,str,pos);
   strcat(temp,pat);
   strcat(temp,str+pos);
   strcpy(str,temp);
}


void main()
{
 char str[30],pat[30],rep[30];
 int pos,patlen;
 printf("enter the string     :");
 gets(str);
 printf("enter the pattern to search   :");
 gets(pat);
 pos=nfind(str,pat);
 if(pos!=-1)
 {
 printf("the pattern is found at index:%d\n",pos);
 printf("enter the string to replace :");
 gets(rep);
 patlen=strlen(pat);
 strrem(str,pos,patlen);
 printf("string after removing pattern:%s\n",str);
 strins(str,rep,pos);
 printf("string after replacing rep :%s\n",str);
 }
 else
 printf("the pattern is not found in the string");
}


