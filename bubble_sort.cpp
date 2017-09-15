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

void bubble_sort(int arr[],int n){
        int i,j;
        for(i=0;i<n;i++){
                
                for(j=0;j<n-i-1;j++){
                        if(arr[j]>arr[j+1]){
                                swap(arr,j,j+1);
                        }
                }
                
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
        bubble_sort(arr,n);
        cout<<"After Bubble Sort"<<endl;
        display(arr,n);
}
