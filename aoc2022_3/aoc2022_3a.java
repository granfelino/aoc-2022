import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class aoc2022_3a {

    public static int sumOfPriority(BufferedReader br) throws IOException {
        String line = br.readLine();
        String lowercase = "abcdefghijklmnopqrstuvwxyz";
        int prioritySum = 0;

        while(line != null) {
            int linePrio = 0;
            String first = line.substring(0, (line.length() / 2));
            String second = line.substring(line.length() / 2);
            
            for(int i = 0; i < first.length(); i++) {
                if(second.contains("" + first.charAt(i)) &&
                   Character.isUpperCase(first.charAt(i))
                   ) {

                    char tempChar = Character.toLowerCase(first.charAt(i));
                    linePrio = 26 + (1 + lowercase.indexOf(tempChar));

                } else if(second.contains("" + first.charAt(i)) &&
                          Character.isLowerCase(first.charAt(i))
                          ) {

                            linePrio = 1 + lowercase.indexOf(first.charAt(i));
                          }
            }

            prioritySum += linePrio;
            line = br.readLine();
        }

        return prioritySum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/aoc2022_3/input.txt"));
        System.out.println(sumOfPriority(br));
        br.close();
    }
}