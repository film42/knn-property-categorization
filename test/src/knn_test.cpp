#include "things.h"

using namespace ::testing;

TEST( KnnTest, can_calc_property_types ) {

  kNN::PropertyList property_list( kNN::properties );

  auto type1 = property_list.calculate_type( kNN::Property( 4, 700 ),  3 );
  auto type2 = property_list.calculate_type( kNN::Property( 1, 1700 ), 3 );
  auto type3 = property_list.calculate_type( kNN::Property( 5, 2700 ), 3 );
  auto type4 = property_list.calculate_type( kNN::Property( 3, 300 ),  3 );
  auto type5 = property_list.calculate_type( kNN::Property( 2, 700 ),  3 );

  EXPECT_EQ( kNN::to_string( type1 ), "Apartment" );
  EXPECT_EQ( kNN::to_string( type2 ), "Flat" );
  EXPECT_EQ( kNN::to_string( type3 ), "House" );
  EXPECT_EQ( kNN::to_string( type4 ), "Apartment" );
  EXPECT_EQ( kNN::to_string( type5 ), "Flat" );

}