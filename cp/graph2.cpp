#include<iostream>
#include<cstdlib>
using namespace std;

struct adjNode
{
	int vex_no;
	struct adjNode *next;
};


struct graph
{
	int v;
	int e;
	adjNode **adj;
};



struct graph *adjMatrixofGraph(struct graph *g)
{
	int i;
	int x,y;
	g=(struct graph*)malloc(sizeof(struct graph));

	if(!g)
	{
		printf("memory error");
		return g;
	}

	scanf("%d %d",&g->v,&g->e);
	g->adj=(struct adjNode**)malloc((g->v)*sizeof(struct adjNode));

	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct adjNode*)malloc(sizeof(struct adjNode));
		g->adj[i]->vex_no=i;
		g->adj[i]->next=g->adj[i];
	}

	for(i=0;i<g->e;i++)
	{
		//read an edge
		scanf("%d %d",&x,&y);
		struct adjNode* temp=(struct adjNode*)malloc(sizeof(struct adjNode));
		temp->vex_no=y;
		temp->next=g->adj[x];
		g->adj[x]->next=temp;
		temp=(struct adjNode*)malloc(sizeof(struct adjNode));
		temp->vex_no=y;
		temp->next=g->adj[y];
		g->adj[y]->next=temp;

	}

	return g;

}


void printGraph(struct graph* graph)
{

    for(int i=0;i<graph->v;i++){
        adjNode *root=graph->adj[i];
        adjNode *t=root;
        cout<<"Adjacency list of vertex "<<i<<endl;
         cout<<root->vex_no<<" -> ";
         root=root->next;
        while(root!=t)
        {
            cout<<root->vex_no<<" -> ";
            root=root->next;
        }
        cout<<endl;
    }
}


int main()
{
	struct graph *g1;
	g1=adjMatrixofGraph(g1);
	printGraph(g1);
}



