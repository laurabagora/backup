from turtle import *
import random, os

os.system('mode con: cols=25 lines=8')

bsize = 80
girth = 50
length = 600
xoffset = 0 - (length/2)

hideturtle()
setup(800,600)
title('Dick Window')
speed(15)

bgcolor('black')
color('black')
setx(xoffset)

color('#756046') 

#balls
begin_fill()
circle(bsize)
circle(0 - bsize)
end_fill()

#shaft 1
begin_fill()
sety(0 - girth)
forward(length)
end_fill()

#head
color('pink')
begin_fill()
circle(girth,180)
end_fill()

#shaft 2
color('#756046')
begin_fill()
forward(length)
sety(0)

#shaft fill
setpos(length + xoffset, 0 - girth)
setpos(length + xoffset, girth)
setpos(xoffset,0)
end_fill()

done()
