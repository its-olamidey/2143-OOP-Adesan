#include <iostream>

#include <vector>

#include <string>

#include "helpers.hpp"

using namespace std;

#pragma once

class Die {

int sides;

public:

Die(): sides {

6

} {}

Die(int sides): sides {

sides

} {}

int roll(int rolls = 1) {

int sum = 0;

while (rolls--) {

sum += (rand() % sides) + 1;

}

return sum;

};

friend ostream & operator << (ostream & os,

const Die & d) {

return os << "[" << d.sides << "]";

}

};

class Dice {

private:

vector < Die > dice;

bool average;

bool best;

bool constant;

public:

Dice() {

init(1, 6);

}

Dice(int n, int s) {

init(n, s);

}

Dice(string d) {

vector < string > parts = tokenize(d, ".");

int n;

int s;

if (parts[0][0] >= 65) {

n = stoi(parts[1]);

s = stoi(parts[3]);

if (parts[0][0] == 'a') {

average = true;

} else {

best = true;

}

} else {

n = stoi(parts[0]);

s = stoi(parts[2]);

if (parts[2].length() > 2) {

constant = true;

}

}

init(n, s);

}

void init(int n, int s) {

while (n--) {

dice.push_back(Die(s));

}

}

/**

* @brief Roll the dice

*

* TODO: YOU MUST FIX TO ADD BEST OR AVERAGE!

*

* @param rolls

* @return int

*/

int roll(int rolls = 1) {

int sum = 0;

int max = 0;

int min = 30;

while (rolls--) {

for (int i = 0; i < dice.size(); i++) {

int x = dice[i].roll();

sum += x;

if (x >= max)

max = x;

if (x < min)

min = x;

}

}

if (average)

return sum / rolls;

else if (best)

return max;

else

return min + sum;

}

friend ostream & operator << (ostream & os,

const Dice & d) {

for (int i = 0; i < d.dice.size(); i++) {

os << d.dice[i];

}

return os;

}

};