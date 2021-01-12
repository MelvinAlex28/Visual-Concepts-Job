#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
int smallest(int arr[]);
void main()
{
int i, n, arr[100];
int start, end, total;
time_t t;
printf("Enter no. of elements: \n");
scanf("%d",&n);
srand((unsigned) time(&t));
printf("\nElements randomly generated are: \n");
for(i=0; i<n; i++)
arr[i]=rand()%100; start=clock(); insertion_sort(arr, n); end=clock();
printf("\nThe sorted array is: \n");
for(i=0; i<n; i++)
printf("%d \t",arr[i]);
total=end-start;
printf("\nTotal time taken by insertion sort: %dms\n",total); 
start=clock(); 
selection_sort(arr, n); 
end=clock();
total=end-start;
printf("\nTotal time taken by selection sort: %dms\n",total);
}
void insertion_sort(int arr[], int n)
{
int i, j, k, key;
for(j=1; j<n-1; j++)
{
key=arr[j];
i=j-1;
while(i>=0 && arr[i]>key)
{
arr[i+1]=arr[i];
i--;
}
arr[i+1]=key;

printf("\nPass[%d]: ", j);
for(k=0; k<n; k++)
printf("%d \t",arr[k]);
}
}
void selection_sort(int arr[], int n)
{
int i, smallest, temp, j, k, cnt;
for(i=0; i<n-1; i++)
{
smallest=i;
for(k=i+1; k<n; k++)
{
if(arr[smallest]>arr[k])
smallest=k;
}
if(i!=smallest)
{
temp=arr[i]; arr[i]=arr[smallest]; arr[smallest]=temp;
}
printf("\nPass[%d]: ", i+1);
for(cnt=0; cnt<n; cnt++)
printf("%d \t",arr[cnt]);
}
}

