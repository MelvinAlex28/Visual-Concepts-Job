#include<stdio.h>
int schedule[65][65]; int row,column,n; void tennis(int n)
{
if (n==2)
{
 



}
else
{
 
schedule[1][1]=2;
schedule[1][2]=1;





tennis(n/2);
for (column = 1; column <= n/2-1; column++)
{
 
for(row = n/2+1; row <= n; row++)
{

schedule[column][row]=(schedule[column][row- n/2]+n/2);
}
}
for (row =1 ; row <= n/2; row++)
{
schedule[n/2][row]=row+n/2;
}
for (row =n/2+1 ; row <= n; row++)
{
schedule[n/2][row]=row-n/2;
}
for (column = n/2+1; column <= n-1; column++)
{
for (row = 1; row <=n/2; row++)
{
if ((schedule[column-1][row]+1)>n)
{

 



 
schedule[column][row]=(schedule[column-1][row]+1)-n/2;


}
else
{


schedule[column][row]=schedule[column-1][row]+1;
}
 
}
 
}
for(column = n/2+1; column <= n-1; column++)
{
for ( row = n/2+1; row <=n; row++)
{
if((schedule[column-1][row]-1)<1)
{


schedule[column][row]=(schedule[column-1][row]-
1)+n/2;
}
else
{


schedule[column][row]=schedule[column-1][row]-1;
}
}
}
}
}

void showSchedule(int n)
{
printf("\t");
for (column = 1; column <=n-1; column++)
{
printf("%d\t",column);
}
printf("\n\n");
for(row = 1; row <=n; row++)
{
printf("%d\t",row);
for ( column = 1; column <=n-1; column++)
{
printf("%d\t",schedule[column][row]);
}
printf("\n");
}
}

void main()
{
printf("Enter number of players \n");
scanf("%d",&n); tennis(n); showSchedule(n);
 
}
