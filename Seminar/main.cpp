#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Colors {CLUBS = 1, DIAMONDS, HEARTS, SPADES};
enum Strengths {ACE = 1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGTH,NINE,TEN,JACK,QUEEN,KING};

struct Card{
    Colors color;
    Strengths strength;
};

Card enterCard(){
    Card card;
    cout << "Choose card color: ";
    int color;
    cin >> color;
    card.color = (Colors)color;
    cout << "Choose card strength: ";
    int strength;
    cin >> strength;
    card.strength = (Strengths)strength;

    return card;
}

void cardColors(){
    cout << endl << "Choose card color by pressing:"<< endl << "1 for Clubs " << endl
         << "2 for Diamonds " << endl << "3 for Hearts"
         << endl << "4 for Spades"<<endl;
}

void cardStrenths(){
    cout << endl << "Choose card strenth by pressing: " << endl
         <<"1 for Ace" << endl << "2,3,...,10 for 2,3,...,10" << endl
         <<"11 for Jack" << endl << "12 for Queen" << endl <<"13 for King"<<endl;
}

void printCard(const Card card){
    switch (card.strength){
        case 1: cout << "Ace"; break;
        case 2: cout << "Two"; break;
        case 3: cout << "Three"; break;
        case 4: cout << "Four"; break;
        case 5: cout << "Five"; break;
        case 6: cout << "Six"; break;
        case 7: cout << "Seven"; break;
        case 8: cout << "Eigth"; break;
        case 9: cout << "Ninie"; break;
        case 10: cout << "Ten"; break;
        case 11: cout << "Jack"; break;
        case 12: cout << "Queen"; break;
        case 13: cout << "King"; break;
    }

    cout << " of ";

    switch (card.color){
        case 1: cout << "Clubs"; break;
        case 2: cout << "Diamonds"; break;
        case 3: cout << "Hearts"; break;
        case 4: cout << "Spades"; break;
    }
}

void printAllCards(const Card* cards,const int size){
    for (int i = 0; i < size; i++){
        cout << "Card " << i+1 << " is ";
        printCard(cards[i]);
        cout << endl;
    }
}

void shuffle(Card* cards,const int N){
    int random1,random2;

    if (rand()%100 == 0)    //End of the recursion is random
        return;

    else {
         random1 = rand()%N;
         random2 = rand()%N;
         Card temp;
         temp = cards[random1];
         cards[random1] = cards[random2];
         cards[random2] = temp;
    }

    shuffle(cards,N);


}

int main(){
    cout << "Enter 3 cards by the following rules: ";
    cardColors();
    cardStrenths();
    cout << endl;
    const int N = 3;

    Card cards[N];
    for (int i = 0; i < N; i++){
        cards[i] = enterCard();
        cout << endl;
    }

    printAllCards(cards,N);

    srand(time(NULL));
    int random_number = rand() % N +1;

    cout << endl << "Now I will shuffle the cards" << endl;
    shuffle(cards,N);

    cout << endl << "Which card do you think is the ";
    printCard(cards[random_number - 1]);
    cout << " ?" << endl;

    int choice;
    cin >> choice;
    cout << endl;

    if (cards[choice-1].color == cards[random_number - 1].color && cards[choice-1].strength == cards[random_number-1].strength)
        cout << "Right! " << endl << endl;
    else
        cout << "Wrong! " << endl << endl;

    printAllCards(cards,N);
}
