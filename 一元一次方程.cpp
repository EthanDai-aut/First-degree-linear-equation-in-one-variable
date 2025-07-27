#include <iostream>
#include <string>
using namespace std;

string Kuohao(string s) {
    if (s.empty()) {
        return "";
    }
    // 确保第一个字符是运算符（+、-、*、/）
    if (s[0] != '+' && s[0] != '-' && s[0] != '*' && s[0] != '/') {
        s = "+" + s;
    }

    // 计算有效的分隔符（二元运算符 + 或 -）
    int fuhaoshu = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (i == 0) {
                fuhaoshu++;
            } else {
                char prev = s[i - 1];
                // 检查前一个字符是否是运算符（避免将一元运算符误判为分隔符）
                if (prev != '+' && prev != '-' && prev != '*' && prev != '/') {
                    fuhaoshu++;
                }
            }
        }
    }

    // 为单项式分配动态数组
    string* h = new string[fuhaoshu];
    int start = 0;   // 当前单项式的起始位置
    int tot = 0;     // 单项式计数器

    // 将字符串分割成单项式
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            char prev = s[i - 1];
            // 跳过一元运算符（当前字符紧跟在其他运算符后）
            if (prev == '+' || prev == '-' || prev == '*' || prev == '/') {
                continue;
            } else {
                // 提取从start开始到当前位置的单项式
                if (i - start > 0) {
                    h[tot] = s.substr(start, i - start);
                    tot++;
                }
                start = i;  // 更新下一个单项式的起始位置
            }
        }
    }
    // 提取最后一个单项式
    if (s.length() - start > 0) {
        h[tot] = s.substr(start, s.length() - start);
        tot++;
    }

    // 输出所有单项式
    for (int i = 0; i < tot; i++) {
        cout << h[i];
    }
    cout << endl;

    delete[] h;  // 释放动态分配的内存
    return "";
}

int main() {
    string s;
    cin >> s;
    Kuohao(s);
    return 0;
}