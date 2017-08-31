#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
/*避免运行超时，使用hash对名字进行表示，同时为了保证内存不超限，使用vector*/
vector<int> stu[500000];

int hashn(char a[]){
	int num=0;
	for(int i=0;i<4;i++){
		if(i!=3) num+=(a[i]-'A')*pow(26,3-i);
		else num+=a[i]-'0';
	}
	return num;
}

int main(){
	int N,K,i,j,index,s,hashnum;
	vector<int>::iterator itr;
	char tmp[5];
	scanf("%d %d",&N,&K);
	for(i=0;i<K;i++){
		scanf("%d %d",&index,&s);
		for(j=0;j<s;j++){
			scanf("%s",tmp);
			hashnum=hashn(tmp);
			stu[hashnum].push_back(index);
		}
	}
	for(i=0;i<N;i++){
		scanf("%s",&tmp);
		hashnum=hashn(tmp);
		printf("%s ",tmp);
		printf("%d",stu[hashnum].size());
		sort(stu[hashnum].begin(),stu[hashnum].end());
		for(itr=stu[hashnum].begin();itr!=stu[hashnum].end();itr++)
			printf(" %d",(*itr));
		printf("\n");
	}
	return 0;
} 
