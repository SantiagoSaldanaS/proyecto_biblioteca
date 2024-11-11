#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <vector>
#include <algorithm> //  Para find.

using namespace std;

class Author {
private:
    string name;
    int books;
    vector<string> book_titles; // Lista.

public:
    // Constructor por omision.
    Author() {
        name = "Desconocido";
        books = 0;
    }

    // Constructor con parametros.
    Author(string _name, int _books) {
        name = _name;
        books = _books;
    }

    // Getters.
    string get_name() {
        return name;
    }
    int get_books() {
        return books;
    }
    vector<string> get_book_titles() {
        return book_titles;
    }

    // Setters.
    void set_name(string _name) {
        name = _name;
    }

    // Metodos para manipular los libros hechos por los autores.
    void add_book(string _book) {
        // Checar si el libro ya existe.
        if (find(book_titles.begin(), book_titles.end(), _book) == book_titles.end()) {
            book_titles.push_back(_book);
            books++;
        }
    }

    void remove_book(string _book) {
        auto it = find(book_titles.begin(), book_titles.end(), _book);
        if (it != book_titles.end()) {
            book_titles.erase(it);
            books--;
        }
    }

    void delete_all_books() {
        book_titles.clear();
        books = 0;
    }

    // Metodo para mostrar info del autor.
    void show_info() {
        cout << "Nombre: " << name << endl;
        cout << "Libros: " << books << endl;
        cout << "Titulos de libros: " << endl;
        for (const string& title : book_titles) {
            cout << " -" << title << endl;
        }
        cout << endl;
    }
};

#endif
