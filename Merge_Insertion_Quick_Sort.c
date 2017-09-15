#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000

void swap(int arr[],int i,int j)
{
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
}
int partition(int arr[],int p,int q)
{
        int i,j,x,k;
        x=arr[q];
        i=p-1;
        for(j=p;j<q-1;j++)
        {
                if(arr[j]<x)
                {
                        i=i+1;
                        swap(arr,j,i);
                }
        }
        swap(arr,i+1,q);
        return i+1;
}
void quick(int arr[],int p,int q)
{
        int x;
        if(p<q)
        {
                x=partition(arr,p,q);
                quick(arr,p,x-1);
                quick(arr,x+1,q);
        }
}
void insertion_sort(int arr[],int n)
{
        int i,j;
        for(i=1;i<n;i++)
        {
                j=i;
                while(j>0 && arr[j]<=arr[j-1])
                {
                        swap(arr,j,j-1);
                        j=j-1;
                }
        }
}
void merge(int arr[],int s,int m1,int m2,int e);
void merge_sort(int arr[],int i,int j)
{
        int mid;
        if(i<j)
        {
                mid=(i+j)/2;
                merge_sort(arr,i,mid);
                merge_sort(arr,mid+1,j);
                merge(arr,i,mid,mid+1,j);
        }
}
void merge(int arr[],int s,int m1,int m2,int e)
{
        int i,j,k=0,temp;
        int b[N];
        i=s;
        j=m2;
        while(i<=m1 && j<=e)
        {
                if(arr[i]<arr[j])
                        b[k++]=arr[i++];
                else
                        b[k++]=arr[j++];
        }
        while(i<=m1)
        {
                b[k++]=arr[i++];
        }
        while(j<=e)
        {
                b[k++]=arr[j++];
        }
        for(i=s,k=0;i<=e;i++,k++)
        {
                arr[i]=b[k];
        }
}
int main()
{

        int arr[N];
        int i,j,n,k,val;
        n=N;
        FILE *fp1,*fp2;
        fp1=fopen("file1.dat","w+");


        time_t t;
        clock_t starti,endi,diff,sm,em,dm,sq,eq,dq;
        srand(t);
        for(i=0;i<N;i++)
        {
                val=rand();
                fprintf(fp1,"%d\n",val);

        }
        fclose(fp1);
        fp1=fopen("file1.dat","r");
        for(k=0;k<N;k++)
        {
                fscanf(fp1,"%d\n",&arr[k]);
        }
        fp2=fopen("file2.dat","w+");


        starti=clock();
        insertion_sort(arr,n-1);
        endi=clock();
        diff=endi-starti;
         for(i=0;i<N;i++){
                printf("\n %d: %d ",i,arr[i] );
                       }
                printf("\nNo of clock cycles: %ld",diff);
                 printf("\nNo of clock cycles per sec: %f",((float)CLOCKS_PER_SEC));
                printf("\n Time taken:%f ",(((float)diff)/CLOCKS_PER_SEC));

        sm=clock();
        merge_sort(arr,0,n-1);
        em=clock();
        dm=em-sm;
        printf("\nMerge Sort!");
        for(i=0;i<N;i++){
                printf("\n %d: %d ",i,arr[i] );
                        }
                printf("\nNo of clock cycles: %ld",dm);

                printf("\n Time taken:%f ",(((float)dm)/CLOCKS_PER_SEC));

        printf("\nQuick Sort!");
        sq=clock();
        quick(arr,0,n-1);
        eq=clock();
        dq=eq-sq;
        for(i=0;i<N;i++)
        {
                printf("\n%d: %d\n",i,arr[i]);
        }
        printf("No of clock cycles: %f \n Time taken: %f \n",(float)dq,(((float)dq)/CLOCKS_PER_SEC));




        printf("\nComparing Results\n");
        printf("\n\n===============================================================================================\n \n");
         printf("\n\tInsertion Sort\n \nNo of clock cycles: %f \n",(float)diff);
                printf("Time taken: %f \n\n",(((float)diff)/CLOCKS_PER_SEC));
         printf("\n\tMerge Sort \n");
                printf("\nClocks Cycles:%f\n",(float)dm);
                printf("Time taken:%f \n\n",(((float)dm)/CLOCKS_PER_SEC));
        printf("\n\tQuick Sort:\n\nClock Cycles: %f \nTime Taken: %f\n ",(float)dq,(((float)dq)/CLOCKS_PER_SEC));
        printf("\n==================================================================================================================\n \n");

        float perc;
        int flag=0;
        if(dm<diff)
                {
                        if(dm<dq)
                                flag=1;
                        else
                                flag=2;
                }
        else
                flag=3;
                        if(flag==1)
                        {
                                printf("\nMerge Sort is faster ");
                                perc=((diff-dm)/dm)*100;
                                printf("by %f percent.\n",perc);
                        }
                        else if(flag==2)
                        {
                                perc=((diff-dq)/dq)*100;
                                printf("\nQuick Sort is faster by %f \n",perc);

                        }
                        else
                                printf("Insertion Sort is faster! pffft!!");
        i=0;
        j=0;
                                                                                                                           158,1-8       58%
              fprintf(fp2,"%d\n %d\n %d\n",(int)diff,(int)dm,(int)dq);
        fclose(fp1);
        fclose(fp2);
        fp2=fopen("file2.dat","r");
        int res;
        fscanf(fp2,"%d \n",&res);
        while(res!=EOF)
        {
                printf("%d\n ",res);
                fscanf(fp2,"%d \n",&res);
        }

        fclose(fp2);
        printf("\n\n");
}

