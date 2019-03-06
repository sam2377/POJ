#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
vector<int>V,LIS;
void find_lis();
int input;
int main(){
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		int temp;
		scanf("%d",&temp);
		V.push_back(temp);
		LIS.push_back(0);
	}
	find_lis();
//	for(int i=0;i<input;i++)
//		printf("%d ",LIS[i]);
	sort(LIS.begin(),LIS.end());
	printf("%d\n",LIS[input-1]);
} 
void find_lis(){
	for(int i=0;i<input;i++){
		LIS[i]=1;
		for(int j=0;j<i;j++){
			if(V[j]<V[i]&&LIS[j]+1>LIS[i])
				LIS[i]=LIS[j]+1;
		}
	}
}
