#include<cstdio>
const int maxn=100;
void merge_sort(int *A,int x,int y,int *T){
	if(y-x>1){//有排序的必要 
		int m=x+(y-x)/2;//first step:分两半
		int p=x,q=m,i=x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);//second step:分治排序两个部分
		//third step:两遍分治排序完以后，放到一个数组里
		while(p<m||q<y){//成立一个就是没合并完毕 
		//合并时候,从进入程序是的x开始合并到y,两部分都合完 
			if(p>=m||(q<y&&A[q]<=A[p])) T[i++]=A[q++];
			else T[i++]=A[p++];
		} 
		for(i=x;i<y;i++) A[i]=T[i];//从辅助空间复制回A数组 
	}
} 
int main(){
	int A[maxn]={0};
	int T[maxn]={0};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&A[i]);
	merge_sort(A,0,n,T);
	for(int i=0;i<n;i++){
		i==n-1?printf("%d\n",A[i]):printf("%d ",A[i]);
	}
	return 0;
} 
