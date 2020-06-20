#include <iostream>
#include <list>

using namespace std;

struct Simple {
    Simple(const char* str, int id) : str_(str), id_(id) {
        cout << "Simple(" << str_ << ", " << id_ << ") : this=" << this << endl;
    }

    ~Simple() {
        cout << "~Simple(): str=" << str_ << ", id=" << id_ << ", this=" << this << endl;
    }

    void print(const char *prefix) const {
        cout << prefix << "Simple: str=" << str_ << ", id=" << id_ << ", this=" << this << endl;
    }

    string str_;
    int id_;
};

Simple MakeSimple(const char* str, int id) {
    return Simple(str, id);
}

int main()
{
    list<Simple> li;

    Simple s1 {"first", 1};

    cout << "Push first" << endl;
    li.push_back(s1);

    cout << "Push second" << endl;
    li.push_back(Simple{"second", 2});

    cout << "Push third" << endl;
    li.push_back(MakeSimple("third", 3));

    cout << "List:" << endl;
    for (const auto &s : li) {
        s.print("  ");
    }

    auto s4 = MakeSimple("fourth", 4);
    s4.print("generated with make | ");

    cout << "Terminated." << endl;
}
