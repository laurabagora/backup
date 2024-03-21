# imports
#constants

# main function that gets input
def main():
    # get input
    value = input('Original data:   ')
    print()

# go to said funtions
    decimal(value)
    

# this function turns the base64 into base10 into binary
def decimal(value):
    print("In base 10:      ", end = '')
    # base64 encoding string
    base64 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
    #base64 encoding list
    base64s = list(base64)
    
    # count the number of values there are
    count = 0
    lists = []
    for index in range(len(value)):
        count += 1
        
    # iterates through value and finds the index
    for val in value:
        if val in base64s:
            vals = base64s.index(val)
        # if not a base64 value print N/A
        else:
            vals = 'N/A'
        print(vals, end = ' ')

    # Now work on the groups of 6
    print()
    print()
    print('Groups of 6:     ', end = '')

    # iderate through and find the base 64 value again
    list1 = []
    for val in value:
       # for index in base64s:
        if val in base64s:
            vals = base64s.index(val)
            # turn the decimal into an binary number
            bins = bin(vals)
            bins = bins.replace('0b', '')
            bins = str(bins)
            # makes sure the string is a length of 6
            # if not then add zeros to make it 6 
            if len(bins) <= 6:
                bins = str(bins)
                bins = str(bins).zfill(6)
        # if it is n/a then turn to x's
        else:
            vals = 'N/A'
            bins = 'xxxxxx'
        list1.append(bins)
        
    # making sure the input is an even number of characters
    # if not then append another line of x's
    # this makes for a better output
    counter = 0
    list2 =[]
    # iterate through loop
    for index in list1:
        counter += 1
        list2.append(index)
        if (count % 2):
            if count == counter:
                list2.append('xxxxxx')
                
    #print statement
    counted = 0
    # splitting the 6's into 2 sections
    for index in list2:
        counted += 1
    count = counted / 2
    counts = 0
    # printing the output
    for index in list2:
        if counts == count:
            print() 
            print('                 ', end = '')
            print(index, end = ' ')
            counts += 1
        else:
            print(index, end = ' ')
            counts += 1
    # call to function that turns to 8 bits  
    binary8(list2)

# turns the 6 bits into 8 bits
def binary8(list2):
    print()
    print()
    print('Group of 8:      ', end = '')
    
    list3 = []
    # bring the list all together
    string1 = ''.join(list2)
    for index in string1:
        # check if there is an x, remove it
        if index == 'x':
            string1 = string1.replace('x','')
            
    # split it into 8's
    list4 = []
    for index in range(0, len(string1), 8):
        list3.append(string1[index : index + 8])
        
    # make sure it is 8 bits long
    for index in list3:
        if len(index) < 8:
            index = index.zfill(8)
        else:
            index = index
        list4.append(index)
        
    # print this statement
    for index in list4:
        print(index, end = ' ')
    print()
    print()

    # call to ascii function
    asciis(list4)

# function that turns these numbers into ascii    
def asciis(list4):
    print('ASCII codes:     ', end = '')
    # turns into ascii then to hex
    for index in list4:
        bine = chr(int(index,2))
        hexy = hex(ord(bine))
        
        # print output
        hexy = hexy.replace('0x','')
        print(bine + ' = $' + hexy, end = ' ')
        
    print()
    print()
    print('Decoded:         ', end = '')
    for index in list4:
        bine = chr(int(index,2))

        print(bine, end = '')
            
main()

