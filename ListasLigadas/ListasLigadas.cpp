#include <iostream>
#include <conio.h>
#include <ctype.h>
#include "ListaNodo.h"
#include "ListaLigada.h"

#define KEY_ESC 27
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

int main()
{
	int a = 0;

	// lista ligada de palabras
	string p1 = "Excalibur";
	string p2 = "Gungnir";
	string p3 = "Levathein";
	string p4 = "Pambazo";
	string p5 = "Tacos";

	ListaNodo<string>* s1 = new ListaNodo<string>(&p1);
	ListaNodo<string>* s2 = new ListaNodo<string>(&p2);
	ListaNodo<string>* s3 = new ListaNodo<string>(&p3);
	ListaNodo<string>* s4 = new ListaNodo<string>(&p4);
	ListaNodo<string>* s5 = new ListaNodo<string>(&p5);

	s2->InsertAfter(s1);
	s3->InsertAfter(s2);
	s4->InsertAfter(s3);
	s5->InsertAfter(s4);
	s1->InsertAfter(s5);
	// convertir en lista ligada

	// prueba de iterador
	ListaNodo<string>* iter = s1;
	ListaNodo<string>* primerItem = s1;
	do {
		cout << *(iter->data) << endl;
		iter = iter->next;
	} while (iter != primerItem);

	//prueba con clase lista ligada
	int x = 79;
	ListaLigada<int>* lista = new ListaLigada<int>(&x);
	int y = 100;
	lista->Insert(&y);

	cout << *lista->GetHeader()->data << endl;

	// ciclo de update
	ListaNodo<string>* currentItem = s1;
	int keypressed = 0;

	while (keypressed != KEY_ESC) {
		keypressed = _getch();
		//cout << "key pressed: " << keypressed << endl;}
		if (keypressed == KEY_DOWN) {
			currentItem = currentItem->next;
			cout << "Item selected: " << *currentItem->data << endl;
		}
		if (keypressed == KEY_UP) {
			currentItem = currentItem->prev;
			cout << "Item selected: " << *currentItem->data << endl;
		}
	}
	return 0;
}