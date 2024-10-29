#include <print>
#include <cinttypes>
#include <array>
#include <utility>
#include "utility.hpp"

std::int32_t main()
{
  int a[10] {};
  int b[5]  {};
  auto test {utility::make_pair(a, b)};
  //auto test {std::make_pair(a, b)};
  std::println("{}, {}", *test.first, *test.second);

  return 0;
}