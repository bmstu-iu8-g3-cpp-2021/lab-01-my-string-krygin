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
    temp[j+size1] = str2[j];
  }
  temp[size1 + size2] = '\0';
  return temp;
}


String::String() {
  Data = new char[1];
  Data[0] = '\0';
}

String::String(const char *data) {
  size_t size = strlen(data);
  Data = new char[size + 1];
  for (size_t i = 0; i < size + 1; i++) {
    Data[i] = data[i];
  }
}

String::String(const String &rhs): String(rhs.Data) {
}

String::~String() {
  delete [] Data;
}

String &String::operator=(const String &rhs) {
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

String String::operator+(const String& rhs) {
    return *this + rhs.Data;
}

std::ostream& operator<<(std::ostream& o, const String& s) {
  o << s.Data;
  return o;
}

bool operator==(const char* a, const String& b) {
  return strcmp(a, b.Data) == 0;
}
