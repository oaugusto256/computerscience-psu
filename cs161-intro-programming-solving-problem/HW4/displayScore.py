import turtle

def displayScore(score, radius):

    turtle.color("black","white")       
    turtle.setheading(0)                # Set the orientation of the turtle to zero

    turtle.penup()                      # Pull the pen up – no drawing when moving.
    turtle.goto(radius,radius+10)       # Move turtle
    turtle.pendown()                    # Pull the pen down – drawing when moving.
    
    # Create a rectangle
    turtle.begin_fill()
    for i in range(4):
        if i%2 == 0:
            turtle.forward(100)
            turtle.left(90)
        else:
            turtle.forward(60)
            turtle.left(90)
    turtle.end_fill()

    
    turtle.penup()                      # Pull the pen up – no drawing when moving.
    turtle.goto(radius+5,radius+30)     # Move turtle
    turtle.pendown()                    # Pull the pen down – drawing when moving.
    turtle.write("SCORE: " + str(score), font=("Times", int(radius/10)))    # Write the score in the GUI
