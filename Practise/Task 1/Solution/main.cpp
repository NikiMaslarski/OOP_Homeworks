#include <Library.h>
#include <iostream>

using namespace std;

int main(){

    Library test_library;
    cout << "Enter library name: ";
    cin.getline(test_library.name,MAX_LEN);

    cout << endl << "Enter book 1: " << endl << endl;

    Book book1 = read_book();
    cout << endl << "Enter book 2: " << endl << endl;
    cin.get();
    Book book2 = read_book();
    cout << endl << "Enter book 3:" << endl << endl;
    cin.get();
    Book book3 = read_book();
    cout << endl;

    addBook(&test_library,book1);
    addBook(&test_library,book2);
    addBook(&test_library,book3);

    menu(test_library);
}
