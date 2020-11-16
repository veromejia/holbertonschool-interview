#!/usr/bin/python3
"""N queens puzzle"""


class chessboard:
    """NXN chessboard"""

    def __init__(self, nqs):
        self.nqs = nqs
        self.solutions = None
        self.tracker = [-1] * nqs

    def isValid(self, col):
        """Check if a queen can be placed in a column"""
        for i in range(col):
            if abs(self.tracker[i] - self.tracker[col]) in {0, col - i}:
                return False
        return True

    def nQueens(self, index, cols):
        """Solve N-Queens problem"""
        if index == self.nqs:
            self.solutions.append(cols)
            return
        for i in range(self.nqs):
            self.tracker[index] = i
            if self.isValid(index):
                self.nQueens(index + 1, cols + [i])

    def solve(self):
        """Recursive call to nQueens"""
        if self.solutions is None:
            self.solutions = []
            self.nQueens(0, [])
        return [list(enumerate(sol)) for sol in self.solutions]


if __name__ == '__main__':
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solver = chessboard(n)
    solutions = solver.solve()
    for res in solutions:
        out = [list(el) for el in res]
        print(out)
