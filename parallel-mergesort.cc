/**
 *  \file parallel-mergesort.cc
 *
 *  \brief Implement your parallel mergesort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.hh"
//#include "omp.h"

void seqMerge(keytype* arr,int start,int middle,int end)
{
	int position_a=0,position_b=0;
	int len_a = middle-start;
	int len_b = end-middle+1;
	int position_arr = start;


	//Copy first part in A and second part in B

	keytype* A = newKeys(len_a);
	memcpy(A,arr,len_a*sizeof(keytype));

	keytype* B = newKeys(len_b);
	memcpy(B,arr + middle,len_b*sizeof(keytype));

	for(int i=0;i<len_a;i++) A[i] = arr[i+start];

		for(int i=0;i<len_b;i++) B[i] = arr[i+middle];


			while(position_a < len_a && position_b < len_b)
			{
				if(A[position_a] < B[position_b])
				{
					arr[position_arr] = A[position_a];
					position_a ++ ;
					position_arr++;
				}
				else
				{
					arr[position_arr] = B[position_b];
					position_b ++;
					position_arr++;

				}
			}
			if(position_a < len_a)
			{
				for(int i = position_a;i<len_a;i++)
				{
					arr[position_arr] = A[i];
					position_arr ++;
				}
			}
			else if(position_b < len_b)
			{
				for(int i = position_b;i<len_b;i++)
				{
					arr[position_arr] = B[i];
					position_arr++;

				}
			}



}

void seqMergeSort(keytype* arr, int start,int end)
{
	if(start>=end) return;
	int mid = int((start+end+1)/2);
	seqMergeSort(arr,start,mid-1);
	seqMergeSort(arr,mid,end); //here mid is the beginning of the second array
	seqMerge(arr,start,mid,end);
	return;

}

void parallelSort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
	// #pragma omp parallel
	// {
	// 	int id = omp_get_thread_num();
	// 	printf("hello %d ",id);
	// 	print("world %d\n",id);
	// }
	seqMergeSort(A,0,N-1);				
}

/* eof */

/*
#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int start, int middle, int end)
{
 
  //middle is whether the second array starts
  
  //Initialize vectors A and B and copy elements
  
  
  
  
  
  int position_a=0,position_b=0;
  int len_a = middle-start;
  int len_b = end-middle+1;
  int position_arr = start;
  
  vector<int> A(len_a,0);
  vector<int> B(len_b,0);
  
  for(int i=0;i<len_a;i++) A[i] = arr[i+start];
  
  for(int i=0;i<len_b;i++) B[i] = arr[i+middle];
  
   
  while(position_a < len_a && position_b < len_b)
  {
    if(A[position_a] < B[position_b])
    {
      arr[position_arr] = A[position_a];
      position_a ++ ;
      position_arr++;
    }
    else
    {
      arr[position_arr] = B[position_b];
      position_b ++;
      position_arr++;
      
    }
  }
  if(position_a < len_a)
  {
    for(int i = position_a;i<len_a;i++)
    {
      arr[position_arr] = A[i];
      position_arr ++;
    }
  }
  else if(position_b < len_b)
  {
     for(int i = position_b;i<len_b;i++)
    {
      arr[position_arr] = B[i];
       position_arr++;
       
    }
  }
  
  
}


void mergeSort(int arr[], int start, int end)
{
  if(start>=end) return;
  int mid = int((start+end+1)/2);
  mergeSort(arr,start,mid-1);
  mergeSort(arr,mid,end); //here mid is the beginning of the second array
  merge(arr,start,mid,end);
  return;
  
  
}

int main() {
  cout<<"Hello";
  

 
  int array[10] = {5,8,2,3,9,1,0,9,-3,8};
  int n = 10;
    mergeSort(array, 0, n-1);
 
    cout<<"\n Array after sorting : ";
 
    for(int i=0;i<n;i++)
     cout<<array[i]<<" ";
 
  return 0;
  
}



*/