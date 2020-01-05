//´æÔÚÖØ¸´ÔªËØ 
#include <stdlib.h>  
#define MAX(x, y) ((x)>(y) ? (x) : (y))

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
	for (int i = 0; i < numsSize; i++) {
		for (int j = MAX(i - k, 0); j < i; j++) {
			if (labs((long)nums[i] - (long)nums[j]) <= t) return true;
		}
	}
	return false;
}