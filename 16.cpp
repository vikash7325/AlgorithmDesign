/*Permutatin Goldman Sachs Vikash Kumar*/
#include<iostream>
using namespace std;
void swap(char *a, char *b){
	char temp;
	temp = *b;
	*b = *a;
	*a = temp;
	return;
}
void permute(string in, int l, int r){
	int index;
	if (l == r){
		cout<<in<<"\n";
	}
	else
	{
		for (index = l; index<= r; index++){
			swap(&in[l], &in[index]);
			permute(in, l + 1, r);
			swap(&in[l], &in[index]);
		}
	}
}
int main(){
	string inp = "ABC";
	permute(inp, 0, 2);
	return 0;
}
