# imports
from ctypes import c_uint8 as uint8
from ctypes import c_uint64 as uint64
from struct import pack
from struct import unpack

# main function that gets input
def main():
    # get input for number
    value = float(input('Enter a real number: '))
    print()

    # go to the analysis funciton
    analysis(value)

# function that does calculations and prints outputs
def analysis(value):

    # checks if the number is greater than 0 for sign bit
    if value < 0:
        sign = '(negative)'
    else:
        sign = '(positive)'
        
    # getting representation of a float (double)
    fpbytes = pack(">d", value)
    list(fpbytes)
    fp = "".join([f"{b:064b}" for b in fpbytes])

    # repacking the bytes of the float (double) into 64-bit unsigned
    fpbin = unpack(">Q", fpbytes)
    fpuint = uint64(fpbin[0]).value

    # extracting the sign, exponent, and significand fields
    # extract sign field
    signbit = fpuint >> 63

    # extract the exponent field
    exponent = (fpuint << 1) & uint64(-1).value
    exponent = fpuint >> 52
    exponen = f"{exponent:011b}"
    # turns exponent into a useable binary number
    exponent = bin(exponent)
    exponent = exponent.replace('0b','')
    # find the base 10 number of exponent
    expon_value = int(exponent,2)
    # subtract the 64 bit bias (1023) from that
    expon_total = expon_value - 1023

    # extract the significand field
    significand = (fpuint << 12) & uint64(-1).value
    significand = significand >> 12
    significan = f"{significand:052b}"
    # turn significand into binary to manipulate
    significand = (bin(significand))
    significand = significand.replace('0b','')

    # create the implied number
    # turn number to list to append a '1.'
    implied = []
    strings = str(significand)
    for index in strings:
        implied.append(index)
    implied.insert(0,'.')
    implied.insert(0,'1')
    # turn list back to string
    implied = ''.join(implied)

    # print the outputs
    print('Float Analysis')
    print('Bit Pattern:    ',  signbit,' ', exponen, ' ', significan)
    
    # checks if number is zero
    if value == 0:
        print('This is the special pattern for negative zero')
    else:
        print('                 S   Exponent      Significand/mantissa')
        print()
        print('Sign:            ' + str(signbit) +' ' + sign)
        print('Exponent:        ' + exponen + ' = ' + str(expon_value), end = '')
        print('; w/bias 1023 -> (' + str(expon_value) + '-1023) = ' + str(expon_total))
        print('Significand      ' + significan)
        print('   w/implied 1:  ' + str(implied))
        print()
        print('Combined:        + [' + str(implied) + '] * 2^' + str(expon_total))
        print('  or:            + [1 + ', end = '')

        # checks every bit if needs to be added if '1'
        count = 0
        significand = str(significand)
        for index in significand:
            if index == '1':
                count += 1
                exp = 2 ** count
                print_total ='(1/'+str(exp)+') + ' 
                total = 1/exp
                print(str(print_total), end = '')
                # if it is zero, go to next number
            else:
                count += 1           
                print(end = '')
        # print final output
        print('(0)] * 2^' + str(expon_total))
        
main()

