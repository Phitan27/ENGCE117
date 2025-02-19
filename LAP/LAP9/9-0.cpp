#include <stdio.h>

// Prototype declarations
int SumLoop(int n);
int SumRecur(int n);
void TowerHanoi(int m, int i, int j);

int main() {
    int n = 0, m = 0, i = 0, j = 0;
    scanf("%d %d %d %d", &n, &m, &i, &j);
    printf("%d\n", SumLoop(n));
    printf("%d\n", SumRecur(n));
    TowerHanoi(m, i, j);
    return 0;
}

// Function definitions

// SumLoop: Find the sum from 1 to n using a loop
int SumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

// SumRecur: Find the sum from 1 to n using recursion
int SumRecur(int n) {
    if (n == 0) return 0;
    return n + SumRecur(n - 1);
}

// TowerHanoi: Solve Tower of Hanoi problem using recursion
void TowerHanoi(int m, int i, int j) {
    if (m == 1) {
        printf("Move disc %d from %d to %d\n", m, i, j);
        return;
    }
    int aux = 6 - i - j; // Calculate auxiliary peg number
    TowerHanoi(m - 1, i, aux);
    printf("Move disc %d from %d to %d\n", m, i, j);
    TowerHanoi(m - 1, aux, j);
}
