#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#define L(rt) rt<<1
#define R(rt) rt<<1|1
#define MAXN 100010
using namespace std;

int A[MAXN];

struct nd{
	int left,right;
	long long delta,sum;
}nd[MAXN *4];

void build(int rt,int l,int r){
	nd[rt].left = l;
	nd[rt].right = r;
	nd[rt].delta = 0;
	if(l==r){
		nd[rt].sum = A[l];
		return ;
	}
	
	int m = l+(r-l)/2;
	build(L(rt),l,m);
	build(R(rt),m+1,r);
	nd[rt].sum = nd[L(rt)].sum + nd[R(rt)].sum;
}

long long query(int rt,int l,int r){
	if(nd[rt].left==l && nd[rt].right==r){
		return nd[rt].sum;
	}

	if(nd[rt].delta){
		nd[L(rt)].delta += nd[rt].delta;
		nd[R(rt)].delta += nd[rt].delta;
		nd[L(rt)].sum += nd[rt].delta * (nd[L(rt)].right - nd[L(rt)].left+1);
		nd[R(rt)].sum += nd[rt].delta * (nd[R(rt)].right - nd[R(rt)].left+1);
		nd[rt].delta = 0;	
	}

	int m = nd[rt].left + (nd[rt].right-nd[rt].left)/2;
	if(r<=m){
		return query(L(rt),l,r);
	}else if(l>m){
		return query(R(rt),l,r);
	}else{
		return query(L(rt),l,m) + query(R(rt),m+1,r);
	}
}

void update(int rt,int l,int r,long long v){
	if(nd[rt].left == l && nd[rt].right == r){
		nd[rt].delta += v;
		nd[rt].sum += v * (r-l+1);
		return;
	}

	if(nd[rt].delta){
		nd[L(rt)].delta += nd[rt].delta;
		nd[R(rt)].delta += nd[rt].delta;
		nd[L(rt)].sum += nd[rt].delta * (nd[L(rt)].right - nd[L(rt)].left+1);
		nd[R(rt)].sum += nd[rt].delta * (nd[R(rt)].right - nd[R(rt)].left+1);
		nd[rt].delta = 0;	
	}
		
	int m =  nd[rt].left + (nd[rt].right - nd[rt].left)/2;
	if(r<=m){
		update(L(rt),l,r,v);
	}else if(l>m){
		update(R(rt),l,r,v);
	}else{
		update(L(rt),l,m,v);
		update(R(rt),m+1,r,v);
	}
	
	nd[rt].sum = nd[L(rt)].sum + nd[R(rt)].sum;
}

int main(){
	int N,Q;
	while(cin >> N >> Q){
		for(int i=1; i<=N ;i++)
			scanf("%d",&A[i]);

		build(1,1,N);
		int l,r;
		string str;
		long long v;
		while(Q--){
			cin >> str;
			scanf("%d%d",&l,&r);
			if(str=="Q"){
				printf("%lld\n",query(1,l,r));
			}
			else{
				scanf("%lld",&v);
				update(1,l,r,v);
			}
		}
	}
	return 0;
}
