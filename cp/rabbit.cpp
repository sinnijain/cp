#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct node
{
	node *a1;
	node *a2;
	node *a3;
	node *a4;
	string info;

}typedef node;





node *newNode(string data)
{
	node *temp = new node;
	temp->info=data;
	temp->a1=NULL;
	temp->a2=NULL;
	temp->a3=NULL;
	temp->a4=NULL;

	return temp; 
}



void action(string data,node* temp)
{
	string t=data;
	for(int i=0;i<data.length();i++)
	{
		

		if(data[i]=='-' && (i-1)>=0 )
		{
			t[i-1]='-';
			t[i]=data[i-1];
			temp->a1=newNode(t);

			action(t,temp->a1);

			t=data;
		}

		else if(data[i]=='-' && (i-2)>=0 )
		{
			t[i-2]='-';
			t[i]=data[i-2];
			temp->a2=newNode(t);

			t=data;
		}

		else if(data[i]=='-' && (i+1)<=data.length())
		{
			t[i]=data[i+1];
			t[i+1]='-';
			temp->a3=newNode(t);

			t=data;
		}

		else if(data[i]=='-' && (i+2)<=data.length())
		{
			t[i]=data[i+2];
			t[i+2]='-';
			temp->a4=newNode(t);

			t=data;
		}


	}
	
}

void print(node *temp)
{
	printf("%s",temp->info);
	print(temp->a1);
	print(temp->a2);
	print(temp->a3);
	print(temp->a4);
}



int main()
{
	node *root=newNode("lll-rrr");

	

	action(root->info,root);



	print(root);

}