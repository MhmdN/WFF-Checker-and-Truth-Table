#include <math.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int varinuma = 0, varinumb = 0;
string strwffa, strwffb;
char variablesa[27] = { '\0' }, variwortha[27] = { '\0' };
char variablesb[27] = { '\0' }, variworthb[27] = { '\0' };
void swap(char &a, char &b) {
	char m = a;
	a = b;
	b = m;
}
void bubblesort(char* a, int n) {
	for (int i = 1; i<n; i++) {
		int s = 0;
		for (int j = 0; j<n - i; j++) {
			if (a[j]>a[j + 1]) {
				swap(a[j], a[j + 1]);
				s++;
			}
		}
		if (s == 0) break;
	}
}
void findvariables() {
	int i = 0, j;
	for (varinuma = 0; i<strwffa.size(); i++) {
		if (strwffa[i] >= 97 && strwffa[i] <= 122) {
			int f = 0;
			for (j = 0; j<strlen(variablesa); j++) if (strwffa[i] == variablesa[j]) f++;
			if (f == 0) {
				variablesa[j] = strwffa[i];
				variwortha[j] = '0';
				variwortha[j + 1] = '\0';
				variablesa[j + 1] = '\0';
				varinuma++;
			}
		}
	}
	bubblesort(variablesa, varinuma);
	for (i = 0, varinumb = 0; i<strwffb.size(); i++) {
		if (strwffb[i] >= 97 && strwffb[i] <= 122) {
			int f = 0;
			for (j = 0; j<strlen(variablesb); j++) if (strwffb[i] == variablesb[j]) f++;
			if (f == 0) {
				variablesb[j] = strwffb[i];
				variworthb[j] = '0';
				variworthb[j + 1] = '\0';
				variablesb[j + 1] = '\0';
				varinumb++;
			}
		}
	}
	bubblesort(variablesb, varinumb);
}
string solve(string strin) {
	int i, j;
	for (int k = 1; k < strin.size() - 1; k++) {
		if (strin[k] == ')') {
			for (i = k; strin[i] != '('; i--);
			string cut(strin, i, k - i + 1);
			cut = solve(cut);
			for (j = 0; i <= k; j++, i++) strin[i] = cut[j];
		}
	}
	for (int k = 1; k < strin.size() - 1; k++) {
		if (strin[k] == '0' || strin[k] == '1');
		else if (strin[k] == '/') {
			if (strin[k - 1] == '1' && strin[k + 2] == '1') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
			else {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '0';
			}
		}
		else if (strin[k] == '\\') {
			if (strin[k - 1] == '0' && strin[k + 2] == '0') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '0';
			}
			else {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
		}
		else if (strin[k] == '-') {
			if (strin[k - 1] == '1' && strin[k + 2] == '0') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '0';
			}
			else {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
		}
		else if (strin[k] == '<') {
			if (strin[k - 1] == '1' && strin[k + 3] == '1') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
			else if (strin[k - 1] == '0' && strin[k + 3] == '0') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
			else {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '0';
			}
		}
		else if (strin[k] == '~') {
			if (strin[k + 1] == '1') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '0';
			}
			else if (strin[k + 1] == '0') {
				for (i = k; strin[i] != '('; i--);
				for (j = i; strin[j] != ')'; j++);
				for (int l = i; l <= j; l++) strin[l] = '1';
			}
		}
	}
	return strin;
}
bool placement(char * worth, string str) {
	for (int i = 0; i<str.size(); i++) {
		if (str[i] == 'T') str[i] = '1';
		else if (str[i] == 'F') str[i] = '0';
		else if (str[i] <= 122 && str[i] >= 97) {
			for (int j = 0; j<strlen(variablesa); j++) {
				if (variablesa[j] == str[i]) {
					str[i] = worth[j];
					break;
				}
			}
		}
	}
	string ans = solve(str);
	if (ans[1] == '1') return 1;
	else return 0;
}
void makeworth() {
	int f = 0;
	for (int m = 0; m < pow(2, varinuma); m++) {
		for (int i = 0; i<varinuma; i++) {
			variwortha[i] = (m / (int)pow(2, varinuma - i - 1)) % 2 + 48;
			variworthb[i] = variwortha[i];
		}
		if (placement(variwortha, strwffa) != placement(variworthb, strwffb)) {
			cout << "0";
			return;
		}
		else f++;
	}
	if (f == pow(2, varinuma)) cout << "1";
}
int main() {
	cin >> strwffa;
	cin >> strwffb;
	findvariables();
	if (varinuma != varinumb) cout << "0";
	else {
		int f = 0;
		for (int i = 0; i<varinuma; i++) if (variablesa[i] != variablesb[i]) f++;
		if (f == 0) makeworth();
		else cout << "0";
	}
	return 0;
}

