/*Author Vikash Kumar Goldman Sachs, spiral traversal*/==> Incomplete
#include<iostream>

using namespace std;
int MAX_R = 5;
int MIN_L = 0;
int MAX_D = 5;
int MIN_U = 0;

void spiralPrint(int array[5][5], int row, int column){
	int index;
	while(1)
	{
		for (index = MIN_L; index < MAX_R; index++){
			cout<<array[index][MIN_U]<<"\t";	
		}	
		
		if (MAX_R - MIN_L <= 1){
			break;
		}
		
		MIN_U++;
		cout<<"\n";
		int i=0;
		for (index = MAX_R - 1; index < (MAX_D + MAX_R - 2); index++){
			cout<<array[MIN_U + i][MAX_D]<<"\t";
			i = i + 1;
		}
		
		MAX_R--;
		cout<<"\n";
		
		for (index = MAX_R - 1; index >= MIN_L; index--){
			cout<<array[MAX_D][index]<<"\t";
		}
		
		MAX_D--;
		cout<<"\n";
		
		for (index = MAX_D - 1; index >= MIN_U; index--){
			cout<<array[index][MIN_L]<<"\t";
		}
		MIN_L++;
	}
}

int main(){
	int array[5][5] = 
	{
		{1, 2, 3, 4,  5},
		{6, 7, 8, 9, 10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	spiralPrint(array, 5, 5);
    return 0;
}
