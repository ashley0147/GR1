typedef struct node_t
{
    int vertex;
    struct node_t *next;
} Node;

Node *createNode(int vertex);

typedef struct graph_t
{
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

Graph *createGraph(int verticeNumber);
void bfs(Graph *graph, int startVertex);