#include <iostream>
using namespace std;
class A {
public:
	A() { x = 0; cout << "1"; }
	A(int px) { x = px; cout << "2"; }
	A(const A& pa) { x = pa.x; cout << "3"; }
protected:
	int x;
};
class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; }
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }
protected:
	A a;
	int y;
};
class C : public B {
public:
	C(int pz = 1) { z = pz; cout << "6"; }
	C(A pa) : B(pa) { z = 0; cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }
protected:
	A a;
	int z;
};
int main() {
	cout << "-- A --\n";
	A a0; cout << endl; // Appel du constructeur par défaut de A : A(). Initialise x à 0 et affiche "1".
	A a1(3); cout << endl; // Appel du constructeur de A avec un int : A(int px). Initialise x à 3 et affiche "2".
	A a2(a1); cout << endl; // Appel du constructeur de copie de A : A(const A& pa). Initialise x avec la valeur de x de a1 (3) et affiche "3".
	A a3 = a2; cout << endl; // Appel du constructeur de copie de A : A(const A& pa). Initialise x avec la valeur de x de a2 (3) et affiche "3".
	a3 = a1; cout << endl; // Appel de l'opérateur d'affectation par défaut de A. Ne produit pas de sortie car non surchargé. Copie la valeur de x de a1 (3) dans a3.
	cout << "-- B --\n";
	B b0(a0, 3); cout << endl;// Appel du constructeur de B avec A et int : B(const A& pa, int py).
	            // D'abord, le membre 'a' de B est construit en utilisant a0 (constructeur de copie de A : A(const A&)). Affiche "3".
	B b1(a1); cout << endl;// Appel du constructeur de B avec A : B(const A& pa = A()).
	            // D'abord, le membre 'a' de B est construit en utilisant a1 (constructeur de copie de A : A(const A&)). Affiche "3".
	B b2; cout << endl;// Appel du constructeur par défaut de B : B(const A& pa = A()).
	            // L'argument par défaut A() est utilisé.
	            // D'abord, un objet temporaire de A est créé (appel de A()). Affiche "1".
	            // Ensuite, le membre 'a' de B est construit en utilisant cet objet temporaire (constructeur de copie de A : A(const A&)). Affiche "3".
				// Enfin, le corps du constructeur B() est exécuté. Affiche "4".
	cout << "-- C --\n";
	C c0; cout << endl; // Appel du constructeur par défaut de C : C(int pz = 1).
	            // Avant le corps du constructeur de C, le constructeur par défaut de la classe de base B est appelé.
	            // Cela suit le comportement de B b2 : objet temporaire A() -> Affiche "1".
	            // Constructeur de copie pour B::a -> Affiche "3".
	            // Corps de B() -> Affiche "4".
	            // Ensuite, z est initialisé à 1 et le corps du constructeur C() est exécuté. Affiche "6".

	C c1(a1); cout << endl;// Appel du constructeur de C avec A : C(A pa).
	            // D'abord, l'argument `pa` est construit par copie de `a1` (constructeur de copie de A : A(const A&)). Affiche "3".
	            // Ensuite, le constructeur de la classe de base B est appelé avec cette copie de `pa` (B(pa)).
	            // Le membre `B::a` est construit par copie de `pa` (constructeur de copie de A : A(const A&)). Affiche "3".
	            // Le corps du constructeur B(pa) est exécuté. Affiche "4".
	            // Enfin, z est initialisé à 0 et le corps du constructeur C(A pa) est exécuté. Affiche "7".
	C c2(b2); cout << endl; // Appel du constructeur de C avec const B& : C(const B& pb).
	            // D'abord, le constructeur de la classe de base B est appelé avec `b2` (B(const B&)).
	            // Le membre `B::a` est construit par copie de `b2.a` (constructeur de copie de A : A(const A&)). Affiche "3".
	            // Le corps du constructeur B(b2) est exécuté. Affiche "4".
	            // Ensuite, le membre `C::a` est construit avec l'argument `1` (constructeur de A(int px)). Affiche "2".
	            // Enfin, z est initialisé à 0 et le corps du constructeur C(const B& pb) est exécuté. Affiche "8".
}



//