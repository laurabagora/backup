def caeser_cipher():
    message = input('Your message? ').upper()
    value = int(input('Encoding key? '))
    output = ''

    for index in message:
        if ord(index) >= ord('A') and ord(index) <= ord('Z'):
            encode = ord(index) + value
            while encode > ord('Z'):
                encode -= 26
            while encode < ord('A'):
                encode += 26
            final = chr(encode)
        else:
            final = index
        output += final
    print(output)
caeser_cipher()
