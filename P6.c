#include <stdio.h>

int size(char s[50]){
 for(int i=0;i<50;i++)
 if(s[i]>122||s[i]<97)return i;
return 49;
}

int main()
{
char s[50];
int key;
printf("введіть слово\n");
scanf("%s",s);
printf("введіть діаметр\n");
scanf("%d",&key);
for(int y=size(s)/key-1;y>=0;y--)
 for(int x=0;x<=key;x++)
 if(x*(size(s)/key)+y<size(s))
printf("%c",s[x*(size(s)/key)+y]);
    return 0;
}