/*
    C++ PATTERN PRINTING NOTES
    Structure followed from the VS Code screenshot:
      - Separate pattern functions: print1(int n), print2(int n), print3(int n)
      - main() reads number of test cases t
      - Each test case reads n and calls a pattern function
      - Only one main() function in this file

    Input format:
      t
      n1
      n2
      ...
*/

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// PATTERN 1: Print n stars in one row
// Example n = 5
// * * * * *
// ------------------------------------------------------------
void print1(int n) {
    for (int j = 1; j <= n; j++) {
        cout << "* ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// PATTERN 2: Print n stars in one column
// Example n = 5
// *
// *
// *
// *
// *
// ------------------------------------------------------------
void print2(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "*" << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 3: Right-angled triangle
// Example n = 5
// *
// * *
// * * *
// * * * *
// * * * * *
// Logic: row i contains i stars.
// ------------------------------------------------------------
void print3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 4: Inverted triangle
// Example n = 5
// * * * * *
// * * * *
// * * *
// * *
// *
// ------------------------------------------------------------
void print4(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 5: Square
// Example n = 5 -> 5 rows, 5 stars per row
// ------------------------------------------------------------
void print5(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 6: Right-aligned triangle
// Example n = 5
//         *
//       * *
//     * * *
//   * * * *
// * * * * *
// ------------------------------------------------------------
void print6(int n) {
    for (int i = 1; i <= n; i++) {
        // Print leading spaces: n-i
        for (int s = 1; s <= n - i; s++) {
            cout << "  ";
        }

        // Print stars: i
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 7: Full pyramid
// Example n = 5
//     *
//    ***
//   *****
//  *******
// *********
// Spaces = n-i; stars = 2*i-1
// ------------------------------------------------------------
void print7(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 8: Hollow square
// Example n = 5
// * * * * *
// *       *
// *       *
// *       *
// * * * * *
// Print star on boundary cells only.
// ------------------------------------------------------------
void print8(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 9: Increasing number triangle
// Example n = 5
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// ------------------------------------------------------------
void print9(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 10: Floyd's triangle
// Example n = 5
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
// ------------------------------------------------------------
void print10(int n) {
    int value = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << value << " ";
            value++;
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 11: Alphabet triangle
// Example n = 5
// A
// A B
// A B C
// A B C D
// A B C D E
// ------------------------------------------------------------
void print11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // 'A' + 0 = A, 'A' + 1 = B, etc.
            char ch = 'A' + j;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// PATTERN 12: Butterfly
// Example n = 4
// *      *
// **    **
// ***  ***
// ********
// ***  ***
// **    **
// *      *
// ------------------------------------------------------------
void print12(int n) {
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int s = 1; s <= 2 * (n - i); s++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }

    // Lower half: n-1 prevents duplicate middle row
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int s = 1; s <= 2 * (n - i); s++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }
}

// ------------------------------------------------------------
// MAIN FUNCTION
// ------------------------------------------------------------
int main() {
    int t;
    cin >> t; // Number of test cases

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; // Size for this test case

        // Select the pattern function you want to run.
        // Keep only one function call active at a time.
        print3(n);

        // Examples:
        // print1(n);
        // print2(n);
        // print4(n);
        // print5(n);
        // print6(n);
        // print7(n);
        // print8(n);
        // print9(n);
        // print10(n);
        // print11(n);
        // print12(n);
    }

    return 0;
}

/*
SAMPLE INPUT
3
3
4
5

SAMPLE OUTPUT (because print3(n) is active)
*
* *
* * *

*
* *
* * *
* * * *

*
* *
* * *
* * * *
* * * * *

COMPLEXITY
- print1 / print2: O(n) time, O(1) auxiliary space.
- square: O(n^2) time, O(1) auxiliary space.
- triangle: O(n^2) time because 1+2+...+n stars are printed.
- pyramid: O(n^2) time; spaces plus stars are proportional to n^2.
- butterfly: O(n^2) time, O(1) auxiliary space.
- main stores only t, i, and n: O(1) auxiliary space.

HOW TO ADD ANOTHER PATTERN
1. Create a function: void print13(int n) { ... }
2. Put row logic in the outer loop.
3. Put spaces/items in inner loops.
4. Print endl after each row.
5. Call print13(n) inside main().
*/
