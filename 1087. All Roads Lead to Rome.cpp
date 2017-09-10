#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxN=1000000000;
int N,K,maxhappy=0;
int happy[210],v[210][210];
map<string,int> stringtoint;
map<int,string> inttostring;
int visited[210]={0},d[210],num[210];
vector<int> pre[210];
vector<int> path,tmp_path;

void dijkstra(){
	fill(d,d+210,maxN);
	fill(num,num+210,0);
	d[0]=0;
	num[0]=1;
	for(int i=0;i<N;i++){
		int u=-1,min=maxN;
		for(int j=0;j<N;j++){
			if(!visited[j]&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;
		visited[u]=1;
		for(int j=0;j<N;j++){
			if(!visited[j]&&v[u][j]!=maxN){
				if(d[u]+v[u][j]<d[j]){
					d[j]=d[u]+v[u][j];
					num[j]=num[u];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if(d[u]+v[u][j]==d[j]){
					num[j]+=num[u];
					pre[j].push_back(u);
				}
			}
		}
	}
}

void DFS(int start,int des){
	if(start==des){
		int happiness=0;
		for(int j=0;j<tmp_path.size();j++){
			happiness+=happy[tmp_path[j]];
		}
		if(happiness>maxhappy){
			maxhappy=happiness;
			path=tmp_path;
		}
		else if(happiness==maxhappy){
			if(happiness/tmp_path.size()>maxhappy/path.size()){
				path=tmp_path;
			}
		}
		return;
	}
	tmp_path.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		DFS(start,pre[des][i]);
	}
	tmp_path.pop_back();
}
void printpath(int start){
	cout<<inttostring[0];
	for(int i=path.size()-1;i>=0;i--){
		cout<<"->"<<inttostring[path[i]];
	}
}
int main(){
	int i,j,h;
	string city,city2;
	fill(v[0],v[0]+210*210,maxN);
	cin>>N>>K>>city;
	stringtoint[city]=0;
	inttostring[0]=city;
	for(i=1;i<N;i++){
		cin>>city>>h;
		stringtoint[city]=i;
		inttostring[i]=city;
		happy[i]=h;		
	}
	for(i=0;i<K;i++){
		cin>>city>>city2>>h;
		v[stringtoint[city]][stringtoint[city2]]=h;
		v[stringtoint[city2]][stringtoint[city]]=h;
	}
	dijkstra();
	int rome=stringtoint["ROM"];
	path.push_back(0);
	DFS(0,rome);
	cout<<num[rome]<<" "<<d[rome]<<" "<<maxhappy<<" "<<maxhappy/path.size()<<endl;
	printpath(0);
	return 0;
}
