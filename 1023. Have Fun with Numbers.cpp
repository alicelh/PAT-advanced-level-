#include<cstdio>
#include<cstring>
char n[25];
struct number{
	int p[25];
	int len;
	number(){
		len=0;
		memset(p,0,sizeof(int));
	}
}n1,n2;

int t1[10]={0},t2[10]={0};

void convertnum(){
	int l=strlen(n);
	n1.len=l;
	for(int i=l-1;i>=0;i--){
		n1.p[l-i-1]=n[i]-'0';
		t1[n[i]-'0']++;
	}
	return;
}

void doublenum(){
	int carry=0,tmp;
	for(int i=0;i<n1.len;i++){
		tmp=n1.p[i]+carry+n1.p[i];
		n2.p[i]=tmp%10;
		t2[tmp%10]++;
		carry=tmp/10;
		n2.len++;
	}
	if(carry>0){
		n2.p[n2.len]=carry;
		t2[carry]++;
		n2.len++;
	}
}
int main(){
	int flag=0;
	scanf("%s",&n);
	convertnum();
	doublenum();
	for(int i=0;i<10;i++){
		if(t1[i]!=t2[i]) flag=1;
	}
	if(flag) printf("No\n");
	else printf("Yes\n");
	for(int i=n2.len-1;i>=0;i--){
		printf("%d",n2.p[i]);
	}
	return 0;
}
