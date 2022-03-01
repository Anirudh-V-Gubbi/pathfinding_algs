#include <iostream>
#include <unordered_map>
#include <vector>

#define coord std::pair<int, int>

const int width = 10;
const int height = 10;

coord start(0, 0);
coord end(7, 7);

enum DIRECTIONS {
    no_dir = 0,
    down = 1,
    right = 2,
    left = 4,
    up = 8
};

std::unordered_map<int, DIRECTIONS> dir_map;
std::vector<coord> stack;

int arr[width][height] =
{
    {14, 13,  9,  8,  9,  8,  8,  9, 8, 11},
    { 6, 15, 12,  3, 12,  3,  6, 13, 0, 11},
    { 6, 12,  3, 12,  3, 13,  1,  9, 0, 11},
    { 4,  3, 12,  3, 12,  9, 10, 12, 0, 11},
    { 6, 12,  3, 12,  1,  8,  3,  6, 4, 11},
    { 4,  3, 12,  3, 15,  6, 14,  6, 4, 11},
    { 6, 14,  6, 15, 12,  2,  5,  0, 0, 10},
    { 6,  6,  4,  9,  1,  1, 11,  7, 6,  7},
    { 6,  7,  6, 12,  9,  9,  9, 10, 4, 11},
    { 5,  9,  1,  1,  9,  9,  9,  1, 3, 15}
};

bool visited(coord pos)
{
    for(int i = 0; i < stack.size(); i++){
        if(stack[i] == pos)
            return true;
    }
    return false;
}

bool found = false;
void move(coord pos, DIRECTIONS notdir)
{
    stack.push_back(pos);
    if(pos == end)
    {
        found = true;
        return;
    }
    if(pos.first < 0 || pos.first >= width || pos.second < 0 || pos.second >= height)
        return;
    
    for(int i = 0; i < dir_map.size(); i++)
    {
        DIRECTIONS dir = dir_map.find(i)->second;
        if(((arr[pos.first][pos.second] & dir) == 0) && (dir != notdir)){
            //std::cout << "(" << pos.first << "," << pos.second << ") ";
            if(dir == right){
                if(!visited(coord(pos.first, pos.second + 1)))
                    move(coord(pos.first, pos.second + 1), left);
                if(found)
                    return;
            }
            if(dir == left){
                if(!visited(coord(pos.first, pos.second - 1)))
                    move(coord(pos.first, pos.second - 1), right);
                if(found)
                    return;
            }
            if(dir == up){
                if(!visited(coord(pos.first - 1, pos.second)))
                    move(coord(pos.first - 1, pos.second), down);
                if(found)
                    return;
            }
            if(dir == down){
                if(!visited(coord(pos.first + 1, pos.second)))
                    move(coord(pos.first + 1, pos.second), up);
                if(found)
                    return;
            }

        }
    }
    stack.pop_back();
}

int main()
{
    dir_map.insert({0, down});
    dir_map.insert({1, left});
    dir_map.insert({2, right});
    dir_map.insert({3, up});

    move(start, no_dir);
    
    for(int i = 0; i < stack.size(); i++)
    {
        std::cout << "(" << stack[i].first << "," << stack[i].second << ") ";
    }

    return 0;
}
