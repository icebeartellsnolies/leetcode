import heapq
from copy import deepcopy
from time import time
from memory_profiler import profile
class PriorityQueue:
    def __init__(self):
        self.q=[]
    
    def enqueue(self, node):
        heapq.heappush(self.q,(node))

    def dequeue(self):   
        if not self.is_empty():     
            return heapq.heappop(self.q)
        
    def is_empty(self):
        return len(self.q)==0

goal_state=dict({1:(0,0),2:(0,1),3:(0,2),4:(1,0),5:(1,1),6:(1,2),7:(2,0),8:(2,1)})
class Node:
    def __init__(self, state,parent=None):
        self.state = state 
        self.parent = parent
        self.h = self.heuristic(self)
        
    def __lt__ (self, other):
        return self.h<=other.h
    
    def heuristic(self, state):
        total_d=0
        for r in range(3):
            for c in range(3):
                
                to_check=state.state[r][c]
                if to_check!=' ':
                    x,y=goal_state[to_check]
                    man_dist=abs(x-r)+abs(y-c)
                    total_d+=man_dist
        return total_d
    
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
    
   
    def solve_puzzle(self):
        if not self.is_solvable(self.start):
            return f'the given state isnt solvable'
        start_time=time()
        pq = PriorityQueue()
        pq.enqueue(self.start)
        explored = set()
        while not pq.is_empty():
            curr=pq.dequeue()
            if curr.h==0:
                self.print_solution(curr)
                end_time=time()
                e_time=end_time-start_time
                print(f"Execution time: {e_time:.4f} seconds")
                return
            flt=tuple(self.flatten(curr))
            if flt in explored:
                continue
            explored.add(flt)
            children=self.generate_children(curr)
            for c in children:
                child_tuple=tuple(self.flatten(c))
                if child_tuple not in explored:
                    pq.enqueue(c)
        
        return
    
    def print_solution(self, node):        
        path=[]
        while node:
            path.append(node)
            node=node.parent
        print('it took',len(path)-2,'steps')
        # for i in range(len(path)-1,-1,-1):
        #     print(path[i])


n = Node([[4, 7, 8], [3, 6, 5], [1, 2, ' ']])
ps=PuzzleSolver(n)
ps.solve_puzzle()

# if solution:
#     for state in solution:
#         print(state)
# else:
#     print(solution)