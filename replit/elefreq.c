#include <stdio.h>
int main ()
{
  int arr[10][2], brr[10][2];
  int k = 0, n = 10, temp, count;
  int num[10];
  //Initialize array elements 
  printf ("Enter the array elements :");
  scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
    &arr[0][0],&arr[1][0],&arr[2][0],&arr[3][0],&arr[4][0],&arr[5][0],&arr[6][0],&arr[7][0], &arr[8][0], &arr[9][0]);
  for (int i = 0; i < n; i++)
    {
      arr[i][1] = 0;
    }
  // Unique elements and its frequency are stored in another array
  for (int i = 0; i < n; i++)
    {
      if (arr[i][1])
	continue;
      count = 1;
      for (int j = i + 1; j < n; j++)
	{
	  if (arr[i][0] == arr[j][0])
	    {
	      arr[j][1] = 1;
	      count++;
	    }
	}
      brr[k][0] = arr[i][0];
      brr[k][1] = count;
      k++;
    }
  n = k;
    for (int i = 0; i < n - 1; i++)
    {
      temp = brr[i][0];
      for (int j = i + 1; j < n; j++)
	{
	  if (temp > brr[j][0])
	    {
	      temp = brr[j][0];
	      brr[j][0] = brr[i][0];
	      brr[i][0] = temp;
	    }
	}
    }
  //Print the elements and its frequency
  for (int i = 0; i < n; i++)
    {
      printf ("Element %d: Frequency = %d \n", brr[i][0], brr[i][1]);
    }
  return 0;
}