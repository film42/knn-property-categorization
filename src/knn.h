#ifndef KNN_H
#define KNN_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <limits>

namespace kNN {

  enum class PropertyType {
    House,
    Apartment,
    Flat,
    Unknown
  };

  class Property {
    public:
      Property( int rooms, int area, PropertyType type = PropertyType::Unknown )
        : m_rooms(rooms), m_area(area), m_type(type) {}

      void calculate_neighbor_distance( double rooms_range, double area_range ) {
        for( auto& neighbor : m_neighbors ) {
          double delta_rooms = ( neighbor.get_rooms() - get_rooms() ) / rooms_range;
          double delta_area = ( neighbor.get_area() - get_area() ) / area_range;

          double delta_rooms_squared = delta_rooms * delta_rooms;
          double delta_area_squared = delta_area * delta_area;

          double distance = std::sqrt( delta_rooms_squared + delta_area_squared );
          neighbor.set_distance( distance );
        }
      }

      void sort_neighbors_by_distance() {
        std::sort(m_neighbors.begin(), m_neighbors.end(), [](Property& p1, Property& p2) {
          return p1.get_distance() < p2.get_distance();
        });
      }

      PropertyType guess_type_from_neighbors( int k ) {
        // Get types of nearest K neighbors
        std::map< PropertyType, int > totals;
        for( auto it = m_neighbors.begin(); it != ( m_neighbors.begin() + k ); ++it ) {
          auto& neighbor = *it;

          // Init type in totals
          if( totals.count( neighbor.get_type() ) <= 0 ) {
            totals.insert( std::pair< PropertyType, double >( neighbor.get_type(), 0 ) );
          }

          // Increment
          totals[ neighbor.get_type() ]++;
        }

        // Get max type
        auto max_type = PropertyType::Unknown;
        int max_count = 0;
        for( auto pair : totals ) {
          if( pair.second > max_count ) {
            max_type = pair.first;
            max_count = pair.second;
          }
        }

        return max_type;
      }

      //
      // Getters and Setters
      //

      int get_rooms() { return m_rooms; }
      int get_area() { return m_area; }
      PropertyType get_type() { return m_type; }
      double get_distance() { return m_distance; }
      void set_distance(double distance) { m_distance = distance; }
      std::vector< Property > get_neighbors() { return m_neighbors; }
      void set_neighbors( std::vector< Property > properties ) {
        m_neighbors = properties;
      }

    private:
      // Assigned
      int m_rooms;
      int m_area;
      PropertyType m_type;
      // Calculated
      double m_distance;
      std::vector< Property > m_neighbors;
  };

  class PropertyList {
    public:
      PropertyList( std::vector< Property > properties )
        : m_properties(properties) {}

      PropertyType calculate_type( Property p, int k = 1 ) {

        // Add neighbors
        p.set_neighbors( m_properties );

        // Measure the distance
        double rooms_range = get_max_rooms() - get_min_rooms();
        double area_range = get_max_area() - get_min_area();
        p.calculate_neighbor_distance(rooms_range, area_range);

        // Sort Neighbors
        p.sort_neighbors_by_distance();

        // Get types of nearest K neighbors
        return p.guess_type_from_neighbors( k );
      }

      //
      // GETTERS
      //

      std::vector< Property > get_properties() { return m_properties; };

    private:
      std::vector< Property > m_properties;

      int get_max_rooms() {
        double max_rooms = 0;
        for( auto p : m_properties ) {
          if( p.get_rooms() > max_rooms ) {
            max_rooms = p.get_rooms();
          }
        }
        return max_rooms;
      }

      int get_max_area() {
        double max_area = 0;
        for( auto p : m_properties ) {
          if( p.get_area() > max_area ) {
            max_area = p.get_area();
          }
        }
        return max_area;
      }

      int get_min_rooms() {
        double min_rooms = std::numeric_limits<double>().max();
        for( auto p : m_properties ) {
          if( min_rooms > p.get_rooms() ) {
            min_rooms = p.get_rooms();
          }
        }
        return min_rooms;
      }

      int get_min_area() {
        double min_area = std::numeric_limits<double>().max();
        for( auto p : m_properties ) {
          if( min_area > p.get_area() ) {
            min_area = p.get_area();
          }
        }
        return min_area;
      }
  };

  std::string to_string( PropertyType type );

}

#endif // KNN_H
