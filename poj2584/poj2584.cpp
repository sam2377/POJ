#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define INF 999999
using namespace std;

bool DFS(int);
int FordFulkerson(int,int);
int Findflow(int,int);

string A,B,no_use;
int num;
int cap[30][30],flow[30][30];
int pa[30],visited[30];
map<char,int> m;
int main(){

	m['S']=21,m['M']=22,m['L']=23,m['X']=24,m['T']=25;

	while(cin>>A){
		if(A=="ENDOFINPUT") break;
		else{

			memset(cap,0,sizeof(cap));
			memset(flow,0,sizeof(flow));
			
			cin >> num;
		
			for(int i=1;i<=num;i++){
				cin >> B;
				for(int l=m[B[0]],r=m[B[1]];l<=r;l++)
					cap[i][l]=1;
				cap[0][i]=1;
			}
			for(int i=21,temp;i<=25;i++){
				cin >> temp;
				cap[i][29] = temp;
			}
			
			cin >> no_use;
			
			if(FordFulkerson(0,29)==num)
				printf("T-shirts rock!\n");
			else
				printf("I'd rather not wear a shirt anyway...\n");
		}
	}
}

bool DFS(int k,int t){
	visited[k]=1;
	if(k==t) return true;
	for(int i=0;i<=t;i++){
		
		if(visited[i]) continue;

		if(cap[k][i]>flow[k][i]||flow[i][k]>0){
			pa[i]=k;
			if(DFS(i,t)) return true;
		}
	}
	return false;	
}

int FordFulkerson(int s,int t){
	int ret = 0;
	while(1){
		memset(visited,0,sizeof(visited));
		if(!DFS(s,t)) break;
		ret += Findflow(s,t);
	}	

	return ret;
}

int Findflow(int s,int t){
	int pre,f=INF,i;
	for(i=t;i!=s;i=pa[i]){
		pre = pa[i];
		if(cap[pre][i]>flow[pre][i])
			f = min(f,cap[pre][i]-flow[pre][i]);
		else
			f = min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i]){
		pre = pa[i];
		if(cap[pre][i]>flow[pre][i])
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}

	return f;
}

