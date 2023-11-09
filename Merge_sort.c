#include<stdio.h>
void array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void merge(int arr[],int p,int q,int r){
    int i,j,k,temp[r+1];
    i=p;
    j=q+1;
    k=p;
    while(i<=q&&j<=r){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=q){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(k=p;k<=r;k++){
        arr[k]=temp[k];
    }

}
void mergesort(int arr[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
int main(){
    int arr[100];
    int n;
    printf("enter the no.element in array: ",n);
    scanf("%d",&n);
    int p=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nThe array is: ");
    array(arr,n);
    mergesort(arr,p,n-1);
    printf("\nThe sorted array is: ");
    array(arr,n);
    return 0;
}