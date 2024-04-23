#include<stdio.h>
#include<conio.h>
int max,min;
int arr[10];
void maxmin(int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max=min=arr[i];
	}else if(i==j-1)
	{
		if(arr[i]<arr[j])
		{
			max=arr[j];
			min=arr[i];
		}else
		{
			max=arr[i];
			min=arr[j];
		}
	}else
	{
		mid = (i+j)/2;
		maxmin(i,mid);
		max1=max;
		min1=min;
		maxmin(mid+1,j);
		if(max<max1)
			max=max1;
		if(min>min1)
			min=min1;
	}
}

void maxmin2(int arr[],int size)
{
	int i;
	int max2=-1;
	int min2=999;
	for(i=0;i<size;i++)
	{
		if(max2<arr[i]){
			max2=arr[i];
		}
		if(min2>arr[i]){
			min2=arr[i];
		}
	}
	printf("MAX2: %d\tMIN2: %d\n",max2,min2);
}

int main ()
{
	int i,num;
	clrscr();
	printf("\nEnter the number of elements: ");
	scanf("%d",&num);
	printf("Enter the elements: ");
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
	max=arr[0];
	min=arr[0];
	maxmin(0,num-1);
	printf("MAX: %d\tMIN: %d\n",max,min);
	maxmin2(arr,num);
	getch();
	return 0;
}