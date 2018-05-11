//算法


#include "stdafx.h"using namespace std;void printArry(int a[],int len){ for(int i=0;i<len;i++){  cout<<a[i]<<" "; } cout<<endl;}//插入排序void insertSort(int a[],int len){ for(int i=1;i<len;i++){  //假设i之前的已经排序完毕  int pro=a[i];  int j=i-1;  while(j>=0&&pro<a[j]){   a[j+1]=a[j];   j--;  }  a[j+1]=pro; }}//二分插入排序   当比较操作比交换操作更麻烦void dvInsertSort(int a[],int len){ for(int i=1;i<len;i++){  //假设i之前的已经排序完毕  int get=a[i];  int left=0;  int right=i-1;  while(left<=right){   int mid=(left+right)/2;   if(a[mid]>get)    right=mid-1;   else    left=mid+1;  }  for(int j=i-1;j>=left;j--){   a[j+1]=a[j];  }  a[left]=get; }}
//希尔排序void shellSort(int a[],int len){ int sep=1; while(sep<len)  sep=sep*3+1; while(sep>=1){  for(int i=sep;i<len;i++){   int j=i-sep;   int get=a[i];   while(j>=0&&a[j]>get){    a[j+sep]=a[j];    j-=sep;   }   a[j+sep]=get;  }
  sep=(sep-1)/3; }}
//选择排序void selectSort(int a[],int len){ for(int i=0;i<len-1;i++){  int min=i;  for(int j=i+1;j<len;j++){   if(a[j]<a[min]){    min=j;   }  }  if(min!=i){   int tmp=a[i];   a[i]=a[min];   a[min]=tmp;  } }}
//合并排序完毕的数组 left-mid   mid+1-rightvoid mergeArry(int a[],int left,int mid,int right){ int len=right-left+1; int * tmp=new int[len]; int i=left,index=0; int j=mid+1; while(i<=mid&&j<=right){  tmp[index++]=a[i]<=a[j]?a[i++]:a[j++]; } while(i<=mid)  tmp[index++]=a[i++]; while(j<=right)  tmp[index++]=a[j++]; for(index=0;index<len;index++)  a[left+index]=tmp[index];
 delete []tmp;}void mergeSort(int a[],int left,int right){ if(left==right)  return; int mid=(left+right)/2; mergeSort(a,left,mid); mergeSort(a,mid+1,right); mergeArry(a,left,mid,right);}
void mergeSort_2(int a[],int len){ int left,mid,right; for(int i=1;i<len;i*=2){  left=0;  while(left+i<len){   mid=left+i-1;   right=mid+i<len?mid+i:len-1;   mergeArry(a,left,mid,right);   left=right+1;  }
 }}
int quickPart(int a[],int left,int right){ int get=a[right]; int tail=left-1; for(int i=left;i<right;i++){  if(a[i]<=get){   if(i!=tail+1){    int tmp=a[i];    a[i]=a[tail+1];    a[tail+1]=tmp;   }   tail++;  } } a[right]=a[tail+1]; a[tail+1]=get;
 return tail+1;
}
void quickSort(int a[],int left,int right){ if(left>=right)  return; int get_index=quickPart(a,left,right); quickSort(a,left,get_index-1); quickSort(a,get_index+1,right);}
void swap(int a[],int i,int j){ int tmp =a[i]; a[i]=a[j]; a[j]=tmp;}
void heapSort(int a[],int len){ int heapSize=buildHeap(a,len); printArry(a,15); while(heapSize>1){  swap(a,0,--heapSize);  heapIfy(a,0,heapSize);  cout<<heapSize<<endl;  printArry(a,15); }
}int buildHeap(int a[],int len){ for(int i=len/2-1;i>=0;i--){  heapIfy(a,i,len); } return len;}void heapIfy(int a[],int i,int len){ int lch=i*2+1; int rch=i*2+2; int max=i; if(lch<len&&a[lch]>a[max])  max=lch; if(rch<len&&a[rch]>a[max])  max=rch; if(i!=max){  swap(a,i,max);  heapIfy(a,max,len); }}

