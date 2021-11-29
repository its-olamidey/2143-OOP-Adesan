//create a more robust MyVector class that includes some added functionality with the overloading of some C++ operators. 
//The operations performed by using a particular operator will be defined by us with a brief discussion on what we should do.
//We do not have to abide by convention, we can define each operator to do anything we want.




#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

//highest value of integer
const int INTMAX = numeric_limits<int>::max(); //


class Node
{
public:
    int data;   // Data
    int index;  // Index
    Node *prev; // previous node
    Node *next; // next node

    
    Node(int _data, Node *_prev = nullptr, Node *_next = nullptr)
    {
        data = _data;
        prev = _prev;
        next = _next;
    }

    friend ostream &operator<<(ostream &os, const Node &other)
    {
        os << other.data;
        return os;
    }
};


class MyVector
{
private:
    Node *head; // Head
    Node *tail; // tail
    int size;   // size

public:
   //Default constructor
    MyVector() 
    {
        head = tail = nullptr;
        size = 0;
    }

    
    MyVector(const MyVector &V2)
    {
        head = tail = nullptr;
        size = 0;

        Node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    //Array constructor
    MyVector(int *A, int _size) 
    {
        head = tail = nullptr;
        size = 0;

        for (int i = 0; i < _size; i++)
        {
            pushRear(A[i]);
        }
    }

   //file constructor
    MyVector(string fileName) 
    {
        ifstream infile;
        infile.open(fileName);

        head = tail = nullptr;
        size = 0;

        int val;
        while (!infile.eof())
        {
            infile >> val;
            pushRear(val);
            size++;
        }
        infile.close();
    }

   // destructor
    ~MyVector()
    {
        while (head)
        {
            popFront();
        }
    }

    
    void pushFront(int val)
    {
        if (!head)
        {
            head = tail = new Node(val); 
        }
        else if (head == tail) 
        {
            head = new Node(val, nullptr, head); 
            tail->prev = head;                   
        }
        else
        {
            head = new Node(val, nullptr, head); 
            head->next->prev = head;             
        }
        size++;
    }

    
    void pushFront(MyVector &V2)
    {
        Node *temp = V2.tail;

        while (temp)
        {
            pushFront(temp->data); 
            temp = temp->prev;
        }
    }

    // Push
    void pushRear(int val) 
    {
        if (!head)
        {
            head = tail = new Node(val); 
        }
        else if (head == tail)
        {
            tail = new Node(val, tail); 
            head->next = tail;          
        }
        else
        {
            tail = new Node(val, tail); 
            tail->prev->next = tail;    
        }
        size++;
    }

    
    void pushRear(MyVector &V2)
    {
        Node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data); 
            temp = temp->next;
        }
    }

   
    void pushAt(int loc, int val)
    {
        if (loc >= 0 && loc < size)
        {
            Node *temp = head;

            for (int i = 0; i > loc; i++)
            {
                temp = temp->next;
            }

            temp->data = val;
        }
    }

    
    int popFront()
    {
        if (!head)
        {
            return INTMAX; // not possible to pop
        }
        else if (head == tail)
        {
            int ans = head->data;
            delete head;
            head = tail = nullptr;
            size--;
            return ans;
        }
        else
        {
            int ans = head->data; 
            Node *deleteMe = head;     
            head = head->next;         
            head->prev = nullptr;

            delete deleteMe;
            size--;
            return ans;
        }
    }

    
    int popRear()
    {
        if (!tail) // not possible to pop
        {
            return INTMAX;
        }
        else if (head == tail) 
        {
            int ans = tail->data;
            delete tail;
            head = tail = nullptr;
            size--;
            return ans;
        }
        else
        {
            int ans = tail->data; 
            Node *ans1 = tail;     
            tail = tail->prev;         
            tail->next = nullptr;      

            delete ans1;
            size--;
            return ans;
        }
    }

   
    int popAt(int loc)
    {
        if (!head) // not possible to pop
        {
            return INTMAX;
        }
        else if (loc < 0 || loc > size - 1) 
        {
            return INTMAX;
        }
        else if (loc == 0) 
        {
            return popFront();
        }
        else if (loc == size - 1) 
        {
            return popRear();
        }
        else 
        {
            Node *temp = head;
            for (int i = 0; i < loc; i++)
            {
                temp = temp->next;
            }
            int ans = temp->data;
            temp->prev->next = temp->next; 
            temp->next->prev = temp->prev; 
            delete temp;

            return ans;
        }
    }

   
    int find(int val)
    {
        Node *temp = head;
        int i = 0;

        while (temp)
        {
            if (val == temp->data)
            {
                return i;
            }
            else
            {
                temp = temp->next;
                i++;
            }
        }
        return -1;
    }

  
    void print()
    {
        if (head) 
        {
            Node *travel = head; 

            cout << "[";

            while (travel) 
            {
                cout << travel->data; 
                if (travel->next)
                {
                    cout << ", ";
                }
                travel = travel->next;
            }
            cout << ']' << endl;
        }
    }

   
    void print(ofstream &outfile)
    {
        if (head) 
        {
            Node *travel = head; 

            outfile << "[";

            while (travel) 
            {
                outfile << travel->data; 
                if (travel->next)
                {
                    outfile << ", ";
                }
                travel = travel->next; 
            }
            outfile << ']' << endl;
        }
    }

  
    int getSize()
    {
        return size;
    }

    friend ostream &operator<<(ostream &os, const MyVector &V)
    {
        os << fixed << setprecision(2);

        Node *temp = V.head;
        os << "[ ";
        while (temp)
        {
            os << temp->data;
            if (temp->next)
            {
                os << ", ";
            }
            temp = temp->next;
        }
        os << " ]";
        return os;
    }

    friend ofstream &operator<<(ofstream &of, const MyVector &V)
    {
        of << fixed << setprecision(2);

        Node *temp = V.head;
        of << "[ ";
        while (temp)
        {
            of << temp->data;
            if (temp->next)
            {
                of << ", ";
            }
            temp = temp->next;
        }
        of << " ]";
        return of;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            exit(0);
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    MyVector &operator=(const MyVector &rhs)
    {
        if (this != &rhs)
        {
            this->~MyVector();
            MyVector other(rhs);
            this->pushRear(other);
        }
        return *this;
    }

    bool operator==(const MyVector &rhs)
    {
        bool isEqual;

        MyVector other = rhs;
        if (this->size != other.size)
        {
            isEqual = false;
        }
        else
        {
            for (int i = 0; i < this->size; i++)
            {
                isEqual = (*this)[i] == other[i];
            }
        }
        return isEqual;
    }

    bool operator!=(const MyVector &rhs)
    {
        return !(*this == rhs);
    }


    MyVector &operator+=(const MyVector &rhs)
    {
        MyVector other = rhs;

        if (this->size >= other.size)
        {
            for (int i = 0; i < other.size; i++)
            {
                (*this)[i] += other[i];
            }
        }
        else
        {

            for (int i = 0; i < this->size; i++)
            {
                (*this)[i] += other[i];
            }
            this->~MyVector();
            this->pushRear(other);
        }
        return *this;
    }

    MyVector &operator-=(const MyVector &rhs)
    {
        MyVector other = rhs;

        if (this->size >= other.size)
        {
            for (int i = 0; i < other.size; i++)
            {
                (*this)[i] -= other[i];
            }
        }
        else
        {

            for (int i = 0; i < this->size; i++)
            {
                (*this)[i] -= other[i];
            }
            this->~MyVector();
            this->pushRear(other);
        }
        return *this;
    }

    MyVector &operator*=(const MyVector &rhs)
    {
        MyVector other = rhs;

        if (this->size >= other.size)
        {
            for (int i = 0; i < other.size; i++)
            {
                (*this)[i] *= other[i];
            }
        }
        else
        {

            for (int i = 0; i < this->size; i++)
            {
                (*this)[i] *= other[i];
            }
            this->~MyVector();
            this->pushRear(other);
        }
        return *this;
    }

    MyVector &operator/=(const MyVector &rhs)
    {
        MyVector other = rhs;

        if (this->size >= other.size)
        {
            for (int i = 0; i < other.size; i++)
            {
                if (other[i] == 0)
                {
                    exit(0);
                }
                else
                {
                    (*this)[i] /= other[i];
                }
            }
        }
        else
        {

            for (int i = 0; i < this->size; i++)
            {
                if (other[i] == 0)
                {
                    exit(0);
                }
                else
                {
                    (*this)[i] /= other[i];
                }
            }
            this->~MyVector();
            this->pushRear(other);
        }
        return *this;
    }

    const MyVector operator+(const MyVector &rhs) const
    {
        return MyVector(*this) += rhs;
    }

    const MyVector operator-(const MyVector &rhs) const
    {
        return MyVector(*this) -= rhs;
    }

    const MyVector operator*(const MyVector &rhs) const
    {
        return MyVector(*this) *= rhs;
    }

    const MyVector operator/(const MyVector &rhs) const
    {
        return MyVector(*this) /= rhs;
    }

};
int main()
{

  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector v1(a1,5);
  MyVector v2(a2,3);

  ofstream fout;
  fout.open("output.txt");

  cout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 / v2;
  cout << v3 << endl;
  // writes out [0,0,0,4,9] to console.

  v3 = v2 / v1;
  cout << v3 << endl;
  // writes out [10,10,10,4,9] to console.

  cout << (v2 == v1) << endl;
  // writes 0 to console (false) .

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true) .
}
