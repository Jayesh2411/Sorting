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
//Selection Sort

void selection_sort(int arr[],int n){
	int i,j,min=0;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		swap(arr,min,i);
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
	selection_sort(arr,n);
	cout<<"After Selection Sort"<<endl;
	display(arr,n);
}
