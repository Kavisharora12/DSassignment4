/*Write a program interleave the first half of the queue with second half. 
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9*/
#include <iostream>
using namespace std;
class interleave{
    int* arr;
    int front;
    int rear;
    int size = 6;
    public:

    interleave(int n){
        arr = new int[size];
        front = -1;
        rear = -1;
        size = n;
    }
    void interleaveQueue(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        int n = rear - front + 1;
        if(n % 2 != 0){
            cout<<"Queue has odd number of elements, cannot interleave"<<endl;
            return;
        }
        int half = n / 2;
        int* firstHalf = new int[half];
        int* secondHalf = new int[half];
        for(int i = 0; i < half; i++){
            firstHalf[i] = arr[front + i];
        }
        for(int i = 0; i < half; i++){
            secondHalf[i] = arr[front + half + i];
        }
        int index = front;
        for(int i = 0; i < half; i++){
            arr[index++] = firstHalf[i];
            arr[index++] = secondHalf[i];
        }
        delete[] firstHalf;
        delete[] secondHalf;
    }
    void enqueue(int value){
        if(rear == size - 1){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        arr[++rear] = value;
    }
    void dequeue(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
    void display(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Elements in the queue are: ";
        for(int i = front; i <= rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

        int main(){
            interleave q(6);
            int a,b,c,d,e,f;
            cout<<"Enqueue first element a:";
            cin >> a;
            q.enqueue(a);
            cout<<"Enqueue second element b:";
            cin >> b;
            q.enqueue(b);
            cout<<"Enqueue third element c:";
            cin >> c;
            q.enqueue(c);
            cout<<"Enqueue fourth element d:";
            cin >> d;
            q.enqueue(d);
            cout<<"Enqueue fifth element e:";
            cin >> e;
            q.enqueue(e);
            cout<<"Enqueue sixth element f:";
            cin >> f;
            q.enqueue(f);
            cout<<"Original Queue: ";
            q.display();
            q.interleaveQueue();
            cout<<"Interleaved Queue: ";
            q.display();
            return 0;

        }
