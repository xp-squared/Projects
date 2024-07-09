/******************************************************************************

CSC 1501 – Assignment 3
Logical Statements 2
Assignment: Create a program that can try out every possible logical combination of
the variables A, B, and C for the following statements. Take note there are eight
different possible permutations of the three variables A, B, and C. Make certain you test
all eight of the permutations, and display THE FINAL OUTPUT (you do not need to
display the output of every single step)

(1) (A nor C) xor B
(2) (B implies C) nand (A nor B)
(3) (A xor B) implies (B xnor C)
(4) (A implies B) implies !C


*******************************************************************************/
#include <iostream>

using namespace std;

bool nand(bool a, bool b) {
    return !(a&&b);
}

bool xor1(bool a, bool b) {
    return a!=b;
}

bool xnor(bool a, bool b) {
    return a==b;
}

bool implies(bool a, bool b) {
    return !(a&&!b);
}

bool nor(bool a, bool b) {
    return !(a||b);
}

int main()
{   
    bool a[8] = {0,0,0,0,1,1,1,1};
    bool b[8] = {0,0,1,1,0,0,1,1};
    bool c[8] = {0,1,0,1,0,1,0,1};
    
    bool result1[8] = {};
    bool result2[8] = {};
    bool result3[8] = {};
    bool finalResult[8] = {};
    
    cout << "Question 1: (A nor C) xor B\n-----------" << endl; // (A nor C) xor B
    for(int i1 = 0; i1 < 8; i1++) {
        result1[i1] = nor(a[i1],c[i1]); // indexes each number and logs results
        cout << a[i1] << " " << b[i1] << " " << c[i1] << "  \t"; 
        finalResult[i1] = xor1(result1[i1],b[i1]);
        cout << finalResult[i1] << endl; 
    }
    
    cout << "\nQuestion 2: (B implies C) nand (A nor B)\n-----------" << endl; // (B implies C) nand (A nor B)
    for (int i2 = 0; i2 < 8; i2++) {
        result1[i2] = implies(b[i2],c[i2]);
        result2[i2] = nor(a[i2],b[i2]);
        cout << a[i2] << " " << b[i2] << " " << c[i2] << "  \t"; 
        finalResult[i2] = nand(result1[i2],result2[i2]);
        cout << finalResult[i2] << endl;
    }

    
    cout << "\nQuestion 3: (A xor B) implies (B xnor C)\n-----------" << endl;  // (A xor B) implies (B xnor C)
        for (int i3 = 0; i3 < 8; i3++) {
        result1[i3] = xor1(a[i3],b[i3]);
        result2[i3] = xnor(b[i3],c[i3]);
        cout << a[i3] << " " << b[i3] << " " << c[i3] << "  \t"; 
        finalResult[i3] = implies(result1[i3],result2[i3]);
        cout << finalResult[i3] << endl;
    }
    
    cout << "\nQuestion 4: (A implies B) implies !C\n-----------" << endl; // (A implies B) implies !C
    for (int i4 = 0; i4 < 8; i4++) {
        result1[i4] = implies(a[i4],b[i4]);
        result2[i4] = !c[i4];
        cout << a[i4] << " " << b[i4] << " " << c[i4] << "  \t";
        finalResult[i4] = implies(result1[i4],result2[i4]);
        cout << finalResult[i4] << endl;
    } 

    return 0;
}

