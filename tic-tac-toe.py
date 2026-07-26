#tic-tac-toe.py
import pygame
import sys
import random
from collections import deque

# Initialize pygame
pygame.init()

# Screen setup
WIDTH, HEIGHT = 600, 600
LINE_WIDTH = 10
BOARD_ROWS, BOARD_COLS = 3, 3
SQUARE_SIZE = WIDTH // BOARD_COLS
CIRCLE_RADIUS = SQUARE_SIZE // 3
CIRCLE_WIDTH = 15
CROSS_WIDTH = 20
SPACE = SQUARE_SIZE // 4

# Colors
BG_COLOR = (28, 170, 156)
LINE_COLOR = (23, 145, 135)
CIRCLE_COLOR = (239, 231, 200)
CROSS_COLOR = (66, 66, 66)

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tic Tac Toe: Human vs Computer")
screen.fill(BG_COLOR)

# Board
board = [[' ' for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]
playerX_moves = deque(maxlen=4)
playerO_moves = deque(maxlen=3)

def draw_lines():
    # Horizontal
    pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (0, 2 * SQUARE_SIZE), (WIDTH, 2 * SQUARE_SIZE), LINE_WIDTH)
    # Vertical
    pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE, 0), (SQUARE_SIZE, HEIGHT), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (2 * SQUARE_SIZE, 0), (2 * SQUARE_SIZE, HEIGHT), LINE_WIDTH)

def draw_figures():
    for row in range(BOARD_ROWS):
        for col in range(BOARD_COLS):
            if board[row][col] == 'O':
                pygame.draw.circle(screen, CIRCLE_COLOR, (int(col * SQUARE_SIZE + SQUARE_SIZE//2),
                                                          int(row * SQUARE_SIZE + SQUARE_SIZE//2)),
                                   CIRCLE_RADIUS, CIRCLE_WIDTH)
            elif board[row][col] == 'X':
                pygame.draw.line(screen, CROSS_COLOR,
                                 (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE),
                                 (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SPACE),
                                 CROSS_WIDTH)
                pygame.draw.line(screen, CROSS_COLOR,
                                 (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SPACE),
                                 (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE),
                                 CROSS_WIDTH)

def check_win(symbol):
    # Rows and cols
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] == symbol: return True
        if board[0][i] == board[1][i] == board[2][i] == symbol: return True
    # Diagonals
    if board[0][0] == board[1][1] == board[2][2] == symbol: return True
    if board[0][2] == board[1][1] == board[2][0] == symbol: return True
    return False

def check_draw():
    for row in board:
        for cell in row:
            if cell == ' ':
                return False
    return True

# def apply_move(moves, r, c, symbol):
#     if len(moves) == 3:
#         oldest_r, oldest_c = moves.popleft()
#         board[oldest_r][oldest_c] = ' '
#     board[r][c] = symbol
#     moves.append((r, c))
def apply_move(moves, r, c, symbol):
    # If deque is full, oldest is auto-removed when appending
    board[r][c] = symbol
    moves.append((r, c))
    # If something was auto-removed, clear that cell
    if len(moves) == moves.maxlen:
        # Rebuild board marks from current deque
        for i in range(3):
            for j in range(3):
                if board[i][j] == symbol:
                    board[i][j] = ' '
        for (mr, mc) in moves:
            board[mr][mc] = symbol

def find_winning_move(symbol):
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = symbol
                if check_win(symbol):
                    board[i][j] = ' '
                    return (i, j)
                board[i][j] = ' '
    return None

def computer_move():
    win = find_winning_move('O')
    if win:
        apply_move(playerO_moves, win[0], win[1], 'O')
        return
    block = find_winning_move('X')
    if block:
        apply_move(playerO_moves, block[0], block[1], 'O')
        return
    if board[1][1] == ' ':
        apply_move(playerO_moves, 1, 1, 'O')
        return
    empty = [(i, j) for i in range(3) for j in range(3) if board[i][j] == ' ']
    if empty:
        r, c = random.choice(empty)
        apply_move(playerO_moves, r, c, 'O')

# Game loop
draw_lines()
current_player = 'X'
game_over = False

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if not game_over and current_player == 'X':
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouseX = event.pos[0] // SQUARE_SIZE
                mouseY = event.pos[1] // SQUARE_SIZE
                if board[mouseY][mouseX] == ' ':
                    apply_move(playerX_moves, mouseY, mouseX, 'X')
                    if check_win('X'):
                        print("You win!")
                        game_over = True
                    elif check_draw():
                        print("Draw!")
                        game_over = True
                    else:
                        current_player = 'O'

        if not game_over and current_player == 'O':
            computer_move()
            if check_win('O'):
                print("Computer wins!")
                game_over = True
            elif check_draw():
                print("Draw!")
                game_over = True
            else:
                current_player = 'X'

    screen.fill(BG_COLOR)
    draw_lines()
    draw_figures()
    pygame.display.update()
