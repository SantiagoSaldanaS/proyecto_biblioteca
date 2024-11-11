// Santiago Saldaña Subías - A01708446 (08/11/2024)

#include <iostream>
#include "Author.h"
#include "Member.h"
#include "Book.h"

using namespace std;

int main() {
    // Test Author class
    Author author("J.K. Rowling", 0);
    cout << "Autor creado: " << endl;
    author.show_info();

    cout << "\nAnadiendo libros al autor..." << endl;
    author.add_book("Harry Potter and the Philosopher's Stone");
    author.add_book("Harry Potter and the Chamber of Secrets");
    author.add_book("Harry Potter and the Prisoner of Azkaban");

    cout << "\nInformacion del autor tras crear libros: " << endl;
    author.show_info();

    cout << "\nEliminando libros del autor..." << endl;
    author.remove_book("Harry Potter and the Chamber of Secrets");
    author.show_info();

    cout << "\nBorrando todos los libros del autor..." << endl;
    author.delete_all_books();
    author.show_info();

    // Test Book class
    Book book("1984", "Dystopian", "A story about surveillance and government control.", 
              "John Doe", "George Orwell", 328, 50);

    cout << "\nLibro creado: " << endl;
    book.show_info();

    cout << "\nActualizando el numero de rentas..." << endl;
    book.set_last_rented("Jane Doe");
    book.set_number_of_rents(book.get_number_of_rents() + 1);
    book.show_info();

    // Test Member class
    Member member("Alice Johnson");
    cout << "\nMiembro creado: " << endl;
    member.show_info();

    cout << "\nAnadiendo libros rentados al miembro..." << endl;
    member.rent_book("1984");
    member.rent_book("Brave New World");
    member.show_info();

    cout << "\nEliminando libro rentado del miembro..." << endl;
    member.return_book("1984");
    member.show_info();

    cout << "\nLibros actualmente rentados:" << endl;
    for (const string& book : member.get_current_books()) {
        cout << book << ", ";
    }
    cout << endl;

    cout << "\nHistorial de renta de libros: " << endl;
    for (const string& book : member.get_rented_history()) {
        cout << book << ", ";
    }
    cout << endl;

    return 0;
}
