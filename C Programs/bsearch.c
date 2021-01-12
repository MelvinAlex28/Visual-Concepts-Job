#include<stdio.h>

int pos,key,id,temp,flag=0;

int bsearch(int [],int,int,int);



int main()

{

	int x[10],n,i;



	printf("Enter the no. of elements in array:");

	scanf("%d",&n);
 



	printf("Enter %d numbers in sorted order:",n);



	for(i=0;i<n;i++)

	scanf("%d",&x[i]);



	printf("Enter no. to search:");

	scanf("%d",&key);



	id=1;

	bsearch(x,0,n-1,key);



	if(flag==1)

	{

		printf("\nFirst occurrence of %d at %d index",key,pos);

		temp=pos;



		id=2;

		bsearch(x,0,n-1,key);

		printf("\nLast occurrence of %d at %d index",key,pos);



		printf("\n%d occurs %d times",key,pos-temp+1);

	}



	else

	printf("Element not found!!");

}



int bsearch(int a[],int start,int end,int key)
 

{



	while(start<=end)

	{

		int mid = (start+end)/2;



		if(key==a[mid])

		{

			pos=mid;

			flag=1;



			if(id==1)

			return(bsearch(a,start,mid-1,key));



			else

			return(bsearch(a,mid+1,end,key));

		}

		else if(key>a[mid])

		return(bsearch(a,mid+1,end,key));

		else

		return(bsearch(a,start,mid-1,key));

	}

}


