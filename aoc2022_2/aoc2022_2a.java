import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


class aoc2022_2a {
    
    public static int pointsSum(BufferedReader br) throws IOException {
        String line = br.readLine();
        int points = 0;

        while(line != null) {
            if(line.equals("")) { break; }

            char op = line.charAt(0);
            char you = line.charAt(2);

            // switch for what you choose
            switch(you) {
                case 'X':
                points += 1;
                break;

                case 'Y':
                points += 2;
                break;

                case 'Z':
                points += 3;
                break;

                default:
                System.out.println("wtf");
                break;
            }

            points += RPS(you, op);
            line = br.readLine();
        }

        return points;
    }

    public static int RPS(char you, char op) {
        int points = 0;

        
        switch(you) {
            
            //rock
            case 'X':
            switch(op) {
                case 'A':
                points = 3;
                break;
                
                case 'B':
                points = 0;
                break;
                
                case 'C':
                points = 6;
                break;
            }
            break;

            //paper
            case 'Y':
            switch(op) {
                case 'A':
                points = 6;
                break;
                
                case 'B':
                points = 3;
                break;
                
                case 'C':
                points = 0;
                break;
            }
            break;

            //scissors
            case 'Z':
            switch(op) {
                case 'A':
                points = 0;
                break;
                
                case 'B':
                points = 6;
                break;
                
                case 'C':
                points = 3;
                break;
            }
            break;

            default:
            break;

        }

        return points;
    }
    
    public static void main(String[] args) throws IOException {
        String path = "/home/granfelino/own/aoc2022/aoc2022_2/input.txt";
        BufferedReader br = new BufferedReader(new FileReader(path));

        System.out.println(pointsSum(br));
        br.close();
        
    }
}