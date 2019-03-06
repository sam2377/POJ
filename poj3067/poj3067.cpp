#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long sum(int);
void modify(int);

struct node{
	int E,W;
	bool operator < (const node & a) const{
		if(E == a.E) return W > a.W;
		return E > a.E;
	}
}road[1000100];

long long s[1100];

int main(){
	int x,N,M,K,cases=1;
	scanf("%d",&x);
	for(int i=1;i<=x;i++){
		scanf("%d%d%d",&N,&M,&K);
		for(int j=0;j<K;j++){
			scanf("%d%d",&road[j].E,&road[j].W);
		}
		sort(road,road+K);
		long long ans = 0;
		memset(s,0,sizeof(s));
		for(int k=0;k<K;k++){
			ans += sum(road[k].W-1);
			modify(road[k].W);
		}
		printf("Test case %d: %lld\n",cases++,ans);
	}
	return 0;
}

void modify(int index){
	for (int i=index;i<1100;i+=(i&(-i)))
		s[i]++;
}

long long sum(int index){
	long long ans=0;
	while(index>0){
		ans+=s[index];
		index-=(index&(-index));
	}
	return ans;
}

