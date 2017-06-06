/*
Source: http://wordaligned.org/articles/top-ten-percent
  This program runs three different partial sort algorithms head to head,
  writing timing information to standard out.

Usage: partial_sort S N

Here, S is the size of the collection to partially sort and N is
  the number of elements from this collection to sort. S and N must
  be positive with S >= N.

The program outputs three figures, the clock times taken by
  full_sort, partial_sort, nth_element_then_sort respectively.

Example:
  $ partial_sort 1000000 500000
  11 17 6
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <stdlib.h>
#include <time.h>

namespace {

typedef std::vector<long> numbers;
typedef numbers::size_type size_type;
typedef numbers::iterator iter;
typedef std::pair<size_type, size_type> number_pair;

// Generate a 31-bit random value.
long random_value(numbers::value_type ignored) { return random(); }

// Fill the input numbers with random values.
void random_fill(numbers &ns) {
  std::transform(ns.begin(), ns.end(), ns.begin(), random_value);
}

// full_sort(), partial_sort() and nth_element_then_sort()
// implement three variant algorithms for solving the same problem:
// of sorting the input numbers vector in place so that the N
// smallest values are in order and at the front of the vector.
typedef void (*sort_fn)(iter first, iter nth, iter last);

void full_sort(iter first, iter nth, iter last) {
  // Ignore Nth, just sort the whole vector
  sort(first, last);
}

void part_sort(iter first, iter nth, iter last) {
  partial_sort(first, nth, last);
}

void nth_element_then_sort(iter first, iter nth, iter last) {
  nth_element(first, nth, last);
  sort(first, nth);
}

// Return the clock time taken by a sort function call.
clock_t clock_it(sort_fn fn, iter first, iter nth, iter last) {
  clock_t const t_start = clock();
  fn(first, nth, last);
  return clock() - t_start;
}

// Confirms the numbers vectors share the same leading N elements.
// Throws an error if not.
void check_equal_n(std::vector<numbers> const &nn, size_type N) {
  typedef numbers::const_iterator const_iter;

  if (!nn.empty()) {
    const_iter const first = nn[0].begin();
    const_iter const nth = first + N;
    std::vector<numbers>::const_iterator ni = nn.begin() + 1;

    while (ni != nn.end() && equal(first, nth, ni->begin())) {
      ++ni;
    }
    if (ni != nn.end()) {
      throw std::runtime_error("check_equal_n fails");
    }
  }
}

// "Clocks" time taken by the supplied sort functions,
// publishing results to the output stream.
void clock_sorters(std::ostream &out, number_pair SN) {
  typedef std::vector<numbers> numbers_vec;

  // Unpack S and N
  size_type const S = SN.first;
  size_type const N = SN.second;

  sort_fn sorters[] = {full_sort, part_sort, nth_element_then_sort};

  unsigned const n_sorters = sizeof(sorters) / sizeof(*sorters);
  std::ostream_iterator<clock_t> put_times(out, " ");

  numbers ns(S);
  random_fill(ns);
  numbers_vec nn(n_sorters, ns);

  sort_fn *sorter = sorters;
  int i = 0;
  for (numbers_vec::iterator ni = nn.begin(); ni != nn.end(); ++ni) {
    *put_times++ = clock_it(*sorter++, ni->begin(), ni->begin() + N, ni->end());
    if (i == 0) {
      out << "Full sort\n";
    } else if (i == 1) {
      out << "Partial sort\n";
    } else {
      i = 0;
      out << "Segment Sort";
    }
    ++i;
  }
  check_equal_n(nn, N);
  out << '\n';
}

// Processes the command line reading S, the size of the
// numbers array and N, the number of elements to sort.
// Throws a runtime_error on failure.
number_pair read_cli(int argc, char *argv[]) {
  number_pair SN;
  std::stringstream buf;

  if (!(argc == 3 && buf << argv[1] << ' ' << argv[2] &&
        buf >> SN.first >> SN.second && SN.first >= SN.second)) {
    throw std::runtime_error("Usage: please supply S and N, "
                             "where S and N are postive, and S >= N");
  }
  return SN;
}

} // anonymous namespace

int main(int argc, char *argv[]) {
  int error = 0;

  try {
    clock_sorters(std::cout, read_cli(argc, argv));
  } catch (std::exception const &exc) {
    std::cout << "An error occurred: " << exc.what() << '\n';
    error = 1;
  } catch (...) {
    std::cout << "An error occurred.\n";
    error = 1;
  }

  return error;
}