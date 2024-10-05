//from official docs
#include <catch2/catch_test_macros.hpp>
#include "MyList.h"

#include <cstdint>
/*
uint32_t factorial(uint32_t number) 
{
    return number <= 1 ? number : factorial(number - 1) * number;
}
*/
TEST_CASE("Check Empty and Size") 
{
    List  l;

    REQUIRE( l.Empty() );
    REQUIRE(l.Size() == 0);

}

TEST_CASE("Check Clear")
{
    List  l;
    l.PushBack(1); l.PushBack(2);

    REQUIRE(l.Empty() == false);
    REQUIRE(l.Size() == 2);
    l.Clear();
    REQUIRE(l.Empty() == true);


}

