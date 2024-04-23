#include<stdio.h>
#include<conio.h>


void printArray(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void seSort(int arr[],int size)
{
	int i,j,temp,min;
	printf("\t Selection Sort\n");
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		temp = arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		printf("pass: %d\tmin: %d\t",i,min);
		printArray(arr,size);
	}
	printf("Final Output: ");
	printArray(arr,size);
}


void inSort(int a[],int n)
{
	printf("\t\tInsertion Sort\n");
	for(int i=0;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
		printf("pass: %d\ttemp %d\t",i,temp);
		printArray(a,n);
	}
	printf("Final Result: ");
	printArray(a,n);
}

int partition(int a[],int p,int r)
{
	int x,i,j,d,b,c;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i++;
			d=a[j];
			a[j]=a[i];
			a[i]=d;
		}
	}
	c=a[r];
	a[r]=a[i+1];
	a[i+1]=c;
	return i+1;
}
void quickSort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}

void merge(int arr[],int p,int q,int r)
{
	int n1=q-p+1,n2=r-q,i,j,k;
	int l[10],R[10];
	for(i=0;i<n1;i++)
	{
		l[i]=arr[i+p];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=arr[q+1+j];
	}
	l[n1]=999;R[n2]=999;i=0;j=0;
	for(k=p;k<=r;k++)
	{
		if(l[i]<=R[j])
		{
			arr[k]=l[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
	}
}

void mergeSort(int arr[],int p, int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}


int main()
{
	clrscr();
	int size,ch;
	printf("Enter the no of inputs: ");
	scanf("%d",&size);
	int arr[30];
	printf("Enter the numbers: ");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Select the sort\n1.insertion sort\n2.selection sort\n3.quick sort\n4.merge sort\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: inSort(arr,size); break;
		case 2: seSort(arr,size); break;
		case 3: quickSort(arr,0,size-1);
			printf("\tQuick Sort: ");
			printArray(arr,size);
			break;
		case 4: mergeSort(arr,0,size-1);
			printf("\tMerge Sort: ");
			printArray(arr,size);
			break;
		default : printf("invalid input\n");
	}
	getch();
	return 0;
}