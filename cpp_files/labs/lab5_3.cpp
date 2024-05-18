#include <iostream>
using namespace std;
#include <vector>

class library {
    string name;
    vector<string> books ;

    public:
        library(string name){
            this -> name = name;

        }
        void add_book(string title){
            books.push_back(title);
        }

        void removeBook(const string &title){
            int len = books.size();
            for (int i=0; i<len; i++){
                if (books[i]==title){
                    string temp = books[i];
                    books[i] = books[len-1];
                    books[len-1] = temp;
                    books.pop_back();
                    break;
                }

            }
        }
        void printLibraryDetails(){
            int len = books.size();
            cout << "name: " <<  this -> name << endl;
            for (int i=0; i<len; i++){
                cout << books[i] << " ";
            }
            cout << endl;
        }
    void totalBooksCount(){
        int len = books.size();
        cout << "total books in the library are: " << len << endl;
    }
};

int main(){
    library lib1("library1");
    lib1.add_book("sherlock holmes");
    lib1.totalBooksCount();
    lib1.printLibraryDetails();
    lib1.removeBook("sherlock holmes");
    lib1.printLibraryDetails();
    lib1.totalBooksCount();
}