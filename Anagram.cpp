/*Anagram Goldman Sachs vikash kumar*/
#include<iostream>
using namespace std;
void swap(char *a, char *b){
	char temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}
int partition(char *array, int p, int r){
	char pivot;
	int i;
	int index;
	
	i = p - 1;
	pivot = array[r];
	
	for (index = p; index < r; index++){
		if (array[index] <= pivot){
			i++;
			swap(&array[i], &array[index]);
		}
	}
	swap(&array[i+1], &array[r]);
	return i+1;
}
void quickSort(char *array, int p, int r){
	int part;
	if 	(p < r){
		part = partition(array, p, r);
		quickSort(array, p , part - 1);
		quickSort(array, part + 1, r);
	}
	return;
}
int main(){
	string bca = "abscd";
	string abc = "dcba";
	quickSort(&abc[0], 0, 3);
	for (int i=0; i <4; i++){
		cout<<abc[i]<<"\t";
	}
	if (abc == bca){
		cout<<"Anagram";
	}else{
		cout<<"Not Anagram";
	}
	return 0;
}
