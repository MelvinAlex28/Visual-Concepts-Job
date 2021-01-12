#include<stdio.h>
#include<stdlib.h>
void MergeSort( int Arr[100],int low , int high); 
void Combine( int Arr[100], int low , int mid , int high);
int n;
void MergeSort( int Arr[100], int low , int high)
{
     int mid;
     if(low<high)
     {
        mid=(low+high)/2; 
        MergeSort(Arr,low,mid); 
        MergeSort(Arr,mid+1,high); 
        Combine(Arr,low,mid,high);                             
     }   
}
void Combine(int Arr[100], int low, int mid , int high)
{
     int i , j , k;    
     int temp [100]; 
     k = low;
     i = low;
     j = mid+1;  
     while( i <= mid && j <= high)
     {
            if(Arr[i] <= Arr[j])
            {
            temp[k]= Arr[i];
            i++;
            k++;                     
            }             
            else
            {
              temp[k]= Arr[j];
              j++;
              k++;        
            }    
     }    
     while(i<=mid)
     {
        temp[k]= Arr[i];
        i++;
        k++;                              
     }                   
          while(j<=high)
     {
        temp[k]= Arr[j];
        j++;
        k++;                              
     }            
     for (k = low ; k <= high ; k++)
     Arr[k] = temp[k];
}
int main()
{
   int i , low , high;
time_t t;
	int start, end, total;
   int Arr[100];
   printf("\n ENTER THE NUMBER OF ELEMENTS WITH WHICH U WOULD LIKE TO WORK :");
   scanf("%d",&n);
srand((unsigned) time(&t));
	printf("\nTHE NUMBERS ARE : \n");
	for(i=0; i<n; i++)	
	Arr[i]=rand()%100;
	for(i=0;i<n;i++)
	printf("%d\t",Arr[i]);   
   low = 0;
   high = n-1;
start=clock();
   MergeSort(Arr,low,high);
end=clock();
   printf( " \nTHE ELEMENTS AFTER SORTING IS AS FOLLOWS: \n");
   for ( i = 0 ; i<n ; i++)
     printf("%d\t",Arr[i]);
	total=end-start;
	printf("\nTHE TOTAL TIME TAKEN IS: %dms \n",total);
}

