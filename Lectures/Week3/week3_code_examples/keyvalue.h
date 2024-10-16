// keyvalue.h
#pragma once

#ifndef KEYVALUE_H
#define KEYVALUE_H

#include <iostream>

template <typename K, typename V>
class Keyvalue {
  K key{};
  V val{};
public:
  Keyvalue() {

  }
  Keyvalue(K k, V v) {
    key = k;
    val = v;
  }
  std::istream& input(std::istream& is) {
    std::cout << "Enter a key: ";
    is >> key;
    std::cout << "Enter a value: ";
    is >> val;
    return is;
  }
  std::ostream& display(std::ostream& os)const {
    os << key << " : " << val << std::endl;
    return os;
  }
  Keyvalue<K, V>& operator+=(const Keyvalue<K,V>& kv) {
    *this = Keyvalue(kv.key, kv.val);
    return *this;
  }
};

template<>
Keyvalue<std::string, std::string>& Keyvalue<std::string,std::string>::operator+=(const Keyvalue<std::string, std::string>& kv) {

}
template <typename K, typename V> std::ostream& operator<<(std::ostream& os, const Keyvalue<K, V>& keyval) {
  return keyval.display(os);
}

template <typename K, typename V>
std::istream& operator>>(std::istream& os, Keyvalue<K, V>& keyval) {
  return keyval.input(os);
}

#endif
