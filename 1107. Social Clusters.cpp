 #include<cstdio>
 #include<set> 
 #include<algorithm>
 using namespace std;
 int N, father[1010];
 int n[1010][1010],total[1010]={0};
 void init(){
 	for(int i=1;i<=1000;i++){
 		father[i]=i;
	}
 }
 int findfather(int a){
 	int x=a;
 	while(a!=father[a]){
 		a=father[a];	
	}
	int tmp,z=a;
	while(x!=father[x]){
		tmp=father[x];
		father[x]=z;
		x=tmp;
	}
	return z;
 }
 void unionset(int a,int b){
 	int faA=findfather(a);
 	int faB=findfather(b);
 	if(faA!=faB){
 		father[faB]=faA;
	 }
 }
 bool cmp(int a,int b){
 	return a>b;
 }
 int main(){
 	int i,j,num,fa;
	set<int> s;
 	scanf("%d",&N);
 	init();
 	for(i=0;i<N;i++){
 		scanf("%d:",&num);
 		for(j=0;j<num;j++){
 			scanf("%d",&n[i][j]);
 			if(j!=0){
 				unionset(n[i][j],n[i][j-1]);
			}
		}
	}
	for(i=0;i<N;i++){
		int root=findfather(n[i][0]);
		total[root]++;
		if(s.find(root)==s.end()) s.insert(root);
 	}
 	sort(total,total+1010,cmp);//注意要取1001或更大 
 	printf("%d\n",s.size());
 	for(i=0;i<s.size();i++){
 		if(i!=0) printf(" ");
 		printf("%d",total[i]);
	}
	return 0;
 }
