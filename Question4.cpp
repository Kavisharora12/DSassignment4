/*Write a program to find first non-repeating character in a string using Queue. 
Sample I/P: a a b c Sample O/P: a -1 b b */
#include <iostream>
using namespace std;
class queue{
    char* arr;
    int front;
    int rear;
    int size = 100;
    public:

    queue(int n){
        arr = new char[size];
        front = -1;
        rear = -1;
        size = n;
    }
    void enqueue(char value){
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
    }
    bool isEmpty(){
        return front == -1 || front > rear;
    }
    ~queue(){
        delete[] arr;
    }
    void NonRep(string str){
        int freq[26] = {0};
        for(char ch : str){
            freq[ch - 'a']++;
            enqueue(ch);
            while(!isEmpty() && freq[arr[front] - 'a'] > 1){
                dequeue();
            }
            if(isEmpty()){
                cout<<"-1 ";
            }
            else{
                cout<<arr[front]<<" ";
            }
        }
        cout<<endl;
    }
};
        int main(){
            string str;
            cout<<"Enter a string: ";
            cin>>str;
            queue q(str.length());
            q.NonRep(str);
            return 0;
        }