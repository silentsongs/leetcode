// source: https://leetcode.com/problems/rectangle-area/

/**
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 *
 **/

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C-A) * (D-B);
		int area2 = (G-E) * (H-F);
		int sum_area = area1 + area2;
		if (C <= E || G <= A || H <= B || D <= F)
			return sum_area;
		int I = A < E ? E : A;
		int J = B < F ? F : B;
		int K = C < G ? C : G;
		int L = D < H ? D : H;
		int repated_area = (K-I) * (L-J);
		return (sum_area-repated_area);
	}
};
