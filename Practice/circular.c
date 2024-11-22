#include<stdio.h>
int front = -1;
int rear = -1;
int queue[10];
int size = sizeof(queue)/sizeof(queue[0]);

void enqueue(int val){
    // overflow
    if((rear+1)%size==front){
        printf("Overflow");
    }
    if(front==-1 && rear==-1){
        front = 0;
        rear=0;
        queue[rear]=val;
    }
    else{
        rear = (rear+1)%size;
        queue[rear]=val;
    }

}

int dequeue(){
    //underflow
    int ele;
    if(front==-1 && rear==-1){
        printf("Underflow!!!!!");
    }
    if(front==rear){

        ele = queue[front];
        front=-1;
        rear=-1;
        printf(" The deleted element is : %d\n",ele);
        return ele;
    }
    else{
        ele = queue[front];
        printf(" The deleted element is : %d\n",ele);
        front = (front + 1)%size;
        return ele;
    }
    
}

void show(){
    printf("The element in queue is : \n");
    

    // FIRST APPROACH

    // if(front==-1){
    //     printf("Stack is empty");
    // }
    // // printf("\n");
    // else{
    //     if (rear >= front){
    //     for (int i = front; i <= rear; i++)
    //         printf("%d \t",queue[i]);
    // }
    //     else{
    //     for (int i = front; i < size; i = i++)
    //         printf("%d \t", queue[i]);
 
    //     for (int i = 0; i <= rear; i++)
    //         printf("%d ", queue[i]);
    //     }
    // }


    // SECONF APPROACH

    int i = front;
    while(i!=rear){
        printf("%d\t",queue[i]);
        i = (i+1)%size;
    }
    printf("%d\t",queue[rear]);
    printf("\n");

}

int main(){
    for(int i=1 ;i<=10;i++){
        enqueue(i*3);
    }
    show();
    printf("F = %d\n",front);
    printf("R = %d\n",rear);
    for(int i=1 ;i<=10;i++){
        printf("  %d: ",i);
        dequeue();
    }
    enqueue(6);
    printf("F = %d\n",front);
    printf("R = %d\n",rear);
    show();
    printf("F = %d\n",front);
    printf("R = %d\n",rear);
    dequeue();
    printf("F = %d\n",front);
    printf("R = %d\n",rear);
    show();
    // dequeue();
    // dequeue();
    // dequeue();
    // show();

   

}