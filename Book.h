# ifndef BOOK_H
# define BOOK_H

# include <iostream>
# include <vector>

using namespace std;

class Book {
    private:
        string title;
        string genre;
        string summary;

        string last_rented;  // Nombre de la persona que rentó el libro por última vez.
        string author;  // Nombre del autor.
        vector<string> rented_members;

        int length;
        int number_of_rents;


        ///////////////////// Constructores //////////////////////

        // Constructor por omision.
        Book(){
            title = "Desconocido";
            genre = "Desconocido";
            summary = "N/A";
            last_rented = "Desconocido";
            length = 0;
            number_of_rents = 0;
        }

        // Constructor con parametros.
        Book(string _title, string _genre, string _summary, string _author, int _length){
            title = _title;
            genre = _genre;
            summary = _summary;
            author = _author;
            length = _length;
            number_of_rents = 0;
        }

        friend class Library;

    public:
        
        //////////////////////// Getters /////////////////////////

        string get_title(){
            return title;
        }
        string get_genre(){
            return genre;
        }
        string get_summary(){
            return summary;
        }
        string get_last_rented(){
            return last_rented;
        }
        string get_author(){
            return author;
        }
        int get_length(){
            return length;
        }
        int get_number_of_rents(){
            return number_of_rents;
        }
        vector<string> get_rented_members(){
            return rented_members;
        }


        //////////////////////// Setters /////////////////////////

        void set_title(string _title){
            title = _title;
        }
        void set_genre(string _genre){
            genre = _genre;
        }
        void set_summary(string _summary){
            summary = _summary;
        }
        void set_last_rented(string _last_rented){
            last_rented = _last_rented;
        }
        void set_author(string _author){
            author = _author;
        }
        void set_length(int _length){
            length = _length;
        }


        //////////////////////// Métodos /////////////////////////

        void show_info(){
            cout << endl << "======================================================================" << endl << endl;
            cout << "Titulo: " << title << endl;
            cout << "Genero: " << genre << endl;
            cout << "Autor: " << author << endl;
            cout << "Resumen: " << summary << endl;
            cout << "Paginas: " << length << endl << endl;
            cout << "Rentado por ultima vez por: " << last_rented << endl;
            cout << "Veces rentado: " << number_of_rents << endl;
            cout << "Miembros que lo rentaron: " << endl;
            for (string member : rented_members){
                cout << " -" << member << endl;
            }
        }

        void increment_rents(){
            number_of_rents++;
        }
        void reset_number_of_rents(){
            number_of_rents = 0;
        }
        void add_member(string member_name){
            rented_members.push_back(member_name);
            last_rented = member_name;
        }
        void remove_member(string member_name){
            rented_members.erase(remove(rented_members.begin(), rented_members.end(), member_name), rented_members.end());
        }

        void replace_member(string old_name, string new_name){
            remove_member(old_name);
            add_member(new_name);
        }
};

# endif
