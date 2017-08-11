#include<iostream>

using namespace std;

int a[32];

int main(){
	int N,b,i,num=0;
	int flag=1;
	cin>>N>>b;
	//十进制转换为b进制 
	do{
		a[num++]=N%b;
		N=N/b;
	}while(N!=0);
	
	num--;
	for(i=0;i<(num+1)/2;i++)
		if(a[i]!=a[num-i])
			flag=0;
		
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	for(i=num;i>0;i--){
		cout<<a[i]<<" ";
	}
	cout<<a[0];
	
	return 0;
}
