#include<iostream>

using namespace std;

int main(){
	int i,l,floor=0;
	int N,sum=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>l;
		if(l>floor)
			sum+=(l-floor)*6+5;
		else if(l<floor)
			sum+=(floor-l)*4+5;
		else sum+=5;//注意楼层号连在一起也要再算进停的时间 
		floor=l;
	}
	cout<<sum;
	return 0;
}
