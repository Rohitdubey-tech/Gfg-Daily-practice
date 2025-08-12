#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int p = x + y; 
    int q = x - y; 
    int r = x * y; 
    int s = 0;     
    int t = 0;     
    if (y != 0) { 
        s = x / y;
        t = x % y;
    }
    cout << p << " " << q << " " << r << " " << s << " " << t << endl;
    return 0;
}