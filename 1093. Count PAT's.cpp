#include<cstdio>
#include<cstring>

/*���õ������Ǽ���ÿ��Aǰ���P�ͺ����T,��˼�Ϊ���*/ 

char n[100010];
int p[100010],a[100010],t[100010],nt[100010]={0};

int main(){
	int i,len,j=0,k=0,s=0;
	int lp,la,lt,tmpj=0,tmpk=0;
	long long num=0;
	scanf("%s",n);
	len=strlen(n);
	for(i=0;i<len;i++){
		if(n[i]=='P') p[j++]=i;
		else if(n[i]=='A') a[k++]=i;
		else t[s++]=i;
	}
	lp=j;
	la=k;
	lt=s;
	for(i=0;i<la;i++){
		for(j=tmpj;j<lt;j++){
			if(a[i]<t[j]){
				nt[i]=lt-j;
				tmpj=j;
				break;
			}
		}
	}
	for(i=la-2;i>=0;i--){//����ÿ��A�����ж�������AT 
		nt[i]+=nt[i+1];
	} 
	for(i=0;i<lp;i++){
		for(j=tmpk;j<la;j++){
			if(p[i]<a[j]){
				num+=nt[j];
				tmpk=j;
				break;
			}
		}
	}		
	printf("%ld",num%1000000007);
	return 0;
} 
