# turtle_example.py - example program for turtle graphics
# (c) 2015, Otavio Augusto Alves Siva, 902840168
#

import turtle

turtle.color('red','yellow')
turtle.begin_fill()
while True:
   turtle.forward(200)
   turtle.left(170)
   if abs(turtle.pos()) < 1:
       break
turtle.end_fill()
turtle.done()
