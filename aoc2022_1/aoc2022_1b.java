import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class aoc2022_1b {
    
    public static int getTopThree(BufferedReader br) throws IOException {
        String line = br.readLine();
        int first = 0;
        int second = 0;
        int third = 0;

        while(line != null) {
            
            //get number of cals for current elf
            int currentElf = 0;
            while(!line.equals("")) {
                currentElf += Integer.parseInt(line);
                line = br.readLine();
            }
            line = br.readLine();

            //more than 3rd, less than 2nd
            if((currentElf > third) && (currentElf < second)) { 
                third = currentElf; 
            }
            
            //more than 2nd, less than 1st
            if((currentElf > second) && (currentElf < first)) {
                third = second;
                second = currentElf;
            }

            //more than 1st
            if((currentElf > first)) {
                third = second;
                second = first;
                first = currentElf;
            }
        }

        return first + second + third;

    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/input.txt"));
        System.out.println(getTopThree(br));
        br.close();
    }
}