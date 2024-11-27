
# ifndef LIBRARY_H
# define LIBRARY_H

# include <vector>
# include <string>
# include <algorithm>
# include <iostream>
# include "Author.h"
# include "Book.h"
# include "Member.h"


using namespace std;

class Library{
    private:
        vector<Author> authors;
        vector<Book> books;
        vector<Member> members;

    public:

        ///////////////////// Constructores //////////////////////
    
        Library(){}


        //////////////////////// Getters /////////////////////////

        vector<Author>& get_authors(){
            return authors;
        }
        vector<Member>& get_members(){
            return members;
        }
        vector<Book>& get_books(){
            return books;
        }


        //////////////////////// Métodos /////////////////////////

        // Añadir libros.
        void add_book(string title, string genre, string summary, string author_name, int length){
            books.push_back(Book(title, genre, summary, author_name, length));

            // Checar si el autor existe.
            bool author_found = false;
            for (auto i = 0u; i < authors.size(); ++i){
                if (authors[i].get_name() == author_name){

                    // Si el autor existe añadimos el libro a su lista.
                    authors[i].add_book(title);
                    author_found = true;
                    break;
                }
            }

            // Si el autor no existe creamos uno nuevo y rentamos el libro.
            if (!author_found){
                Author new_author(author_name);
                new_author.add_book(title);
                authors.push_back(new_author);
            }
            
            cout << "Libro '" << title << "' anadido.\n";
        }


        // Añadir autores.
        void add_author(string author_name){

            // Loopeamos por la lista de autores.
            for (auto& author : authors){
                
                // Si el autor existe no hacemos nada.
                if (author.get_name() == author_name) {
                    cout << "El autor ya existe!\n";
                    return;
                }
            }

            // Si el autor no existe lo añadimos.
            authors.push_back(Author(author_name));
            cout << "Autor '" << author_name << "' anadido.\n";
        }


        // Añadir miembros.
        void add_member(string member_name) {

            // Loopeamos por la lista de miembros.
            for (auto& member : members) {

                // Si el miembro ya existe no hacemos nada.
                if (member.get_name() == member_name) {
                    cout << "El miembro ya existe!\n";
                    return;
                }
            }

            // Si el miembro no existe lo añadimos.
            members.push_back(Member(member_name));
            cout << "Miembro '" << member_name << "' anadido.\n";
        }


        // Eliminar libros.
        void delete_book(string title) {

            // Loopeamos por todos los libros.
            for (auto i = 0u; i < books.size(); ++i) {

                // Si el libro tiene el título a eliminar.
                if (books[i].get_title() == title) {

                    // Eliminamos el libro de sus respectivos autores y miembros.
                    for (auto& author : authors) {
                        author.remove_book(title);
                    }
                    for (auto& member : members) {
                        member.return_book(title);
                    }

                    // Eliminamos el libro.
                    books.erase(books.begin() + i);
                    cout << "Libro '" << title << "' eliminado.\n";
                    return;
                }
            }

            // Si no lo encontramos no hacemos nada.
            cout << "Libro '" << title << "' no encontrado.\n";
        }


        // Eliminar autores.
        void delete_author(string author_name) {

            // Loopeamos por todos los autores.
            for (auto i = 0u; i < authors.size(); ++i) {

                // Si el autor tiene el nombre a eliminar.
                if (authors[i].get_name() == author_name) {
                    
                    // Actualizamos todos los libros con este autor.
                    for (auto& book : books) {
                        if (book.get_author() == author_name) {
                            book.set_author("Desconocido");
                        }
                    }

                    // Eliminamos al autor.
                    authors.erase(authors.begin() + i);
                    cout << "Autor '" << author_name << "' eliminado.\n";
                    return;
                }
            }

            // Si no lo encontramos no hacemos nada.
            cout << "Autor '" << author_name << "' no encontrado.\n";
        }


        // Eliminar miembros.
        void delete_member(string member_name) {

            // Loopeamos por todos los miembros.
            for (auto i = 0u; i < members.size(); ++i) {

                // Si el miembro tiene el nombre a eliminar.
                if (members[i].get_name() == member_name) {

                    // Eliminamos al miembro de todos los libros rentados.
                    for (auto& book : books) {
                        book.remove_member(member_name);
                    }

                    // Eliminamos al miembro.
                    members.erase(members.begin() + i);
                    cout << "Member '" << member_name << "' deleted.\n";
                    return;
                }
            }

            // Si no lo encontramos no hacemos nada.
            cout << "Member '" << member_name << "' not found.\n";
        }


        // Renta de libros a miembros.
        void rent_book_to_member(string book_title, string member_name) {

            // Buscamos al libro.
            auto book_it = find_if(books.begin(), books.end(), [&](Book b) {
                return b.get_title() == book_title;
            });

            // Si encontramos al libro.
            if (book_it != books.end()) {

                // Buscamos al miembro.
                auto member_it = find_if(members.begin(), members.end(), [&](Member m) {
                    return m.get_name() == member_name;
                });

                // Si encontramos al miembro.
                if (member_it != members.end()) {

                    // Rentar el libro al miembro.
                    member_it->rent_book(book_title);
                    book_it->add_member(member_name);  // Añadir el miembro a la lista de renta del libro.
                    book_it->increment_rents();  // Incrementamos el número de veces que ha sido rentado.

                } else {
                    // Si no lo encontramos no hacemos nada.
                    cout << "¡Miembro no encontrado!" << endl;
                }
            } else {
                
                // Si no lo encontramos no hacemos nada.
                cout << "¡Libro no encontrado!" << endl;
            }
        }


        // Actualización de nombres de autores.
        void update_author_name(string old_name, string new_name) {
            bool author_found = false;

            // Actualizamos el nombre en la lista de autores (vector).
            // Loopeamos por la lista de autores.
            for (auto& author : authors) {

                // Si el nombre que se buscaba es igual al de la lista.
                if (author.get_name() == old_name) {

                    // Reemplazamos el nombre.
                    author.set_name(new_name);
                    author_found = true;
                }
            }

            // Si el autor no se encontró no hacemos nada.
            if (!author_found) {
                cout << "Autor con el nombre '" << old_name << "' no encontrado." << endl;
                return;
            }

            // Actualizamos el nombre del autor en todos los libros.
            // Loopeamos por los libros.
            for (auto& book : books) {

                // Si el nombre del autor es igual al que se busca se reemplaza.
                if (book.get_author() == old_name) {
                    book.set_author(new_name);
                }
            }

            cout << "Autor con nombre '" << old_name << "' reemplazado con '" << new_name << "'." << endl;
        }
        

        // Actualización de nombres de libros.
        void update_book_name(string old_title, string new_title) {

            // Booleano que determina si el libro fue encontrado.
            bool book_found = false;

            // Loopeamos por todos los libros.
            for (auto& book : books) {

                // Si el libro tiene el titulo que se busca cambiamos su nombre.
                if (book.get_title() == old_title) {
                    book.set_title(new_title);
                    book_found = true;
                    break;
                }
            }

            // Si el libro no fue encontrado no hacemos nada.
            if (!book_found) {
                cout << "Libro llamado  '" << old_title << "' no encontrado." << endl;
                return;
            }

            // Actualizamos el nombre del libro en todos los autores que lo tengan.
            for (auto& author : authors) {

                vector<string> authored_books = author.get_book_titles(); // Obtener una copia de la lista de libros del autor.
                for (auto& book_title : authored_books) {

                    // Si el título es igual al antiguo.
                    if (book_title == old_title) {
                        book_title = new_title;  // Actualizamos el título con el nuevo.
                        break;
                    }
                }
                author.set_book_titles(authored_books);  // Reemplazamos la lista antigua con la nueva.
            }

            // Actualizamos los nombres de los libros de los miembros.

            // Para los libros rentados actualmente.
            for (auto& member : members) {

                vector<string> rented_books = member.get_current_books();  // Copia de sus libros rentados.

                // Iteramos sobre la lista de libros rentados.
                for (auto& rented_title : rented_books) {
                    if (rented_title == old_title) {
                        rented_title = new_title;  // Cambiamos el título viejo con el nuevo.
                        break;
                    }
                }
                member.set_current_books(rented_books); // Reemplazamos la lista antigua con la nueva.
            }

            // Para los libros rentados en el historial (mismos pasos).
            for (auto& member : members) {

                vector<string> rented_books = member.get_rented_history();
                for (auto& rented_title : rented_books) {
                    if (rented_title == old_title) {
                        rented_title = new_title;
                        break;
                    }
                }
                member.set_rented_history(rented_books);
            }

            cout << "Título actualizado de  '" << old_title << "' a '" << new_title << "'." << endl;
        }


        // Actualización de nombres de miembros.
        void update_member_name(string old_name, string new_name){

            // Iteramos por todos los miembros.
            for (auto& member : members){

                // Si el nombre es igual al viejo.
                if (member.get_name() == old_name){

                    // Reemplazamos el nombre por el nuevo.
                    member.set_name(new_name);

                    // Actualizamos el nombre de ese miembro en todos los libros.
                    for (auto& book : books){
                        book.replace_member(old_name, new_name);
                    }

                    cout << "Nombre de miembro actualizado de '" << old_name << "' a '" << new_name << "'." << endl;
                    return;
                }
            }
            cout << "Miembro llamado '" << old_name << "' no encontrado.\n";
        }


        // Forma de mostrar todos los autores de la biblioteca.
        void show_authors(){

            // Si no hay autores no hacemos nada.
            if (authors.empty()){
                cout << "No hay autores.\n";
                return;
            }

            // Iteramos por todos los autores.
            for (auto& author : authors){
                author.show_info();
            }
        }


        // Forma de mostrar todos los miembros que pertenecen a la biblioteca.
        void show_members(){

            // Si no hay autores no hacemos nada.
            if (members.empty()){
                cout << "No hay miembros.\n";
                return;
            }

            // Iteramos por todos los miembros.
            for (auto& member : members) {
                member.show_info();
            }
        }


        // Forma de mostrar todos los libros de la biblioteca.
        void show_books(){

            // Si no hay libros no hacemos nada.
            if (books.empty()){
                cout << "No hay libros.\n";
                return;
            }

            // Iteramos por todos los libros.
            for (auto& book : books){
                book.show_info();
            }
        }
};


# endif 