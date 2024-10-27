#include <print>
#include <cinttypes>
#include "utility.hpp"

std::int32_t main()
{
  auto test_pair {utility::make_pair<std::int32_t, char>(25, 'W')};
  
  std::println("{}, {}", test_pair.first, test_pair.second);

  return 0;
}