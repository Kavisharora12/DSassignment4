/*Develop a menu driven program demonstrating the following operations on Circular Queues: 
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include <iostream>
using namespace std;
class circularqueue{
    int* arr;
    int front;
    int rear;
    int size = 100001;
    public:
    circularqueue(int n){
        arr = new int[size];
        front = -1;
        rear = -1;
        size = n;
    }
    bool enqueue(int value){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }
    int dequeue(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
    void display(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Elements in the circular queue are: ";
        if(rear >= front){
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
        }
        else{
            for(int i = front; i < size; i++){
                cout<<arr[i]<<" ";
            }
            for(int i = 0; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
    void peek(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front element is: "<<arr[front]<<endl;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (front == 0 && rear == size-1) || (rear == (front-1)%(size-1));
    }
    ~circularqueue(){
        delete[] arr;
    }
};

    int main(){
        circularqueue q(5);
        int choice, value;
        while(true){
            cout<<"1. Enqueue"<<endl;
            cout<<"2. Dequeue"<<endl;
            cout<<"3. Display"<<endl;
            cout<<"4. Peek"<<endl;
            cout<<"5. isEmpty"<<endl;
            cout<<"6. isFull"<<endl;
            cout<<"7. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"Enter value to enqueue: ";
                    cin>>value;
                    q.enqueue(value);
                    break;
                case 2:
                    value = q.dequeue();
                    if(value != -1){
                        cout<<"Dequeued value: "<<value<<endl;
                    }
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    q.peek();
                    break;
                case 5:
                    if(q.isEmpty()){
                        cout<<"Queue is empty"<<endl;
                    }
                    else{
                        cout<<"Queue is not empty"<<endl;
                    }
                    break;
                case 6:
                    if(q.isFull()){
                        cout<<"Queue is full"<<endl;
                    }
                    else{
                        cout<<"Queue is not full"<<endl;
                    }
                    break;
                case 7:
                    exit(0);
                default:
                    cout<<"Invalid choice"<<endl;
            }
        }

    }