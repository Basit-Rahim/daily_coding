/*

An sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster than linear time. 
If the element doesn't exist in the array, return null.For example, 
given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
[a,b,c,d,...,n]


*/

#include<iostream>
#include<vector>
using namespace std;

int searchRotated(const vector<int>& nums, int target){
	// Modified binary search on rotated sorted array with unique elements
	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return mid;

		// Left half is sorted
		if (nums[left] <= nums[mid]){
			if (nums[left] <= target && target < nums[mid]){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}else{ // Right half is sorted
			if (nums[mid] < target && target <= nums[right]){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
	}
	return -1; // not found
}

int main(){
	vector<int> nums = {13, 18, 25, 2, 8, 10};
	int target = 8;
	int idx = searchRotated(nums, target);
	cout << idx << endl;
	return 0;
}
