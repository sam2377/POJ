#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int dis[2500]={0},u[2500],v[2500],len[2500];
int input1,input2;
void Relax(int,int,int);
int main(){
	for(int i=2;i<2500;i++)
		dis[i]=999999;
	scanf("%d%d",&input1,&input2);
	for(int i=0;i<input1;i++)
		scanf("%d%d%d",&u[i],&v[i],&len[i]);	
	for(int i=0;i<input2;i++){
		for(int j=0;j<input1;j++){
			Relax(u[j],v[j],len[j]);
			Relax(v[j],u[j],len[j]);
		}
	}
		printf("%d\n",dis[input2]);
}
void Relax(int u,int v,int len){
	if(dis[u]+len<dis[v])
		dis[v]=dis[u]+len;
}
