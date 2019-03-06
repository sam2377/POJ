#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool DFS(int);
int Bipartite(int,int);

int llink[102],rlink[102];
bool used[102];
vector<int> edge[102];

int n,m,k;

int main(){
	while(cin >> n && n){
		cin >> m >> k;
		for(int i=0;i<102;i++){ while(!edge[i].empty()) edge[i].erase(edge[i].begin());}
		for(int i=0;i<k;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if(b==0||c==0) continue;
			edge[b].push_back(c);
		}
		printf("%d\n",Bipartite(n,m));
	}
}

int Bipartite(int nL, int nR){

	int ans=0;

	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));

	for(int i=1;i<=nL;i++){
		memset(used,false,sizeof(used));
		if(DFS(i)) ans++;
	}

	return ans;
}

bool DFS(int now){
	
	int next;
	
	for(int i=0;i<edge[now].size();i++){
		next = edge[now][i];
		if(!used[next]){
			used[next] = true;
			if(!rlink[next]||DFS(rlink[next])){
				llink[now] = next;
				rlink[next] = now;
				return true;
			}
		}
	}
	return false;
}

