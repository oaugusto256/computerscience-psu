import turtle

def target(radius):
    percent = (radius*10)/100       # Variable percent holds 10% of the radius. It wil be used to decrease the radius for the central targets
    
    for i in range(10):             # Loop 10 times
        turtle.penup()              # Pull the pen up – no drawing when moving.
        turtle.goto(0,-radius)      # Move turtle to an absolute position
        turtle.pendown()            # Pull the pen down – drawing when moving.
        
        # Check which colors will be used to fill the target
        if i <= 1:                
            turtle.color("black","white")
        if i > 1:
            turtle.color("white","black")
        if i > 3:
            turtle.color("black","paleturquoise")
        if i > 5:
            turtle.color("black","red")
        if i > 7:
            turtle.color("black","gold")
            
        turtle.begin_fill()         # Called just before drawing a shape to be filled
        turtle.circle(radius)       # Draw a circle with given radius
        turtle.end_fill()           # Fill the shape drawn
        
        radius -= percent           # Reduces the radius by the percent
