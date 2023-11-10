/*Name- Harshdeep*/
#include<stdio.h>
void array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int partition(int arr[],int low,int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    int temp;
    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[j];
    arr[j]=pivot;
    pivot=temp;
    
    return j;

}
void quicksort(int arr[],int p,int r){
    if(p<r){
        int m;
        m=partition(arr,p,r);
        quicksort(arr,p,m-1);
        quicksort(arr,m+1,r);
    }
}
int main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements are: ");
    array(arr,n);
    quicksort(arr,0,n);
    printf("\nThe sorted elements are: ");
    array(arr,n);
    return 0;
}