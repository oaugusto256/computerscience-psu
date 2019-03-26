# Created by Alves Silva, Otavio Augusto
# Email address: alves2@pdx.edu
# Date: 02/14/2015
# Archer target simulation - A program to simulate an arrow shot in an archery target

from target import *            # Draw an archery target
from shoot import *             # Calculate a randow distance and does a dot to symbolize an arrow
from score import *             # Calculate the amount of points by the distance  
from displayScore import *      # Draw a square and show the amount of points 
import turtle                   # Python turtle module to draw the GUI


def singleShot():
        
    turtle.hideturtle()         # Hide the turtle
    turtle.speed(0)             # Turtle will draw in an fastest velocity

    radius = 200                # Radius  will be used to draw the largest circle in the target
                                # and will be used as reference for the smaller circle
    
    target(radius)                      # Draw an archery target with the radius that was passed
    distance = shoot(radius)            # Calculate the distance between the center of the target and the shoot
    points = score(distance, radius)    # Calculate the amount of points using the distance and the radius of the target
    displayScore(points, radius)        # Display the points

singleShot()                    # Execute the program




