#pragma once

#include <map>

#define NORTH 'N'
#define SOUTH 'S'
#define EAST  'E'
#define WEST  'W'

namespace engine
{
    namespace map
    {
        class Node
        {
        private:
            std::map<char, Node*> directions_;

        public:
            void addNode(char direction, Node* content);
        };

        class MapGraph
        {
        private:
            Node* startNode_;

        public:
            MapGraph(std::string seed);
        };

    } // namespace map

} // namespace engine