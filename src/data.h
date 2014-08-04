#ifndef DATA_H
#define DATA_H

#include "knn.h"

namespace kNN {

  //
  // Example Data
  //

  const static std::vector< Property > properties = {

    Property( 1, 350, PropertyType::Apartment ),
    Property( 2, 300, PropertyType::Apartment ),
    Property( 3, 300, PropertyType::Apartment ),
    Property( 4, 250, PropertyType::Apartment ),
    Property( 4, 500, PropertyType::Apartment ),
    Property( 4, 400, PropertyType::Apartment ),
    Property( 5, 450, PropertyType::Apartment ),

    Property( 7, 850, PropertyType::House ),
    Property( 7, 900, PropertyType::House ),
    Property( 7, 1200, PropertyType::House ),
    Property( 8, 1500, PropertyType::House ),
    Property( 9, 1300, PropertyType::House ),
    Property( 8, 1240, PropertyType::House ),
    Property( 10, 1700, PropertyType::House ),
    Property( 9, 1000, PropertyType::House ),

    Property( 1, 800, PropertyType::Flat ),
    Property( 3, 900, PropertyType::Flat ),
    Property( 2, 700, PropertyType::Flat ),
    Property( 1, 900, PropertyType::Flat ),
    Property( 2, 1150, PropertyType::Flat ),
    Property( 1, 1000, PropertyType::Flat ),
    Property( 2, 1200, PropertyType::Flat ),
    Property( 1, 1300, PropertyType::Flat )

  };

}

#endif // DATA_H
