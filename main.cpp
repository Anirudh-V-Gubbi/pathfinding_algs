//pathfinding algorithm
#include <iostream>
#include <vector>

#define coord std::pair<int, int>

const int width = 10;
const int height = 10;

coord start(0, 0);
coord end(7, 7);

std::vector<coord> stack;
void move(coord pos, const char* notdir);

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

bool check_right_wall(coord pos)
{
    return ((arr[pos.first][pos.second] % 4) >= 2);
}

bool check_left_wall(coord pos)
{
    return ((arr[pos.first][pos.second] % 8) >= 4);
}

bool check_up_wall(coord pos)
{
    return ((arr[pos.first][pos.second] % 1) >= 8);
}

bool check_down_wall(coord pos)
{
    return ((arr[pos.first][pos.second] % 2) >= 1);
}

void checkmove(coord pos, const char* dir)
{
    if(dir == "right"){
        if(!check_right_wall(pos))
            if(!visited(coord(pos.first, pos.second + 1)))
                move(coord(pos.first, pos.second + 1), "left");
    }
    else if(dir == "left"){
        if(!check_left_wall(pos))
            if(!visited(coord(pos.first, pos.second - 1)))
                move(coord(pos.first, pos.second - 1), "right");
    }
    else if(dir == "up"){
        if(!check_up_wall(pos))
            if(!visited(coord(pos.first - 1, pos.second)))
                move(coord(pos.first - 1, pos.second), "down");
                
    }
    else if(dir == "down"){
        if(!check_down_wall(pos))
            if(!visited(coord(pos.first + 1, pos.second)))
                move(coord(pos.first + 1, pos.second), "up");

    }
}

bool found = false;
void move(coord pos, const char* notdir)
{
    stack.push_back(pos);
    
    if(pos == end)
    {
        found = true;
        return;
    }
    if(pos.first < 0 || pos.first >= width || pos.second < 0 || pos.second >= height)
        return;
    
    if(notdir != "down")
        checkmove(pos, "down");
    if(found)
        return;
    
    if(notdir != "left")
        checkmove(pos, "left");
    if(found)
        return;
        
    if(notdir != "right")
    checkmove(pos, "right");
    if(found)
        return;
    
    if(notdir != "up")
    checkmove(pos, "up");
    if(found)
        return;
    
    
    stack.pop_back();
}

int main()
{
    move(start, "nodir");
    
    for(int i = 0; i < stack.size(); i++)
    {
        std::cout << "(" << stack[i].first << "," << stack[i].second << ") ";
    }

    return 0;
}
