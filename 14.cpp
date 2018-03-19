/*Vikash Kumar Goldmac sachs 2nd smallest no.*/
/*Idea is to use heapify only two times*/
#include<iostream>
using namespace std;
int size = 9;
int getLeft(int i){
	return (2*i + 1);
}

int getRight(int i){
	return (2*i + 2);
}

void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}

void BuildMinHeap(int *array, int index){
	int l,r,smallest;
	l = getLeft(index);
	r = getRight(index);
	
	if (l < size && array[l] < array[index]){
		smallest = l;
	}else{
		smallest = index;
	}
	
	if (r < size && array[r] < array[smallest]){
		smallest = r;
	}
	
	if (index != smallest){
		swap(&array[0], &array[smallest]);
		BuildMinHeap(&array[0], smallest);
	}
	return;
}

void MinHeapify(int *arr){
	int index;
	for (index=size/2; index>=0; index--){
		BuildMinHeap(&arr[0], index);
	}
	return;
}

int main(){
	int arr[10] = {5,4,3,2,1,10,9,8,7,6};
	MinHeapify(&arr[0]);
	swap(&arr[0], &arr[9]);
	size--;
	MinHeapify(&arr[0]);
	cout<<"2nd Smallese element is "<<arr[0]<<"\n";
	return 0;
}
