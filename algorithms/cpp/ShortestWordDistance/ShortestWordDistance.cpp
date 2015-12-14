// source: https://leetcode.com/problems/shortest-word-distance/

/**
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 *
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 *
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 *
 **/

// a, b, c, d, e, f, a, d

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int index1 = -1, index2 = -1, shortest = 0;
		for(int i = 0; i < words.size(); i++)
		{
			if (words[i] == word1) index1 = i;
			if (words[i] == word2) index2 = i;
			if (index1 >= 0 && index2 >= 0)
			{
				int distance = index1 > index2 ? index1 - index2 : index2 - index1;
				shortest = shortest > 0 && shortest < distance ? shortest : distance;
			}
		}
		return shortest;
	}
};
