/*
	https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

/*
	increase 'right' which increases the window size and if we get an invalid substring we change 'left' to be just ahead of the charecter that is being repeated
	we can do this by two ways
		. using while to find that character
		. storing the indices of occurence in a data structure
*/

#include <iostream>
#include <unordered_set> 
#include <unordered_map>
#include <algorithm>
#include <string>

// method - using set
int methodOne(std::string s){
	int left = 0;
	int length = s.length();
	int maxLength = 0;

	std::unordered_set<char> charSet;

	for (int right = 0; right < length; right++){
		if (charSet.count(s[right]) == 0){
			charSet.insert(s[right]);
			maxLength = std::max(maxLength, right-left+1);
		}
		else{
			while (charSet.count(s[right])){
				charSet.erase(s[left]);
				left++;
			}
			charSet.insert(s[right]);
		}
	}
	return maxLength;
}

// method - using map
int methodTwo(std::string s){
	int length = s.length();
	int left = 0;
	int maxLength = 0;

	std::unordered_map<char,int> charMap;

	for (int right = 0; right < length; right++){
		if (charMap.count(s[right]) == 0 || charMap[s[right]] < left){
			charMap[s[right]] = right;
			maxLength = std::max(maxLength, right-left+1);
		}
		else{
			left = charMap[s[right]] + 1;
			charMap[s[right]] = right;
		}
	}
	return maxLength;
}

int main(){
	std::string s;
	std::cin >> s;

	std::cout << methodOne(s) << std::endl;
	std::cout << methodTwo(s);
	
	return 0;
}
