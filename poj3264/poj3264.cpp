#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 999999
using namespace std;

struct Node{
	int vmax,vmin;
	Node *l,*r;

	void update(int v){
		vmax=v;
		vmin=v;
	}
	void pull(){
		vmax = max(l->vmax,r->vmax);
		vmin = min(l->vmin,r->vmin);
	}
};

Node * build(int,int);
int querymin(Node *,int,int,int,int);
int querymax(Node *,int,int,int,int);

int a[50010];
int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	Node *root = build(1,N);
	for(int i=0;i<Q;i++){
		int l,r;
		scanf("%d%d",&l,&r);	
		printf("%d\n",querymax(root,1,N,l,r)-querymin(root,1,N,l,r));
	}
	return 0;
}


Node* build(int L,int R){
	Node *now = new Node();
	if(L==R){
		now->update(a[L]);
		return now;
	}
	int mid = (L+R)/2;
	now->l=build(L,mid);
	now->r=build(mid+1,R);
	now->pull();
	return now;
}

int querymax(Node* now,int L,int R,int x,int y){
	if(x>R || y<L) return -INF;
	if(x<=L && y>=R) return now->vmax;

	int mid = (L+R)/2;
	return max(querymax(now->l,L,mid,x,y),querymax(now->r,mid+1,R,x,y));
}

int querymin(Node *now,int L,int R,int x,int y){
	if(x>R || y<L) return INF;
	if(x<=L && y>=R) return now->vmin;

	int mid = (L+R)/2;
	return min(querymin(now->l,L,mid,x,y),querymin(now->r,mid+1,R,x,y));
}
