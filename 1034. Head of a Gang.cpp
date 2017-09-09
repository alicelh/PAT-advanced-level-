#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
int N,K,num=0,gangs=0;
map<string,int> stringtoint;
map<int,string> inttostring;
int v[2010][2010]={0};
int node[2010]={0};
bool isVisited[2010]={0};
struct gang{
	int h;
	int number;
}head[1010];
bool cmp(gang a,gang b){
	return inttostring[a.h]<inttostring[b.h];
}
void DFS(int start,int &number,int &maxw,int &h,int &relationw){
	if(isVisited[start]) return;
	isVisited[start]=true;
	if(node[start]>maxw){
		maxw=node[start];
		h=start;
	}
	number++;
	relationw+=node[start];
	for(int i=0;i<num;i++){
		if(v[start][i]!=0&&!isVisited[i]){
			DFS(i,number,maxw,h,relationw);
		}	
	}
}
void nodetraversal(){
	int number,maxw,relationw,h;
	for(int i=0;i<num;i++){
		if(!isVisited[i]){
			number=0;
			maxw=0;
			h=0;
			relationw=0;
			DFS(i,number,maxw,h,relationw);
			if(number>2&&relationw>K*2){
				head[gangs].h=h;
				head[gangs].number=number;
				gangs++;
			}
		}
	}	
}
int main(){
	int i,weight;
	string a,b;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>a>>b>>weight;
		if(stringtoint.find(a)==stringtoint.end()){
			inttostring[num]=a;
			stringtoint[a]=num++;
		}
		if(stringtoint.find(b)==stringtoint.end()){
			inttostring[num]=b;
			stringtoint[b]=num++;
		}
		v[stringtoint[a]][stringtoint[b]]+=weight;
		v[stringtoint[b]][stringtoint[a]]+=weight;
		node[stringtoint[a]]+=weight;
		node[stringtoint[b]]+=weight;
	}
	nodetraversal();
	cout<<gangs<<endl;
	sort(head,head+gangs,cmp);
	for(i=0;i<gangs;i++){
		cout<<inttostring[head[i].h]<<" "<<head[i].number<<endl;
	}
	return 0;
} 
