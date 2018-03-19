/*Goldman Sachs Vikash Kumar*/
#include<iostream>
using namespace std;
int checkIfAll(int val){
	char flag1 = 0;
	char flag2 = 0;
	char flag3 = 0;
	int quot, rem, value;
	if (val < 100){
		return 0;
	}
	
	while(1){
		rem = val%10;
		if (rem == 1){
			flag1 = 1;
		}
	
		if (rem == 2){
			flag2 = 1;
		}
	
		if (rem == 3){
			flag3 = 1;
		}	
			
		val = val/10;
		if (0 == val){
			break;
		}
	}
	if (flag1 && flag2 && flag3){
		return 1;
	}
	
	return 0;
}
void merge(int array[], int p, int q, int r){
	int fSize;
	int sSize;
	int i, j, k;
	int lArray[q - p + 1];
	int rArray[r - q];
	
	fSize = q - p + 1;
	sSize = r - q;
	
	for (i = 0; i < fSize; i++){
		lArray[i] = array[p + i];
	}
	
	for (j = 0; j < sSize; j++){
		rArray[j] = array[q + j + 1];
	}
	
	/* Now need to start merge together */
	k = p;
	i = 0;
	j = 0;
	while ((i < fSize) && (j < sSize))
	{
		if (lArray[i] <= rArray[j]){
			array[k] =	lArray[i];
			i++;
		}
		else{
			array[k] = rArray[j];
			j++;
		}
		k++;
	}
	
	while (i < fSize){
		array[k] = lArray[i];
		k++;
		i++;
	}
	
	while(j < sSize){
		array[k] = rArray[j];
		k++;
		j++;
	}
	
	return;
}

void mergeSort(int array[], int p, int r){
	int q;
	if (p < r){
		q = (p + r - 1)/2;
		mergeSort(array, p, q);
		mergeSort(array, q + 1, r);
		merge(array, p, q, r);
	}
}

int main(){
	int array[4] = {9821, 627183, 12, 1234};
	int outputArray[4] = {0};
	int index = 0;
	int flag = 0,val, outIndex = 0;
	while(index < 4){
		val = array[index];
		if (checkIfAll(val)){
			outputArray[outIndex] = val;
			outIndex++;
			flag = 1;
		}
		index++;
	}
	if (!flag){
		cout<<"-1"<<"\n";
	}else{
		mergeSort(&outputArray[0], 0, 3);
		for (index = 0; index < 4; index++){
			if (outputArray[index]){
				cout<<outputArray[index]<<"\n";
			}
		}
	}
	return 0;
}
