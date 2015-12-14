// source: https://leetcode.com/problems/shortest-word-distance-ii/

/**
 *
 * This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 *
 * Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
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

class WordDistance {
private:
	unordered_map<string, vector<int>> map_;
public:
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); i++)
		{
			map_[words[i]].push_back(i);
		}
	}
	
	int shortest(string word1, string word2) {
		vector<int> distances1 = map_.find(word1)->second;
		vector<int> distances2 = map_.find(word2)->second;
		int shortest = 0;
		for (int i = 0; i < distances1.size(); i++)
		{
			for (int j = 0; j < distances2.size(); j++)
			{
				int distance = distances1[i] > distances2[j] ? distances1[i] - distances2[j] : distances2[j] - distances1[i];
				shortest = shortest > 0 && shortest < distance ? shortest : distance;
			}
		}
		return shortest;
	}
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
