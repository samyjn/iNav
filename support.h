#ifndef support_h
#define support_h
#include "provided.h"

bool operator<=(const GeoCoord& g1, const GeoCoord& g2);

bool operator>(const GeoCoord& g1, const GeoCoord& g2);

bool operator==(const GeoCoord& g1, const GeoCoord& g2);

bool operator==(const StreetSegment& seg1, const StreetSegment& seg2);

bool operator==(const GeoSegment& seg1, const GeoSegment& seg2);

#endif /* support_h */
