#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <xio/xio.hpp>

TEST_CASE("Concepts", "[concepts]") {
    SECTION("UniquelyRepresented") {
        CHECK(xio::UniquelyRepresented<char>);
        CHECK_FALSE(xio::UniquelyRepresented<std::vector<char>>);
    }

    SECTION("Byte") {
        CHECK(xio::Byte<char>);
        CHECK(xio::Byte<std::byte>);
        CHECK_FALSE(xio::Byte<wchar_t>);
    }
}
