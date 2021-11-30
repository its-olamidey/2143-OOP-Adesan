
## PO3A - Rock paper Scissors Lizard Spock
### Angel Badillo
### Description:

This program is a game of RPSLS (Rock Paper Scissors Lizard Spock)
where two players are generated with two random, but distinct weapons 
each (meaning a player cannot have 2 of the same weapon). The 
"weapons" are "hands", which are emojis representing rock, paper, 
scissors, lizard, and spock. The rules are:
* Scissors cuts Paper
* Paper covers Rock
* Rock crushes Lizard
* Lizard poisons Spock
* Spock smashes Scissors
* Scissors decapitates Lizard
* Lizard eats Paper
* Paper disproves Spock
* Spock vaporizes Rock
* Rock crushes Scissors

The p1's first weapon gets compared to p2's second weapon,
if their weapons are not they same (they don't "throw" the same hand)
the game is over and a winner is declared. If they have the same weapon,
there is a second match, and their weapons will be compared, but if for
any reason they have the same weapon again, the game is over and declared a tie.

### Files

|   #   | File                      | Description             |
| :---: | ------------------------- | ----------------------- |
|   1   | [main.cpp](main.cpp)      | Main driver for program |
|   2   | [RPSLS.hpp](RPSLS.hpp)    | RPLS class              |
|   3   | [output.txt](output.txt) | Output from my test run  |



### Instructions

- Just compile and run the program.

- Example Command:
  - g++ main.cpp -o main
  - ./main
