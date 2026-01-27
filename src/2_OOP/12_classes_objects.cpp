#include <iostream>  
#include <string>  

using namespace std;

class Book{
    public:
        string read(int pages);
        string title;
        string author;
        int year;
        Book();
        Book(string _title, string _author, int _year);
        Book(int password);
        friend void displayId(Book book);
    private:
        int id;
};

Book::Book(){
    title = "unknown";
    author = "unknown";
    year = 0;
    id = 0;
}

Book::Book(string _title, string _author, int _year){ //Constructor Overloading
    title = _title;
    author = _author;
    year = _year;
    id = 1;
}

Book::Book(int password):Book(){ //Initializes with the default constructor in case the password is not correct.
    if(password == 2432){
        title = "Sadfjgasdjf";
        author = "Cthulu";
        year = 23424;
        id = -345;
    }
}

string Book::read(int pages){
    return "Im reading " + to_string(pages) + " pages today!";
}

void displayId(Book book){
    cout << "ID:" << book.id << endl;
}

//Template
template <typename T>
class Box {
    public:
        Box(const T &newValue){
            value = newValue;
        }

        const T &getValue() const;
        void setValue(const T &newValue);

    private:
        T value;
};

template <typename T>
const T &Box<T>::getValue() const {
    return value;
}

template <typename T>
void Box<T>::setValue(const T &newValue) {
    value = newValue;
}

void runClassesObjects() {     
    Book book1;
    string &book1Title = book1.title;

    Book book2("The Giving Tree", "Shel Silverstein", 1964);
    string &book2Title = book2.title;

    cout << book1.year << endl;    
    cout << book2Title << endl;  

    book2Title = "Changed Title";

    cout << book2Title << endl;

    cout << book1.read(20) << endl;

    Book book3(2432);
    cout << book3.title << endl;

    displayId(book1);
    displayId(book2);
    displayId(book3);

    Box<int> box1(2);
    Box<string> box2("Hello");

    cout << box1.getValue() << endl;
    cout << box2.getValue() << endl;
}
