//Xenia and tree
//idea:- Maintain a querybuffer which stores all the update queries in a vector
//when you a finddist query for a node you are going iterate on querybuffer(While querybuffer size<=root q) and find the dist between the nodes by lca precomputation
//and in an update operation you are going to push it into the query buffer as long as the querybuffer size <=root q when it crosses root q
//apply mutlisource bfs and update the nearest node red vertex for every node in the tree and clear the query buffer
//complexity o(n root q * logn ) 
