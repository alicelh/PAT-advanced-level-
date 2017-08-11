#include<iostream>
#define max 21

/*20分的题按理说这样过就可以了，但其实这样还是有问题的，因为题目要求最大数是2^63,但用longlong输入
为2^63-1,输入比2^63-1大的数用dev编译得到的是2^63-1，所以当判断(2^63-1)+1>(2^63-1)会出问题，但测试样例
好像并不包括这样的数即输入范围其实是[-2^63,2^63-1],原题用字符串应该是可以满足题目条件的，但题目就复杂了*/ 

using namespace std;

long long a,b,c,sum;
 
int main(){
  int i,N,flag[12];
  cin>>N;
  for(i=1;i<=N;i++){
    cin>>a>>b>>c;
    sum=a+b;//不清楚为什么不用sum下面直接用a+b会出问题 
    if(a>0&&b>0&&sum<=0) 
      flag[i]=1;
    else if(a<0&&b<0&&sum>=0)
      flag[i]=0;
    else if(sum>c) 
      flag[i]=1;
    else
      flag[i]=0;   
  } 
  for(i=1;i<=N;i++){
    cout<<"Case #"<<i<<": ";
    if(flag[i]) cout<<"true"<<endl;
    else cout<<"false"<<endl;
  }
    
  return 0;
} 
