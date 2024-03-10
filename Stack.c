#include <stdio.h>

#define MAX 10
int Stack[MAX];
int top = -1;

void push();
void pop();
void displayChoices();
void displayElement();

int main() {
    int choice;

    printf("*******************choices*********************\n");
    printf("1.T0 push element on to stack\n");
    printf("2.To pop element from stack\n");
    printf("3. Display elements of stack \n");
    printf("4. To display choices \n");
    printf("0. To exit \n");
    printf("*******************choices*********************\n");

    while(1){
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            displayElement();
            break;
            case 4:
            displayChoices();
            break;
            case 0:
            return 0;

        }
    }   

    return 0;
}


void displayElement(){
    if(top == -1 ){
        printf("No elements present in stack\n");
        return;
    }
    printf("elements of stack are\n");
    for(int i=top; i>-1;i--){
        printf("%d ",Stack[i]);
    }
    printf("\n");
}

void push(){
    if(top == MAX - 1){
        printf("stack overflow\n");
        return;
    }
    int element;
    printf("enter element to be pushed\n");
    scanf("%d",&element);
    Stack[++top] = element;

    printf("element :%d \n (Added to the stack) \n",element);

}

void pop(){
    if(top == -1){
        printf("stack is empty\n");
        return;
    }
    printf("element :%d \n (popped out of the stack)\n",Stack[top]);
    top--;
}

void displayChoices(){
    printf("*******************choices*********************\n");
    printf("1.T0 push element on to stack\n");
    printf("2.To pop element from stack\n ");
    printf("3. Display elements of stack \n");
    printf("4. To display choices \n");
    printf("0. To exit \n");
    printf("*******************choices*********************\n");
}