/*Goldman Sachs Vikash Kumar printing all subset*/
#include<iostream>
using namespace std;
void printSubSet(string abc){
	int len = abc.length();
	for(int i=0; i <(1<<len); i++){
		cout<<"{ ";
		for(int j=0; j<len; j++){
			if ((i & (1<< j)) > 0){
				cout<<abc[j]<<" ";
			}
		}
		cout<<" }\n";
	}
}
int main(){
	string in = "abc";
	printSubSet(in);
	return 0;
}
