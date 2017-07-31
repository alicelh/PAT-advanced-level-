#include<iostream>
#include<iomanip> 

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	
	if(c<0){
		c=-c;
		cout<<'-';
	}
	
	if(c>999999)
		cout<<c/1000000<<','<<setfill('0')<<setw(3)<<c/1000%1000<<','<<setfill('0')<<setw(3)<<c%1000<<endl;
	else if(c>999)
		cout<<c/1000<<','<<setfill('0')<<setw(3)<<c%1000<<endl;
	else
		cout<<c<<endl;
	
	return 0;
}
