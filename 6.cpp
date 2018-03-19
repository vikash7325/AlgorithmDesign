/*Maximum SubArray Goldman Sachs Vikash Kumar*/
#include<iostream>
#include<math.h>
using namespace std;
#define MAX_NEGATIVE -1000000;
// A utility funtion to find maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// A utility funtion to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }

int Find_Max_CrossSubArray(int *myArray, int low, int mid, int high, int *lIndex, int *rIndex, int *totalSum){
	int left_sum = MAX_NEGATIVE;
	int right_sum = MAX_NEGATIVE;
	int left_index;
	int right_index;
	int sum = 0;
	
	for (int index=mid; index>= low;index--){
		sum = sum + myArray[index];
		if (sum > left_sum){
			left_sum = sum;
			left_index = index;
		}		
	}
	
	sum = 0;
	for(int index=mid+1; index<high;index++){
		sum = sum+ myArray[index];
		if (sum > right_sum){
			right_sum = sum;
			right_index = index;
		}
	}
	
	*lIndex = left_index;
	*rIndex = right_index;
	*totalSum = left_sum + right_sum;
	return *totalSum;
}
int Find_Max_SubArray(int *myArray, int low, int high, int *lIndex, int *rIndex, int *totalSum){
	int mid;
	int a, b, c;
	
	if (low == high){
		*lIndex = low;
		*rIndex = high;
		*totalSum = myArray[low];
		return myArray[low];
	}
	
	mid = floor((low+high)/2);
	
	a = Find_Max_SubArray(myArray, low, mid, lIndex, rIndex, totalSum);
	b = Find_Max_SubArray(myArray, mid+1, high, lIndex, rIndex, totalSum);
	c = Find_Max_CrossSubArray(myArray, low, mid, high, lIndex, rIndex, totalSum);
	return max(a,b,c);
}
int main(){
	int myArray[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int leftIndex = 0;
	int rightIndex = 0;
	int totalSum = 0;
	cout<<"SUM "<<Find_Max_SubArray(&myArray[0], 0, 16, &leftIndex, &rightIndex, &totalSum)<<"\n";
	cout<<"Left Index "<<leftIndex<<"\n";
	cout<<"Right Index "<<rightIndex<<"\n";
	cout<<"Total Sum "<<totalSum<<"\n";
	return 0;
}
