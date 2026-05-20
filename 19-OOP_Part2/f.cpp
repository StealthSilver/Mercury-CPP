// Illustration: pure virtual functions.
// A *pure virtual* (abstract) function is declared with `= 0` in the base class.
// That means: "there is no default implementation *here* — a concrete derived class
// must supply the logic." The base only names the operation; it does not define it.
//
// Syntax (same idea as your notes, with spelling normalized):
//     virtual void function() = 0;
//
// A class with any pure virtual remains abstract until every `= 0` is overridden
// with a real body in some derived type.

#include <iostream>
#include <string>

class DataSource {
   public:
    // Pure virtual: no `{ ... }` body in this class — only `= 0`.
    virtual std::string next_line() = 0;

    // Ordinary virtual *with* a body: derived *may* override; default exists.
    virtual void reset() { std::cout << "DataSource::reset (default)\n"; }

    virtual ~DataSource() = default;
};

// Still abstract: inherits `next_line() = 0` but does not implement it.
// Uncomment the next two lines to see "abstract class" errors:
// class UnfinishedSource : public DataSource {};
// UnfinishedSource bad;

class StringSource : public DataSource {
   public:
    explicit StringSource(std::string data) : data_(std::move(data)), pos_(0) {}

    // Required: provide the logic promised by the pure virtual in the base.
    std::string next_line() override {
        if (pos_ >= data_.size()) {
            return {};
        }
        const auto start = pos_;
        while (pos_ < data_.size() && data_[pos_] != '\n') {
            ++pos_;
        }
        std::string line = data_.substr(start, pos_ - start);
        if (pos_ < data_.size() && data_[pos_] == '\n') {
            ++pos_;
        }
        return line;
    }

   private:
    std::string data_;
    std::size_t pos_;
};

void dump_lines(DataSource& src) {
    for (;;) {
        const std::string line = src.next_line();
        if (line.empty()) {
            break;
        }
        std::cout << "  | " << line << "\n";
    }
}

int main() {
    // DataSource ds;  // error: abstract class (has pure virtual)

    StringSource in("alpha\nbeta\n");
    std::cout << "Reading from StringSource:\n";
    dump_lines(in);
    in.reset();

    return 0;
}
