#include <iostream>
using namespace std;

class Solution {
public:
    void printTerms(int a, int d, int n) {

        int nth = a + (n - 1) * d;
        int n1th = a + (n - 2) * d;
        int n2th = a + (n - 3) * d;

        cout << "nth term     = " << nth << endl;
        cout << "(n-1)th term = " << n1th << endl;
        cout << "(n-2)th term = " << n2th << endl;
    }
};

int main() {
    int a, d, n;
    cin >> a >> d >> n;

    Solution obj;
    obj.printTerms(a, d, n);

    return 0;
}