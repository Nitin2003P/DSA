//queue using stack
// Dequeue is costly


#include<stdio.h>
int arr[10];
int brr[10];
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = sizeof(brr)/sizeof(brr[0]);
int top1 = -1;
int top2  =-1;



void push1(int val){
    if(top1==(size1-1)){
        printf("Overflow");
    }
    else{
        top1 = top1+1;
        arr[top1]=val;
    }

}


void pop1(){
    if(top1==-1){
        printf("undeflow");
    }
    else{
        top1--;
    }
}

void push2(int val){
    if(top2==(size2-1)){
        printf("Overflow");
    }
    else{
        top2 = top2+1;
        brr[top2]=val;
    }

}


void pop2(){
    if(top2==-1){
        printf("undeflow");
    }
    else{
        top2--;
    }
}


void enqueue(int val){
    push1(val);
}
void dequeue(){
    
    while(top1!=-1){
        int ele = arr[top1];
        push2(ele);
        pop1();
    }

    pop2();
    printf("\nThe element  is deleted");

    while(top2!=-1){
        int el = brr[top2];
        push1(el);
        pop2();
    }
    
}


void show(){
    printf("\nThe element in queue is : \n");
    for(int i=0;i<(top1+1);i++){
        printf("%d\t",arr[i]);
    }
}


int main(){

    for(int i=1;i<=5;i++){
        enqueue(i*3);
    }
    show();
    dequeue();
    dequeue();
    show();
    return 0;
}