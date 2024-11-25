# ifndef AUTHOR_H
# define AUTHOR_H

# include <iostream>
# include <vector>
# include <algorithm> //  Para find.

using namespace std;

class Author{
    private:
        string name;
        vector<string> book_titles; // Lista de libros escritos por el autor.


        ///////////////////// Constructores //////////////////////
    
        // Constructor por omision.
        Author(){
            name = "Desconocido";
        }

        // Constructor con parametros.
        Author(string _name){
            name = _name;
        }

        // Hace que solo la clase de Library pueda construir este tipo de objeto.
        friend class Library;

    public:

        //////////////////////// Getters /////////////////////////

        string get_name(){
            return name;
        }
        vector<string>& get_book_titles(){
            return book_titles;
        }


        //////////////////////// Setters /////////////////////////

        void set_name(string _name){
            name = _name;
        }

        void set_book_titles(vector<string> new_books){
            book_titles = new_books;
        }


        //////////////////////// Métodos /////////////////////////

        // Métodos para manipular los libros hechos por los autores.

        void add_book(string book_title){
            // Checar si el libro ya existe.
            if (find(book_titles.begin(), book_titles.end(), book_title) == book_titles.end()) {
                book_titles.push_back(book_title);
            }
        }

        void remove_book(string book_title){
            auto it = find(book_titles.begin(), book_titles.end(), book_title);
            if (it != book_titles.end()){
                book_titles.erase(it);
            }
        }

        void delete_all_books(){
            book_titles.clear();
        }

        // Metodo para mostrar info del autor.
        void show_info(){
            cout << endl << "----------------------------------------------------------------------" << endl << endl;
            cout << "Nombre: " << name << endl << endl;
            cout << "Libros: " << endl;
            for (const string& title : book_titles) {
                cout << " -" << title << endl;
            }
        }
};

# endif
