#include <cstdio>

using namespace std;

struct NoMove {
  NoMove(int n) : id{n} {
    printf("NoMove(%d) @ %p\n", id, this);
    buffer = new char[4];
    for (int i = 0; i < 3; i++) buffer[i] = n + 96;
    buffer[3] = 0;
  }

  NoMove(const NoMove& nm) {
    id = nm.id;
    buffer = new char[4];
    for (int i = 0; i < 4; i++) buffer[i] = nm.buffer[i];
    printf("NoMove Copy Constructor: id=%d @ %p\n", id, this);
  }

  NoMove operator=(const NoMove& nm) {
    id = nm.id;
    if (buffer) delete[] buffer;
    buffer = new char[4];
    for (int i = 0; i < 4; i++) buffer[i] = nm.buffer[i];
    printf("NoMove Assignement Operator: id=%d @ %p", id, this);
    return *this;
  }

  ~NoMove() {
    printf("~NoMove(%d) @ %p\n", id, this);
    delete[] buffer;
  }

  void Data() { printf("id=%d @ %p ==> %s\n", id, this, buffer); }

  int id;
  char* buffer;
};

NoMove MakeNoMove(int n) { return NoMove(n); }

NoMove a{1};

int main() {
  printf("starting\n");
  NoMove b{2};
  b.Data();
  NoMove* c = new NoMove{3};
  NoMove d{a};
  NoMove e = b;
  printf("MakeNoMove...\n");
  NoMove f = MakeNoMove(4);
  f.Data();
  delete (c);
  printf("exiting\n");
}
