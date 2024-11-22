#include<stdio.h>
#include<stdlib.h>

int *stack;
int top=-1;
int size=0;

void createStack(int isize){
	size=isize;
	
	stack = (int*)malloc(size*sizeof(int));
	if(!stack){
		
		exit(0);
	}
	else{
		printf("Memory is successfully allocated\n");
	}
		
}


int isfull(){
    if(top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int  isempty(){
    if(top==-1){
        return 1;

    }
    else{
        return 0;
    }
}

void resizeStack(){
	size = size*2;
	stack = (int*)realloc(stack,size*sizeof(int));
	if(!stack){
	printf("Memory is not allocated\n");
		exit(0);
	}
	
	
}


void push(int val){
	
	// printf(" push  function called \n");
	if(isfull()){
		printf(" Overflow \n" );
		resizeStack();
	}
	
	top = top+1;
	stack[top]=val;
	
	
}

void show(){
	printf("show function called \n");
	for(int i=0;i<=top;i++){
		printf("At %d index the value is %d \n",i,stack[i]);
	}
}

void pop(){
		printf("pop function called \n");
	if(isempty()){
		printf("Underflow\n");
	}
	top = top-1;
}

void peek(){
		printf("peek function called \n");
	printf("%d\n",stack[top]);
}

int main(){
	createStack(2);
	push(10);
	push(12);
	push(13);
	push(14);
	show();	
	pop();
	show();
	peek();
	peek();
	
}