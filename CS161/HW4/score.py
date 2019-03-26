import math

def score(distance, radius):
    """
    Radius = 200
    Examples:
         score(0,200)     - Return 10
         score(4,200)     - Return 10
         score(19,200)    - Return 10
         score(20,200)    - Return 9
         score(45,200)    - Return 8
         score(49,200)    - Return 8
         score(50,200)    - Return 7
         score(199,200)   - Return 1
         score(200,200)   - Return 0
         score(25x10,200) - Return 0
    """

    point = math.floor(10*(distance/radius)) # Calculate the target color which the arrow was shoot.
    score = 10 - point                       # Calculate the score using the point

    if score <= 0:      # If the score is less or equal than 0. The arrow was fired off target
        score = 0
        
    return score        # Return the score

