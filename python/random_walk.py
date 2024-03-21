def random_walk(threshold):
    pos = 0
    maxpos = 0
    steps = 0

    while pos != threshold:
        print('Position = ' str(pos))
        steps = steps + 1
        random = random.randint(1,2)

        if random = = 1:
            move = -1

        else:
            move = 1

        pos = pos + move

        if pos > maxpos:
            maxpos = pos
