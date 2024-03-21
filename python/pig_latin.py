def pig_latin(name):
    
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    
    with open(name) as file:
        names = file.readlines()      
    
    
    for other in names:
        named = other.split()
        new = ''
        for index in named:

            words = index[0]
            words = str(words)
            length = len(index)  

            if words in vowels:
                newword = (index + 'yay')
                new = new + newword + ' '
            else:
                remove = index[1:length]
                newword = remove + words + 'ay'            
                new = new + newword + ' '
        print(new) 
