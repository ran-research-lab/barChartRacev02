////
//// Created by Rafael Arce Nazario on 11/1/20.
////
//
//#include "catch.hpp"
//
//#include "Bar.h"
//
//TEST_CASE( "Unit tests for Bar class", "[bar]" ) {
//    Bar b{"Example", 42, "ExampleCat"};
//    REQUIRE( b.getName() == "Example" );
//    REQUIRE( b.getValue() == 42 );
//    REQUIRE( b.getCategory() == "ExampleCat" );
//    Bar c{"OtherExample", 32, "ExampleCat"};
//
//    REQUIRE( c < b );
//    REQUIRE( b.getName() != c.getName() );
//    REQUIRE( b.getCategory() == c.getCategory() );
//
//    std::vector<Bar> V{{"Antilope", 32, "Mamifero"},
//                       {"Cucaracha", 42, "Insecto"},
//                       {"Canguro", 12, "Marsupial"}};
//    std:sort(V.begin(),V.end());
//    REQUIRE(V[0].getName() == "Canguro") ;
//    REQUIRE(V[2].getName() == "Cucaracha");
//    REQUIRE(V[1].toString() == "Antilope 32 Mamifero");
//}