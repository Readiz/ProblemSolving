#include<stdio.h>
int main()
{
  bool che[246913]={0};
  int prime[123456];
  long long i,j,k=0;
  for(i=2;i<=246912;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=246912;j+=i)che[j]=1;
    }
  }
  int n;
  for(;scanf("%d",&n),n;)
  {
    int s=0;
    for(i=0;i<k;i++)
    {
      if(prime[i]>n)
      {
        if(prime[i]<=2*n)s++;
        else break;
      }
    }
    printf("%d\n",s);
  }
}
