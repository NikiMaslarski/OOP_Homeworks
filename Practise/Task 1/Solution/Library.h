#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED


enum Genre {CRIMINAL, FAIRY_TALE,FANTASY, GRAPHIC_NOVEL, ROMANCE, SCIENCE_FICTION, OTHER};

struct Book{

    char isbn[ISBN_SIZE +1];
    char title[MAX_LEN];
    char author[MAX_LEN];
    int numberOfPages;
    int publishYear;
    Genre genre;

};

struct Library{

    char name[MAX_LEN];
    Book books[LIBRARY_CAPACITY];
    int numberOfBooks = 0;
};

void printBook(const Book&);
Book read_book();
bool addBook(Library*,const Book& );
void printLibraryInfo(const Library* );
void findIsbn(const Library&);
bool checkForEqual(const char*,const char*);
void findBook(const Library&);
void findAuthor(const Library&);
void sortGenre(Library&);
void swapBook(Book*,Book*);
void compareBook(Library&);
void menu(Library&);

#endif // LIBRARY_H_INCLUDED
