#include<cstdio>
#include<cstring>

using namespace std;

char s1[10000],s2[300];
int main(){
	char tmp;
	int i,j,num=0,flag;
	gets(s1);
	tmp=getchar();
	while(tmp!='\n'){//将重复的进行化简，减少下面比较次数 
		flag=0;
		for(i=0;i<num;i++){
			if(tmp==s2[i]){
				flag=1;
				break;				
			}
		}
		if(!flag) s2[num++]=tmp;
		tmp=getchar();
	}
	for(i=0;i<strlen(s1);i++){
		flag=0;
		for(j=0;j<num;j++){
			if(s1[i]==s2[j]){
				flag=1;
				break;
			}
		}
		if(!flag) printf("%c",s1[i]);
	}
	return 0;
}
