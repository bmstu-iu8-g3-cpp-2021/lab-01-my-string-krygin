// Copyright 2020 Your Name <your_email>

#include <string.hpp>


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

std::ostream& operator<<(std::ostream& o, const String& s) {
  o << s.Data;
  return o;
}

bool operator==(const char* a, const String& b) {
  return strcmp(a, b.Data) == 0;
}
