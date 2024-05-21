#include <iostream>
#include <cstring>

class String {
private:
    char* str; // Рядок (масив символів)
    size_t length; // Довжина рядка

public:
    // Конструктори
    String(); // Конструктор за замовчуванням
    String(const char* s); // Конструктор з параметрами
    String(const String& s); // Конструктор копії

    // Деструктор
    ~String();

    // Методи доступу
    size_t getLength() const;
    const char* getCString() const;

    // Операції над рядками
    String operator+(const String& s) const; // Об'єднання рядків
    String& operator=(const String& s); // Операція присвоювання
    bool operator==(const String& s) const; // Операція порівняння

    // Вивід рядка
    friend std::ostream& operator<<(std::ostream& out, const String& s);
};

// Реалізація конструкторів
String::String() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String& s) {
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

// Реалізація деструктора
String::~String() {
    delete[] str;
}

// Реалізація методів доступу
size_t String::getLength() const {
    return length;
}

const char* String::getCString() const {
    return str;
}

// Реалізація операцій над рядками
String String::operator+(const String& s) const {
    String result;
    result.length = length + s.length;
    result.str = new char[result.length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    return *this;
}

bool String::operator==(const String& s) const {
    return strcmp(str, s.str) == 0;
}

// Реалізація операції виводу рядка
std::ostream& operator<<(std::ostream& out, const String& s) {
    out << s.str;
    return out;
}

int main() {
    String s1("Hello");
    String s2(" world!");
    String s3 = s1 + s2;
    std::cout << s3 << std::endl;

    String s4 = s3; // Перевірка конструктора копії
    std::cout << (s4 == s3) << std::endl; // Порівняння рядків

    return 0;
}
