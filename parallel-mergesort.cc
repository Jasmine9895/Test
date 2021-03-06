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

//	keytype* A = newKeys(len_a);
//	memcpy(A,arr+start,len_a*sizeof(keytype));

		keytype A[len_a];
		keytype B[len_b];

		for(int i=0;i<len_a;i++) A[i] = arr[i+start];

	  for(int i=0;i<len_b;i++) B[i] = arr[i+middle];

//	keytype* B = newKeys(len_b);
//	memcpy(B,arr + middle,len_b*sizeof(keytype));


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
int binary_search(keytype* arr,int val,int len_arr,int start,int end)
{
  //Should return index of array such that arr[index] <= val


  int mid = (start+end)/2;

  while(start<=end)
  {
      mid = (start+end)/2;
      if(arr[mid] == val)
      {
        return mid;
      }
      else if(arr[mid] > val)
      {
          end = mid-1;
      }
      else
      {
          start = mid +1;
      }

  }


  if(start >= len_arr) return start; //Greater than all elements in array(=len_arr)
  else if(end <0) return end; //Lesser than all elements in array - (-1)
  else return ((start+end)/2); //between 2 values

}




void parallel_merge(keytype* arr,int start,int middle,int end)
{
  //middle is whether the second array starts
  //Initialize vectors A and B and copy elements


  if(start>= middle || middle>end || start>=end)
  {
<<<<<<< HEAD

=======
    printf("return from parallel merge\n");
>>>>>>> parent of 2ee78ea... Print statements now commented
    return;
  }
  if(end-start==1)
  {
    //This case is when there are only 2 elements to be merged
    if(arr[start] > arr[end])
    {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end]= temp;

    }
<<<<<<< HEAD
=======

    printf("Sorted array is");
    for(int i=start;i<=end;i++) printf("%d ", arr[i]);

      printf("\n");
    printf("Returning from parallel_merge\n");

>>>>>>> parent of 2ee78ea... Print statements now commented
    return;
  }

  // int position_a=start,position_b=middle;
	int position_a=0,position_b=0;
  int len_a = middle-start;
  int len_b = end-middle+1;
  int position_arr = start;


  //Copy first part in A and second part in B

<<<<<<< HEAD
	keytype A[len_a];
	keytype B[len_b];

	for(int i=0;i<len_a;i++) A[i] = arr[i+start];

	for(int i=0;i<len_b;i++) B[i] = arr[i+middle];
=======
    printf("Values in A: ");
  for(int i=0;i<len_a;i++){


    printf("%d ", A[i]);
  } 

  printf("\n");
  printf("Values in B: ");
  for(int i=0;i<len_b;i++)
  {

    printf("%d ", B[i]);
  } 
  printf("\n");

  printf("Callling binary_search for value %d at index %d in A\n",v,mid_a);
>>>>>>> parent of 2ee78ea... Print statements now commented

  // keytype* A = newKeys(len_a);
  // memcpy(A,arr+start,len_a*sizeof(keytype));
  //
  // keytype* B = newKeys(len_b);
  // memcpy(B,arr + middle,len_b*sizeof(keytype));

<<<<<<< HEAD
  int mid_a = len_a/2;
=======
  //3 cases > all , < all, middle
  //value returned such that B[k] <=v
  printf("binary_search result value = %d at index %d in B\n",B[k],k);
>>>>>>> parent of 2ee78ea... Print statements now commented

  keytype v = A[mid_a];
  //int k = binary_search(B,v,len_b,middle,end);
	int k = binary_search(B,v,len_b,0,len_b-1);

  if(k>=middle && k<end+1)
  {
    int p = start+mid_a;
    int q = p+k+1;
    int r = q+len_a-mid_a;

    //Below 3 can be parallelized

    for(int i=p;i<q;i++)
    {
      arr[i] = B[i-p];

    }

    for(int i=q;i<r;i++)
    {
      arr[i] = A[mid_a+i-q];
    }

    for(int i=r;i<=end;i++)
    {
      arr[i] = B[k+1+i-r];
    }

    parallel_merge(arr,start,p,q-1);
    parallel_merge(arr,q,r,end);

  }
  else if(k<0)
  {
<<<<<<< HEAD
    //all elements in B are greater than mid-point of A
    //a1b1a2b2, there is no b1, as all elements are greater than mid-point of a, so there is just b2, which includes all of b
    //so we can directly call parallel merge , no need to modify elements , just modify the call(just a1b1b2)
   parallel_merge(arr,start+mid_a+1,middle,end); //mid_a + 1 as have to merge a2b, mid_a is in a1
=======
    printf("k<0 case:\n");

    //all elements in B are greater than mid-point of A
    //a1b1a2b2, there is no b1, as all elements are greater than mid-point of a, so there is just b2, which includes all of b
    //so we can directly call parallel merge , no need to modify elements , just modify the call(just a1b1b2)
    int st = start+mid_a+1;
    int  m= middle;
    int  e =end;

    printf("Calling parallel_merge st= arr[%d] = %d, mid =arr[%d]= %d , end = arr[%d]=%d\n",st,arr[st],m,arr[m],e,arr[e]);
      parallel_merge(arr,start+mid_a+1,middle,end); //mid_a + 1 as have to merge a2b, mid_a is in a1
>>>>>>> parent of 2ee78ea... Print statements now commented

  }
  else if(k>=len_b)
  {
      //all elements of b are less than mid_point of A
      //a1b1a2b2, no b2, therefore just a1,b1a2
      int p = start+mid_a;
      int q = p+len_b;//here I am assuming that k= len_b
      //int r = q+len_a-mid_a;

      for(int i=p;i<q;i++)
      {
        arr[i] = B[i-p];
      }
      for(int i=q;i<=end;i++)
      {
        arr[i] = A[mid_a+i-q];
      }
      //just a1,b1 has to be merged, a2 can be left as it is
      parallel_merge(arr,start,p,q-1);

  }
<<<<<<< HEAD
=======
  printf("Completed parallel merge for \n");
  printf("Values in A: ");
  for(int i=0;i<len_a;i++){


    printf("%d ", A[i]);
  } 

  printf("\n");
  printf("Values in B: ");
  for(int i=0;i<len_b;i++)
  {

    printf("%d ", B[i]);
  } 

  printf("\n final result\n");
  for(int i=start;i<=end;i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n----------------\n");
>>>>>>> parent of 2ee78ea... Print statements now commented

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



void parMergeSort(keytype* arr, int start,int end)
{
  if(start>=end) return;
  int mid = int((start+end+1)/2);

<<<<<<< HEAD
  parMergeSort(arr,start,mid-1);
  parMergeSort(arr,mid,end); //here mid is the beginning of the second array

=======
  printf("Calling merge Sort : start: %lu, mid= %lu, end=%lu\n",start,mid,end);
  parMergeSort(arr,start,mid-1);
  parMergeSort(arr,mid,end); //here mid is the beginning of the second array
  
  printf("Calling merge: : start: %lu, mid= %lu, end=%lu\n",start,mid,end);
>>>>>>> parent of 2ee78ea... Print statements now commented
  parallel_merge(arr,start,mid,end);
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

  printf("Before sort\n");
  for(int i=0;i<N;i++) printf("%lu ",A[i]);

  int sp =1;
	if(sp == 0)
  {
    seqMergeSort(A,0,N-1);
  }
  else
  {
<<<<<<< HEAD
    parMergeSort(A,0,N-1);
  }
 // printf("\nAfter sort\n");
=======
    parMergeSort(A,0,N-1);  
  }			
  printf("\nAfter sort\n");
>>>>>>> parent of 2ee78ea... Print statements now commented

  for(int i=0;i<N;i++) printf("%lu ",A[i]);
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
