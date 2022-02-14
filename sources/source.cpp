// Copyright 2020 Your Name <your_email>

#include <string.hpp>

char* prepareStringConcat(const char* str1, const char* str2) {
  size_t size1 = strlen(str1);
  size_t size2 = strlen(str2);
  char* temp = new char[size1 + size2 + 1];
  for (size_t i = 0; i < size1; i++) {
    temp[i] = str1[i];
  }
  for (size_t j = 0; j < size2; j++) {
    temp[j + size1] = str2[j];
  }
  temp[size1 + size2] = '\0';
  return temp;
}

char* prepareStringMultiplication(const char* str, unsigned int m) {
  size_t size = strlen(str);
  char* temp = new char[size * m + 1];
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < m; j++) {
      temp[i + size * j] = str[i];
    }
  }
  temp[size * m] = '\0';
  return temp;
}

String::String() {
  Data = new char[1];
  Data[0] = '\0';
}

String::String(const char* data) {
  size_t size = strlen(data);
  Data = new char[size + 1];
  for (size_t i = 0; i < size + 1; i++) {
    Data[i] = data[i];
  }
}

String::String(const String& rhs) : String(rhs.Data) {}

String::~String() { delete[] Data; }

String& String::operator=(const String& rhs) {
  if (this != &rhs) {
    size_t size = strlen(rhs.Data);
    delete[] Data;
    Data = new char[size + 1];
    for (size_t i = 0; i < size + 1; i++) {
      Data[i] = rhs.Data[i];
    }
  }
  return *this;
}

String& String::operator+=(const String& rhs) {
  char* temp = prepareStringConcat(Data, rhs.Data);
  delete[] Data;
  Data = temp;
  return *this;
}

String& String::operator+=(const char* rhs) {
  char* temp = prepareStringConcat(Data, rhs);
  delete[] Data;
  Data = temp;
  return *this;
}

String String::operator+(const char* rhs) {
  char* temp = prepareStringConcat(Data, rhs);
  String result(temp);
  delete[] temp;
  return result;
}

String String::operator+(const String& rhs) { return *this + rhs.Data; }

size_t String::Size() const { return strlen(Data); }

bool String::Empty() const { return strlen(Data) == 0; }

void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < strlen(Data); i++) {
    if (Data[i] == oldSymbol) {
      Data[i] = newSymbol;
    }
  }
}

String String::operator*(unsigned int m) {
  char* temp = prepareStringMultiplication(Data, m);
  String result(temp);
  delete[] temp;
  return result;
}

String& String::operator*=(unsigned int m) {
  char* temp = prepareStringMultiplication(Data, m);
  delete[] Data;
  Data = temp;
  return *this;
}

void String::LTrim(char symbol) {
  size_t pos = 0;
  while (Data[pos] == symbol) {
    pos++;
  }
  char* temp = new char[strlen(Data) - pos + 1];
  for (size_t i = 0; i < strlen(Data); i++) {
    temp[i] = Data[i + pos];
  }
  temp[strlen(Data) - pos] = '\0';
  delete[] Data;
  Data = temp;
}

void String::RTrim(char symbol) {
  size_t pos = strlen(Data) - 1;
  while (Data[pos] == symbol) {
    pos--;
  }
  char* temp = new char[pos + 2];
  for (size_t i = 0; i <= pos; i++) {
    temp[i] = Data[i];
  }
  temp[pos + 1] = '\0';
  delete[] Data;
  Data = temp;
}

size_t String::Find(const char* substr) const {
  size_t size1 = strlen(Data);
  size_t size2 = strlen(substr);

  if (size2 > size1) {
    return -1;
  }

  for (size_t i = 0; i < size1 - size2 + 1; i++) {
    for (size_t j = 0; j < size2; j++) {
      if (Data[i + j] == substr[j]) {
        if (j == size2 - 1) {
          return i;
        }
        continue;
      } else {
        break;
      }
    }
  }
  return -1;
}

void String::swap(String& oth) {
  char* temp = oth.Data;
  oth.Data = Data;
  Data = temp;
}

size_t String::Find(const String& substr) const {
  return Find(substr.Data);
}

std::ostream& operator<<(std::ostream& o, const String& s) {
  o << s.Data;
  return o;
}

bool operator==(const char* a, const String& b) {
  return strcmp(a, b.Data) == 0;
}
