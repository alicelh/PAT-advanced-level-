#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	float que1[20],que2[20],result[40];
	int N1,N2;
	int head1=0;
	int head2=0;
	cin>>N1;
	for(int i=0;i<N1*2;i++)
		cin>>que1[i];
	cin>>N2;
	for(int i=0;i<N2*2;i++)
		cin>>que2[i];
		
	int j=0;
	//类似于归并排序的思想，对两个数组进行合并 
	while(head1<N1*2||head2<N2*2){
		if(head1>=N1*2){
			result[j++]=que2[head2++];
			result[j++]=que2[head2++];
			continue;
		}
		if(head2>=N2*2){
			result[j++]=que1[head1++];
			result[j++]=que1[head1++];
			continue;
		}
		if(que1[head1]>que2[head2]){
			result[j++]=que1[head1++];
			result[j++]=que1[head1++];
		}
		else if(que1[head1]==que2[head2]){
			if(que1[head1+1]+que2[head2+1]==0){
				head1+=2;
				head2+=2;
				continue;
			}				
			result[j++]=que1[head1++];
			result[j++]=que1[head1++]+que2[head2+1];
			head2+=2;
		}
		else{
			result[j++]=que2[head2++];
			result[j++]=que2[head2++];
		}		
	}
	
	cout<<j/2;
	int i=0;
	while(i<j){
		cout<<' '<<setiosflags(ios::fixed)<<setprecision(0)<<result[i++];
		cout<<' '<<setiosflags(ios::fixed)<<setprecision(1)<<result[i++];
	}
	return 0;
}
