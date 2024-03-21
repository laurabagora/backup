# Imports
from geolocation import GeoLocation
from math import *

# Main function
# Opens files and removes newlines
def main():
    new = open('myplaces.txt')
    new = new.readlines()
    files = []
    for index in new:
        files.append(index.replace('\n',''))
    prints(files)

# Prints the information needed        
def prints(files):
    # First geolocation information
    # From Geolocation classes
    geo = GeoLocation(files[3],files[4])

    # Geolocation names
    first = files[0]
    two = files[5]
    three = files[10]
   
    # Second geolocation information
    geo2 = GeoLocation(files[8], files[9])

    # Third geolocation information
    geo3 = GeoLocation(files[13], files[14])

    # Print correct information
    print('the '+first+' is at the ' + geo. __str__())
    print('the '+two+' is at the ' + geo2. __str__())
    print('the '+three+' is at the ' + geo3.__str__())

    # Calls to distance formula
    print('distance in miles between:')
    print('    '+first+'/'+two+'      = '+str(geo.distance_from(geo2)))
    print('    '+first+'/'+three+' = ' + str(geo.distance_from(geo3)))
    
main()
