#include <iostream>
#include <cstring>
#include <Library.h>

using namespace std;

void printBook(const Book& book){

    cout << "Book title: " << book.title << endl
         << "Book author: " << book.author << endl
         << "Book isbn: " << book.isbn << endl
         << "Number of pages: "  << book.numberOfPages << endl
         << "Year of publishing: " << book.publishYear << endl;

    cout << "Genre: ";

    switch(book.genre) {
    case 0: cout << "CRIMINAL" << endl; break;
    case 1: cout << "FAIRY_TALE" << endl; break;
    case 2: cout << "FANTASY" << endl; break;
    case 3: cout << "GRAPHIC_NOVEL" << endl; break;
    case 4: cout << "ROMANCE" << endl; break;
    case 5: cout << "SCIENCE_FICTION" << endl; break;
    case 6: cout << "OTHER" << endl; break;
    }

    cout << endl;
}

Book read_book(){

    Book new_book;

    cout << "Enter book isbn: ";
    cin.getline(new_book.isbn,ISBN_SIZE +1);

    cout << "Enter book author: ";
    cin.getline(new_book.author,MAX_LEN);

    cout << "Enter book title: ";
    cin.getline(new_book.title,MAX_LEN);

    cout << "Enter book length: ";
    cin >> new_book.numberOfPages;

    cout << "Enter the year of publishing the book: ";
    cin >> new_book.publishYear;

    int genre;
    cout << "Enter genre: ";
    do{
        cin >> genre;
    } while (genre < 0 || genre > 6); // The number of genres *

    new_book.genre = (Genre) genre;

    return new_book;
}

bool addBook(Library* library, const Book& book){

    if (library->numberOfBooks >= LIBRARY_CAPACITY)  // CHeck if the library is full
        return false;

    library->books[library->numberOfBooks] = book; // Add book

    library->numberOfBooks++; // Count the books

    return true;
}

void printLibraryInfo(const Library* library){

    cout << endl << "Library name: " << library->name << endl;

    int librarySize = library->numberOfBooks;
    for (int i = 0; i < librarySize; i++){
        cout << endl << "Book " << i+1 << " is: " << endl;
        printBook(library->books[i]);
        cout << endl;
    }
}

void findIsbn(const Library& library){

    char isbn[ISBN_SIZE +1];
    cout << "Enter isbn: ";
    cin.get();
    cin.getline(isbn,ISBN_SIZE +1);
    cout << endl;

    int numberOfBooks = library.numberOfBooks;

    for (int i = 0; i < numberOfBooks; i++){
        if(checkForEqual(isbn,library.books[i].isbn)){
            printBook(library.books[i]);
        }
    }
}

bool checkForEqual(const char* str1,const char* str2){       // Copmare strings
    bool flag = 1;
    while (*str1 || *str2){
        flag *= (*str1 == *str2); // if str1!=str2 flag will be FALSE
        str1++;
        str2++;
    }
    return flag;
}

void findAuthor(const Library& library){

    char author[MAX_LEN];
    cout << "Enter author: ";
    cin.get();
    cin.getline(author,MAX_LEN);

    int numberOfBook = library.numberOfBooks;

    for (int i = 0; i < numberOfBook; i++){
        if(checkForEqual(author,library.books[i].author)){
            printBook(library.books[i]);
            cout << endl;
        }
    }
}

void sortGenre(Library& library){

    int numberOfBook = library.numberOfBooks;
    Book temp;

    for(int i = 0; i < numberOfBook; i++){
        for (int j = 0; j < numberOfBook - i - 1;j++){
            if( (int)library.books[j].genre > (int)library.books[j+1].genre ){
                temp = library.books[j];
                library.books[j] = library.books[j+1];
                library.books[j+1] = temp;
            }

            if( (int)library.books[j].genre == (int)library.books[j+1].genre ){  // Alphabet order
                swapBook(&library.books[j],&library.books[j+1]);
            }
        }
    }
}

void swapBook(Book* book1,Book* book2){           // Assist function to sort books by name
    Book temp;
    if(book1->title[0] > book2->title[0]){
        temp = *book1;
        *book1 = *book2;
        *book2 = temp;
    }
}

void compareBook(Library& library){           // Prints the year difference of the book with most pages and the book with least pages

    Book mostPages = library.books[0];
    Book leastPages = library.books[1];
    int numberOfBooks = library.numberOfBooks;

    for (int i = 0; i < numberOfBooks; i++){                                //Finds the book with most and the one with the least pages
        if (library.books[i].numberOfPages > mostPages.numberOfPages)
            mostPages = library.books[i];

        else if (library.books[i].numberOfPages < leastPages.numberOfPages)
            leastPages = library.books[i];
    }

    int diference = mostPages.publishYear - leastPages.publishYear;
    if (diference < 0)
        diference = -diference;
    cout << "The page difference between the oldest and the newest book is: " << diference;
}

void menu(Library& library){
    cout << endl << "Pleace choose an option: " << endl
         << "Press 1 to print the library information." << endl
         << "Press 2 to search for book by ISBN." << endl
         << "Press 3 to search for author." << endl
         << "Press 4 to sort the books in the library." << endl
         << "Press 5 to compare the oldest and the newest book in the library." << endl
         << "Press 0 to exit" << endl;
    int option;
    cout << "Enter option: ";
    cin >> option;
    cout << endl;
    switch (option){

    case 1: printLibraryInfo(&library); break;
    case 2: findIsbn(library); break;
    case 3: findAuthor(library); break;
    case 4: sortGenre(library); break;
    case 5: compareBook(library); break;
    case 0: return;
    default : cout << "Pleace choose option between 0 - 5 " << endl;
    }
    cout << endl;
    menu(library);
}
