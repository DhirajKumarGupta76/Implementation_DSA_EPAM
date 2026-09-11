// Idea::
// Compare adjacent elements.
// If they are in the wrong order, swap them.
// After each pass, the largest element moves to the end (like a bubble rising to the top).

//This simple optimization makes Bubble Sort much faster for already sorted or nearly sorted arrays

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){

    int n = arr.size();

    for(int i=0;i<n-1;i++){

        bool swapped = false;

        for(int j=0;j<n-i-1;j++){

            if(arr[j] > arr[j+1]){

                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
//No swaps happened → The array is already sorted → Stop early with:
        if(!swapped)
            break;
    }
}

int main(){

    vector<int> arr = {5,1,4,2,8};

    bubbleSort(arr);

    for(int x:arr)
        cout<<x<<" ";

}