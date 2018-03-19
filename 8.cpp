/*Quick sort Goldman Sachs vikash kumar*/
#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}

int partition(int *array, int p, int r){
	int pivot = array[r];
	int i;
	int index;
	
	i = p - 1;
	for (index = p; index < r; index++){
		if (array[index] <= pivot){
			i++;
			swap(&array[i], &array[index]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i+1;
}

void QuickSort(int *array, int p, int r){
	int partiti;
	if (p < r){
		partiti = partition(array, p, r);
		QuickSort(array, p, partiti - 1);
		QuickSort(array, partiti + 1, r);
	}
}
int main(){
	int myArray[10] = {5,4,3,2,1,10,9,8,7,6};
	QuickSort(&myArray[0], 0, 9);
	for (int index=0; index<10; index++){
		cout<<myArray[index]<<"\t";
	}
	cout<<"\n";
	return 0;
}
