#include<cstdio>

int main(){
	int a,b,c;
	int aa,bb,cc;
	int aaa=0,bbb=0,ccc=0;
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&aa,&bb,&cc);
	
	ccc=c+cc;
	if(ccc>=29){
		ccc-=29;
		bbb=1;
	}
	bbb+=b+bb;
	if(bbb>=17){
		bbb-=17;
		aaa=1;
	}
	aaa+=a+aa;
	printf("%d.%d.%d",aaa,bbb,ccc);
	
	return 0;
}
