import java.util.regex.*;
import java.util.*;

public class TokenizeString {
  public static int getDigit(String str) {
    String[] digits = { "zero","one","two","three", "four","five","six","seven","eight","nine"};
    for (int i=0; i<digits.length; i++)
    {
      if (digits[i].equals(str))
        return i;
    }
    return -1;
  }

  public static void main(String[] args) {
    String input = "foursixzeroplusfourthree";
    String regex = "four|six|zero|plus|three";

    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = pattern.matcher(input);

    List<String> tokens = new ArrayList<>();

    while (matcher.find()) {
      tokens.add(matcher.group());
    }

    String number1 = "";
    String number2 = "";
    String op ="";
    boolean next = false;
    for (int i=0; i<tokens.size(); i++) {
      String token = tokens.get(i);
      if (token.equals("plus")) {
        System.out.println("+");
        op = "+";
        next = true;
      }
      else {
        if (next == false)
          number1 += String.valueOf(getDigit(token));
        else 
          number2 += String.valueOf(getDigit(token));
        System.out.println(getDigit(token));
      }
    }

    int total =0;

    if (op.equals("+"))
      total = Integer.valueOf(number1) + Integer.valueOf(number2);



    System.out.println("Number1=" + number1);
    System.out.println("Number2=" + number2);
    System.out.println("Total=" + total);
    System.out.println(tokens);
  }
}
