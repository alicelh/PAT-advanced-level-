 #include<cstdio>
 #include<vector>
 #include<queue>
 
 using namespace std;
 int N,M,l[110]={0};
 struct Node{
 	int level;
 	vector<int> child;
 }n[110];
 void BFS(){
 	queue<int> q;
 	q.push(1);
 	n[1].level=1;
 	l[1]=1;
 	while(!q.empty()){
 		Node top=n[q.front()];
 		q.pop();
 		for(int i=0;i<top.child.size();i++){
 			q.push(top.child[i]);
 			n[top.child[i]].level=top.level+1;
 			l[top.level+1]++;
		}
	}
 }
 int main(){
 	int i,j,num,child,max,index;
 	scanf("%d %d",&N,&M);
 	for(i=0;i<M;i++){
 		scanf("%d %d",&index,&num);
 		for(j=0;j<num;j++){
 			scanf("%d",&child);
 			n[index].child.push_back(child);
		}
	}
	BFS();
	max=1;
	index=1;
	for(i=2;i<N;i++){
		if(l[i]>max){
			max=l[i];
			index=i;
		}
	}
	printf("%d %d",max,index);
	return 0;
 } 
