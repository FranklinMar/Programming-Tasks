#include <stdio.h>

int diap(int x,int min,int max){
 while(x<min){x+=max-min;}
 while(x>=max){x-=max-min;}
 return x;
}

int krapka(char s[50]){
 for(int i=0;i<50;i++)
  if(s[i]=='.')return 0;
 return 1;
} 

int size(char s[50]){
 for(int i=0;i<50;i++)
 if(s[i]>122||s[i]<97)return i;
return 49;
}

int main()
{
 int g,p=0;
char s[50][50];
char key[50];
printf("1-зашифрувати\n2-розшифрувати\n");
scanf("%d",&g);
 for(int i=0;i<50;i++)
for(int x=0;x<50;x++)
 s[i][x]=0;
printf("введіть текст\n");
g=0;
do{
scanf("%s",s[g]);
g++;
}
while(krapka(s[g-1]));
printf("введіть ключ(слово)\n");
scanf("%s",key);
for(int i=0;i<50;i++)
for(int x=0;x<50;x++){
 if(s[i][x]>=97&&s[i][x]<=122){
 s[i][x]=diap(s[i][x]-96+key[p%size(key)],97,123);
 p++;
 }
 else
  s[i][x]=0;
}
for(int i=0;i<g;i++){
printf("%s",s[i]);
if(i+1!=g)printf(" ");
}
printf(".");
}
    return 0;
}
