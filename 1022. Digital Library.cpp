#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

map<string,string> n[6];
string tmp[100000];

int main(){
	int N,M,i,j,k,index,front,flag,num;
	char t;
	string r,name;
	map<string,string>::iterator it;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		cin>>name;
		getchar();
		k=0;
		front=0;
		for(j=1;j<=5;j++){
			if(j==3){//对keywords做键，减少查询时的花销 
				getline(cin,r);
				while(k<r.length()){
					if(r[k]==' '){
						if(n[j].find(r.substr(front,k-front))!=n[k].end()) n[j][r.substr(front,k-front)]+=name;
						else n[j][r.substr(front,k-front)]=name;
						front=k+1;
					}
					k++;
				}
				if(n[j].find(r.substr(front,k-front))!=n[k].end()) n[j][r.substr(front,k-front)]+=name;
						else n[j][r.substr(front,k-front)]=name;
			}
			else getline(cin,n[j][name]);
		}
	}
	for(it=n[3].begin();it!=n[3].end();it++){
		j=0;
		num=0;
		while(j<(it->second).length()){
			tmp[num++]=(it->second).substr(j,7);
			j+=7;
		} 
		sort(tmp,tmp+num);
		(it->second).clear();
		j=0;
		while(j<num){
			(it->second)+=tmp[j];
			j++;
		}
	}
	scanf("%d",&M);
	for(i=0;i<M;i++){
		scanf("%d:",&index);
		getline(cin,r);
		printf("%d:%s\n",index,r.c_str());
		r.erase(0,1);
		flag=0;
		if(index==3){
			if(n[index].find(r)!=n[index].end()){
				j=0;
				while(j<n[index][r].length()){
					printf("%s\n",n[index][r].substr(j,7).c_str());
					j+=7;
				} 
				flag=1;
			}
		}
		else{
			for(it=n[index].begin();it!=n[index].end();it++){
				if(r==it->second){
					printf("%s\n",(it->first).c_str());
					flag=1;
				}
			}
		}
		if(!flag)
			printf("Not Found\n");
	}
	return 0;
} 
