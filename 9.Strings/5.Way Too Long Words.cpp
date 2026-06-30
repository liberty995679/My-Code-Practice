//缩写字符串，超过10个只写开头和结尾，中间用数字表示省略的字符
#include <iostream>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() > 10) {
            cout << s.substr(0, 1) << to_string(s.size() - 2) << s.substr(s.size() - 1) << endl;
        } else cout << s << endl;
    }
    
    return 0;
}