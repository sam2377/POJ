#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Find(int);
void Union(int,int);
struct node{
	int point_a;
	int point_b;
	int length;
	bool operator<(const node &a) const { return length < a.length;}
}array[10001];
int p[2001];
int main(){
	int N,M,cnt=0,maximum=-1;
	cin >> N >> M;
	for(int i=0;i<N;i++) p[i]=i;
	for(int i=0;i<M;i++)
		cin>>array[i].point_a>>array[i].point_b>>array[i].length;
	sort(array,array+M);
	for(int i=0;i<M;i++){
		if(cnt==N-1) break;
		if(Find(array[i].point_a)!=Find(array[i].point_b)){
			Union(array[i].point_a,array[i].point_b);
			if(array[i].length>maximum) maximum=array[i].length;
			cnt++;
		}
	}
	printf("%d\n",maximum);

}

int Find(int x){
	if(x==p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x,int y){
	int X,Y;
	X = Find(x);
	Y = Find(y);

	p[X]=Y;
}
