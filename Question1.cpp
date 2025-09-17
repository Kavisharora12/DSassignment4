/*Develop a menu driven program demonstrating the following operations on simple 
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include<iostream>
using namespace std;
class queue{
    int* arr;
    int qfront;
    int rear;
    int size;
    
    public:
    queue(){
        size=100000;
        arr = new int[size];
        qfront=0;
        rear=0;
    }
    ~queue() {
        delete[] arr;
    }
    bool isempty(){
            if(qfront==rear){
                return true;
            }
            else{
                return false;
            }
    }
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
        arr[rear]=data;
        rear++;
        }
    }
    int dequeue(){
        if(qfront==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }
    int peek(){
        if(qfront==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
int main(){
    queue q;
    int choice, value;
    while(true){
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Is Empty"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                cout<<"Dequeued value: "<<q.dequeue()<<endl;
                break;
            case 3:
                cout<<"Front value: "<<q.peek()<<endl;
                break;
            case 4:
                if(q.isempty()){
                    cout<<"Queue is empty"<<endl;
                }
                else{
                    cout<<"Queue is not empty"<<endl;
                }
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
