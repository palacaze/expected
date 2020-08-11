#include <catch2/catch.hpp>
#include <tl/expected.hpp>

TEST_CASE("Relational operators", "[relops]") {
  tl::expected<int, int> a = 1;
  tl::expected<int, int> b = 1;
  tl::expected<int, int> c = 2;

  tl::unexpected<int> fail1(1);
  tl::unexpected<int> fail2(2);
  tl::expected<int, int> e = fail1;
  tl::expected<int, int> f = fail1;
  tl::expected<int, int> g = fail2;

  CHECK(a == b);
  CHECK(a != c);
  CHECK(a != e);
  CHECK(e == f);
  CHECK(e != g);

  CHECK(a == 1);
  CHECK(a != 2);
  CHECK(a != fail1);
  CHECK(1 == a);
  CHECK(2 != a);
  CHECK(fail1 != a);
  CHECK(e == fail1);
  CHECK(e != fail2);
  CHECK(e != 1);
  CHECK(fail1 == e);
  CHECK(fail2 != e);
  CHECK(1 != e);
}
}
