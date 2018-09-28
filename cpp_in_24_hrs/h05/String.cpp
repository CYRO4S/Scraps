//
// Created by ralf on 18-9-19.
//

#include <cstring>
#include "String.h"


// default constructor.
// create string of 0 bytes.
String::String()
{
    value = new char[1];
    value[0] = '\0';
    len = 0;

    // constructorCount++;
}


// private constructor.
// create a null-filled string with specified length.
String::String(int length)
{
    value = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        value[i] = '\0';
    }
    len = length;

    // constructorCount++;
}

String::String(const char* const cString)
{
    len = strlen(cString);
    value = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        value[i] = cString[i];
    }
    value[len] = '\0';

    // constructorCount++;
}

String::String(const String& rhs)
{
    len = rhs.getLen();
    value = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        value[i] = rhs[i];
    }
    value[len] = '\0';

    // constructorCount++;
}

String::~String()
{
    delete [] value;
    len = 0;
}

String& String::operator=(const String& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    delete [] value;
    len = rhs.getLen();
    value = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        value[i] = rhs[i];
    }
    value[len] = '\0';

    return *this;
}

char& String::operator[](int offset)
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
}

char String::operator[](int offset) const
{
    if (offset > len)
        return value[len - 1];
    else
        return value[offset];
}

String String::operator+(const String& rhs)
{
    int totalLen = len + rhs.getLen();
    String temp(totalLen);

    int i;
    for (i = 0; i < len; ++i)
        temp[i] = value[i];
    for (int j = 0; j < rhs.getLen(); ++j, ++i)
        temp[i] = rhs[j];

    temp[totalLen] = '\0';

    return temp;
}

void String::operator+=(const String& rhs)
{
    int rhsLen = rhs.getLen();
    int totalLen = len + rhsLen;
    String temp(totalLen);

    int i;
    for (i = 0; i < len; ++i)
        temp[i] = value[i];
    for (int j = 0; j < rhs.getLen(); ++j, ++i)
        temp[i] = rhs[i - len];

    temp[totalLen] = '\0';
    *this = temp;
}

// int String::constructorCount = 0;