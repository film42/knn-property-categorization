#include "knn.h"

#include <string>

namespace kNN {

  std::string to_string( kNN::PropertyType type ) {
    switch (type) {
      case kNN::PropertyType::House:
        return "House";

      case kNN::PropertyType::Apartment:
        return "Apartment";

      case kNN::PropertyType::Flat:
        return "Flat";

      default:
        return "Not Found";
    }
  }

}