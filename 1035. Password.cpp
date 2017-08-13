#include<iostream>
#include<cstring>

using namespace std;

char name[1000][14],psw[1000][14];
int ind[1000];
int main(){
	int N,i,num=0,len,j,flag;
	
	cin>>N;
	for(i=0;i<N;i++){
		cin>>name[i]>>psw[i];
		len=strlen(psw[i]);
		flag=0;
		for(j=0;j<len;j++){
			if(psw[i][j]=='1'){
				psw[i][j]='@';
				flag=1;
			}	
			else if(psw[i][j]=='0'){
				psw[i][j]='%';
				flag=1;
			}
			else if(psw[i][j]=='l'){
				psw[i][j]='L';
				flag=1;
			}
			else if(psw[i][j]=='O'){
				psw[i][j]='o';
				flag=1;
			}				
		}
		if(flag){
			ind[num++]=i;
		}
	}
	
	if(!num){
		if(N>1)
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		else
			cout<<"There is 1 account and no account is modified"<<endl;//注意这里是is =.= 
	}
	else{
		cout<<num<<endl;
		for(i=0;i<num;i++){
			cout<<name[ind[i]]<<" "<<psw[ind[i]]<<endl;
		}
	}
	
	return 0;
}

