#include <iostream>
#include <vector>
#include <string>

class Book {
    std::string title;

public:
    Book(const std::string& t) : title(t) {}
    const std::string& getTitle() const {
        return title;
    }
};

class Library {
    std::vector<const Book*> books;

public:
    void addBook(const Book& book) {
        books.push_back(&book); // Aggregation: Library doesn't own books
    }
    void displayBooks() const {
        std::cout << "Books in library:" << std::endl;
        for (const auto& book : books) {
            std::cout << "- " << book->getTitle() << std::endl;
        }
    }
};

int main() {
    Book book1("The C++ Programming Language");
    Book book2("Effective Modern C++");

    Library library;
    library.addBook(book1);
    library.addBook(book2);

    library.displayBooks();
    return 0;
}
