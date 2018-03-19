/*Print sum of all sub set Goldman sachs vikash kumar*/
#include<iostream>
using namespace std;
void printSumSubset(int *arr, int n){
	int sum = 0;
	for(int i=0; i < (1<<n); i++){
		for(int j=0; j<n;j++){
			if ((i & (1<<j)) > 0){
				sum += arr[j];
			}
		}
		cout<<sum<<"\n";
		sum = 0;
	}
}
int main(){
	int arr[3] = {1,2,3};
	printSumSubset(arr, 3);
	return 0;
}
