#ifndef __LIB_UTILITY__
#define __LIB_UTILITY__ 1

namespace utility
{

  template<class T1, class T2>
  struct pair
  {
  public:
    using value_type1      = T1;
    using value_type2      = T2;
    using reference        = pair&;
    using rvalue_reference = pair&&;
  public:
    T1 first;
    T2 second;
  public:
    pair()
      : first  ()
      , second ()
    {}

    pair(value_type1& fvalue, value_type2& svalue)
      : first  (fvalue)
      , second (svalue)
    {}

    pair(value_type1&& fvalue, value_type2&& svalue)
      : first  (std::move(fvalue))
      , second (std::move(svalue))
    {}

    pair(reference other)
      : first  (other.first)
      , second (other.second)
    {}

    pair(rvalue_reference other)
      : first  (std::move(other.first))
      , second (std::move(other.second))
    {}

    ~pair() = default;

    reference operator=(reference other)
    {
      first  = other.first;
      second = other.second;
    }

    reference operator=(rvalue_reference other)
    {
      first  = std::move(other.first);
      second = std::move(other.second);
    }
  };

  template<class T1, class T2>
  pair<T1, T2> make_pair()
  {
    return pair<T1, T2>();
  }

  template<class T1, class T2>
  pair<T1, T2> make_pair(T1& fvalue, T2& svalue)
  {
    return pair<T1, T2>(fvalue, svalue);
  }

  template<class T1, class T2>
  pair<T1, T2> make_pair(T1&& fvalue, T2&& svalue)
  {
    return pair<T1, T2>(fvalue, svalue);
  }

  template<class T1, class T2>
  bool operator==(const utility::pair<T1, T2>& lhs, const utility::pair<T1, T2>& rhs)
  {
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
  }

  template<class T1, class T2>
  bool operator!=(const utility::pair<T1, T2>& lhs, const utility::pair<T1, T2>& rhs)
  {
    return !(lhs == rhs);
  }

}

#endif