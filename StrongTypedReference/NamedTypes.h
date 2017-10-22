#pragma once

// Passing by reference
// version 1:
template <typename T, typename Parameter>
class NamedTypeRef
{
public:
  explicit NamedTypeRef(T& t) : t_(std::ref(t)) {}
  T& get() { return t_.get(); }

  // passing by const
  T const& get() const { return t_.get(); }

private:
  std::reference_wrapper<T> t_;
};


// version: 2
template <typename T, typename Parameter>
class NamedType
{
public:
  explicit NamedType(T const& value) : value_(value) {}
  // explicit NamedType(T&& value) : value_(value) {}

  // SFINAE 
  template <typename T_ = T>
  explicit NamedType(T&& value, 
    typename std::enable_if<!std::is_reference<T_>{},
    std::nullptr_t>::type = nullptr) : value_(std::move(value)) {}

  T& get() { return value_; }
  T const& get() const { return value_; }

private:
  T value_;
};
