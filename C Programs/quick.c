#include<stdio.h>
#include<time.h>
void quicksort(int [],int,int);
int n,x[10];
int main()
{
	int i,start,end,total,a,b;
	time_t t;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	srand((unsigned) time(&t));
printf("\nElements randomly generated are: \n");
	for(i=0; i<n; i++)	
		x[i]=rand()%100;
	start=clock();
	quicksort(x,0,n-1);
	end=clock();
	total=end-start;
	printf("\ntotal time taken: %d\n",total);
}

void quicksort(int x[],int first,int last)
{
  		int pivot,j,temp,r,i;
		  int pivotIndex=first+ rand()%(r - first + 1);
    	
    	pivot=x[pivotIndex];
    	static int k=1;
	 if(first<last)
	{
         pivot=first;
         i=first;
         j=last;
	 while(i<j)
	{
        	while(x[i]<=x[pivot]&&i<last)
                 i++;
                while(x[j]>x[pivot])
                 j--;
             
                if(i<j)
		{
                 	temp=x[i];
                  	x[i]=x[j];
                  	x[j]=temp;
                }
	}
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;

printf("\npass[%d]: ",k++);
for(r=0;r<n;r++)
printf("%d\t",x[r]);

quicksort(x,first,j-1);
quicksort(x,j+1,last);
    	}
}

