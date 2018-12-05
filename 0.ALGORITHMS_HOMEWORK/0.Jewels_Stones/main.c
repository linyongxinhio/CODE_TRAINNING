/**
* @description:给定一个字符串J和一个字符串S，计算S中较J中相同字符的个数（大小写敏感）
* @idea:用一个数组来构造哈希表，把a-z和A-Z进行换算成连续排列的下标，然后遍历一次两个字符串即可；
        本题用C++有更好的方法可以解决，这里用的是C语言来写
* @author: 林永欣
* @date: 2018/10/20
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int F[60];
    int pp,sum,i;
    char J[100];
    char S[100];

    printf("请输入J:");
    gets(J);
    printf("请输入S:");
    gets(S);

    for (i=0;i<60;i++)
    {
        F[i]=0;
    }
    pp=0;
    for (i=0;i<strlen(S);i++)
    {
        if (S[i]>='A' && S[i]<='Z')
            pp = S[i] - 65;
        else if (S[i]>='a' && S[i]<='z')
            pp = S[i] - 71;

        F[pp]++;
    }

    for (i=0;i<52;i++)
    {
        printf("%d=%d\n",i,F[i]);
    }

    sum = 0;
    for (i=0;i<strlen(J);i++)
    {
       if (J[i]>='A' && J[i]<='Z')
           pp = J[i] - 65;
       else if (J[i]>='a' && J[i]<='z')
           pp = J[i] - 71;

       sum = sum + F[pp];
    }
    printf("%d",sum);
    return 0;
}
