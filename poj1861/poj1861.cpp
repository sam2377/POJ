#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int Find(int);
void Union(int,int);
struct node{
	int point_a;
	int point_b;
	int length;
	bool operator<(const node &a) const{ return length < a.length;}
}array[15002];
struct ans{
	int a;
	int b;
};
int p[1002];
vector<struct ans> V;
int main(){
	int N,M;
	cin >> N >> M;
		int cnt=0,max=-1;
		for(int i=0;i<1002;i++) p[i]=i;
		for(int i=0;i<M;i++)
			cin >> array[i].point_a >> array[i].point_b >> array[i].length;
		sort(array,array+M);
		for(int i=0;i<M;i++){
			if(cnt==N-1) break;
			if(Find(array[i].point_a)!=Find(array[i].point_b)){
				Union(array[i].point_a,array[i].point_b);
				struct ans temp;
				temp.a=array[i].point_a;
				temp.b=array[i].point_b;
				V.push_back(temp);
				if(array[i].length>max) max = array[i].length;
				cnt++;
			}
		}
		printf("%d\n%d\n",max,N-1);
		for(int i=0;i<V.size();i++)
			printf("%d %d\n",V[i].a,V[i].b);
		V.clear();
	}


int Find(int x){
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}
void Union(int x,int y){
	int X,Y;
	X=Find(x);
	Y=Find(y);

	p[X]=Y;
}

