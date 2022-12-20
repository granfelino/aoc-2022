import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

class aoc2022_4b {
    public static int getContainsCount(BufferedReader br) throws IOException{
        String line = br.readLine();
        int totalCount = 0;

        while(line != null) {
            Integer[] fields = getIntList(line).toArray(new Integer[0]);
            boolean firstInSecondOne = fields[0] >= fields[2] && fields[0] <= fields[3]; 
            boolean firstInSecondTwo = fields[1] >= fields[2] && fields[1] <= fields[3];
            boolean secondInFirstOne = fields[2] >= fields[0] && fields[2] <= fields[1];
            boolean secondInFirstTwo = fields[3] >= fields[0] && fields[3] <= fields[1];
            boolean overlap = firstInSecondOne || firstInSecondTwo || secondInFirstOne || secondInFirstTwo;
            if(overlap) { totalCount++; }
            line = br.readLine();
        }

        return totalCount;
    }

    public static ArrayList<Integer> getIntList(String line) {
        ArrayList<Integer> fields = new ArrayList<>();
        int i = 0;
        while(i < line.length()) {
            char currChar = line.charAt(i);
            String number = "";
            while(currChar != ',' && currChar != '-') {
                number += currChar;
                if(i != (line.length() - 1)) {
                    i++;
                    currChar = line.charAt(i);

                } else {
                    break;
                }
                
            }
            fields.add(Integer.parseInt(number));
            i++;
        }
        return fields;
    }


    public static void main(String[] args) throws IOException {
        String path = "/home/granfelino/own/aoc2022/aoc2022_4/input.txt";
        BufferedReader br = new BufferedReader(new FileReader(path));

        System.out.println(getContainsCount(br));
        br.close();

    }
}