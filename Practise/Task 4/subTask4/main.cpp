#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");
    if(!file.is_open()){
        cerr << "Failed to open file!";
        return -1;
    }

    int lineCount = 0;
    int largestLineSize = 0;
    int largestLine = 0;
    int charCounter;

    while(file.peek() != EOF){
        lineCount++;
        charCounter = 0;

        while(file.get() != '\n' && file.peek() != EOF){
            charCounter++;
        }
        if(charCounter > largestLineSize){
           largestLineSize = charCounter;
           largestLine = lineCount;
           }
    }
    cout << "The largest line is: " << largestLine;
    file.close();
}
