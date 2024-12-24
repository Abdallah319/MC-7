//create a c program that prompts the user to input intiger munber into an array the peogram dynamically allocates
//memory for the arrary based in the users input for the size of the array.

#include <stdio.h>
#include <stdlib.h>
int main(){
int size;
printf("Enter the size of array:");
scanf("%d",&size);

int *array =(int *)malloc(size*sizeof(int));
if(array==NULL){
    printf("Memory allocation failed:\n");
    return 1;
}
printf("Enter %d integer numbers:\n ",size);
for(int i=0;i<size;i++){
    scanf("%d",&array[i]);
}
printf("\n");

free(array);
return 0;

}




//c program to search for an element in an array using linear search.

#include <stdio.h>
int main(){
int array[] ={3,5,3,8,7,2};
int size =sizeof(array)/sizeof(array[0]);
int target =8;
int found =0;

for(int i=0;i<size;i++){
    if(array[i]==target){
        found =1;
        printf("Element %d found at index %d\n",target,i);
    }
}
if(!found){
    printf("Element %d not found in the array\n",target);
}
return 0;
}

//define a structure called student with members name rollnumber marks an array of integers
//representing marks in different subjects and average marks.

#include <stdio.h>

struct student{
char name[50];
int roll_number;
int marks[5];
float average_marks;
};
int main(){
int num_students;
printf("Enter the number of students:");
scanf("%d",&num_students);

struct student students[num_students];

for(int i=0;i<num_students;i++){
    printf("\nEnter details for students %d:\n",i+1);
    printf("Name:");
    scanf("%s",students[i].name);
    printf("Roll number");
    scanf("%d",&students[i].roll_number);
    printf("Enter the marks for 5 subjects:\n");
    for(int j=0;j<5;j++){
        scanf("Subject %d:",j+1);
    scanf("%d",&students[i].marks[j]);
}

float sum =0.0;
for(int j=0;j<5;j++){
    sum +=students[i].marks[j];
}
students[i].average_marks =sum/5;
}

printf("\nStudent Details:\n");
for(int i=0;i<num_students;i++){
    printf("Name:%s\n",students[i].name);
    printf("Roll number:%d\n",students[i].roll_number);
    printf("Marks:");
    for(int j=0;j<5;j++){
        printf("%d",students[i].marks[j]);
    }
    printf("\nAverage Marks:%.2f\n",students[i].average_marks);
}
return 0;
}

//stack overflow

//implements a stack using an array in ca to push integer values and print the elements of stack

#include <stdio.h>
int MAXSIZE =8;
int stack[8];
int top =-1;

int isfull(){
    if(top==MAXSIZE)
        return 1;
    else
        return 0;
}

int push(int data){
if(!isfull()){
    top =top+1;
    stack[top] =data;
}else{
printf("Could nit insert data,stack is full.\n");
}
return 0;
}

int main(){
int i;
push(30);
push(85);
push(70);
push(38);

printf("Stack Elements:\n");
for(i=0;i<8;i++){
    printf("%d",stack[i]);
}
return 0;

}


//queue
//create a queue of integers enqueue three integer onto
//the queue print each element and display the size of the queue

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct{
int items[MAX_SIZE];
int front;
int rear;
}IntQueue;

void initializeQueue(IntQueue*queue){
queue->front =0;
queue->rear =-1;
}
int isEmpty(IntQueue*queue){
return queue->rear<queue->front;
}

void enqueue(IntQueue*queue,int value){
if(queue->rear==MAX_SIZE -1){
    printf("Queue overflow!\n");
    return;
}
queue->items[++queue->rear]+value;
}

int main(){
IntQueue queue;
initializeQueue(&queue);

enqueue(&queue,40);
enqueue(&queue,50);
enqueue(&queue,60);

printf("Elements of the queue:\n");
for(int i=queue.front;i<=queue.rear;i++){
    printf("%d\n",queue.items[i]);
}

printf("Size of the queue are:%d\n",queue.rear-queue.front+1);
return 0;
}





//Bubble sort.
#include <stdio.h>
void bubble_sort(int arr[],int size){
for(int i=0;i<size;i++){
    for(int j=0;j<size-1;j++){
        if(arr[j]>arr[j+1]){
            int temp =arr[j];
            arr[j] =arr[j+1];
            arr[j+1] =temp;
        }
    }
}

}
int main(){
int my_array[] ={5,8,6,4,2,0};
int size =sizeof(my_array)/sizeof(my_array[0]);

printf("Array before sorting:\n");
for(int i=0;i<size;i++){
    printf("%d",my_array[i]);
}
printf("\n");

bubble_sort(my_array,size);

printf("Array after sorting:\n");
for(int i=0;i<size;i++){
    printf("%d",my_array[i]);
}
return 0;
}




//Insertion sort.

#include <stdio.h>

void insertionsort(int arr[],int n){
int i,key,j;
 for(i=1;i<n;i++){
    key =arr[i];
    j =i-1;

    while(j >= 0 && arr[j] > key){
        arr[j+1] =arr[j];
        j =j-1;
    }
    arr[j+1] =key;
 }
}

void printArray(int arr[],int n){
int i;
for(i=0;i<n;i++){
    printArray("%d",arr[i]);
}
printf("\n");
}

int main(){
int arr[] ={6,7,4,3,2};
int n =sizeof(arr)/sizeof(arr[0]);

printf("Original array:\n");
printArray(arr,n);

insertionsort(arr,n);
printf("\n Sorted array:\n");
printArray(arr,n);

return 0;

}




//Selection sort.

#include <stdio.h>

void selectionsort(int arr[],int n){
int i,j,min_el,temp;

for(i=0;i<n-1;i++){
    min_el =i;

    for(j=i+1;j<n;j++){
        if(arr[j]<arr[min_el]){
            min_el =j;
        }
    }

    if(min_el !=i){
        temp =arr[i];
        arr[i] =arr[min_el ];
        arr[min_el] =temp;
    }
  }
}

int main(){
int arr[] ={6,8,0,4,2};
int n =sizeof(arr)/sizeof(arr[0]);

printf("Original array:\n");
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
selectionsort(arr,n);
printf("\nSorted array:\n");
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}
return 0;
}
















































