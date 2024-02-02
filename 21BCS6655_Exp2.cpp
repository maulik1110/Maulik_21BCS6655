// not working

#include<iostream>
using namespace std;


void rotatebyD(int arr[],int d, int n){
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i-d] = arr[i];
    }
    
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i - (n - d)];
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cin>>d;

    rotatebyD(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}