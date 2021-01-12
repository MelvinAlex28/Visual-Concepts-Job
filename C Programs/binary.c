#include <stdio.h>
#include<time.h>
 
int main()
{
   int i, j, first, last, middle, n, search,start,end, array[100], temp, flag=0;
time_t t;
 
   printf("Enter no. of elements: \n");
	scanf("%d",&n);
start=clock();
	srand((unsigned) time(&t));
	printf("\nElements randomly generated are: \n");
	for(i=0; i<n; i++)	
		array[i]=rand()%100;
for(i=0; i<n; i++)	
		printf("%d\t",array[i]);	
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<n-i-1; j++)
			{
				if(array[j]>array[j+1])
				{
				 	temp=array[j];
				 	array[j]=array[j+1];
				 	array[j+1]=temp;
				}
			}
		}
printf("\nsorted elements are: \t");
for(i=0; i<n; i++)	
		
		printf("%d\t",array[i]);	


		
printf("\nEnter value to find\n");
   scanf("%d", &search);
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         flag=1;
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (flag==0)
      printf("Not found! %d is not present in the list.\n", search);
end=clock();
printf("time taken is %d\n",end-start);
   return 0;
  
}

