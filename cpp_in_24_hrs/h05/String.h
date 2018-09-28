//
// Created by ralf on 18-9-19.
//

#ifndef H05_STRING_H
#define H05_STRING_H


class String {
public:
    // constructors
    String();
    explicit String(const char*);
    String(const String&);
    ~String();

    // overloaded ops
    char& operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String&);
    void operator+=(const String&);
    String& operator=(const String&);

    // general accessors
    int getLen() const { return len; }
    const char* getString() const { return value; }

    static int constructorCount;

private:
    explicit String(int);
    char* value;
    int len;
};


#endif //H05_STRING_H
