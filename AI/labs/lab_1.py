from copy import deepcopy
from time import time
from memory_profiler import profile
class Node:
    def __init__(self, state, parent=None):
        self.state=state
        self.parent=parent
    def __str__(self):
        result=''
        for i in range(3):
            for j in range(3):
                result+=str(self.state[i][j])+' '
            result+='\n'
        return result
    def __repr__(self):
        return self.__str__()

class PuzzleSolver:
    def __init__(self, start):
        self.start=start
        self.goal=[1, 2, 3,4, 5, 6,7, 8, ' ']
        # Initialize the puzzle with start and goal state
    
    def flatten(self, state):
        state=state.state
        flattened=[]
        for i in range(3):
            for j in range(3):
                flattened.append(state[i][j])
        return flattened
    
    def is_solvable (self, state):
        flattened=self.flatten(state)
        inversions=0
        for i in range(9):
            for j in range(i+1, 9):
                if flattened[i]!=' ' and flattened[j]!=' ' and flattened[j]<flattened[i]:
                    inversions+=1

        return inversions%2==0
        # Check if the puzzle state is solvable
       

    def find_space(self, state):
        state=state.state
        for i in range(3):
            for j in range(3):
                if state[i][j]==' ':
                    return i,j
        # Implement the method to find the position (x, y) of the empty space (' ')
        

    def find_moves(self, pos):
        # Implement the method to generate valid moves for the empty space
        x, y = pos
        return [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]

    def is_valid(self, move):
        # Implement the method to check if a move is within bounds of the puzzle
        x,y=move
        if x<0 or y<0:
            return False
        if x>2 or y>2:
            return False
        return True
        

    def play_move(self, state, move, space):
        # Implement the method to generate a new state after making the move
        m1,m2=move
        s1,s2=space
        new_state=deepcopy(state.state)
        new_state[m1][m2], new_state[s1][s2]=new_state[s1][s2], new_state[m1][m2]
        return new_state

    def generate_children(self, state):
        # Implement the method to generate all valid children from a state
        children = []
        space = self.find_space(state) #returns tuple
        moves = self.find_moves(space)  #returns list of tuples

        for move in moves:
            if self.is_valid(move):
                child =  self.play_move(state,move,space) 
                child=Node(child, state)
                children.append(child)
        return children

    
    def solve_puzzle(self, by):
        # Implement the search strategy for simple backtracking
       
        if by.strip().lower()=='dfs':
            start_time=time()
            to_backtrack=self.solve_puzzle_dfs()
            end_time=time()
            e_time=end_time-start_time
            print(f"Execution time: {e_time:.4f} seconds")
            parents=[]
            while to_backtrack!=None:
                parents.append(to_backtrack.parent)
                to_backtrack=to_backtrack.parent
            
            

        elif by.strip().lower()=='bfs':
            start_time=time()
            to_backtrack=self.solve_puzzle_bfs()
            end_time=time()
            e_time=end_time-start_time
            print(f"Execution time: {e_time:.4f} seconds")
            parents=[]
            while to_backtrack!=None:
                parents.append(to_backtrack.parent)
                to_backtrack=to_backtrack.parent
            
        
        else:
            start_time=time()
            to_backtrack, depth=self.solve_puzzle_dfid()
            end_time=time()
            e_time=end_time-start_time
            print(f"Execution time: {e_time:.4f} seconds")
            parents=[]
            while to_backtrack!=None:
                parents.append(to_backtrack.parent)
                to_backtrack=to_backtrack.parent
            print('solution found at depth',depth)
        self.disp_solution(parents)
        return

    def dfs(self, open_list, closed_list):
        while open_list:
            
            curr_state = open_list.pop()
            flattened_state=tuple(self.flatten(curr_state))
            if flattened_state == tuple(self.goal):
                return curr_state
            if flattened_state in closed_list:
                continue
            closed_list.add(flattened_state)
            children = self.generate_children(curr_state)
            open_list.extend(children)
        return None

    def solve_puzzle_dfs(self):
        # Implement the search strategy for simple depth-first-search
        if not self.is_solvable(self.start):
            print("state cant reach the goal")
            return
        state=self.start
        open_list = [state]
        # closed_list=visited
        closed_list = set()
        final_state= self.dfs(open_list, closed_list)
        return final_state
        

    def solve_puzzle_bfs(self):
        # Implement the search strategy for breadth-first-search
        if not self.is_solvable(self.start):
            print("current state cant reach the goal")
            return
        open_list = [self.start]
        closed_list = set()
        children=[]
        while open_list:
            curr_node=open_list.pop(0)
            flattened=tuple(self.flatten(curr_node))
            if flattened==tuple(self.goal):
                return curr_node
            if flattened in closed_list:
                continue
            closed_list.add(flattened)
            children=self.generate_children(curr_node)
            open_list.extend(children)
        return

    def dls (self, node, depth, closed):
        flattened=tuple(self.flatten(node))
        if tuple(self.goal)==flattened:
            return node
        closed.add(flattened)
        if depth<=0:
            return None
        children=self.generate_children(node)
        for c in children:
            c_t=tuple(self.flatten(c))
            if c_t not in closed:
                res = self.dls(c,depth-1, closed)
                if res is not None:
                    return res
        return None
                    

    def solve_puzzle_dfid(self):
        # Implement the search strategy for depth-first-search with iterative deepening
        if not self.is_solvable(self.start):
            return f'the given state isnt solvable'
        for i in range(40):
            closed=set()
            ans=self.dls(self.start,i, closed)
            if type(ans)==Node:
                return ans,i
        return None,-1
        

    def disp_solution(self, nodes):
        opposite = [n for n in nodes if n is not None]
        print(len(opposite))
        # for i in range(len(opposite)-1,-1,-1):
        #     print(opposite[i])

#Run this Test-Case

def main ():
    start = Node([[4, 7, 8], [3, 6, 5], [1, 2, ' ']])
    print(start)
    solver = PuzzleSolver(start=start)
    # solver.solve_puzzle_backtracking()
    # solver.solve_puzzle_dfs()
    # solver.solve_puzzle_bfs()
    # solver.solve_puzzle_dfid()
    solver.solve_puzzle('dfid')
main()