#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int a,b,c;
	int flag=0;
	cin>>a>>b;
	c=a+b;
	int v1=c/1000000;
	if(abs(v1)>=1){
		cout<<v1<<",";
		flag=2;
	}
	int v2=c/1000;
	if(!flag){
		if(abs(v2)>=1){
			cout<<v2%1000<<",";	
			flag=1;
		}
	}
	else{
		if(abs(v2%1000)>=100)
			cout<<abs(v2%1000)<<",";
		else if(abs(v2%1000)>=10)
			cout<<"0"<<abs(v2%1000)<<",";
		else if(abs(v2%1000)>=1)
			cout<<"00"<<abs(v2%1000)<<",";
		else 
			cout<<"000,";
		flag=1;	
	}
	
	if(!flag)
		cout<<c<<endl;
	else{
		if(abs(c%1000)>=100)
			cout<<abs(c%1000)<<endl;
		else if(abs(c%1000)>=10)
			cout<<"0"<<abs(c%1000)<<endl;
		else if(abs(c%1000)>=1)
			cout<<"00"<<abs(c%1000)<<endl;
		else 
			cout<<"000";
	}
	return 0;
}
