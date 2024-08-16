#include <stdio.h>
#include "stack.h"

void application(){
    push(0, 'x');
    push(1, 'y');
    push(1, 'z');
    push(0, 'a');
    push(-1, 'b');
    char ans = pop(1);
    printf("Popped from stack 1: %c\n", ans);
}

int main(){
    application();
    return 0;
}
