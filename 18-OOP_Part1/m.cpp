#include <iostream>
#include <string>
using namespace std;

// Modes of inheritance (the keyword after ':'):
//   class Derived : public Base      — "interface" inheritance (common)
//   class Derived : protected Base
//   class Derived : private Base     — default if you omit it:  class D : B  ==  private B
//
// How base members appear in the derived class (summary table from notes):
//
//   base member     |  : public Base   |  : protected Base  |  : private Base
//   ----------------+------------------+---------------------+------------------
//   public          |  public          |  protected          |  private
//   protected       |  protected       |  protected          |  private
//   private         |  not accessible  |  not accessible     |  not accessible

class Base {
public:
    string pub = "base-public";
    void showPub() const { cout << "    Base::showPub: " << pub << "\n"; }

protected:
    string prot = "base-protected";
    void showProt() const { cout << "    Base::showProt: " << prot << "\n"; }

private:
    string priv = "base-private";
    void showPriv() const { cout << "    Base::showPriv: " << priv << "\n"; }
};

// --- 1) public inheritance: public stays public, protected stays protected ---
class DerivedPublic : public Base {
public:
    void inside() {
        cout << "  [DerivedPublic::inside] can use inherited pub & prot; priv is hidden.\n";
        showPub();
        cout << "    pub = " << pub << "\n";
        showProt();
        cout << "    prot = " << prot << "\n";
        // showPriv();   // error: Base::priv / showPriv not accessible in derived
    }
};

// --- 2) protected inheritance: base public+protected both become protected here ---
class DerivedProtected : protected Base {
public:
    void inside() {
        cout << "  [DerivedProtected::inside] still sees pub & prot inside this class.\n";
        showPub();
        showProt();
    }
};

// --- 3) private inheritance: base public+protected both become private in this class ---
class DerivedPrivate : private Base {
public:
    void inside() {
        cout << "  [DerivedPrivate::inside] inside the class, pub/prot of Base are usable.\n";
        showPub();
        showProt();
    }
};

int main() {
    cout << "=== 1) public inheritance ===\n";
    DerivedPublic d1;
    d1.showPub();           // OK: Base::showPub stayed public
    cout << "    d1.pub = " << d1.pub << "\n";   // OK
    d1.inside();
    // d1.showProt();       // error: protected in DerivedPublic — not callable from main
    // d1.prot = "x";       // error: same

    cout << "\n=== 2) protected inheritance ===\n";
    DerivedProtected d2;
    d2.inside();
    // d2.showPub();        // error: Base public became protected — not visible outside
    // d2.pub = "x";        // error

    cout << "\n=== 3) private inheritance ===\n";
    DerivedPrivate d3;
    d3.inside();
    // d3.showPub();        // error: former Base public is now private in DerivedPrivate
    // d3.pub = "x";        // error

    cout << "\n=== Base private in all modes ===\n";
    cout << "    Base private members are never accessible in any derived class.\n";

    cout << "\n=== Default for `class` ===\n";
    cout << "    `class D : B` is private inheritance (same as `class D : private B`).\n";
    cout << "    `struct D : B` defaults to public inheritance.\n";

    return 0;
}
