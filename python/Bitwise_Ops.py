# imports
from ctypes import c_uint8 as uint8
from ctypes import c_uint64 as uint64
from struct import pack
from struct import unpack

# main function to print statments,get inputs and call to functions
def main():
    # print what the program does
    print("This program shows results of bitwise operations")
    print()
    print("Choose two integers")

    # get input from user
    num1 = int(input("Enter Value 1: "))
    num2 = int(input("Enter Value 2: "))
    print()

    # call to first function
    decimal(num1, num2)

# this function calculates the decimal bitwise operations    
def decimal(num1, num2):

    # calculates the And calculation
    decAnd = num1 & num2
    # turns that answer to a string
    decStr1 = str(decAnd)
    # pads the answer with zeros (4 digits for decimal)
    dc1 = decStr1.zfill(4)

    # calculates the Or calculation
    decOr = num1 | num2
    decStr2 = str(decOr)
    dc2 = decStr2.zfill(4)

    # calculates the exclusive calculation
    decEx = num1 ^ num2
    decStr3 = str(decEx)
    dc3 = decStr3.zfill(4)

    #calculates the complement calculation
    decCom = ~num1
    decStr4 = str(decCom)
    dc4 = decStr4.zfill(4)

    #calculates the right shift calculation
    try:
        decRShift = num1 >> num2
        decStr5 = str(decRShift)
        dc5 = decStr5.zfill(4)
    except:
        dc5 = ('Illegal Negative Shift')
        
    # calculates the left shift calculation
    try:
        decLShift = num1 << num2
        decStr6 = str(decLShift)
        dc6 = decStr6.zfill(4)
    except:
        dc6 = 'Illegal Negative Shift'

    # prints the answers for the outputs in decimal
    print("Decimal outputs: ")
    print()
    print("a & b  = " + str(dc1))
    print("a | b  = " + str(dc2))
    print("a ^ b  = " + str(dc3))
    print("  ~a   = " + str(dc4))
    print("a >> b = " + str(dc5))
    print("a << b = " + str(dc6))
    print()
    
    # calls to the next function
    binary(num1,num2,dc1,dc2,dc3,dc4,dc5,dc6)

# this function calculates the binary bitwise operations
def binary(num1,num2,dc1,dc2,dc3,dc4,dc5,dc6):
    
    # turns the numbers into binary
    binNum1 = bin(num1)
    binNum2 = bin(num2)

    # turns the binary to integer from string
    # the second value in parameter means binary
    binA = int(binNum1,2)
    binB = int(binNum2,2)

    # calculates the And calculation
    bin1Cal = bin(binA & binB)
    # turns the number into a binary integer
    bin1Cal = int(bin1Cal,2)
    # checks to see if the number is positive
    # you cannot have a negative binary number
    # I used the answer from the decimal to correspond
    if int(dc1) < 0:
        # if it is negatice, do 2's compliment
        # 2 is the binary number and 16 is the bytes
        # you have to subtrat one according to compliment
        bin1R = bin(bin1Cal & (2**16-1))
        # take out the binary indicator
        binAnd = bin1R.replace('0b','')
    else:
        # if not negative, keep it the same
        bin1Cal = bin(bin1Cal)
        # replace the binary indicator
        bin1R = bin1Cal.replace('0b','')
        # pad the answer with zeros
        binAnd = bin1R.zfill(16)

    # calculates the Or calculation
    bin2Cal = bin(binA | binB)
    bin2Cal = int(bin2Cal,2)
    if int(dc2) < 0:
        bin2R = bin(bin2Cal & (2**16-1))    
        binOr = bin2R.replace('0b','')
    else:
        bin2Cal = bin(bin2Cal)
        bin2R = bin2Cal.replace('0b','')
        binOr = bin2R.zfill(16)

    # calculates the exclusive calculation
    bin3Cal = bin(binA ^ binB)
    bin3Cal = int(bin3Cal,2)
    if int(dc3) < 0:
        bin3R = bin(bin3Cal & (2**16-1))    
        binEx = bin3R.replace('0b','')
    else:
        bin3Cal = bin(bin3Cal)
        bin3R = bin3Cal.replace('0b','')
        binEx = bin3R.zfill(16)
        
    # calculates the complimentary calculation
    bin4Cal = ~binA
    if num1 > 0:
        # since it is the oppositive I had to turn the number
        # into a negative so the binary switched, the computer
        # did not do it itself
        bin4Cal = -abs(bin4Cal)
        # then I took 2's compliment
        # 2 is the binary number and 16 is the bytes
        # you have to subtrat one according to compliment
        bin4R = bin(bin4Cal & (2**16-1))
        # replaced the binary indicator
        binCom = bin4R.replace('0b','')
    else:
        # if it is already positive, keep the same
        bin4Cal = bin(bin4Cal)
        # take out the binary indicator
        binCom = bin4Cal.replace('0b','')
        # pad with zeros to make it neater
        binCom = binCom.zfill(16)

    # calculates the right shift calculation
    
    try:
        bin5Cal = bin(binA >> binB)
        bin5Cal = int(bin5Cal,2)            
        if int(dc5) < 0:
            bin5R = bin(bin5Cal & (2**16-1))    
            binRShift = bin5R.replace('0b','')
        else:
            bin5Cal = bin(bin5Cal)
            bin5R = bin5Cal.replace('0b','')
            binRShift = bin5R.zfill(16)
    except ValueError:
        binRShift = ('Illegal Negative Shift')

    # calculates the left shift calculation
    try:
        bin6Cal = bin(binA << binB)
        bin6Cal = int(bin6Cal,2)
        if int(dc6) < 0:
            bin6R = bin(bin6Cal & (2**16-1))    
            binLShift = bin6R.replace('0b','')

        else:
            bin6Cal = bin(bin6Cal)
            bin6R = bin6Cal.replace('0b','')
            binLShift = bin6R.zfill(16)
            binLShift = binLShift.replace('0b','')
    except ValueError:
        binLShift = ('Illegal Negative Shift')


    # prints outputs for binary bitwise operators    
    print("Binary outputs: ")
    print()
    print("a & b  = " + str(binAnd))
    print("a | b  = " + str(binOr))
    print("a ^ b  = " + str(binEx))
    print("  ~a   = " + str(binCom))
    print("a >> b = " + str(binRShift))
    print("a << b = " + str(binLShift))
    print()

    # call to next function
    hexy(num1,num2,dc1,dc2,dc3,dc4,dc5,dc6)
    
# this funciton calulates the hexadecmial bitwise operations    
def hexy(num1,num2,dc1,dc2,dc3,dc4,dc5,dc6):

    # turns the numbers to hexadecimal
    hexNum1 = hex(num1)
    hexNum2 = hex(num2)

    # turns the hexadecimal to integer from string
    # the second value perameter means hexadecimal
    hexA = int(hexNum1,16)
    hexB = int(hexNum2, 16)

    # Calculates the And calculations
    hex1Cal = hex(hexA & hexB)
    # turns number into hexadecimal integer
    hex1Cal = int(hex1Cal,16)
    # checks to see if corresponding decimal is positive
    # you cannot have a negative hexadecimal value
    if int(dc1) < 0:
        # if it is negative, take 2's binary
        # 16 is th enumber of bytes
        hex1R = hex((hex1Cal + (1 << 16)) % (1 << 16))
        # replace the hexadecimal indiciator
        hex1 = hex1R.replace('0x','')
        # pad with zeros to make neater
        hexAnd = hex1.zfill(8)
    else:
        # if it is positive, keep the same
        hex1Cal = str(hex1Cal)
        # take out the hexadecimal indicator
        hex1 = hex1Cal.replace('0x','')
        # pad with zeros to look neater
        hexAnd = hex1.zfill(8)
    
    # Calculates the Or calculations
    hex2Cal = hex(hexA | hexB)
    hex2Cal = int(hex2Cal,16)
    if int(dc2) < 0:
        hex2R = hex((hex2Cal + (1 << 16)) % (1 << 16))
        hex2 = hex2R.replace('0x','')
        hexOr = hex2.zfill(8)
    else:
        hex2Cal = str(hex2Cal)
        hex2 =hex2Cal.replace('0x','')
        hexOr = hex2.zfill(8)

    # Calculates the exculsive calculations    
    hex3Cal = hex(hexA ^ hexB)
    hex3Cal = int(hex3Cal,16)
    if int(dc3) < 0:
        hex3R = hex((hex3Cal + (1 << 16)) % (1 << 16))
        hex3 = hex3R.replace('0x','')
        hexEx = hex3.zfill(8)
    else:
        hex3Cal = str(hex3Cal)
        hex3 = hex3Cal.replace('0x','')
        hexEx = hex3.zfill(8)
    
    # Calculates the compliment calculations
    hex4Cal = ~hexA
    # checks if number is positive
    if num1 > 0:
        # if it is, make it negative
        # the computer makes it all positive
        hex4Cal = -abs(hex4Cal)
        # take 2''s compliment
        hex4R = hex((hex4Cal + (1 << 16)) % (1 << 16))
        # replace the hexadecimal indicator
        hexCom = hex4R.replace('0x','')
        # pad with zeros to look more neat
        hexCom = hexCom.zfill(8)    
    else:
        # if it is negative, leave as is
        hex4R = hex((hex4Cal + (1 << 16)) % (1 << 16))
        # change back to string to manipulate it
        hex4Cal = str(hex4Cal)
        # take out the hexadecimal indicator
        hexCom = hex4Cal.replace('0x','')
        # pad with zeros
        hexCom = hexCom.zfill(8)    

    # Calculates the right shift calculations
    try:
        hex5Cal = hex(hexA >> hexB)
        hex5Cal = int(hex5Cal,16)
        if int(dc5) < 0:
            hex5R = hex((hex5Cal + (1 << 16)) % (1 << 16))
            hex5 = hex5R.replace('0x','')
            hexRShift = hex5.zfill(8)
        else:
            hex5Cal = str(hex5Cal)
            hex5 = hex5Cal.replace('0x','')
            hexRShift = hex5.zfill(8)
    except ValueError:
        hexRShift = ('Illegal Negative Shift')
        
    
    # Calculates the left shift calculations
    try:
        hex6Cal = hex(hexA << hexB)
        hex6Cal = int(hex6Cal,16)
        if int(dc6) < 0:
            hex6R = hex((hex6Cal + (1 << 16)) % (1 << 16))
            hex6 = hex6R.replace('0x','')
            hexLShift = hex6.zfill(8)
        else:
            hex6Cal = str(hex6Cal)
            hex6 = hex6Cal.replace('0x','')
            hexLShift = hex6.zfill(8)
    except ValueError:
            hexLShift = ('Illegal Negative Shift')

    

    # prints out the hexadecimal bitwise operations              
    print("Hexadecimal outputs: ")
    print()
    print("a & b  = " + str(hexAnd))
    print("a | b  = " + str(hexOr))
    print("a ^ b  = " + str(hexEx))
    print("  ~a   = " + str(hexCom))
    print("a >> b = " + str(hexRShift))
    print("a << b = " + str(hexLShift))

# end program
main()
