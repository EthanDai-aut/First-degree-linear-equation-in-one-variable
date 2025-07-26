#include<iostream>
#include<string>
using namespace std;
string KuoHao(string n) {
    if (n[0] != '-' || n[0] != '+') {
        n = '+' + n;
    }
    int fuhaoshu = 0;//fuhaoshu用于存储有多少个符号
    for (int i = 0;i<n.length();i++) {
        if (n[i] == '-' || n[i] == '+' || n[i] == '*' || n[i] == '/') {
            fuhaoshu++;
        }
    }

    //left是用于储存上一个符号的位置
    int left = 0;
    //h是用于储存各个单项式
    string h[fuhaoshu-1];
    //tot表示h的当前下标
    int tot = 0;
    for (int i=0;i<=n.length()-1;i++) {
        if (i == 0) {
            continue;
        }
        if (n[i] == '-' || n[i] == '+' || n[i] == '/' || n[i] == '*') {
            h[tot] = n.substr(left, i - left);
            cout << h[tot] << endl;
            left = i;
        }

        if (i == fuhaoshu - 1) {
            h[tot] = n.substr(left, i - left); //0 1 2 3 4 i=3 left=1

        }
        cout << h[tot] << " " << n[i] << endl;

    }
    return h[0];
}
int main() {
    string n;
    cin >> n;
    string h = KuoHao(n);
    cout << h;
    return 0;
}


