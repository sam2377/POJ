#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int s[32005]={0};
int level[15005]={0};

int lowbit(int in){
	return in&(-in);
}

int main(){
	int N,x,y,temp=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		x++;
		for(int j=x;j<32005;j+=lowbit(j))
			s[j]++;
		temp=0;
		while(x>0){
			temp+=s[x];
			x-=lowbit(x);
		}
		level[temp-1]++;
	}
	for(int i=0;i<N;i++)
		printf("%d\n",level[i]);
	return 0;
}
