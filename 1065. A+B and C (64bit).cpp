#include<iostream>
#define max 21

/*20�ֵ��ⰴ��˵�������Ϳ����ˣ�����ʵ��������������ģ���Ϊ��ĿҪ���������2^63,����longlong����
Ϊ2^63-1,�����2^63-1�������dev����õ�����2^63-1�����Ե��ж�(2^63-1)+1>(2^63-1)������⣬����������
���񲢲������������������뷶Χ��ʵ��[-2^63,2^63-1],ԭ�����ַ���Ӧ���ǿ���������Ŀ�����ģ�����Ŀ�͸�����*/ 

using namespace std;

long long a,b,c,sum;
 
int main(){
  int i,N,flag[12];
  cin>>N;
  for(i=1;i<=N;i++){
    cin>>a>>b>>c;
    sum=a+b;//�����Ϊʲô����sum����ֱ����a+b������� 
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
