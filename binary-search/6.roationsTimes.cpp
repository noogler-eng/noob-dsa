// find kth roations
// it also includes the minimum value of the array

#include<iostream>
using namespace std;

// Input: arr = [5, 1, 2, 3, 4]
// we have to find that element which is lesser then next but greater then prev
// if not found then it is sorted
int findKRotation(vector<int> &arr) {
    int low = 0;
    int high = arr.size()-1;
    int n = arr.size()-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        // finding th pivot which is smallest element
        if(arr[mid % n] <= arr[(mid+1) % n] && arr[mid % n] <= arr[(mid-1) % n]){
            return mid;
        }else if(arr[mid] <= arr[high]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }    
    return 0;
}