#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

bool DFS(int);
int Bipartite(int,int);
struct coo{
   double x;
   double y;
};

int n,m,s,v;
vector<struct coo> A,B;
vector<int> edge[102]; 
int llink[102],rlink[102];
bool used[202];

int main(){	
  
    while(cin>>n>>m>>s>>v){
	for(int i=0;i<102;i++){ while(!edge[i].empty()) edge[i].erase(edge[i].begin());}
	while(!A.empty()) A.erase(A.begin());
	while(!B.empty()) B.erase(B.begin());
	
	for(int i=0;i<n;i++){
    	    struct coo temp;
	    cin >> temp.x >> temp.y;
	    A.push_back(temp);
	}
	for(int i=0;i<m;i++){
	    struct coo temp;
	    cin >> temp.x >> temp.y;
	    B.push_back(temp);
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
	    	double X1=A[i-1].x,X2=B[j-1].x,Y1=A[i-1].y,Y2=B[j-1].y;
		if(sqrt(pow(X1-X2,2)+pow(Y1-Y2,2))/v<s){
			edge[i].push_back(j);
			//edge[j+100].push_back(i);
		}
	    }
	}
	
	printf("%d\n",n-Bipartite(n,m));
	
		
    }
}

int Bipartite(int nL, int nR){
	
	int i,ans=0;
	
	memset(llink,0,(nL+1)*sizeof(int));
	memset(rlink,0,(nR+1)*sizeof(int));

	for(int i=1;i<=nL;i++){
		memset(used,false,(nR+1)*sizeof(bool));
		if(DFS(i)) ++ans;
	}
	return ans;
}

bool DFS(int now){
	
	int i,next;

	for(i=0;i<(int)edge[now].size();i++){

		next=edge[now][i];
		
		if(!used[next]){
			used[next]=true;
			if(!rlink[next]||DFS(rlink[next])){
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
