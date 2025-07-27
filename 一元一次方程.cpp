#include<iostream>
#include<string>
using namespace std;
string Kuohao(string s) {
    if (s[0] != '+' || s[1] != '-' || s[2] != '*' || s[3] != '/') {
        s = "+" + s;
    }

    int fuhaoshu = 0;
    for (int i=0;i<=s.length()-1;i++) {
        if (s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '+') {
            fuhaoshu++;
        }
    }
    //h是所有单项式
    string h[fuhaoshu];
    int left = 0,tot=0;
    for (int i=0;i<=s.length()-1;i++) {
        if (i == 0) {
            continue;
        }
        if (s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '+') {
            h[tot] = s.substr(left,i-left);
            left = i;
        }
        if (i == s.length()-1) {
            h[tot] = s.substr(left,i-left);
        }
        tot++;
    }

    cout << h[0] << h[1] << h[2] << h[3];
}
int main() {
    string s;
    cin >> s;
    Kuohao(s);
    return 0;
}

