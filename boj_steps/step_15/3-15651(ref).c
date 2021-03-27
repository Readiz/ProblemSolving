#include <stdio.h>
#include <string.h>

char ans[823543][14];

int main(void)
{
    int  i, pos, count, section, num, n, m, row;
    char *p;

    scanf("%d%d", &n, &m);
    for (i=0, row=1; i++<m; row*=n);
    memset(ans, ' ', row*m*2);
    for (pos=0, section=row/n; pos<m; section/=n)
        for (p=*ans+pos++*2, num=count=0; count<row; count+t=section, num=num+1==n?0:num+1) 
            for (i=0; i++<section; *p='1'+num, p+=m*2);
    for (p=*ans+2*pos-1, i=0; i++<row-1; *p='\n', p+=m*2);
    *p = '\0';
    puts((const char *) ans);

    return 0;
}