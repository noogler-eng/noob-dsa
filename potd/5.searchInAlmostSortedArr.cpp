// Search In Almost Sorted Array
// where some elements of the array are moved to either of the adjacent 
// positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].

// time complexity o(N)
// space complexity o(1)
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == target) return i;
        }
        return -1;
    }
};

// optmized time complexity o(logN)
// space complexity o(1)
// [10, 3, 40, 20, 50, 80, 70],
// target = 40
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return mid;
            // here if the element is found like 30 is not found now it will not be found
            if(mid > low && arr[mid-1] == target) return mid-1;
            if(mid < high && arr[mid+1] == target) return mid+1;

            if(arr[mid] > target) {
                // we are skipping mid - 1 as we already checked it 
                // if that is target then already returned
                high = mid - 2;
            }
            if(arr[mid] < target) {
                // we are skipping mid + 1 as we already checked it 
                // if that is target then already returned
                low = mid + 2;
            }
        }

        return -1;
    }
};
