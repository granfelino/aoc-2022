import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

class aoc2022_5a {
    public static BufferedReader readFile() throws IOException {
        String path = "/home/granfelino/own/aoc2022/aoc2022_5/input.txt";
        BufferedReader br = new BufferedReader(new FileReader(path));
        return br;
    }

    public static ArrayList<ArrayList<Character>> stacksArrayList() {
        Character[] first = {'P', 'F', 'M', 'Q', 'W', 'G', 'R', 'T'};
        Character[] second = {'H', 'F', 'R'};
        Character[] third = {'P', 'Z', 'R', 'V', 'G', 'H', 'S', 'D'};
        Character[] fourth = {'Q', 'H', 'P', 'B', 'F', 'W', 'G'};
        Character[] fifth = {'P', 'S', 'M', 'J', 'H'};
        Character[] sixth = {'M', 'Z', 'T', 'H', 'S', 'R', 'P', 'L'};
        Character[] seventh = {'P', 'T', 'H', 'N', 'M', 'L'};
        Character[] eighth = {'F', 'D', 'Q', 'R'};
        Character[] ninth = {'D', 'S', 'C', 'N', 'L', 'P', 'H'};

        
        return stacks;
    }

    public static int[] parseLine(String line) {
        int[] parameters = new int[3];

        if(line.length() == 18) {
            parameters[0] = Integer.parseInt("" + line.charAt(5));
            parameters[1] = Integer.parseInt("" + line.charAt(12));
            parameters[2] = Integer.parseInt("" + line.charAt(17));
        } else {
            parameters[0] = Integer.parseInt("" + line.charAt(5) + line.charAt(6));
            parameters[1] = Integer.parseInt("" + line.charAt(13));
            parameters[2] = Integer.parseInt("" + line.charAt(17));
        }

        return parameters;
        
    }

    public static String top() throws IOException {
        String topCrates = null;
        BufferedReader br = readFile();
        ArrayList<Character[]> stacks = stacksArrayList();
        String line = br.readLine();

        while(line != null) {
            ArrayList<Integer> tempCrates = new ArrayList<>();
            int[] parameters = parseLine(line);
            int quantity = parameters[0];
            int from = parameters[1] - 1;
            int to = parameters[2] - 1;
            
            for(int i = quantity; i > 0; i--) {
                
            }


            line = br.readLine();
        }


        return topCrates;
    }
}