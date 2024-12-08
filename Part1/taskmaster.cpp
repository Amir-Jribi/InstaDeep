#include <bits/stdc++.h>
using namespace std;

// Function that checks the string that is passed in parameter is 
// palindrome or not
bool isPalindrome(string str){
	vector<char> removeEdgeCases;
	for(int i=0;i<str.size();i++){
		if (str[i]>='a' && str[i]<='z'){
			removeEdgeCases.push_back(str[i]);
		}
		else if (str[i]>='A' && str[i]<='Z'){
			int c=str[i]-'A';
			char b=char(97+c);
			// cout<<b<<endl;
			removeEdgeCases.push_back(b);
		}
	}
	for(int i=0;i<removeEdgeCases.size();i++){
		if (removeEdgeCases[i]!=removeEdgeCases[removeEdgeCases.size()-1-i]){
				return false;
		}
	}
	// for(auto u:tmp) cout<<u<<" ";
	return true;
}
int main(){
	string str;
	cin>>str;
	bool answer = isPalindrome(str);
	if (answer) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	// cout<<int('A')<<endl; // 65
	// cout<<int('a')<<endl; //97

	return 0;
}