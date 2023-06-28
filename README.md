# Line-polygonDistanceQueries
Let P be a simple polygon with n vertices, and L be a line in the plane which does not intersect it. 
The distance between the polygon P and the line L is defined as the minimum distance between a point in P and a point in L:
                distance(P, L) = min{|p-q| : p ∈ P ∧ q ∈ L}
In the following, we assume that the line L does not intersect any of the edges of the polygon P, and that the line is not 
parallel to any of the polygon edges.
This is a data structure to answer a series od line-polygon quesries for polygon P and lines L1,..., Lm. Storage is O(n) and 
the query time O(logn).
