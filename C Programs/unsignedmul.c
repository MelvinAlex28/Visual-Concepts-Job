#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
 
void shift(int a[] , int q[] , int p, int m) 
{ 
	 int i,temp; 
	 temp = a[m-1]; 
	 for(i = m - 1;i >0; i--) 
	 a[i] = a[i-1]; 
 
	 for(i = p - 1; i > 0; i--) 
	 { 
		  q[i] = q[i-1]; 
	 } 
	 q[0] = temp; 
	 a[0] = 0; 
} 
 
void main() 
{ 
	 int m,q,i,n,q0; 
  
	 printf("Enter No. Of Bits of Multiplicand M: "); 
	 scanf("%d",&m); 
  
	 int M[m]; 
  
	 printf("\nEnter the multiplicant's value in binary(from 0 to 15):\n"); 
	 for(i = 0; i < m; i++) 
	 { 
		  scanf("%d",&M[i]); 
		  if(M[i] != 0 && M[i] != 1) 
		  { 
	   printf("\nWrong Input.\n"); 
	   exit(0); 
		  } 
	 }  
	 printf("Enter No. Of Bits of Multiplier Q: "); 
	 scanf("%d",&q); 
  
	 int Q[q]; 
  
	 printf("\nEnter the multiplier's value in binary(from 0 to 15):\n"); 
	 for(i = 0; i < q; i++) 
	 { 
		  scanf("%d",&Q[i]); 
		  if(Q[i] != 0 && Q[i] != 1) 
		  {  
			   printf("\nWrong Input.\n"); 
			   exit(0); 
		  }  
   
	 }  
 
	 int temp[m]; 
	 for(i = 0; i < m; i++) 
	  temp[i] = 0; 
	 int c; 
	 n = q; 
	 int A[m]; 
	 for(i = 0; i < m; i++) 
	  A[i] = 0; 
	 
	 printf("C = 0\tA ="); 
	 for(i = 0; i < m;i++) 
	  printf("%d",A[i]); 
	 printf("\tQ ="); 
	 for(i = 0; i < q;i++) 
	  printf("%d",Q[i]); 
	 printf("\tInitial operation"); 
 
	 int ch; 
	 while(n > 0) 
	 { 
	 
		 printf("\nDo You Want To see Step %d : (0/1)",q+1-n); 
		 scanf("%d",&ch);  
	 
		 if(ch == 1) 
		 { 
			  if( Q[q-1] == 1) 
			  { 
				   q0 = 1; 
				   for(i = 0; i < m; i++) 
				   temp[i] = A[i]; 
   
				   c = 0; 
  
				  for(i = m - 1 ;i >= 0; i--) 
				  { 
					   A[i] = temp[i] + M[i] + c; 
	    
					   if(A[i] == 3) 
					   { 
						    A[i] = 1; 
						    c = 1; 
					   } 
					   else if(A[i] == 2) 
					   { 
						    A[i] = 0; 
						    c = 1; 
					   } 
					   else if(A[i] == 0) 
					   { 
						    A[i] = 0; 
						    c = 0; 
					   } 
					   else if(A[i] == 1) 
					   { 
						    A[i] = 1; 
						    c = 0; 
					   } 
    
   
 				 } 
 			 } 
 			 else 
 			  q0 = 0; 
   
   
   
  			shift(A,Q,q,m); 
  			if(c == 1) 
  			 A[0] = c; 
  			n = n - 1; 
   	
 			printf("C = %d\tA =",c); 
 			for(i = 0; i < m;i++) 
	  		printf("%d",A[i]); 
 			printf("\tQ ="); 
 			for(i = 0; i < q;i++) 
 			 printf("%d",Q[i]); 
 			if(q0 == 0) 
 			 printf("\tOperation: Since Q0 = 0\tOnly Shift"); 
 			else 
 			 printf("\tOperation: Since Q0 = 1\tAdd and Shift");  
 
			 c = 0;  
 
		 } 
	}	 
   
  
	 printf("\nDo You Want To see Step %d : (0/1)",q+1-n); 
	 scanf("%d",&ch); 
	 if(ch == 1) 
	  printf("\nLast step is reached\n"); 
	  
	  
	 printf("Output Is:\n"); 
  
	 for(i = 0; i < m;i++) 
	  printf("%d",A[i]); 
   
	 printf("\t"); 
   
	 for(i = 0; i < q;i++) 
	  printf("%d",Q[i]); 
  
	 printf("\n"); 
  
} 

