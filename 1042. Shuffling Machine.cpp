#include<iostream>

using namespace std;

int main(){
	int K,i,j;
	int a[55],b[55],c[55];
	cin>>K;
	for(i=1;i<55;i++){
		cin>>a[i];
		c[i]=i;
	}
		
	for(i=0;i<K;i++){
		for(j=1;j<55;j++)
			b[a[j]]=c[j];
		for(j=1;j<55;j++)
			c[j]=b[j];
	}
	
	for(i=1;i<55;i++){
		if(c[i]<14)
			cout<<'S'<<c[i];
		else if(c[i]<27)
			cout<<'H'<<(c[i]+1)%14;
		else if(c[i]<40)
			cout<<'C'<<(c[i]+2)%14;
		else if(c[i]<53)
			cout<<'D'<<(c[i]+3)%14;
		else 
			cout<<'J'<<(c[i]-52);
		if(i<54) cout<<' ';
	}
	
	return 0;
} 
