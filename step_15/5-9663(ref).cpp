#include <stdio.h>
int arr[16][16];
int count, n;

void visit(int x, int y, int c)
{
	int i;
	
	for(i=1;x+i<=n;i++)
	{
		arr[x+i][y] += c;
		if(y-i >= 0) arr[x+i][y-i] += c;
		if(y+i <= n) arr[x+i][y+i] += c;
	}
}

void dfs(int x)
{
	int i;

	if(x == n+1)
	{
		count++;
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		if(arr[x][i]==0)
		{
			visit(x, i, 1);
			dfs(x + 1);
			visit(x, i, -1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d\n", count);
	return 0;
}
