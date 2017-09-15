#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

void display(int arr[],int n){
        for(int i=0;i<n;i++)
                cout<<arr[i]<<endl;
}
void swap(int arr[],int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
}
//Heap Sort
//O(n Log n)

void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(arr[left]>arr[largest] && left<n){
		largest=left;
	}
	if(arr[right]>arr[largest] && right<n){
		largest=right;
	}
	if(largest != i){
		swap(arr,i,largest);
		heapify(arr,n,largest);
	}
}
void heap_sort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		swap(arr,0,i);
		heapify(arr,i,0);
	}
	
}
int main(){
        int n;
        time_t t;
        srand((unsigned) t);
        cin>>n;
        int i=0;
        int arr[n];
        while(i<n){
                arr[i]=rand()%10;
                i++;
        }
        cout<<"Elements:"<<endl;
        display(arr,n);
        heap_sort(arr,n);
        cout<<"After Heap Sort"<<endl;
        display(arr,n);
}
