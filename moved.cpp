#include <list>
#include <iostream>

struct Simple {
    Simple(const char* str, size_t size) : length_{size}, name_{str} {
        std::cout << "Simple(" << name_ << ", " << size << ")";
        data_ = new double[length_];
        std::cout << " this=" << this << " / data_=" << data_ << std::endl;
        for (size_t i=0; i<length_; i++) {
            data_[i] = 10.0*(i+1);
        }
    }

    ~Simple() {
        std::cout << "~Simple(" << name_ << ") : this=" << this << std::endl;
        delete []data_;
        data_ = nullptr;
    }

    void print() {
        std::cout << name_ << " (this=" << this << " / data_=" << data_ << ") = [ ";
        for (size_t i=0; i<length_; i++) {
            std::cout << data_[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
    private:
    double* data_;
    size_t length_;
    std::string name_;
};

int main()
{
    std::list<Simple> li;

    auto s1 = Simple("first", 3);
    std::cout << "Push first" << std::endl;
    li.push_back(s1);
    
    std::cout << "Push second" << std::endl;
    li.push_back(Simple("second", 5));

    s1.print();
    auto p1 = li.front();
    p1.print();
    auto p2 = li.back();
    p2.print();
    
    auto s3 = Simple("third", 7);
    s3.print();

    std::cout << "Now exiting." << std::endl;
}