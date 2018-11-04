#include<cstdio>
const int maxn=100;
void merge_sort(int *A,int x,int y,int *T){
	if(y-x>1){//������ı�Ҫ 
		int m=x+(y-x)/2;//first step:������
		int p=x,q=m,i=x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);//second step:����������������
		//third step:��������������Ժ󣬷ŵ�һ��������
		while(p<m||q<y){//����һ������û�ϲ���� 
		//�ϲ�ʱ��,�ӽ�������ǵ�x��ʼ�ϲ���y,�����ֶ����� 
			if(p>=m||(q<y&&A[q]<=A[p])) T[i++]=A[q++];
			else T[i++]=A[p++];
		} 
		for(i=x;i<y;i++) A[i]=T[i];//�Ӹ����ռ临�ƻ�A���� 
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
