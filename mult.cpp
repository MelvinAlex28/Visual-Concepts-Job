//Matrix Multiplication Problem
#include<iostream>
#include<conio.h>
#include <stdlib.h>

class multiply
{
	int a[10][10], m,n;
	public:
	multiply()
	{

	}
	multiply(int m,int n)
	{
		this->m=m;
		this->n=n;
	}
	void arrange_matrix()
	{
        for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	    a[i][j]=0;
	}

	void rd_matrix();//to read the matrix
	void display_matrix();
	void multiply_matrix(multiply,multiply);
};
void multiply :: rd_matrix()
{
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
	    std::cout<<"enter element "<<i+1<<","<<j+1<<"?";
	    std::cin>>a[i][j];
	}
}
void multiply :: display_matrix()
{
	 std::cout<<"Matrices Values  :";
	for(int i=0;i<m;i++)
	{
	    for(int j=0;j<n;j++)
	    std::cout<<a[i][j]<<"  ";
	    std::cout<< std::endl;
	}
}
void multiply :: multiply_matrix(multiply m1,multiply m2)
{
	if(m1.n!=m2.m)
	 std::cout<<"Invalid ";
	else
	{
	  for(int i=0;i<m1.m;i++)
	   for(int j=0;j<m1.n;j++)
		for(int k=0;k<m2.n;k++)
		{
		  a[i][j]+=m1.a[i][k]*m2.a[k][j];
		}
	}
}
int main()
{
	int m,n,x,y;
	
	
    std::cout<<"Matrix 1 size: ";
	std::cin>>m>>n;
	multiply m1(m,n);
	m1.rd_matrix();
	std::cout<<"Matrix 2 size:";
    std::cin>>x>>y;
	multiply m2(x,y);
	m2.rd_matrix();
	multiply m3(m,y);
	m3.arrange_matrix();
	m3.multiply_matrix(m1,m2);
	m1.display_matrix();
	m2.display_matrix();
	m3.display_matrix();
	getch();
	return 0;
}
