# ifndef MEMBER_H
# define MEMBER_H

# include <iostream>
# include <vector>  // Para las listas.
# include <algorithm> // Para find.

using namespace std;

class Member {
    private:
        string name;
        vector<string> current_books; // Listas.
        vector<string> rented_history;


        ///////////////////// Constructores //////////////////////

        // Constructor por omision.
        Member(){
            name = "Desconocido";
        }

        // Constructor con parametros.
        Member(string _name){
            name = _name;
        }

        friend class Library;

    public:

        //////////////////////// Getters /////////////////////////

        string get_name(){
            return name;
        }
        vector<string> get_current_books(){
            return current_books;
        }
        vector<string> get_rented_history(){
            return rented_history;
        }

        // Setters.
        void set_name(string _name){
            name = _name;
        }

        void set_current_books(vector<string> new_current_books){
            current_books = new_current_books;
        }

        void set_rented_history(vector<string> new_rented_history){
            rented_history = new_rented_history;
        }


        //////////////////////// Métodos /////////////////////////

        // Metodos de manipulación de libros rentados.
        void rent_book(string book_title){
            current_books.push_back(book_title);
            rented_history.push_back(book_title);
        }

        void return_book(string book_title){
            auto it = find(current_books.begin(), current_books.end(), book_title);
            if (it != current_books.end()){
                current_books.erase(it);
            }
        }

        // Metodos de impresa de info.
        void show_info() {
            cout << "======================================================================" << endl << endl;
            cout << "Nombre: " << name << endl << endl;
            cout << "Libros actuales: " << endl;
            for (const string& book : current_books){
                cout << " -" << book << endl;
            }
            cout << endl << "Historial de todos los libros rentados: " << endl;
            for (const string& book : rented_history){
                cout << " -" << book << endl;
            }
        }
};

# endif
