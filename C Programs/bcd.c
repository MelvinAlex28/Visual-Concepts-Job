#include<stdio.h>

void binary(int num);
int sbinary(int num);
int correct(int sum);
int res[10];

int main()
{
	int a, b, sum, i, c_in, c_out, corr;

	printf("Enter two numbers less than 16: \n");
	printf("Enter first number: ");
	scanf("%d",&a);
	if(a>16)
	{
		printf("\nEnter first number again: ");
		scanf("%d",&a);
	}
	printf("Binary equivalent of A: \n");
	binary(a);	
	printf("\nEnter second number: ");	
	scanf("%d",&b);
	if(b>16)
	{
		printf("\nEnter second number again: ");	
		scanf("%d",&b);
	}
	printf("Binary equivalent of B: \n");
	binary(b);

	printf("Enter value of C_in: \n");
	scanf("%d",&c_in);

	switch(c_in)
	{
		case 0: 
			sum = a+b;
			corr = correct(sum);
			sum = sum + corr;
			printf("Sum of A and B is : \n");			
			c_out = sbinary(sum);
			printf("C_out : %d \n",c_out);
			break;
		case 1:
			sum = a+b+c_in;			
			corr = correct(sum);
			sum = sum + corr;
			printf("Sum of A and B is : \n");		
			c_out = sbinary(sum);		
			printf("C_out : %d \n",c_out);		
			break;
		default:
			printf("C_in entered is not valid! \n");
	}
	
	return(0);
}

int sbinary(int num)
{
	int r, i, cnt = 0;

	do
	{
		r = num%2;
		num = num/2;
		res[cnt] = r; 
		cnt++;
	}while(num!=0);
	
	for(i=cnt-2; i>=0; i--)
		printf("%d",res[i]);
	printf("\n");				 

	return res[cnt-1];
}

void binary(int num)
{
	int r, i, cnt = 0;

	do
	{
		r = num%2;
		num = num/2;
		res[cnt] = r; 
		cnt++;
	}while(num!=0);
	
	for(i=cnt-1; i>=0; i--)
		printf("%d",res[i]);
	printf("\n");
}

int correct(int sum)
{
	if(sum>=9)
		return(6);
		
	else
		return(0);	
}

