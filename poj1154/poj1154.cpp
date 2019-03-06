#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
void DFS(int,int,int);
int R,C,answer;
char a[30][30];
bool b[26];
int main()
{
	scanf("%d%d",&R,&C);
  	for(int i=0;i<R;i++) scanf("%s",a[i]);
	for(int i=0;i<26;i++) b[i] = false ;
	DFS(0,0,0);
	printf("%d\n",answer);
	return 0;
}
void DFS(int y, int x,int m){
	b[a[y][x]-'A']=true;
	m++;
	if(y>0&&!b[a[y-1][x]-'A']) DFS(y-1,x,m);
	if(y<R-1&&!b[a[y+1][x]-'A']) DFS(y+1,x,m);
	if(x>0&&!b[a[y][x-1]-'A']) DFS(y,x-1,m);
	if(x<C-1&&!b[a[y][x+1]-'A']) DFS(y,x+1,m);
	if(m>answer)
	answer = m;
	b[a[y][x]-'A']=false;
}
