/**
* @description:����һ���ַ���J��һ���ַ���S������S�н�J����ͬ�ַ��ĸ�������Сд���У�
* @idea:��һ�������������ϣ����a-z��A-Z���л�����������е��±꣬Ȼ�����һ�������ַ������ɣ�
        ������C++�и��õķ������Խ���������õ���C������д
* @author: ������
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

    printf("������J:");
    gets(J);
    printf("������S:");
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
