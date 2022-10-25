#include<array>
#include<stdlib.h> 
#include<time.h>
#include<math.h>
#include<string>
#include<iostream>
#define N_DECK 52
using namespace std;

class Poker{
    public:
    int face;
    int point;
};

class Deck{
    public:
        Poker arr[N_DECK];

    void initDecks(){
         
        for(int i=0; i<N_DECK; i++){
            arr[i].face = ceil(i/13);
            arr[i].point = i%13;
        }
    };

    void shuffle(){
        srand(time(NULL));
        for(int i=0; i<N_DECK; i++){
            Poker tmp;
            int rand_i = rand() % N_DECK;
            tmp = arr[i];
            arr[i] = arr[rand_i];
            arr[rand_i] = tmp;
        }
    };

    void printDecks(){
        std::string str_test[4] = {"♣", "♦", "♥", "♠"};//suits_arr[4] = {'♣', '♦', '♥', '♠'};
        static char points_arr[13] = {'3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A', '2'};
        for(int i=0; i<N_DECK; i++){
            if(i%13==0){
                cout << endl;
            }
            cout << str_test[arr[i].face] << " " << points_arr[arr[i].point]  << "  ";
        }
        cout << endl << endl;
    };

};

class Player{
    /*pass*/
};

int main(){
    Deck deck;
    deck.initDecks();
    deck.printDecks();
    deck.shuffle();
    deck.printDecks();

    return 0;
}