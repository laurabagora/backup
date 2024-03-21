# This class stores information about a location on Earth.  Locations are
# Specified using latitude and longitude.  The class includes a method for
# Computing the distance between two locations.

# Imports
from geolocation import GeoLocation
from math import *

# Constants
RADIUS = 3963.1676
geo = GeoLocation

# Class
class PlaceInformation:

    # Constructs object
    def __init__(self, name, address, tag, latitude, longitude):
        self.__name = name
        self.__address = address
        self.__tag = tag
        self.__latitude = float(latitude)
        self.__longitude = float(longitude)

    # Returns name
    def get_name(self):
        return self.__name

    # Returns address
    def get_address(self):
        return self.__address
    
    # Returns tag
    def get_tag(self):
        return self.__tag

    # Returns string 
    def __str__(self):
        geo1 = GeoLocation(self.__latitude, self.__longitude)
        return 'name: '+str(self.__name)+' ('+(geo1.__str__())+')'

    # Returns latitude and longitude
    def get_location(self):
        return(geo.get_latitude(latitdude), geo.get_longitude(self))
        

    # Returns distance from geo locations
    # Imported from geolocation.py
    def distance_from(self, other):
        geo1 = GeoLocation(self.__latitude, self.__longitude)
        return GeoLocation.distance_from(geo1, other)

        
                 
