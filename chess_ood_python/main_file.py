from abc import abstractmethod, ABCMeta
from enum import Enum

class spot():

    def __init__(self, x, y, piece):
        self.x = x
        self.y = y
        self.piece = piece # object of piece type

    # getter and setter for x,y and piece
    def get_piece(self):
        pass


class piece(metaclass=ABCMeta):

    def __init__(self, is_white):
        self.is_white = is_white
        self.is_killed = False

    # getter and setter for is_white and is_killed

    @abstractmethod
    def can_move(self, board, start, end):
        # arguments : board, starting spot, ending spot
        pass

class king(piece):

    def __init__(self, is_white):
        super(king, self).__init__(is_white)

    def can_move(self, board, start, end):
        # arguments : board, starting spot, ending spot
        # logic for king move. returns True or False depeding on valid start to end.
        pass

# All pieces like King, knight, rook etc extends piece class.

class board():

    def __init__(self):
        # list of list containing object of spot
        self.boxes = None

    # initialize board with default pieces
    def reset_board(self):
        for i in range(8):
            row = []
            for j in range(8):
                row.append(spot(i, j, None))
            self.boxes.append(row)
        # add default pieces here.
        pass

    def get_spot(self, x, y):
        if x < 0 or y < 0 or x > 7 or y > 7:
            # throw excpetion for invalid position
            return None
        return self.boxes[x][y]


class player():

    def __init__(self):
        self.white_side = None
        self.human_player = None
    
    def is_white_side(self):
        return self.white_side

    def is_human_player(self):
        return self.is_human_player

class human_player(player):

    def __init__(self, white_side):
        self.white_side = white_side
        self.human_player = True
    
class computer_player(player):
    
    def __init__(self, white_side):
        self.white_side = white_side
        self.human_player = False

    
class move():

    # arguments player, start spot, end spot
    def __init__(self, player, start, end):
        self.player = player
        self.start = start
        self.end = end
        self.piece_moved = start.get_piece()

class game_status(Enum):
    ACTIVE = 0
    BLACK_WIN = 1
    WHITE_WIN = 2
    FORFEIT = 3
    STALEMATE = 4
    RESIGNATION = 5


class game():

    def __init__(self, player1, player2):
        self.players = [player1, player2]
        self.board = board()
        self.board.reset_board()
        self.game_status = game_status.ACTIVE
        self.moves_played = []
        self.current_turn = players[0] if players[0].is_white_side() else players[1]

    def is_end(self):
        return self.game_status != game_status.ACTIVE
    
    def player_move(self, player, x_start, y_start, x_end, y_end):

        start = self.board.get_spot(x_start, y_start)
        end = self.board.get_spot(x_end, y_end)
        p_move = move(player, start, end)
        self.make_move(player, move)

    def make_move(self, player, move):
        '''
        Handle all edge cases like 
            - current piece color align with player's color
            - player's color align with current turn.
            - valid piece
            - valid move for piece using can_move method of piece class.
            - if valid move. move the piece and add it to moves_played
            - toggle player turn
        '''
        pass


if __name__ == "__main__":

    player1 = human_player(True)
    player2 = computer_player(False)
    game = (player1, player2)

    while not game.is_end():
        # take input from player where to move.
        game.player_move(player1, 1, 1, 2, 2) #player1 or player2 according to turn