#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100010
using namespace std;

int lowbit(int in){
	return in&(-in);
}

struct node{
	int pos,S,E;
	bool operator < (const node & a) const{
		if(E == a.E) return S < a.S;
		return E > a.E;
	}
}cow[MAXN];

int s[MAXN],ans[MAXN];

int main(){
	int N,S,E;
	while(cin >> N && N){
		int max_S=0;
		for(int i=0;i<N;i++){
			cin >> S >> E;
			S++,E++;
			cow[i].S = S;
			cow[i].E = E;
			cow[i].pos = i;
			if(S > max_S) max_S = S;
		}
		sort(cow,cow+N);
		memset(s,0,sizeof(s));
		for(int i=0;i<N;i++){
			for(int j=cow[i].S;j<=max_S;j+=lowbit(j))
				s[j]++;
			if(i>0 && cow[i-1].E == cow[i].E && cow[i-1].S == cow[i].S)
				ans[cow[i].pos] = ans[cow[i-1].pos];
			else{
				int sum=0;
				int x = cow[i].S;
				while(x>0){
					sum+=s[x];
					x-=lowbit(x);
				}
				ans[cow[i].pos] = sum-1;
			}
		}
		for(int i=0;i<N;i++){
			if(i==N-1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}
	}
	return 0;
}
