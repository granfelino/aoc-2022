import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
class aoc2022_1 {
    
    // public static int getMaxCal(String input) {
    //     StringTokenizer st = new StringTokenizer(input, "\n\n");
    //     int maxCal = 0;
        
    //     for(String token = st.nextToken(); token != null; token = st.nextToken()) {
    //         int currentElfSum = 0;
    //         StringTokenizer stInner = new StringTokenizer(token, "\n");    
            
    //         for(String tokenInner = stInner.nextToken(); tokenInner != null; tokenInner = stInner.nextToken()) {
    //             currentElfSum += Integer.parseInt(tokenInner);
    //         }

    //         if(currentElfSum > maxCal) { maxCal = currentElfSum; }
    //     }

    //     return maxCal;

    // }

//     StringBuilder sb = new StringBuilder();
//     String line = br.readLine();
    
//     while(line != null) {
//         sb.append(line);
//         sb.append("\n");
//         line = br.readLine();
//     }
//     sb.deleteCharAt(sb.length() - 1);        
//     sb.deleteCharAt(sb.length() - 1);
//     String content = sb.toString();




    public static int getMaxCal(BufferedReader br) throws IOException {
        String line = br.readLine();

        int maxCal = 0;
        while(line != null) {
            int currentElf = 0;
            
            while(!line.equals("")) {
                currentElf += Integer.parseInt(line);
                line = br.readLine();
            }
            
            line = br.readLine();
            if(currentElf > maxCal) { maxCal = currentElf; }
        }

        return maxCal;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/aoc2022_1/input.txt"));        
        System.out.println(getMaxCal(br));
        br.close();
    }
}