#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Account{
	string acc, pwd;
}newAccount;

int main() {
	int n;
	vector<Account> accs;
	map<char, char> mp = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
	scanf("%d", &n);
	for(int i = 0, flag = 0; i < n; i++, flag = 0) {
		cin >> newAccount.acc >> newAccount.pwd;
		for(auto &c : newAccount.pwd) {
			if(mp[c] != '\0') {
				c = mp[c];
				flag = 1;
			}
		}
		if(flag) accs.push_back(newAccount);
	}
	if(accs.empty() && n == 1) printf("There is 1 account and no account is modified\n");
	else if(accs.empty() && n != 1) printf("There are %d accounts and no account is modified\n", n);
	else{
		printf("%d\n", int(accs.size()));
		for(auto acc : accs) printf("%s %s\n", acc.acc.c_str(), acc.pwd.c_str());
	}
	return 0;
}