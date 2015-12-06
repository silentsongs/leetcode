/* One pointer starts from the beginning while the other pointer starts from the end. 
 * They move toward each other until they both meet. 
 * Below is a very simple example to reverse the characters in a string.
 */

public class Solution {
    public void reverse(char[] str) {
      int i = 0;
      int j = str.length - 1;
      while (i < j) {
          swap(str, i, j);
          i++;
          j--;
      }

    private void swap(char[] str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

