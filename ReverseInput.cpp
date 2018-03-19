/*Author Vikash Kumar Goldman Sachs*/
#include<iostream>
using namespace std;
void swap(char *a, char *b){
	char temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}
void reverseInput(char *ptr, int aSize){
	int lIndex,rIndex;
	for (lIndex=0, rIndex= aSize-1; lIndex <= rIndex; lIndex++, rIndex--){
		swap(&ptr[lIndex], &ptr[rIndex]);
	}
	return;
}
int main(){
	char input[5] = {'a','b','c','d','f'};
	reverseInput(&input[0], 5);
	for(int index=0; index<5; index++){
		cout<<input[index]<<"\t";
	}
	cout<<"\n";
	return 0;
}
