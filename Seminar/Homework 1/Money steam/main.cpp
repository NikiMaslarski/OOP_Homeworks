#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 10;
using namespace std;

struct Player{
    int points = 0;
    int diceValue;
};

int dice(){
    return rand() % 6 + 1;
}

void rollDice(int& pl1,int& pl2){
    pl1 = dice();
    pl2 = dice();
}

void pickNumber(int* steam,Player& player){
    int number;
    cin >> number;

    while (number < 0 || number > 9 || steam[number] < 0){
        cout << "Invalid number" << endl;
        cin >> number;
    }
    cout << "You win " << steam[number] << " points" << endl;
    player.points += steam[number];
    steam[number] *= -1;           // Инвалидирам избираните стойности.
}

void playerTwoPick(int* steam,Player& player){
    cout << "Player 2 can pick a number from the interval [0," << N-1 << "]: ";
    pickNumber(steam,player);
    cout << "Player 2 has a total of " << player.points <<" points" << endl;
}

void playerOnePick(int* steam,Player& player){
    cout << "Player 1 can pick a number from the interval [0," << N-1 << "]: ";
    pickNumber(steam,player);
    cout << "Player 1 has a total of " <<  player.points << " points" << endl;
}

void money_steam(){
    int *steam = new int[N];

    for (int i = 0; i < N; i++){
        steam[i] = rand() % 100;
    }

    struct Player player1,player2;

    for (int i = 0; i < N/2; i ++){      // You dont want to know :/
        cout <<endl << "Rolling the dices..." << endl;
        do{
            rollDice(player1.diceValue,player2.diceValue);
            cout << "Player 1 rolls " << player1.diceValue
                 << endl << "Player 2 rolls " << player2.diceValue<< endl;
        }while(player1.diceValue == player2.diceValue);
        cout << endl;

        if (player1.diceValue > player2.diceValue){
            playerOnePick(steam,player1);
            cout << endl;
            playerTwoPick(steam,player2);
            }
        else if (player1.diceValue < player2.diceValue){
            playerTwoPick(steam,player2);
            cout << endl;
            playerOnePick(steam,player1);
        }
    }

    if (player1.points > player2.points){
        cout << endl << "Player 1 wins!";
    }
    else if (player1.points < player2.points){
        cout << endl << "Player 2 wins!";
    }
    else
        cout << endl << "Draw!!!";

    cout << endl;
    delete []steam;
}

int main()
{
    srand(time(NULL));

    int n;
    do{
        money_steam();
        cout << endl << "To exit press 0." << endl
             << "To play again press any other number."<< endl;
        cin >> n;
    }while(n);
}
