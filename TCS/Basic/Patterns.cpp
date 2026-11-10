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
// --------------------------------------------------
// PATTERN 11: Binary Number Triangle
//
// Output for n = 5:
//
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
//
// Logic:
// If i + j is even, print 1.
// Otherwise, print 0.
// --------------------------------------------------

void print11(int n) {
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            if ((i + j) % 2 == 0) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }

        }

        cout << endl;
    }
}


// --------------------------------------------------
// PATTERN 12: Palindromic Number Triangle
//
// Output for n = 4:
//
// 1      1
// 12    21
// 123  321
// 12344321
//
// Logic:
// First loop prints increasing numbers.
// Second loop prints decreasing numbers.
// --------------------------------------------------

void print12(int n) {

    for (int i = 1; i <= n; i++) {

        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Print spaces in the middle
        for (int s = 1; s <= 2 * (n - i); s++) {
            cout << " ";
        }

        // Print decreasing numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }
}


// --------------------------------------------------
// PATTERN 13: Floyd's Triangle
//
// Output for n = 5:
//
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
//
// Logic:
// value increases continuously.
// It does not reset after each row.
// --------------------------------------------------

void print13(int n) {

    int value = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            cout << value << " ";

            value++;
        }

        cout << endl;
    }
}


// --------------------------------------------------
// PATTERN 14: Increasing Alphabet Triangle
//
// Output for n = 5:
//
// A
// AB
// ABC
// ABCD
// ABCDE
//
// Logic:
// Outer loop controls rows.
// Inner loop prints characters from A.
// --------------------------------------------------

void print14(int n) {

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {

            char ch = 'A' + j;

            cout << ch;
        }

        cout << endl;
    }
}


// --------------------------------------------------
// PATTERN 15: Inverted Alphabet Triangle
//
// Output for n = 5:
//
// ABCDE
// ABCD
// ABC
// AB
// A
//
// Logic:
// Outer loop starts from n and decreases.
// Inner loop prints characters from A.
// --------------------------------------------------

void print15(int n) {

    for (int i = n; i >= 1; i--) {

        for (int j = 0; j < i; j++) {

            char ch = 'A' + j;

            cout << ch;
        }

        cout << endl;
    }
}


/*
    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *
*/
void print16(int n) {

    // Upper half of diamond
    for (int i = 1; i <= n; i++) {

        // Leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        // Print boundary stars
        for (int j = 1; j <= 2 * i - 1; j++) {

            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }

    // Lower half of diamond
    for (int i = n - 1; i >= 1; i--) {

        // Leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        // Print boundary stars
        for (int j = 1; j <= 2 * i - 1; j++) {

            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }
}

// ==================================================
// PATTERN 17: HOLLOW BUTTERFLY
//
// Output for n = 4:
//
// *      *
// **    **
// * *  * *
// *  **  *
// *  **  *
// * *  * *
// **    **
// *      *
// ==================================================

void print17(int n) {

    // Upper half
    for (int i = 1; i <= n; i++) {

        // Left wing
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        // Middle spaces
        for (int s = 1; s <= 2 * (n - i); s++) {
            cout << " ";
        }

        // Right wing
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = n; i >= 1; i--) {

        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        for (int s = 1; s <= 2 * (n - i); s++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }
}


// ==================================================
// PATTERN 18: NUMBER DIAMOND
//
// Output for n = 5:
//
//     1
//    121
//   12321
//  1234321
// 123454321
//  1234321
//   12321
//    121
//     1
// ==================================================

void print18(int n) {

    // Upper half
    for (int i = 1; i <= n; i++) {

        // Leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        // Increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {

        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }
}


// ==================================================
// PATTERN 19: HOURGLASS
//
// Output for n = 5:
//
// *********
//  *******
//   *****
//    ***
//     *
//    ***
//   *****
//  *******
// *********
// ==================================================

void print19(int n) {

    // Upper inverted pyramid
    for (int i = n; i >= 1; i--) {

        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower pyramid
    // Start from 2 to avoid repeating the middle star
    for (int i = 2; i <= n; i++) {

        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }
}


// ==================================================
// PATTERN 20: CONCENTRIC SQUARE NUMBER PATTERN
//
// Output for n = 4:
//
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
//
// Logic:
// Outer boundary contains n.
// Numbers decrease toward the centre.
// ==================================================

void print20(int n) {

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            int layer = min(
                min(i, j),
                min(size - 1 - i, size - 1 - j)
            );

            cout << n - layer;
        }

        cout << endl;
    }
}


// ==================================================
// PATTERN 21: SPIRAL MATRIX
//
// Output for n = 5:
//
//  1  2  3  4  5
// 16 17 18 19  6
// 15 24 25 20  7
// 14 23 22 21  8
// 13 12 11 10  9
//
// Logic:
// Fill top, right, bottom, left boundaries.
// Move boundaries inward after every round.
// ==================================================

// void print21(int n) {

//     //vector<vector<int>> matrix(n, vector<int>(n, 0));

//     int top = 0;
//     int bottom = n - 1;
//     int left = 0;
//     int right = n - 1;

//     int value = 1;

//     while (top <= bottom && left <= right) {

//         // Left to right
//         for (int j = left; j <= right; j++) {
//             matrix[top][j] = value++;
//         }
//         top++;

//         // Top to bottom
//         for (int i = top; i <= bottom; i++) {
//             matrix[i][right] = value++;
//         }
//         right--;

//         // Right to left
//         if (top <= bottom) {
//             for (int j = right; j >= left; j--) {
//                 matrix[bottom][j] = value++;
//             }
//             bottom--;
//         }

//         // Bottom to top
//         if (left <= right) {
//             for (int i = bottom; i >= top; i--) {
//                 matrix[i][left] = value++;
//             }
//             left++;
//         }
//     }

//     // Print matrix
//     for (int i = 0; i < n; i++) {

//         for (int j = 0; j < n; j++) {
//             cout << matrix[i][j] << "\t";
//         }

//         cout << endl;
//     }
// }

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
