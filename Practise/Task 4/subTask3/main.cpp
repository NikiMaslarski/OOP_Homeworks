#include <iostream>
#include <fstream>
#include "dictionary.h"

using namespace std;

int main(int argc, char* argv[])
{
    fstream file;

    if(argc == 2){
        file.open(argv[1]);
    }
    else
        file.open("stats.txt");

    if(!file.is_open()){
        cerr << "Failed to open file";
        return -1;
    }

    char temp;
    Dictionary dict;

    while( true ){
        temp = file.get();

        if(temp == EOF)
            break;

        dict.checkFor(temp);
    }

    dict.printPercentage();
    file.close();
    return 0;
}
