#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	map<string, int> m;

	while (t--) {
		string s;
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			
			if (s[i] == '.') {
				m[s.substr(i+1, len - i)]++;
			}
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << '\n';
	}
}



/*
17070. 
https://www.acmicpc.net/problem/17070




*/
