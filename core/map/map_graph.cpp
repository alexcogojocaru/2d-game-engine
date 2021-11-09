#include "map_graph.h"

namespace engine
{
    namespace map
    {
        void Node::addNode(char direction, Node* content)
        {
            directions_[direction] = content;
        }

        MapGraph::MapGraph(std::string seed) : startNode_(nullptr)
        {
            for (int idx = 0; idx < seed.length(); idx++)
            {
                int roomType = seed[idx] - '0';
                char direction = seed[idx + 1];
            }
        }
    }
}