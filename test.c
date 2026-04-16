#include <stdio.h>

int main() {
    int T[10] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 1}, C;

    for (int i = 0; i < 10-1; i++) { 
        if (T[i] != 0) {
            C = 0;
        }
        C++;
    }
    printf("%d", 10-C);
}