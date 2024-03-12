#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 5
char Stack[MAX];
int top = -1;

void push(char c);
char pop();
void display();
int prc(char opr);


// Algo-
// 1.iterate through the expression
// 2.if come across operant add it to postfix exp str
// 3.if came across operator push it on to the stack according to the prescedence
// 4.if the precedence of the operator is less pop all the operators to the postfix str 

int main(){

    char infix[10],postfix[10];
    postfix[0] = '\0';
    int i=0,k=0;



    printf("Enter an infix expression\n");
    scanf("%s",infix);

    while(infix[i] != '\0'){
        char c = infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }
        else {
            while(prc(c) <= prc(Stack[top])){
                char opr;
                opr = pop();
                postfix[k++] = opr;
            }
            push(c);
        }

        i++;

      

    }

    while(top != -1){
        char opr;
        opr = pop();
        postfix[k++] = opr;
    }

  printf("postfix Exp:%s",postfix);
    return 0;
}

int prc(char opr){
    switch (opr)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    
    default:
        return 0;
        break;
    }
}

void push(char c){
    if(top == MAX-1){
        printf(" (Stack full)\n");
        return;
    }
    
    Stack[++top] = c;
}

char pop(){
    if(top == -1){
        printf(" (stack empty)\n");
        return 0;
    }
    return Stack[top--];
    //post increment

}

void display(){
    if(top == -1){
        printf(" (stack empty)\n");
        return ;
    }
    printf("elements of stack are :\n");
    for (int i=top; i > -1 ; i--){
        printf("%c ",Stack[i]);
    }
}