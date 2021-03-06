//Author:           Olamide Adesan
  //Email:            obadesan@my.msutexas.edu
  //Label:            A04
  //Title:            Linked List Class
  //Course:           CMPS2143
  //Semester:         Fall 2021

  Description:

#include <iostream>

using namespace std;


class CircularArrayQue {

//defining the private variables
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    // constructor to give some initial values to private variables
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    // checker to see if the que is full or not

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    // circular queue initializer with the given size 
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

// function to push the element in the queue, as you can seeit is using modules operation to make the queue circular
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
// function to pop the element from the queue, it is also using modulo operation to work in circular manner
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */ 
 // main function
int main() {
    //initializing the queue of size 5
    CircularArrayQue C1(5);

//pushing some elements in the que
    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}