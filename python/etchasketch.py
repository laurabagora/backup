# Imports
from turtle import *

# Constants
width = 200
height = 200

# Main function
def main():
    # Calls functions
    set_world()
    sketch()

# Sets up turtle
def set_world():
    setworldcoordinates(0,height,width,0)
    clear()
    shape('turtle')
    pencolor('black')
    fillcolor('black')
    bgcolor('white')
    
    # Puts turtle in center 
    up()
    ht()
    goto(height/2, width/2)
    st()
    speed(6)

# Starts the drawing functions
def sketch():
    listen()
    # When these buttons are pressed than the functions will start
    # a key moves turtle left
    onkeypress(left, 'a')
    
    # d key moves turtle right
    onkeypress(right, 'd')
    
    # w key moves turtle up
    onkeypress(ups, 'w')

    # s key moves turtle down
    onkeypress(downs, 's')

    # q key exits turtle
    onkeypress(quits, 'q')

    # p key puts pen up and down
    onkeypress(pen, 'p')

# Transports portal to other edge when hits barrier
def move_z_dir(direction, xy_cor, xy_set, side, new_side):
    setheading(direction)
    while heading() == direction:
        forward(1)
        if xy_cor() == side:
            speed(0)
            ht()
            result = isdown()
            up()
            xy_set(new_side)
            
            # Putting pen up and down
            if result == True:
                down()
            else:
                up()
            st()
            speed(6)
            
# Sets direction of turtle upward
def ups():
    move_z_dir(270, ycor, sety, 0, height)
    
# Sets direction of turtle downward
def downs():
    move_z_dir(90, ycor, sety, height, 0)
    
# Sets direction of turtle right
def right():
    move_z_dir(0, xcor, setx, width, 0)

# Sets direction of turtle left
def left():
    move_z_dir(180, xcor, setx, 0, width)

# Quits turtle completely in a graceful manor
def quits():
    exit()
    
# Moves pen up and down
def pen():
    result = isdown()
    if result == True:
        up()
    else:
        down()

# Call back to main function
main()
    
