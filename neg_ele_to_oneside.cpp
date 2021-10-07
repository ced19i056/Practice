#include<bits/stdc++.h>
using namespace std;
void neg_normal(int arr[],int n)
{
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
}
void neg_pointer(int arr[],int l,int r)
{
    while(l<=r){
        if(arr[l]<0 && arr[r]<0){
            l++;
        }else if(arr[l]>0 && arr[r]<0){
            int temp=arr[r];
            arr[r]=arr[l];
            arr[l]=temp;
            l++;
            r--;
        }else if(arr[l]>0 && arr[r]>0){
            r--;
        }else{
            l++;
            r--;
        }
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<"\n";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int option;
    cout<<"1.Normal_method   2.Two Pointer method"<<endl;
    cin>>option;
    if(option==1){
        neg_normal(arr,n);
    }else{
        neg_pointer(arr,0,n-1);
    }
    print(arr,n);
    return 0;
}
