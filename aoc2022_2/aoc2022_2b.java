import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class aoc2022_2b {

    public static int sumOfPoints (BufferedReader br) throws IOException{
        String line = br.readLine();
        int points = 0;

        while(line !=  null) {
            if(line.equals("")) { break; };

            char op = line.charAt(0);
            char outcome = line.charAt(2);
            int roundPoints = RPS(op, outcome);
            points += roundPoints;
            line = br.readLine();
        }
        return points;
    }

    public static int RPS(char op, char outcome) {
        int points = 0;

        switch(outcome) {
            
            //lose
            case 'X':
            switch(op) {

                //rock vs. scissors
                case 'A':
                points += 3;
                break;

                //paper vs. rock
                case 'B':
                points += 1;
                break;

                //scissors vs. paper
                case 'C':
                points += 2;
                break;

            }
            break;

            //draw
            case 'Y':
            switch(op) {

                //rock vs. rock
                case 'A':
                points += 3 + 1;
                break;

                //paper vs. paper
                case 'B':
                points += 3 + 2;
                break;

                //scissors vs. scissors
                case 'C':
                points += 3 + 3;
                break;

            }
            break;

            //win
            case 'Z':
            switch(op) {

                //rock vs. paper
                case 'A':
                points += 6 + 2;
                break;

                //paper vs. scissors
                case 'B':
                points += 6 + 3;
                break;

                //scissors vs. rock
                case 'C':
                points += 6 + 1;
                break;

            }
            break;
        }

        return points;
    }


    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/aoc2022_2/input.txt"));
        System.out.println(sumOfPoints(br));
        br.close();
    }
}
