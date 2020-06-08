from enum import Enum

class Direction(Enum):

    LEFT : 1
    UP : 2
    RIGHT : 3
    DOWN : 4


class Dot():

    '''
        - x and y represents location
        - super represents whether Dot is super or regular. (True/False)
    '''
    def __init__(self):
        self.x = None
        self.y = None
        self.super = None
        self.eaten = True

    # getter and setter for x,y amd super

class Ghost():

    def __init__(self):
        self.name = None
        self.color = None
        self.x = None
        self.y = None
        self.dangerous = 0
        self.direction = None

    def set_position(self, x, y):
        pass
    
    # dangerous is timer for how long ghost can be eaten
    def set_dangerous(self, dangerous):
        pass

    def decrement_dangerous_counter(self):
        pass

class Maze():

    def __init__(self):
        self.maze = None
    
    '''
        initialize 2D maze with objects of Dot class.
    '''
    def initialize_maze(self):
        pass
    
    # return number of dots in maze. To check whether game ended or not
    def count_dots(self):
        pass

class Pacman():

    def __init__(self):
        self.x = None
        self.y = None
        self.alive = True

    # setter/getter methods for x,y location and alive status.


class Game():

    def __init__(self):
        self.maze = None
        self.pacman = None
        self.ghosts = []
        self.life = 3
        self.score = 0

    def add_ghost(self, ghost):
        self.ghosts.append(ghost)

    def start(self):
        ghost1 = Ghost()
        # set name color and initial position for ghost
        self.add_ghots(ghost1)
        
        self.maze = Maze()
        self.maze.initialize_maze()

        self.Pacman = Pacman()
        # set initial position for Pacman.

    '''
        check for Dot
            - update ghosts if super dot
                - if pacman eats super dot. Set d
            - update score 
        update dead or alive status of pacman based on interaction with ghost
    '''
    def update_game_status(self):
        pass

    # update x and y of pacman based on direction and maze.
    def move_pacman(self, direction):
        pass

    # add logic to move all ghosts depending upon status of maze
    # this includes logic for ghost can be eaten or not
    def move_ghosts(self):
        pass

    def run(self):
        while self.life > 0 or self.maze.count_dots() > 0:
            self.move_ghosts()
            self.move_pacman(direction)
            self.update_game_status()
