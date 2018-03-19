/*Max Heap Goldman Sachs vikash kumar*/
#include<iostream>
using namespace std;
int size = 9;
int getLeft(int n){
	return (2*n + 1);
}
int getRight(int n){
	return (2*n + 2);
}
void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}
void MaxHeapify(int *arr, int n){
	int l;
	int r;
	int largest;
	l = getLeft(n);
	r = getRight(n);
	if (l <= size && arr[l] > arr[n]){
		largest = l;
	}else{
		largest = n;
	}
	if (l <= size && arr[largest] < arr[r]){
		largest = r;
	}
	
	if (largest != n){
		swap(&arr[largest], &arr[n]);
		MaxHeapify(arr, largest);
	}
	return;
}
void BuildMaxHeap(int *array){
	int index;
	for (index=size/2;index>=0;index--){
		MaxHeapify(array, index);
	}
	return;
}
int main(){
	int arr[10] = {5,4,3,2,1,10,9,8,7,6};
	BuildMaxHeap(&arr[0]);
	for (int i=0; i<10;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}
