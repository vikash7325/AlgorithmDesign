/*Goldman Sachs Vikash Kumar*/
#include<iostream>
using namespace std;
int main(){
	int num[10] = {1,1,2,3,4,4,4,5,6,7};
	int temp = num[0];
	int val;
	int count = 1;
	for (int i=1; i < 9; i++){
		if (temp == num[i]){
			count++;
		}else{
			cout<<"Value "<<temp<<"\t"<<"has count "<<count<<"\n";
			count = 1;
			temp = num[i]; 
		}
	}
	if (temp == num[9]){
		count++;
		cout<<"Value "<<temp<<"\t"<<"has count "<<count<<"\n";
	}
	else{
		temp = num[8];
		cout<<"Value "<<temp<<"\t"<<"has count "<<count<<"\n";
		count = 1;
		cout<<"Value "<<num[9]<<"\t"<<"has count "<<count<<"\n";
	}
	
	return 0;
}
