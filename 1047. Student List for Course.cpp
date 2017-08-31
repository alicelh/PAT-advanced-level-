#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> course[2510];
char tmp[5];

int hashnum(char a[]){
	int len=strlen(a);
	int r=0;
	int ch=27*27*27;
	for(int i=0;i<4;i++){
		if(i<3) r+=(a[i]-'A')*ch;
		else r+=(a[i]-'0')*ch;
		ch/=27;
	}
	return r;
}

void convert(int n){
	int i=3;
	int j=1;
	while(i+1){
		if(i==3) tmp[i--]=n%27+'0';
		else tmp[i--]=n%27+'A';
		n=n/27;
	}
	return;
}

int main(){
	int N,K;
	int i,j,stu,index,num,len;
	
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s",tmp);
		stu=hashnum(tmp);
		scanf("%d",&num);
		for(j=0;j<num;j++){
			scanf("%d",&index);
			course[index].push_back(stu);
		}
	}
	for(i=1;i<=K;i++){
		len=course[i].size();
		printf("%d %d\n",i,len);
		sort(course[i].begin(),course[i].end());
		for(j=0;j<len;j++){
			convert(course[i][j]);
			printf("%s\n",tmp); 
		}
	}
	return 0;
}
