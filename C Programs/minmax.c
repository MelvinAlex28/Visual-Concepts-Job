#include<time.h>
#include<stdio.h>
int max, min;
int a[100];

int main ()
{
 int i, num,d,c;
 time_t t;
 printf ("\nENTER THE NUMBER OF ELEMENTS WITH WHICH U WOULD LIKE TO WORK : ");
 scanf ("%d",&num);
  printf ("THE NUMBERS ARE : \n");
 srand((unsigned) time(&t));
 for (i=1;i<=num;i++)
 // scanf ("%d",&a[i]);
   a[i]=rand()%100;
    for (i=1;i<=num;i++)
 printf ("%d\t",a[i]);
 max = a[0];
 min = a[0];
 c=clock();
 minmax(1, num);
 d=clock();
 d=d-c;
 printf ("\nTHE MINIMUM ELEMENT PRESENT IN THIS LIST IS : %d\n", min);
 printf ("THE MAXIMUM ELEMENT PRESENT IN THIS LIST IS : %d\n", max);
 printf("TOTAL TIME TAKEN IS: %d ms \n",d);
 return 0;
}
void minmax(int i, int j)
{
 int max1, min1, mid;
  
 if(i==j)
 {
  max = min = a[i];
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    max = a[j];
    min = a[i];
   }
   else
   {
    max = a[i];
    min = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   minmax(i, mid);
   max1 = max; min1 = min;
   minmax(mid+1, j);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}

