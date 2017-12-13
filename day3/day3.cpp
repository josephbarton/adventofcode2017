#include <iostream>


int spiral_memory(int input)
{
    int x = 0;
    int x_max = 0;
    int x_min = 0;
    int y = 0;
    int y_max = 0;
    int y_min = 0;
    
    bool neighbor_left = true;
    bool neighbor_right = false;
    bool neighbor_above = true;
    bool neighbor_below = false;
    for(int i = 1; i < input; i++)
    {
        if(!neighbor_right && neighbor_above)
        {
            //move right
            x++;
            neighbor_left = true;
            if(x > x_max)
            {
                neighbor_above = false;
                x_max++;
            }
            continue;
        }
        if(neighbor_left && !neighbor_above)
        {
            //move up
            y++;
            neighbor_below = true;
            if(y > y_max)
            {
                neighbor_left = false;
                y_max++;
            }
            continue;
        }
        if(neighbor_below && !neighbor_left)
        {
            //move left
            x--;
            neighbor_right = true;
            if(x < x_min)
            {
                neighbor_below = false;
                x_min--;
            }
            continue;
        }
        if(neighbor_right && !neighbor_below)
        {
            y--;
            neighbor_above = true;
            if(y < y_min)
            {
                neighbor_right = false;
                y_min--;
            }
        }
    }
    int ret = 0;
    if(x < 0)
    {
        ret += -x;
    }
    else
    {
        ret += x;
    }
    if(y < 0)
    {
        ret += -y;
    }
    else
    {
        ret += y;
    }
    return ret;
}

int add_neighbors(int grid[][51], int idx_x, int idx_y)
{
    int ret = 0;
    ret += grid[idx_x][idx_y];
    ret += grid[idx_x + 1][idx_y];
    ret += grid[idx_x][idx_y + 1];
    ret += grid[idx_x + 1][idx_y + 1];
    ret += grid[idx_x - 1][idx_y];
    ret += grid[idx_x][idx_y - 1];
    ret += grid[idx_x - 1][idx_y - 1];
    ret += grid[idx_x + 1][idx_y - 1];
    ret += grid[idx_x - 1][idx_y + 1];
    return ret;
}

int spiral_neighbors(int input)
{
    int grid[51][51];
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
            grid[i][j] = 0;
    grid[25][25] = 1;
    int row = 25;
    int col = 25;
    int x = 25;
    int x_max = 25;
    int x_min = 25;
    int y = 25;
    int y_max = 25;
    int y_min = 25;
    
    bool neighbor_left = true;
    bool neighbor_right = false;
    bool neighbor_above = true;
    bool neighbor_below = false;
    int sum = 0;
    int i = 0;
    for(i = 0; sum < input; i++)
    {
        if(!neighbor_right && neighbor_above)
        {
            //move right
            x++;
            neighbor_left = true;
            if(x > x_max)
            {
                neighbor_above = false;
                x_max++;
            }
            grid[x][y] = add_neighbors(grid, x, y);
            sum = grid[x][y];
            continue;
        }
        if(neighbor_left && !neighbor_above)
        {
            //move up
            y++;
            neighbor_below = true;
            if(y > y_max)
            {
                neighbor_left = false;
                y_max++;
            }
            grid[x][y] = add_neighbors(grid, x, y);
            sum = grid[x][y];
            continue;
        }
        if(neighbor_below && !neighbor_left)
        {
            //move left
            x--;
            neighbor_right = true;
            if(x < x_min)
            {
                neighbor_below = false;
                x_min--;
            }
            grid[x][y] = add_neighbors(grid, x, y);
            sum = grid[x][y];
            continue;
        }
        if(neighbor_right && !neighbor_below)
        {
            y--;
            neighbor_above = true;
            if(y < y_min)
            {
                neighbor_right = false;
                y_min--;
            }
            grid[x][y] = add_neighbors(grid, x, y);
            sum = grid[x][y];        
        }
    }
    return sum;
}

int main()
{
    std::cout << spiral_memory(361527) << std::endl;
    std::cout << spiral_neighbors(361527) << std::endl;
    return 0;
}
