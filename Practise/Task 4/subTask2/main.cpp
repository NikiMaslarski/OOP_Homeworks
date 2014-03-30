#include <iostream>
#include <fstream>

using namespace std;
int getNumber(fstream&);


int main()
{
    fstream file;
    file.open("input.txt");
    if(!file.is_open()){
        cerr << "Error, can't open file";
        return -1;
    }
    int maxNumber = getNumber(file);
    int minNumber = maxNumber;
    int temp;
    int lineCounter = 1;

    while(!file.eof()){
        if(file.peek() == '\n'){
            cout << "The maximum number on line " << lineCounter
                 << " is " << maxNumber << endl;
            cout << "The minimum number on line " << lineCounter
                 << " is " << minNumber << endl;
            maxNumber = getNumber(file);
            minNumber = maxNumber;
            lineCounter += 1;
        }

        temp = getNumber(file);

        if(temp > maxNumber)
            maxNumber = temp;

        if(temp < minNumber)
            minNumber = temp;
    }
    cout << "The maximum number on line " << lineCounter
         << " is " << maxNumber << endl;
    cout << "The minimum number on line " << lineCounter
         << " is " << minNumber << endl;

    file.close();
}

int getNumber(fstream& file){

    if(file.eof())
        return 1;

    int number;
    while(!((file.peek() > '0' && file.peek() < '9') || file.peek() == '-')){

        if(file.eof())
            break;

        file.get();
    }

    file >> number;
    return number;
}
