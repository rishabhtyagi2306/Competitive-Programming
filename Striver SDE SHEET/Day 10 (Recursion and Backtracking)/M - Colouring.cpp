bool isSafe(bool graph[101][101], int c, int v, int V, int color[])
{
    for(int i = 0; i < V; i++)
    {
        if(graph[i][v] == true && color[i] == c)
            return false;
    }
    
    return true;
}

bool check(bool graph[101][101], int m, int v, int V, int color[])
{
    if(v == V)
        return true;
    
    for(int i = 1; i <= m; i++)
    {
        if(isSafe(graph, i, v, V, color))
        {
            color[v] = i;
            if(check(graph, m, v+1, V, color))
                return true;
            else
                color[v] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V+1] = {0};
    return check(graph, m, 0, V, color);
}