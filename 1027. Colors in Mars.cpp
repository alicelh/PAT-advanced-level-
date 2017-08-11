#include<iostream>

using namespace std;

int main(){
	int a[3],b[2]={0};
	int i,j,k;
	cin>>a[0]>>a[1]>>a[2];
	cout<<"#";
	for(i=0;i<3;i++){
		j=0;
		do{
			b[j]=a[i]%13;
			a[i]=a[i]/13;
			j++;
		}while(a[i]>0);
		for(k=1;k>=0;k--){
			switch(b[k]){
				case 10:
					cout<<'A';
					break;
				case 11:
					cout<<'B';
					break;
				case 12:
					cout<<'C';
					break;
				default:
					cout<<b[k];
			}
		}	
		b[0]=b[1]=0;
	}
	return 0;
} 
