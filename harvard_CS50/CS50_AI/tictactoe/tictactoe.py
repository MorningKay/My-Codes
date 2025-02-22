"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    X_num = 0  # X get the first move
    O_num = 0

    # When X num greater than O, so it's the O turn. Otherwise it's the X turn.
    for row in board:
        for col in row:
            if col == X:
                X_num += 1
            elif col == O:
                O_num += 1
    if X_num + O_num == 9:
        return None
    elif X_num > O_num:
        return O
    elif X_num == O_num:
        return X


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions = []
    for row in range(3):
        for col in range(3):
            if board[row][col] == EMPTY:
                actions.append((row, col))
    actions = set(actions)
    return actions


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    i = action[0]
    j = action[1]
    if i < 0 or i >= 3 or j < 0 or j >= 3:
        raise ValueError("Invalid move: position out of bounds.")
    result_board = copy.deepcopy(board)
    if board[i][j] == EMPTY:
        result_board[i][j] = player(board)
        return result_board
    else:
        raise ValueError("Invalid move: position already occupied.")


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    # Check the rows
    for row in board:
        if all(cell == X for cell in row):
            return X
        if all(cell == O for cell in row):
            return O

    # Check the columns
    for i in range(3):
        if all(board[j][i] == 'X' for j in range(3)):
            return X
        if all(board[j][i] == 'O' for j in range(3)):
            return O

    # Check the diagonals
    if all(board[i][i] == X for i in range(3)):
        return X
    if all(board[i][2 - i] == X for i in range(3)):
        return X
    if all(board[i][i] == O for i in range(3)):
        return O
    if all(board[i][2 - i] == O for i in range(3)):
        return O
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    # Board isn't full but there is a winner
    if winner(board) != None:
        return True
    # Board is full
    if actions(board) == set():
        return True
    return False


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    if terminal(board):
        return None

    if player(board) == X:
        value, move = max_value(board)
        return move
    else:
        value, move = min_value(board)
        return move


def max_value(board):
    """
    Function to return the maximum value and the move that leads to it
    for the maximizing player (X).
    """
    if terminal(board):
        return utility(board), None

    v = -math.inf
    move = None
    for action in actions(board):
        value, _ = min_value(result(board, action))
        if value > v:
            v = value
            move = action
    return v, move


def min_value(board):
    """
    Function to return the minimum value and the move that leads to it
    for the minimizing player (O).
    """
    if terminal(board):
        return utility(board), None

    v = math.inf
    move = None
    for action in actions(board):
        value, _ = max_value(result(board, action))
        if value < v:
            v = value
            move = action
    return v, move
