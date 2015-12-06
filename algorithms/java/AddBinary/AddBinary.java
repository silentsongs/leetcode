// source: https://leetcode.com/problems/add-binary/

/**
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 **/

public class Solution {
    public String addBinary(String a, String b) {
        int lengthA = a.length();
        int lengthB = b.length();
        int i = 0, carry = 0;
        String res = "";
        while(lengthA > i || lengthB > i || carry != 0){
            int x = (lengthA > i) ? Character.getNumericValue(a.charAt(lengthA - 1 - i)) : 0;
            int y = (lengthB > i) ? Character.getNumericValue(b.charAt(lengthB - 1 - i)) : 0;
            res = (x + y + carry) % 2 + res;
            carry = (x + y + carry) / 2;
            i++;
        }
        return res;
    }
}