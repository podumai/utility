#include <print>
#include <cinttypes>
#include "utility.hpp"

std::int32_t main()
{
  int a[10] {};
  int b[5]  {};
  auto test{mpl::utility::pair<int*, int*>(a, b)};
  std::println("{}, {}", *test.first, *test.second);

  return 0;
}