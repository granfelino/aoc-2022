class aoc2022_6b:
    def __init__(self):
        path = "/home/granfelino/own/aoc2022/aoc2022_6/input.txt"
        file = open(path, "r")
        self.stream = file.read()
    
    def check_marker(self, line):
        return len(set(line)) == len(line)
    
    def parse_input(self):
        for i in range(len(self.stream) - 14):
            four = self.stream[i : (i + 14)]
            if self.check_marker(four):
                print(self.stream[i : (i + 14)])
                return i + 14


###################
a = aoc2022_6b()
print(a.parse_input())