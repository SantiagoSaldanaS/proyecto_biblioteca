#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string genre;
    string summary;
    int length;
    int number_of_rents;

    string last_rented;
    string author;

public:
    // Constructor por omision.
    Book() {
        title = "Desconocido";
        genre = "Desconocido";
        summary = "N/A";
        last_rented = "Desconocido";
        length = 0;
        number_of_rents = 0;
    }

    // Constructor con parametros.
    Book(string _title, string _genre, string _summary, string _last_rented, string _author, int _length, int _number_of_rents) {
        title = _title;
        genre = _genre;
        summary = _summary;
        last_rented = _last_rented;
        author = _author;
        length = _length;
        number_of_rents = _number_of_rents;
    }

    // Getters.
    string get_title() {
        return title;
    }
    string get_genre() {
        return genre;
    }
    string get_summary() {
        return summary;
    }
    string get_last_rented() {
        return last_rented;
    }
    string get_author() {
        return author;
    }
    int get_length() {
        return length;
    }
    int get_number_of_rents() {
        return number_of_rents;
    }

    // Setters.
    void set_title(string _title) {
        title = _title;
    }
    void set_genre(string _genre) {
        genre = _genre;
    }
    void set_summary(string _summary) {
        summary = _summary;
    }
    void set_last_rented(string _last_rented) {
        last_rented = _last_rented;
    }
    void set_author(string _author) {
        author = _author;
    }
    void set_length(int _length) {
        length = _length;
    }
    void set_number_of_rents(int _number_of_rents) {
        number_of_rents = _number_of_rents;
    }

    // Metodos.
    void show_info() {
        cout << "Titulo: " << title << endl;
        cout << "Genero: " << genre << endl;
        cout << "Resumen: " << summary << endl;
        cout << "Rentado por ultima vez por: " << last_rented << endl;
        cout << "Autor: " << author << endl;
        cout << "Paginas: " << length << endl;
        cout << "Veces rentado: " << number_of_rents << endl;
    }
};

#endif
