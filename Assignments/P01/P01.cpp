//Author:           Olamide Adesan
  //Email:            obadesan@my.msutexas.edu
  //Label:            P01
  //Title:            Linked List Class
  //Course:           CMPS2143
  //Semester:         Fall 2021
 
 //Description 
 //class that will include more functionality. You will achieve this by writing additional methods to add values, remove values, 
 //and maintain sorted values if needed. This class also needs the ability to be initialized with different data sources (files, other vectors, and arrays).







#include <iostream>


# include<bits/stdc++.h>

using namespace std;

class MyVector{
  public:
  vector<int> vec;

  /****************constructors******************/
  // default constructor
  MyVector(){
  }

  // constructor that takes input an array
  MyVector(int *A, int size){
    
    for(int i=0;i<size;i++){
      vec.push_back(A[i]);
    }
  }
  
  

  // copy constructor
  MyVector(MyVector &v){
    vec = v.vec;
  }
  
  // constructor that reads file
  MyVector(string FileName){
    int num;
    fstream file;
    file.open(FileName);

   while (file >> num)
        vec.push_back(num);
  
  }

  // ************member functions*********************
  void pushFront(int n){
    vec.insert(vec.begin(),n);
  }

  void pushFront(MyVector v){
    for(int i=v.vec.size()-1;i>=0;i--){
      vec.insert(vec.begin(),v.vec[i]);
    }
  }
  void pushRear(int n){
    vec.push_back(n);
  }



  void pushRear(MyVector v){
    for(int i=0;i<v.vec.size();i++){
      vec.push_back(v.vec[i]);
    }
  }

  int popFront(){
    int x;
    x= vec[0];
    vec.erase(vec.begin());
      return x;
  }

  int popRear(){
    int x;
    x= vec[vec.size()-1];
    vec.pop_back();
    return x;
  }

  int popAt(int pos){
    
    int x = vec[pos];
    vec.erase(vec.begin()+pos);
    return x;

  }
  
  
  
  int find(int target){
    for(int i=0;i<vec.size();i++){
      if(vec[i]==target){
        return i;
      }
    }
    return -1;
  }

  void print(){
    cout<<"[";
    for(int i=0;i<vec.size();i++){
      
      cout<<vec[i];
      if(i!=vec.size()-1)
      cout<<", ";
    }
    cout<<"]"<<endl;
  }

};


int main() {
int x = 0;

MyVector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
MyVector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]



v2.pushFront(9);
//v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]
x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
// -1

MyVector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]




MyVector v4("input.dat");
v4.pushRear(v3);
v4.print();
}