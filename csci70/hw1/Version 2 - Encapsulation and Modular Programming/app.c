#include <stdio.h>
#include "stack.h"

extern int top; 

void application(){
    push('x');
    push('y');
    push('z');
    --top;
    char ans = pop();
    printf("Popped: %c\n", ans);
}

int main(){
    application();
    return 0;
}
