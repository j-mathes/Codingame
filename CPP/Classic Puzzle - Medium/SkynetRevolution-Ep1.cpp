#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Node
{
public:

	Node()
	{
		is_gateway = false;
	}

	set<int> neighbors;
	bool is_gateway;
};

int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	cin >> N >> L >> E; cin.ignore();

	vector<Node*> nodes;	// This is our graph data structure

	for (int i = 0; i < N; i++)
		nodes.push_back(new Node());	// Here we create an entry for each node in the graph

	for (int i = 0; i < L; i++) 
	{
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		cin >> N1 >> N2; cin.ignore();

		nodes[N1]->neighbors.insert(N2);	// For a given node, we assign it's neighbor
		nodes[N2]->neighbors.insert(N1);	// For that neighbor node, we assign the N1 node as a neighbor to it as well
	}


	for (int i = 0; i < E; i++)	// Mark all exit gateways
	{
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		nodes[EI]->is_gateway = true;
	}

	// game loop
	while (1) {
		// Read information from standard input
		int SI;	// Skynet Index - The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();

		int SN = -1;	// Skynet node neighbor

		// if one neighbor of skynet is a gateway, break the link
		Node* skynet = nodes[SI];	// Assign a pointer called skynet to the specific node indicated above

		for (set<int>::iterator it = skynet->neighbors.begin(); it != skynet->neighbors.end(); ++it)
		{
			if (nodes[*it]->is_gateway)
			{
				SN = *it;	// if the current node in iteration is a gateway, assign it to the SN node
				break;
			}
		}

		// no skynet neighbor is a gateway, break the link
		// with the first neighbor
		if (SN == -1)
			SN = *skynet->neighbors.begin();

		// update links info
		skynet->neighbors.erase(SN);
		nodes[SN]->neighbors.erase(SI);

		// Write action to standard output
		cout << SI << " " << SN << endl;
	}

	return 0;
}
