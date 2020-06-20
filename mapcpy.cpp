#include <map>
#include <iostream>

using namespace std;

struct A {
    int value;
    int id;

    A(int n) : value(n) {
        id = ++counter;
        cout << "A constructor : " << *this << endl;
    }

    A(A&& rhs) {
        id = rhs.id + 100;
        value = rhs.value;
        cout << "A MOVE constr ( " << rhs << " ) --> " << *this << endl;
    }

    A(const A& a) {
        id = ++counter;
        value = a.value;
        cout << "A COPY const ( " << a << " ) --> " << *this << endl;
    }

    ~A() {
        cout << "~A(id=" << id << ")" << endl;
    }

    friend ostream & operator << (ostream& out, const A& a) {
        out << "A @ " << &a << " [id=" << a.id << ", value=" << a.value << "]";
        return out;
    }

    static int counter;
};

int A::counter = 0;

void printMap(map<string, A> &m) {
    for (const auto& e : m) {
        cout << e.first << " -->  " << e.second << endl;
    }
}

// Function is actually not useful, but only
// here to illustrate a bug with one "&" forgotten
A *get(map<string, A> &m, string str) {
    // The convolution here is to have another variable
    // referencing the map (imagine m was a much more complex
    // expression to start with, like retrieval from a Singleton)
    //auto& tmp = m;
    // This is wrong code to test a bug
    auto tmp = m;
    const auto &e = tmp.find(str);
    if ( e == m.end() ) {
        return nullptr;
    }
    else {
        return &(e->second);
    }
}

int main() {
    map<string, A> theMap;
    theMap.emplace("toto", A(1));
    theMap.emplace("tata", A(2));
    theMap.emplace("titi", A(3));

    cout << "------- print theMap" << endl;
    printMap(theMap);

    cout << "-------- copy theMap" << endl;
    auto newMap = theMap;
    cout << "-------- print newmap" << endl;
    printMap(newMap);
  
    cout << "------- get something" << endl;
    A *a = get(theMap, "tata");
    // This call should actually fail because the memory pointed by
    // a is not valid anymore (released after temp map copy inside function)
    cout << "return A @ " << a << " --> " << *a << endl;
}
