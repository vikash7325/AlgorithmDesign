/*Merge sort Goldman Sachs Vikash Kumar*/
#include<iostream>
void Merge(int *myArray, int p, int q, int r){
	int lArray[q - p + 1];
	int rArray[r - q];
	int fSize = q - p + 1;
	int sSize = r - q;
	
	for(int index=0; index<fSize; index++){
		lArray[index] = myArray[index + p];
	}
	
	for(int index = 0; index<sSize; index++){
		rArray[index] = myArray[index + q + 1];
	}
	
	int k=p;
	int l = 0,m = 0;
	while (l < fSize && m < sSize){
		if (lArray[l] < rArray[m]){
			myArray[k] = lArray[l];
			l++;
		}else{
			myArray[k] = rArray[m];
			m++;
		}
		k++;
	}
	
	while(l < fSize){
		myArray[k] = lArray[l];
		l++;
		k++;
	}
	
	while(m < sSize){
		myArray[k] = rArray[m];
		m++;
		k++;
	}
}
void MergeSort(int *myArray, int p, int r){
	int q;
	if (p < r){
		q = (p + r - 1)/2;	
		MergeSort(myArray, p, q);
		MergeSort(myArray, q + 1, r);
		Merge(myArray, p, q, r);
	}
}	
using namespace std;
int main(){
	int myArray[10] = {2,1,3,5,4,7,6,9,8,10};
	MergeSort(&myArray[0], 0, 9);
	for (int index=0; index<10; index++){
		cout<<myArray[index]<<"\t";
	}
	cout<<"\n";
	return 0;
}
