// Santiago Saldaña Subías - A01708446 (08/11/2024)

# include <iostream>
#include <limits>
# include "Library.h"


using namespace std;


int main(){
    Library library;

    while (true){
        string main_choice;
        string sub_choice;

        string autor;
        string titulo;
        string miembro;

        cout << endl <<  "Seleccione que desea hacer." << endl;
        cout << endl << "1. Anadir" << endl << "2. Eliminar" << endl << "3. Reemplazar" << endl << "4. Rentar" << endl << "5. Devolver" << endl << "6. Mostrar Biblioteca" << endl << "7. Salir" << endl;
        getline(cin, main_choice);

        if (main_choice == "1"){

            cout << endl << "Seleccione que desea anadir." << endl;
            cout << endl << "1. Libro" << endl << "2. Autor" << endl << "3. Miembro" << endl << "4. Salir" << endl;
            getline(cin, sub_choice);

            if (sub_choice == "1"){
                string genero;
                string resumen;
                int longitud;

                cout << endl << "Proporcione un titulo: ";
                getline(cin, titulo);

                cout << endl << "Proporcione un genero: ";
                getline(cin, genero);

                cout << endl << "Proporcione un resumen: ";
                getline(cin, resumen);

                cout << endl << "Proporcione un autor: ";
                getline(cin, autor);

                cout << endl << "Proporcione el numero de paginas: ";
                getline(cin, longitud);

                library.add_book(titulo, genero, resumen, autor, longitud);
            }
            else if (sub_choice == "2"){
                cout << endl << "Proporcione el nombre del autor: ";
                getline(cin, autor);

                library.add_author(autor);
            }
            else if (sub_choice == "3"){
                cout << endl << "Proporcione el nombre del miembro: ";
                getline(cin, miembro);

                library.add_member(miembro);
            }
            else{
                continue;
            }
        }
        else if (main_choice == "2"){

            cout << endl << "Seleccione que desea eliminar." << endl;
            cout << endl << "1. Libro" << endl << "2. Autor" << endl << "3. Miembro" << endl << "4. Salir" << endl;
            getline(cin, sub_choice);

            if (sub_choice == "1"){

                cout << endl << "Proporcione un titulo: ";
                getline(cin, titulo);

                library.delete_book(titulo);
            }
            else if (sub_choice == "2"){
                cout << endl << "Proporcione el nombre del autor: ";
                getline(cin, autor);

                library.delete_author(autor);
            }
            else if (sub_choice == "3"){
                cout << endl << "Proporcione el nombre del miembro: ";
                getline(cin, miembro);

                library.delete_member(miembro);
            }
            else{
                continue;
            }
        }
        else if (main_choice == "3"){
            cout << endl << "Seleccione que desea reemplazar." << endl;
            cout << endl << "1. Nombre de Libro" << endl << "2. Nombre Autor" << endl << "3. Nombre de Miembro" << endl << "4. Salir" << endl;
            getline(cin, sub_choice);

            if (sub_choice == "1"){
                string titulo_nuevo;

                cout << endl << "Proporcione el titulo a reemplazar: ";
                getline(cin, titulo);

                cout << endl << "Proporcione el titulo nuevo: ";
                getline(cin, titulo_nuevo);

                library.update_book_name(titulo, titulo_nuevo);
            }
            else if (sub_choice == "2"){
                string autor_nuevo;

                cout << endl << "Proporcione el nombre del autor a reemplazar: ";
                getline(cin, autor);

                cout << endl << "Proporcione el nuevo nombre del autor: ";
                getline(cin, autor_nuevo);

                library.update_author_name(autor, autor_nuevo);
            }
            else if (sub_choice == "3"){
                string miembro_nuevo;

                cout << endl << "Proporcione el nombre del miembro a reemplazar: ";
                getline(cin, miembro);

                cout << endl << "Proporcione el nuevo nombre del miembro: ";
                getline(cin, miembro_nuevo);

                library.update_member_name(miembro, miembro_nuevo);
            }
            else{
                continue;
            }
        }
        else if (main_choice == "4"){

            cout << endl << "Proporcione el titulo del libro a rentar: ";
            getline(cin, titulo);

            cout << endl << "Proporcione el nombre del miembro a rentar: ";
            getline(cin, miembro);

            library.rent_book_to_member(titulo, miembro);
            
        }
        else if (main_choice == "5"){

            cout << endl << "Proporcione el nombre del miembro que realiza la devolucion: ";
            getline(cin, miembro);


            cout << endl << "Proporcione el titulo del libro a devolver: ";
            getline(cin, titulo);
            
            library.return_book_from_member(titulo, miembro);
        }
        else if (main_choice == "6"){

            cout << "===========================" << endl;
            cout << "          AUTORES" << endl;
            library.show_authors();
            cout << "===========================" << endl;
            cout << "          Libros" << endl;
            library.show_books();
            cout << "===========================" << endl;
            cout << "         Miembros" << endl;
            library.show_members();
            cout << "===========================" << endl;
        }
        else if (main_choice == "7"){
            break;
        }
        else {
            cout << "Error. De una opcion valida." << endl;
        }
    }

    cout << endl << "Gracias por usar el programa de manejo de Bibliotecas" << endl << endl;

    return 0;
}
