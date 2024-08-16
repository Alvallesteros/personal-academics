#include <stdio.h>
#define MAX 100

char Store[MAX];
int top = 0;

void push(char x){
    if (top < MAX )
        Store[top++] = x ;
    else
        printf("Stack full \n") ;
}

char pop(){
    if(top > 0)
        return Store[--top];
    else{
        printf("Stack empty \n") ;
        return 0; /* Make sure something is returned regardless */
    }
}

void application(){
    push('x');
    push('y');
    push('z');
    char ans = pop();
    printf("%c\n", ans);
}

int main(){
    application();
    return 0;
}
