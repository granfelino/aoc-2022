class aoc2022_5b:
    def __init__ (self):
        self.file = open("/home/granfelino/own/aoc2022/aoc2022_5/input.txt", "r")
        self.lines = [line for line in self.file]
        self.stacks_raw = reversed(self.lines[:8])
        self.moves = self.lines[10:]

    def get_stacks(self):
        stacks = {
            0 : [],
            1 : [],
            2 : [],
            3 : [],
            4 : [],
            5 : [],
            6 : [],
            7 : [],
            8 : []
        }

        for line in self.stacks_raw:
            for i in range(9):
                if line[1 + (i * 4)] != ' ':
                    stacks[i].append(line[1 + (i * 4)])

        return stacks


    def parse_line(self, line):
        move = []
        if len(line) == 19:
            move.extend([int(line[5]), int(line[12]), int(line[17])])
        else:
            move.extend([int(line[5] + line[6]), int(line[13]), int(line[18])])
        return move

    def test_parse(self):
        for line in self.moves:
            print(self.parse_line(line))
    
    def get_top_crates(self):
        stacks = self.get_stacks()
        
        for line in self.moves:
            moves = self.parse_line(line)
            qnt = moves[0]
            fr = moves[1] - 1
            to = moves[2] - 1
            
            #adding
            moving = [stacks[fr][-i] for i in range(1, (1 + qnt))]
            stacks[to].extend(moving)
            #deleting
            for i in reversed(range(1, (1 + qnt))):
                del stacks[fr][-i]

        print("hellp")
        
        top_crates = ""
        for i in stacks.keys():
            top_crates += stacks[i][-1]

        return top_crates



##########################################
a = aoc2022_5b()
print(a.get_top_crates())