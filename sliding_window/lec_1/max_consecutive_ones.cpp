/*
	https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

/* 
	we can use the concept of largest substring without repeating character, where we increase 'right' and when we get an invalid string we change left ahead of the first zero 
	again making it a valid string
	
	however we can optimize this further
	since this question can interpreted as the largest substring with atmost k 0's
	we don't need the i and j to signify the {start,end} indices of valid substrings, they can be used to know the size of the largest valid substring by their difference
	note the number of 0's by k (reduce k by 1 when you get a 0)
	at each iteration, 
	increase j by 1 and update k, 
	if substring becomes invalid, increase i by 1, and update k
	{
	here we don't need to take i to after the first 0 to make a valid substring because since we already know that the max so far is j-i we don't need to shorten our window thus saving time
	we need to only check for substrings of length j-i, so by incrementing i we maintain the size of the max string in the opration j-i and only check for substrings of size j-i
	therefore by the end i and j don't refer to the starting and ending indices of the substring but its size
	}
*/

#include <vector>

int longestOnes(vector<int>& nums, int k) {
	int i = 0,j;
	for (j = 0; j<nums.size(); j++){
	  if (nums[j] == 0) k--;
	  if (k < 0){
			if (nums[i] == 0) k++;
      i++;
		}
	}
	return j-i;
}
