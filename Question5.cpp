/*Write a program to implement a stack using (a) Two queues and (b) One Queue.*/
#include <iostream>
#include <queue>
using namespace std;
class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};
class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    cout << "Stack Using Two Queues:\n";
    StackUsingTwoQueues stack1;
    stack1.push(10);
    stack1.push(20);
    cout << "Top element: " << stack1.top() << "\n";  // 20
    stack1.pop();
    cout << "Top element after pop: " << stack1.top() << "\n";  // 10

    cout << "\nStack Using One Queue:\n";
    StackUsingOneQueue stack2;
    stack2.push(5);
    stack2.push(15);
    cout << "Top element: " << stack2.top() << "\n";  // 15
    stack2.pop();
    cout << "Top element after pop: " << stack2.top() << "\n";  // 5
    return 0;
}
