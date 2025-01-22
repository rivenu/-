//懒得做了，直接cvCSDN上的
//原文链接：https://blog.csdn.net/weixin_45619006/article/details/109977891
#include<stdio.h>
#include<stdlib.h>
#define max 21
 
int a[max][max];//记录两点之间是否有连边 
int n,m,r;//顶点数，颜色数，边数 
int count=0; //答案的个数 
int x[max]; //顶点的颜色 
/*判断颜色不一样*/ 
bool notsame(int i)
{
	for(int j=1;j<=n;j++)
		/*判断i，j之间有连边且顶点颜色一样*/ 
		if(a[i][j]==1 && x[i]==x[j])
		{
			return false;
		}
	return true;
}
/*深搜*/ 
void dfs(int i)
{
	if(i>n)
	{
		count++;
	}
	else
	{
		for(int j=1;j<=m;j++)
		{
			x[i]=j;
			if(notsame(i))
			{
				dfs(i+1);
			}
			x[i]=0;
		}
	}
}

int main()
{
	int x,y;
	scanf("%d%d%d",&n,&r,&m);
	for(int i=1;i<=r;i++)
	{
		scanf("%d%d",&x,&y);
		a[x+1][y+1]=1;
		a[y+1][x+1]=1;
	}
	dfs(1);
	if(count>0)
	{
		printf("%d\n",count);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}

