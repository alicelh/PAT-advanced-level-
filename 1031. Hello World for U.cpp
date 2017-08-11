#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int N,i,j,k,n2,n,max=0;
	char ch[85];
	cin>>ch;
	N=strlen(ch);
	for(i=3;i<=N;i++){
		k=(N+2-i)/2;
		if(k<=i&&k>max)
			max=k;
	}
	n2=N+2-max*2;
	n=max;
	
	for(i=0;i<n-1;i++){
		cout<<ch[i];
		for(j=0;j<n2-2;j++) 
			cout<<" ";
		cout<<ch[N-i-1]<<endl; 
	} 
	for(i=0;i<n2;i++)
		cout<<ch[n+i-1];
	return 0;
	
}
