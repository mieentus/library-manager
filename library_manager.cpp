#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Book {
    char title[100];
    char author[50];
    float price;
    int pages;
};


bool compareByTitle(const Book& a, const Book& b) {
    return strcmp(a.title, b.title) < 0;
}


class LibraryManager {
private:
    vector<Book> books;
    const char* db_filename = "library_db.dat";

public:
    LibraryManager() {
        loadDatabase();
    }

    ~LibraryManager() {
        saveDatabase();
    }

    void loadDatabase() {
        books.clear();
        fstream file(db_filename, ios::in | ios::binary);
        
        if (file.good()) {
            Book temp;
            while (file.read((char*)&temp, sizeof(Book))) {
                books.push_back(temp);
            }
            file.close();
        }
    }

    void saveDatabase() {
        fstream file(db_filename, ios::out | ios::binary);
        
        if (file.good()) {
            for (size_t i = 0; i < books.size(); i++) {
                file.write((char*)&books[i], sizeof(Book));
            }
            file.close();
        } else {
            cerr << "Blad zapisu bazy danych!\n";
        }
    }

    void addBook() {
        Book new_book;
        cout << "\n--- Dodawanie nowej ksiazki ---\n";
        
        cout << "Tytul: ";
        cin >> ws;
        cin.getline(new_book.title, 100);
        
        cout << "Autor: ";
        cin.getline(new_book.author, 50);
        
        cout << "Cena: ";
        cin >> new_book.price;
        
        cout << "Liczba stron: ";
        cin >> new_book.pages;

        books.push_back(new_book);
        cout << "Ksiazka zostala pomyslnie dodana!\n";
    }

    void displayAll() {
        if (books.empty()) {
            cout << "\nBiblioteka jest obecnie pusta.\n";
            return;
        }

        cout << "\n--- Lista Ksiazek ---\n";
        for (size_t i = 0; i < books.size(); i++) {
            cout << "[" << i + 1 << "] " << books[i].title 
                 << " | Autor: " << books[i].author 
                 << " | Cena: " << books[i].price << " zl"
                 << " | Stron: " << books[i].pages << "\n";
        }
    }

    void removeBook() {
        if (books.empty()) {
            cout << "\nBrak ksiazek do usuniecia.\n";
            return;
        }

        displayAll();
        cout << "Podaj numer ksiazki do usuniecia (1 - " << books.size() << "): ";
        int index;
        cin >> index;

        if (index > 0 && index <= (int)books.size()) {
            books.erase(books.begin() + (index - 1));
            cout << "Usunieto ksiazke.\n";
        } else {
            cout << "Nieprawidlowy numer!\n";
        }
    }

    void clearLibrary() {
        books.clear();
        cout << "Wszystkie rekordy zostaly trwale usuniete.\n";
    }

    void sortBooks() {
        sort(books.begin(), books.end(), compareByTitle);
        cout << "Posortowano ksiazki alfabetycznie wg tytulu.\n";
    }
};


int main() {
    LibraryManager library;
    bool is_running = true;
    int choice;

    while (is_running) {
        system("clear");

        cout << "\n"
             << "=================================\n"
             << "       SYSTEM BIBLIOTECZNY       \n"
             << "=================================\n"
             << "1. Dodaj nowa ksiazke\n"
             << "2. Pokaz wszystkie ksiazki\n"
             << "3. Usun ksiazke\n"
             << "4. Usun wszystkie ksiazki\n"
             << "5. Posortuj alfabetycznie (wg tytulu)\n"
             << "0. Zapisz i wyjdz\n"
             << "Wybierz opcje: ";
        
        cin >> choice;

        system("clear");

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.displayAll(); break;
            case 3: library.removeBook(); break;
            case 4: library.clearLibrary(); break;
            case 5: library.sortBooks(); break;
            case 0: 
                cout << "Zapisywanie i zamykanie systemu...\n";
                is_running = false; 
                break;
            default:
                cout << "Nieznana opcja. Sprobuj ponownie.\n";
        }

        if (is_running) {
            cout << "\n------------------------------------\n"
                 << "Nacisnij dowolny klawisz, aby wrocic do menu" << flush;
            
            system("bash -c 'read -s -n 1 -r -p \"\"'");
        }
    }

    return 0;
}