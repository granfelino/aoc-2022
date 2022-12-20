import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class aoc2022_3b {

    public static int prioritySum(BufferedReader br) throws IOException {
        String line = br.readLine();
        int totalPrio = 0;
        String alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOQPRSTUVWXYZ";
        
        while(line != null) {
            String[] lines = new String[3];
            int count = 0;

            while(count < 3) {
                lines[count] = line;
                count++;
                line = br.readLine();
            }

            char badge = '?';
            for(char character : lines[0].toCharArray()) {
                if(lines[1].contains("" + character)
                && lines[2].contains("" + character)) {
                    badge = character;
                    break;
                }
            }

            totalPrio += 1 + alphabet.indexOf(badge);
        }

        return totalPrio;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/aoc2022_3/input.txt"));
        System.out.println(prioritySum(br));
    }
}
