#include <iostream>

#define MAX 10

using namespace std;

class Queue {

    private:
        int t[MAX]; // After all Queue are arrays, special arrays.
        int front_end;    // First element of the queue.
        int back_end;      // Last element of the queue.

    public:
        Queue(); // Constructor.
        void del(); // Delete an element function.
        void add(int item); // Add an element to the queue.
        void display(); // Printing the queue.
};

Queue::Queue() {
    front_end = -1;    back_end= -1;
}

void Queue::del() {

    int temp;
    if(front_end==-1) {
        cout << "Queue is empty" << endl;
    } else {
        for(int j=0; j<=back_end; j++) {    // Very important.

            if((j+1)<=back_end) {
                temp = t[j+1];
                t[j] = temp;
            } else {
                back_end--;
                if(back_end==-1)
                    front_end = -1;
                else
                    front_end = 0;
            }
        }
    }
}

void Queue::add(int item) {
    if(front_end==-1 && back_end==-1) {
        back_end++;
        front_end++;
    } else {
        back_end++;     // Very important.
        if(back_end==MAX) {
            cout << "Queue is full" << endl;
            back_end--;
        }
    }
    t[back_end] = item;
}

void Queue::display() {
     if(front_end!=-1) {
        for(int i=0; i<=back_end; i++)
            cout << t[i] << " ";
    } else
        cout << "EMPTY" << endl;
}

int main() {

    Queue q;

    int data[5]={100,200,300,400,500};

    cout << "Queue before adding Elements: " << endl;
    q.display();
    cout << endl;

    for(int iter=0; iter<5; iter++) {
        q.add(data[iter]);
        cout << "Adding number : " << (iter+1) << " : ";
        q.display();
        cout << endl;
    }

    cout << endl;

    for(int x=0; x<5; x++) {
        q.del();
        cout << "Deletion number " << (x+1) << " : ";
        q.display();
        cout << endl;
    }

    return 0;
}
