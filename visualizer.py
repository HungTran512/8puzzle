# Example usage:
# ./Solver_test ./data/puzzle30.txt > results.txt
# python3 visualizer.py

from tkinter import *
from random import choice
import time

class Puzzle_Visual:
    def __init__(self, puzzle_one):
        self.root = Tk()
        self.root.resizable(False, False)
        self.root.title('A* Slider Puzzles')

        self.puzzle = puzzle_one

        self.size = len(puzzle_one)

        self.block_width = 700//self.size
        self.block_height = 700//self.size

        self.board = Canvas(self.root, width = 700, height = 700,
                            relief = 'solid')

        self.draw_board()
        self.board.grid(row = 0, column = 0, columnspan = 2)

    def update_block(self, row, column):
        block = self.blocks[row][column]
        x_one, x_two, y_one, y_two = block

        #color = choice(('red', 'orange', 'green', 'blue', 'purple'))
        color = 'blue'

        self.board.create_rectangle(x_one, y_one, x_two, y_two, fill = color, outline = 'white')

        if self.puzzle[row][column] != '0':
            self.board.create_text(x_one + .5*self.block_height, y_one + .5*self.block_width,
                                fill = 'white', font = ('courier', 35), text = self.puzzle[row][column])

    def start(self):
        self.board.mainloop()

    def draw_board(self):
        self.blocks = list()
        #print(self.puzzle)
        for i in range(self.size):
            y_one = i*self.block_height
            y_two = y_one + self.block_height

            row = list()
            for j in range(self.size):
                x_one = j*self.block_width
                x_two = self.block_width + x_one

                row.append((x_one, x_two, y_one, y_two))
                self.board.create_rectangle(x_one, y_one, x_two, y_two, fill = 'blue', outline = 'white')
                #print(str(i) + ', ' + str(j))
                if self.puzzle[i][j] != '0':
                    self.board.create_text(x_one + .5*self.block_height, y_one + .5*self.block_width,
                                        fill = 'white', font = ('Courier', 35), text = self.puzzle[i][j])

            self.blocks.append(row)

    def update(self):
        self.board.update()

    def update_puzzle(self, new_puzzle):
        for i in range(len(new_puzzle)):
            for j in range(len(new_puzzle)):
                if new_puzzle[i][j] != self.puzzle[i][j]:

                    self.puzzle[i][j] = new_puzzle[i][j]
                    self.update_block(i, j)




if __name__ == '__main__':
    from sys import argv

    if len(argv) > 1:
        flag = argv[1]
    else:
        flag = ''

    with open('results.txt') as results:
        results = (line.strip().split() for line in results.readlines()[1:])

    boards = list()
    board = list()

    for line in results:
        if line:
            board.append(line)
        else:
            boards.append(board)
            board = list()

    for counter, board in enumerate(boards):
        if counter == 0:
            game = Puzzle_Visual(board[1:])
        else:

            if flag == '-c':
                while True:
                    if input() == '':
                        break

            elif flag == '-nd':
                pass

            else:
                time.sleep(.5)

            game.update_puzzle(board[1:])
            game.update()


    game.start()
