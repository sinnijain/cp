#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct node
{
	string data;
	node *left,*right;

} typedef node;



node* getNode(string data)
{
	node *temp = (node *)malloc(sizeof(struct node));

	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

node* insert(node *temp,string data)
{
	if(temp==NULL)
	{
		temp=getNode(data);
		return temp;
	}

	else if(data<=temp->data)
	{
		temp->left=insert(temp->left,data);
		// cout << "a";
	}

	else if(data>=temp->data)
	{
		temp->right=insert(temp->right,data);
		// cout << "b";
	}

	return temp;
}

void printTree(node *temp)
{
	if (temp != NULL) 
    { 
     	printf("%s \n", temp->data);
        printTree(temp->left); 
         
        printTree(temp->right); 
    }
}

int main()
{
	int x;
	node *root = getNode("abc");
	insert(root,"4");
	insert(root,"sinni");
	insert(root,"ab");
	insert(root,"27");

	printTree(root);
}