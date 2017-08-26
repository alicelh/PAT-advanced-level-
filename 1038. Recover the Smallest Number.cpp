#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string n[10000];

bool cmp(string a,string b){//32 321要保证321在前 
	return a+b<b+a;
}

int main(){
	int i,j,N,flag=0;
	cin>>N;
	for(i=0;i<N;i++)
		cin>>n[i];
	sort(n,n+N,cmp);
	for(i=0;i<N;i++){
		if(flag){
			cout<<n[i];
		}
		else{
			for(j=0;j<n[i].length();j++){
				if(flag) cout<<n[i][j];
				else if(n[i][j]!='0'){
					flag=1;
					cout<<n[i][j];
				}
			}
		}
	}	
	if(!flag) cout<<'0';	//输入都为0的情况 
	return 0;
} 
