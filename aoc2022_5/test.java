import java.io.*;

public class test {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("/home/granfelino/own/aoc2022/aoc2022_5/input.txt"));
        String line = br.readLine();
        System.out.println(line.length());
        br.close();
    }
}
