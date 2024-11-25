// Santiago Saldaña Subías - A01708446 (08/11/2024)

# include <iostream>
# include "Library.h"

using namespace std;

int main(){
    Library library;

    cout << endl << "======================================================================" << endl << endl;

    // Anadir libros y autores
    cout << "Anadiendo libros y autores..." << endl;
    library.add_book("1984", "Distopia", "Una historia sobre la vigilancia y el control gubernamental.", "George Orwell", 328);
    library.add_book("Animal Farm", "Satira", "Una critica a los regimenes totalitarios.", "George Orwell", 112);
    library.add_book("Harry Potter y la Piedra Filosofal", "Fantasia", "Un nino descubre que es un mago.", "J.K. Rowling", 223);
    library.add_book("Cien Anos de Soledad", "Realismo Magico", "La saga de la familia Buendia.", "Gabriel Garcia Marquez", 417);

    // Mostrar todos los autores
    cout << "\nAutores en la biblioteca:" << endl;
    library.show_authors();

    // Mostrar todos los libros
    cout << "\nLibros en la biblioteca:" << endl;
    library.show_books();

    // Anadir miembros
    cout << "\nAnadiendo miembros..." << endl;
    library.add_member("Juan Perez");
    library.add_member("Ana Garcia");
    library.add_member("Carlos Ruiz");

    // Mostrar miembros
    cout << "\nMiembros de la biblioteca:" << endl;
    library.show_members();

    // Rentar un libro a un miembro
    cout << "\nRentando un libro a Juan Perez." << endl;
    library.rent_book_to_member("1984", "Juan Perez");

    // Mostrar libros despues de rentar
    cout << "\nLibros despues de rentar:" << endl;
    library.show_books();

    // Intentar rentar un libro que no existe
    cout << "\nIntentando rentar un libro inexistente:" << endl;
    library.rent_book_to_member("Libro Inexistente", "Ana Garcia");

    // Mostrar miembros despues de rentar
    cout << "\nMiembros despues de rentar libros:" << endl;
    library.show_members();

    // Eliminar un libro y verificar
    cout << "\nEliminando el libro 'Animal Farm'..." << endl;
    library.delete_book("Animal Farm");
    library.show_books();

    // Eliminar un autor y verificar
    cout << "\nEliminando el autor 'George Orwell'..." << endl;
    library.delete_author("George Orwell");
    library.show_books(); // Los libros de 'George Orwell' ahora deberian tener autor 'Desconocido'

    // Cambiar el nombre de un autor
    cout << "\nCambiando el nombre del autor 'J.K. Rowling' a 'Joanne Rowling'..." << endl;
    library.update_author_name("J.K. Rowling", "Joanne Rowling");
    library.show_books(); // Los libros deberian mostrar 'Joanne Rowling' ahora

    // Eliminar un miembro
    cout << "\nEliminando el miembro 'Ana Garcia'..." << endl;
    library.delete_member("Ana Garcia");
    library.show_members(); // 'Ana Garcia' ya no deberia aparecer

    // Intentar rentar un libro con un miembro eliminado
    cout << "\nIntentando rentar un libro a un miembro eliminado (Carlos Ruiz):" << endl;
    library.rent_book_to_member("Harry Potter y la Piedra Filosofal", "Carlos Ruiz");

    return 0;
}
