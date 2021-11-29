#include "emoji.h"    
#include <bits/stdc++.h>

using namespace std;

#define ROCK u8"\U0000270A"
#define PAPER u8"\U0000270B"
#define SCISSORS u8"\U0001F44C"
#define LIZARD u8"\U0001F918"
#define SPOCK u8"\U0001F596"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

class check {
    int* arr;
    int  size;

public:
    check() : size{20} {
        arr = new int[size + 1];
        initialiseArr();
    }

    check(int size) : size{size} {
        arr = new int[size + 1];
        initialiseArr();
    }

    void load(int i) {
        arr[i]++;
    }

    void initialiseArr() {
        for (int i = 0; i < size + 1; i++) {
            arr[i] = 0;
        }
    }
    
    void disturb(double res[], double total) {
        for (int i = 0; i < size + 1; i++) {
            res[i] = (double)arr[i] / total;
        }
    }
};

class DiceRoll {
    int faces;

    int Random(int maximum) {
        return 1 + (rand() % maximum);
    }

   
    int Random(int minimum, int maximum) {
        return 1 + minimum + (rand() % (maximum - minimum));
    }
    void init(int _seed, int _faces) {
        faces = _faces;
        srand(_seed);
    }
public:
    DiceRoll() {
        
        init(time(0), 6);
    }
    DiceRoll(int _seed) {
        
        init(_seed, 6);
    }
    DiceRoll(int _seed, int _faces) {
        
        init(_seed, _faces);
    }

    void setDice(int _faces) {
        faces = _faces;
    }

    int Roll(int faces, int x) {
        int ans = 0;
        while (x--) {
            ans += Random(faces);
        }
        return ans;
    }
};



class RandomRoll {
    default_random_engine generator;
    uniform_int_distribution< int > dice[21];

public:
    
    RandomRoll() {
        dice[4] = uniform_int_distribution< int >(1, 4);
        dice[6] = uniform_int_distribution< int >(1, 6);
        dice[8] = uniform_int_distribution< int >(1, 8);
        dice[10] = uniform_int_distribution< int >(1, 10);
        dice[12] = uniform_int_distribution< int >(1, 12);
        dice[20] = uniform_int_distribution< int >(1, 20);
    }

    int Roll(int faces) {
        int diceRoll = dice[faces](generator);
        return diceRoll;
    };
};


struct Hands {
    const string rock = ROCK2;
    const string paper = PAPER2;
    const string scissors = SCISSORS2;
    const string lizard = LIZARD2;
    const string spock = SPOCK2;

    static map< string, string > Emojis; 

    static map< string, string > Names; 

    static string RandomHand() {
        auto it = Emojis.begin();  
        
        
        std::advance(it, rand() % Emojis.size());  

        string random_hand = it->second;  

        return random_hand;  
    }

    static string Rock() {
        return Emojis["rock"];
    }
    static string Paper() {
        return Emojis["paper"];
    }
    static string Scissors() {
        return Emojis["scissors"];
    }
    static string Lizard() {
        return Emojis["lizard"];
    }
    static string Spock() {
        return Emojis["spock"];
    }
};


map< string, string > Hands::Emojis = {
    {"rock", ROCK2},
    {"paper", PAPER2},
    {"scissors", SCISSORS2},
    {"lizard", LIZARD2},
    {"spock", SPOCK2}};

map< string, string > Hands::Names = {
    {ROCK2, "rock"},
    {PAPER2, "paper"},
    {SCISSORS2, "scissors"},
    {LIZARD2, "lizard"},
    {SPOCK2, "spock"}};


class DiceHand : public DiceRoll, public Hands {
public:
  DiceHand(): DiceRoll(time(0)){
      string h = RandomHand();
      cout<<Names[h]<<": " <<h<<endl;
  };
  DiceHand(int seed) : DiceRoll(seed) {
      cout << "Rock: " << Rock() << endl;
  }
};


class Player {
  string weapon1;
  string weapon2;

  public:
    Player() {
      weapon1 = "Unarmed";
      weapon2 = "Unarmed";
    }

    void giveWeapons() {
      weapon1 = Hands::RandomHand();
      weapon2 = Hands::RandomHand();
      while(weapon2 == weapon1) {
        weapon2 = Hands::RandomHand();
      }
    }

    string GetWeapon1() {
      return weapon1;
    }

    string GetWeapon2() {
      return weapon2;
    }

    
    bool operator>(const Player& other) {
      
      if (this->weapon1 == other.weapon1){
        if (this->weapon2 == SCISSORS2 && other.weapon2 == PAPER2){
        return true; 
        }else if (this->weapon2 == PAPER2 && other.weapon2 == ROCK2){
        return true; 
        }else if (this->weapon2 == ROCK2 && other.weapon2 == LIZARD2){
        return true; 
        }else if (this->weapon2 == LIZARD2 && other.weapon2 == SPOCK2){
        return true; 
        }else if (this->weapon2 == SPOCK2 && other.weapon2 == SCISSORS2){
        return true; 
        }else if (this->weapon2 == SCISSORS2 && other.weapon2 == LIZARD2){
        return true; 
        }else if (this->weapon2 == LIZARD2 && other.weapon2 == PAPER2){
        return true; 
        }else if (this->weapon2 == PAPER2 && other.weapon2 == SPOCK2){
        return true; 
        }else if (this->weapon2 == SPOCK2 && other.weapon2 == ROCK2){
        return true; 
        }else if (this->weapon2 == ROCK2 && other.weapon2 == SCISSORS2){
        return true; 
        }
      }else{
        if (this->weapon1 == SCISSORS2 && other.weapon1 == PAPER2){
        return true; 
        }else if (this->weapon1 == PAPER2 && other.weapon1 == ROCK2){
        return true; 
        }else if (this->weapon1 == ROCK2 && other.weapon1 == LIZARD2){
        return true; 
        }else if (this->weapon1 == LIZARD2 && other.weapon1 == SPOCK2){
        return true; 
        }else if (this->weapon1 == SPOCK2 && other.weapon1 == SCISSORS2){
        return true; 
        }else if (this->weapon1 == SCISSORS2 && other.weapon1 == LIZARD2){
        return true; 
        }else if (this->weapon1 == LIZARD2 && other.weapon1 == PAPER2){
        return true; 
        }else if (this->weapon1 == PAPER2 && other.weapon1 == SPOCK2){
        return true; 
        }else if (this->weapon1 == SPOCK2 && other.weapon1 == ROCK2){
        return true; 
        }else if (this->weapon1 == ROCK2 && other.weapon1 == SCISSORS2){
        return true; 
        }
      }   
      return false;
    }

     
    friend ostream& operator<<(ostream& cout, const Player& plyr){
      if (plyr.weapon1 == "Unarmed" && plyr.weapon2 == "Unarmed") {
        cout << "Player is unarmed...\n";
      }else{
        cout << plyr.weapon1 << " + " << plyr.weapon2 << '\n';
      }
      return cout;
    }    
};

int main() {
  
  DiceRoll dr(time(0), 20); 
  Player p1; 
  Player p2; 

  for (int i = 0; i < 10; i++){
    p1.giveWeapons();
    p2.giveWeapons();

    if(p1 > p2){
      
      if (p1.GetWeapon1() != p2.GetWeapon1()) {
        cout << "Player 1 " << p1.GetWeapon1() 
          << " beat Player 2 " << p2.GetWeapon1() << "!" << endl;
      }else{
        cout << "Player 1 " << p1.GetWeapon2() 
          << " beat Player 2 " << p2.GetWeapon2() << "!" << endl;
      }
    }else if(p2 > p1){
      
      if (p1.GetWeapon1() != p2.GetWeapon1()) {
        cout << "Player 2 " << p2.GetWeapon1() 
          << " beat Player 1 " << p1.GetWeapon1() << "!" << endl;
      }else{
        cout << "Player 2 " << p2.GetWeapon2() 
          << " beat Player 1 " << p1.GetWeapon2() << "!" << endl;
      }
    }else{
      cout << "Fight tied !!!" << endl;
      cout << "Player1 Weapons: " << p1;
      cout << "Player2 Weapons: " << p2;
    }
    cout << '\n';
  }

  
  
  return 0;
}