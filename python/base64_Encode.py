# imports
     # none
#constants

# main function that gets input
def main():
    # get input
    value = input('Original data:   ')
    print()

    # go to said functions
    print("ASCII codes:     ", end = "")
    asciis(value)
    print()
    print("In Binary:       ", end = "")
    binarys(value)
    print()
    print("Groups of 8:     ", end = "")
    binarys(value)
    print()
    print("Groups of 6:     ", end = "")
    binarys(value)
    group6(value)


# this function makes the letters into the ascii code
def asciis(value):
    for index in value:
        # creates the ascii codes
        new = hex(ord(index))
        # take out the extra 0x
        new = new.replace('0x','')
        # print this statement
        print(index + " = $" + new, end = "  ")
    print()

# this function converts to the binary code
def binarys(value):
    for index in value:
        # creates binary values
        new = bin(ord(index))
        # take out the extra 0b
        new = new.replace('b','')
        # make sure it is 8 bits
        if len(new) < 8:
            new = new.zfill(8)
        #print this statement
        print(new, end = " ")
    print()
    
def group6(value):
    list1 = []
    list2 = []
    for index in value:
        # creates binary values
        binNum = bin(ord(index))
        # take out the extra 0b
        binNum = binNum.replace('b','')
        # make sure it is 8 bits
        if len(binNum) < 8:
            binNum = binNum.zfill(8)
        # put all of the binary numbers together
        list1.append(binNum)
        # counts how many list places there are
        # you need double this for the output
        count = 0
        for index in range(len(list1)):
            count += 1

    # to see how many bytes are left over
    leftover = 8 * count
    leftover = leftover % 6
    leftover = 6 - leftover
    leftover = leftover * 'x'
    list1.append(leftover)

    # find the leftover bytes to become '='
    added = count % 3
    total = 3 - added
    total = total * 'x' * 6
    list1.append(total)
    
    # turns the list to a string
    string1 = ''.join(list1)
    # seperates the list into groups of 6    
    for index in range(0, len(string1), 6):
        list2.append(string1[index : index + 6])        
    
    # print statement
    print()
    print('                 ', end = '')
    counts = 0
    for index in list2:
        if counts == count:
            print()
            print('                 ', end = '')
            print(index, end = ' ')
            counts += 1
        else:
            print(index, end = ' ')
            counts += 1
    print()
    print()
    
    # call to decimal function
    decimals(list2, count)

# this function converts the binary numbers to decimal numbers
def decimals(list2, count):
    counts = 0
    print("In base 10:      ", end ="")
    # iterate through list to get decimal numbers
    for index in list2:
        # check if x is in the number
        if '0' in index:
            # if it is then replace it with zero
            new = index.replace('x', '0')
            # turn to integer
            new = int(new,2)
            new = bin(new)
            new = int(new, 2)
        elif '1' in index:
            new = index.replace('x', '0')
            new = int(new,2)
            new = bin(new)
            new = int(new, 2)
        # if it is all x's then just print N/A
        else:
            new = 'N/A'
        
        # print statements
        print(new, end = ' ')
    print()
    print()
    # call to base64
    base64(list2)

# this function creates the base64 outputs
def base64(list2):
    # base64 encoding string
    base64 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
    #base64 encoding list
    base64s = list(base64)
    print("Base64 Output:   ", end ="")
    
    # iterate through list to get decimal numbers
    for index in list2:
        # check if x is in the number
        if '0' in index:
            new = index.replace('x', '0')
            new = int(new,2)
            new = bin(new)
            new = int(new, 2)
        elif '1' in index:
            new = index.replace('x', '0')
            new = int(new,2)
            new = bin(new)
            new = int(new, 2)
        else:
            new = 'N/A'

        # checks if new is a real number
        if new == 'N/A':
             #if it isn't, print '='
            print('=', end = '')
        # if not, iterate through list to the correct spot
        else:
            print(base64s[new], end = '')
                  

main()

