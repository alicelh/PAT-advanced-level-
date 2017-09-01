#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>

/*注意点13输出为tam，而不是tam tret,还有使用iostream会超时*/

using namespace std;
string m1[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string m2[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> mar;
map<string,int> hi;

void convertmar(int n){
	if(n/13>0){
		printf("%s",m2[n/13].c_str());
		if(n%13==0){
			printf("\n");
			return;
		}
		printf(" ");
	}
	printf("%s\n",m1[n%13].c_str());
}

int main(){
	int N,i,j,len,sum,flag=0;
	char tmp[10],t1[5],t2[5];
	scanf("%d",&N);
	for(i=0;i<13;i++){
		mar[m1[i]]=i;
	}
	for(i=0;i<13;i++){
		hi[m2[i]]=i;
	}
	int str;
	getchar();
	for(j=0;j<N;j++){
		gets(tmp);
		flag=0;
		if(tmp[0]>='0'&&tmp[0]<='9'){
			len=strlen(tmp);
			sum=0;
			for(i=0;i<len;i++){
				sum+=(tmp[i]-'0')*pow(10,len-i-1);
			}
			convertmar(sum);
		}
		else{
			if(strlen(tmp)==3){
				for(i=0;i<13;i++){
					if(strcmp(tmp,m1[i].c_str())==0){
						flag=1;
						printf("%d\n",i);
					}	
				} 
				if(!flag) printf("%d\n",hi[tmp]*13);
			}
			else{
				for(i=0;i<3;i++){
					t1[i]=tmp[i];
					t2[i]=tmp[4+i];
				}
				printf("%d\n",hi[t1]*13+mar[t2]);
			}
		}
	}
	return 0;
} 
