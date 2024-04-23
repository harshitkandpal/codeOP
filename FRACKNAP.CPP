#include<stdio.h>
#include<conio.h>
#define n 4
int S[n];
float knapsack(int X[],int W[],int V[], int M)
{
	int i,k;
	float SW = 0,SP=0;
	int j,temp;
	float frac;
	int cost[n];
	for(i=0;i<n;i++)
		cost[i]=V[i]/W[i];
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(cost[j]<cost[j+i]){
				temp=cost[j+1];
				cost[j+1]=cost[j];
				cost[j]=temp;
				temp=X[j+1];
				X[j+1]=X[j];
				X[j]=temp;
				temp=W[j+1];
				W[j+1]=W[j];
				W[j]=temp;
				temp=V[j+1];
				V[j+1]=V[j];
				V[j]=temp;
			}
		}
		}
		i=0,k=0;
		while(i<n){
			if(SW+W[i]<=M){
				S[k++]=X[i];
				SW+=W[i];
				SP+=V[i];
			}else{
				frac = (M-SW)/W[i];
				S[k++]=X[i];
				SW+=W[i]*frac;
				SP+=V[i]*frac;
				break;
			}
			i++;
		}
		return SP;

}

void main(){
	int i;
	int X[n];int V[n],W[n],M;
	float max_profit;
	clrscr();
	printf("Enter Items: ");
	for(i=0;i<n;i++)
		scanf("%d",&X[i]);
	printf("\nEnter Weights: ");
	for(i=0;i<n;i++)
		scanf("%d",&W[i]);
	printf("\nEnter Profits: ");
	for(i=0;i<n;i++)
		scanf("%d",&V[i]);
	printf("Enter Weight of Knapsack: ");
	scanf("%d",&M);
	max_profit=knapsack(X,W,V,M);
	printf("Sequence of items: ");
	i=0;
	while(S[i]!='\0'){
		printf("%d ",S[i]);
		i++;
	}
	printf("\nMax Profit; %f",max_profit);
	getch();
}