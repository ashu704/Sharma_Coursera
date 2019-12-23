/******************************************************************************
   Copyright (C) 2017 by Alex Fosdick - University of Colorado
 
   Redistribution, modification or use of this software in source or binary
   forms is permitted as long as the files maintain this copyright. Users are 
   permitted to modify this and use it to learn about the field of embedded
   software. Alex Fosdick and the University of Colorado are not liable for any
   misuse of this material. 
 
 *****************************************************************************/
/*
   @file <Add File Name> 
   @brief <Add Brief Description Here >
 
   <Add Extended Description Here>
 
   @author  : Ashutosh Sharma
   @date    : 22.12.2019
 
 */



#include <stdio.h>
//#include <cstdio>
//#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void print_statistics(int*, int);   // A function that prints the statistics of an array including minimum, maximum, mean, and median.
void print_array(int*, int);        // Given an array of data and a length, prints the array to the screen
int find_median(int*, int);         // Given an array of data and a length, returns the median value
int find_mean(int*, int);           // Given an array of data and a length, returns the mean
int find_maximum(int*, int);        // Given an array of data and a length, returns the maximum
int find_minimum(int*, int);        // Given an array of data and a length, returns the minimum
void sort_array(int*, int);         // Given an array of data and a length, sorts the array in descending order.


int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  int a[40],n;
  printf("Enter the size of the array :");
  scanf("%d",&n);
  printf("Enter the elements of the array :");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  print_array(a,n);
  sort_array(a,n);
  print_array(a,n);
  print_statistics(a,n);
  return 0;

}






void print_array(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  
}

void sort_array(int * ptr, int n){
  int i,j,t;
  for (i = 0; i < n; i++){ 
    for (j = i + 1; j < n; j++){ 
      if (*(ptr + j) < *(ptr + i)){ 
        t = *(ptr + i); 
        *(ptr + i) = *(ptr + j); 
        *(ptr + j) = t; 
      } 
    } 
  } 
}

int find_mean(int a[], int n){
  int sum =0;
  for(int i=0; i<n; i++)
    sum += a[i];
  return(sum/n);
}

int find_median(int a[], int n){
  if(n%2==0)
    return ((a[n/2]+a[(n/2)-1])/2);
  else
    return a[n/2];
      
}

int find_maximum(int a[], int n){
  int max =a[0];
  for(int i=1;i<n;i++){
    if(a[i]>max)
      max = a[i];
  }
  return max;
}

int find_minimum(int a[], int n){
  int min =a[0];
  for(int i=1;i<n;i++){
    if(a[i]<min)
      min = a[i];
  }
  return min;
}

void print_statistics(int a[], int n){
  printf("median  :%d\n", find_median(a,n));
  printf("mean    :%d\n", find_mean(a,n));
  printf("maximum :%d\n", find_maximum(a,n));
  printf("minimum :%d\n", find_minimum(a,n));
}