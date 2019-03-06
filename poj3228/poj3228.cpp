#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

void Union(int,int);
int Find(int);

struct node{
	int x;
	int y;
	int l;
	bool operator < (const node &a) const{ return l < a.l;}
};

vector<struct node> V;
int N,M,total_gold,total_cap,boss1,boss2,ans;
int p[20010],gold[20010],cap[20010];

int main(){

	while(cin >> N && N){
		bool flag=true;
		memset(gold,0,sizeof(gold));
		memset(cap,0,sizeof(cap));
		while(!V.empty()) V.erase(V.begin());
		total_gold=0;
		total_cap=0;
		for(int i=0;i<20010;i++){
			p[i]=i;
		}
		for(int i=1;i<=N;i++){
			cin >> gold[i];	
			total_gold+=gold[i];
		}
		for(int i=1;i<=N;i++){	
			cin >> cap[i];
			total_cap+=cap[i];
		}

		cin >> M;
		for(int i=0;i<M;i++){
			struct node temp;
			cin >> temp.x >> temp.y >> temp.l;
			V.push_back(temp);
		}
		for(int i=1;i<=N;i++){
			if(cap[i]<gold[i]){ 
				flag=false;
				break;
			}
		}
		if(flag){ printf("0\n"); continue;}
		if(total_cap<total_gold){ printf("No solution\n"); continue; }
		
		sort(V.begin(),V.end());
		for(int i=0;i<V.size();i++){
			boss1=Find(V[i].x);
			boss2=Find(V[i].y);
			if(boss1==boss2) continue;
			Union(boss1,boss2);
			for(int j=1;j<=N;j++){
				boss1 = Find(j);
				if(cap[boss1]>=gold[boss1])
					flag=true;
				else{
					flag=false;	
					break;
				}
			}
			if(flag) {ans=V[i].l; break;}
		}
			if(flag) printf("%d\n",ans);
			else	printf("No Solution\n");
	}
	return 0;
}
void Union(int X,int Y){
	p[X]=Y;
	cap[Y]+=cap[X];
	gold[Y]+=gold[X];
}

int Find(int x){

	if(p[x]==x)	return x;
	return p[x]=Find(p[x]);

}
