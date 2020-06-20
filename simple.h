class Simple {
 public:
  int a_;
  Simple(int n);
  Simple(const Simple& rhs);
  Simple(Simple&& rhs) noexcept;
  void print();
};