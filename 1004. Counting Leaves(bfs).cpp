#include<iostream>
#include<vector>
#include<queue> 
#define maxN 100

using namespace std;

vector<int> G[maxN];
int N,M;
int h[maxN];//ÿ��������ڵĸ߶� 
int num[maxN]={0};//ÿ������Ҷ�ڵ��� 
int max_h=1;

void bfs(){
	int id,i;
	queue<int> Q;//���ö��ж�ÿһ����б���ʵ�ֹ���������� 
	Q.push(1);
	while(!Q.empty()){
		id=Q.front();
		Q.pop();
		max_h=max(max_h,h[id]);
		if(!G[id].size()){
			num[h[id]]++; 
		}
		for(i=0;i<G[id].size();i++){
			Q.push(G[id][i]);
			h[G[id][i]]=h[id]+1;
		}
	}
}

int main(){
	int i,j,id,k,child;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>id>>k;
		for(j=0;j<k;j++){
			cin>>child;
			G[id].push_back(child);
		}
	}
	
	h[1]=1;
	bfs();
	
	for(i=0;i<max_h-1;i++)
		cout<<num[i+1]<<" ";
	cout<<num[max_h];
	
	return 0;
}
