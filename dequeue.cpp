#include <iostream>
#define MAX 100

class Deque 
{
    private:
        int arr[MAX];
        int front, rear;

    public:
        Deque() {
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            if (front == -1) return true;
            else return false;
        }

        bool isFull() {
            if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return true;
            else { return false; }
        }

        void insertFront(int value)
        {
            if (isFull()) {
                std::cout << "Deque is full\n";
                return;
            }
            if (front == -1) {
                front = rear = 0;
            } else {
                front=(front-1+MAX)%MAX;
            }
            arr[front] = value;
        }

        void insertRear(int value) {
            if (isFull()) {
                std::cout << "Deque is full\n";
                return;
            }
            if (front == -1) {
                front = rear = 0;
            } else if (rear == MAX - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = value;
        }

        void deleteFront() {
            if (isEmpty()) {
                std::cout << "Deque is empty\n";
                return;
            }
            if (front == rear) {
                front = rear = -1;
            } else     
                front=(front+1)%MAX;
                front++;
        }

        void deleteRear() {
            if (isEmpty()) {
                std::cout << "Deque is empty\n";
                return;
            }
            if (front == rear) {
                front = rear = -1;
            } else if (rear == 0) {
                rear = MAX - 1;
            } else {
                rear--;
            }
        }

        int getFront() {
            if (isEmpty()) {
                std::cout << "Deque is empty\n";
                return -1;
            }
            return arr[front];
        }

        int getRear() {
            if (isEmpty()) {
                std::cout << "Deque is empty\n";
                return -1;
            }
            return arr[rear];
        }
};

int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    std::cout << "Front element: " << dq.getFront() << "\n";
    dq.deleteFront();
    std::cout << "Rear element: " << dq.getRear() << "\n";
    return 0;
}
