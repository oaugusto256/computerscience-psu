import random
import turtle

def shoot(radius):

    distance = random.randrange(0, radius+50)   # Generate a random number between 0 and radius+50 that will represent the arrow distance. 50 will be the margin of error
    angle = random.randrange(0,360)             # Generate the angle which the arrow will be shoot
    
    turtle.penup()                      # Pull the pen up – no drawing when moving.
    turtle.goto((0,0))                  # Move turtle to the center (0,0)
    turtle.setheading(angle)            # Set the orientation of the turtle to the angle
    turtle.forward(distance)            # Move the turtle forward by the specified distance, in the direction the turtle is headed (angle).
    turtle.dot(10, "SteelBlue")         # Draw a circular dot that will symbolize the arrow

    return distance
