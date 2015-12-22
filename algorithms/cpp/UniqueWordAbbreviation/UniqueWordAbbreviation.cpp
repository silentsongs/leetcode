// source: https://leetcode.com/problems/unique-word-abbreviation/

/**
 *
 * An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
 *
 * a) it                      --> it    (no abbreviation)
 *
 *      1
 * b) d|o|g                   --> d1g
 *
 *               1    1  1
 *      1---5----0----5--8
 * c) i|nternationalizatio|n  --> i18n
 *
 *               1
 *      1---5----0
 * d) l|ocalizatio|n          --> l10n
 * Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 *
 *
 * Example: 
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 *
 * isUnique("dear") -> false
 * isUnique("cart") -> true
 * isUnique("cane") -> false
 * isUnique("make") -> true
 *
 **/

class ValidWordAbbr {
private: 
	unordered_map<string, unordered_set<string>> map_;
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (dictionary[i].length() <= 2) continue;
			string str = getAbbr(dictionary[i]);
			map_[str].insert(dictionary[i]);
		}
	}
	
	bool isUnique(string word) {
		if (word.length() <= 2) return true;
		string str = getAbbr(word);
		if (map_[str].size() == 0) 
			return true;
		else if (map_[str].size() == 1 && map_[str].find(word) != map_[str].end())
			return true;
		else
			return false;
	}

	string getAbbr(string word)
	{
		int length = word.length();
		string str = "";
		int num = length - 2;
		str.append(1, word[0]);
		str += to_string(num);
		str.append(1, word[length-1]);
		return str;
	}	
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
