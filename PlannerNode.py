from asyncio.windows_events import NULL
import sys

from MapNode import MapNode

class PlannerNode:
    
    stack = []
    def __init__(self):
        self.current_obj=MapNode()
        
        # Since we know that the first step the bot will take will be down, we can simply do it here
        self.current_obj.direction_callback("down")  # example 1
        notDir = 'up'
        self.stack = []
        self.directions = ['up', 'down', 'left', 'right']

        self.wall_callback(notDir)
        
    

    def wall_callback(self, notDir):
        
        
        print(self.current_obj.current)
        # current_obj has all the attributes to help you in in your path planning !
         
        current_coords = self.current_obj.current 
           
        self.stack.append(current_coords)

        if (notDir != self.directions[0] and not self.current_obj.map.check_top_wall(current_coords) and ((current_coords[0] - 1, current_coords[1]) not in self.stack)):
            self.current_obj.direction_callback(self.directions[0])
            wall_callback(self.directions[1])
            

        if (notDir != self.directions[1] and not self.current_obj.map.check_bottom_wall(current_coords) and ((current_coords[0] + 1, current_coords[1]) not in self.stack)):
            self.current_obj.direction_callback(self.directions[1])
            wall_callback(self.directions[0])

        if (notDir != self.directions[2] and not self.current_obj.map.check_left_wall(current_coords) and ((current_coords[0], current_coords[1] - 1) not in self.stack)):
            self.current_obj.direction_callback(self.directions[2])
            wall_callback(self.directions[3])

        if (notDir != self.directions[3] and not self.current_obj.map.check_right_wall(current_coords) and ((current_coords[0], current_coords[1] + 1) not in self.stack)):
            self.current_obj.direction_callback(self.directions[3])
            wall_callback(self.directions[2])

        stack.pop()
        self.current_obj.direction_callback(notDir)
        
        

if __name__ == '__main__':
    start_obj=PlannerNode()
    start_obj.current_obj.print_root.mainloop()

