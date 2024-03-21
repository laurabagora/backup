def number_square(small, large):
    
    # for each row start from smallest to largest
    for row in range(small, large + 1):
        
        # use row to display row
        # for each value started at row to largest
        for value in range(row, large + 1):
            print(value, end = '')
            
        # for each value from smallest to row
        for value in range(small, row):
            print(value, end = '')
            
        # print line
        print()



