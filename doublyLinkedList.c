#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *pre, *next;
};
struct node *root = NULL, *tail = NULL;

int length(){
	int len=0;
	if(root == NULL){
		
	}
	else{
		struct node *temp = root;
		while(temp!=NULL){
			temp = temp->next;
			len++;
		}
	}
	return len;
}

void display(){
	struct node *temp = root;
	if(root == NULL){
		printf("No nodes to display\n");
	}
	else{
		while(temp!=NULL){
			printf("%d --> ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void InsertAtBeg(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL; newnode->pre = NULL;
	if(root == NULL){
//		root = newnode;
	}
	else{
		newnode->next = root;
		root->pre = newnode;
//		root = newnode;
	}
	root = newnode;
	display();
}

void InsertAtEnd(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL; newnode->pre = NULL;
	if(root == NULL){
		root = newnode;
	}
	else{
		struct node *temp;
		temp = root;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->pre = temp;
	}
	display();
}

void InsertAfter(){
	int n, i=1;
	printf("Enter the position after which you want to add a new node: ");
	scanf("%d",&n);
	if(n==0) InsertAtBeg();
	else if(n==length()) InsertAtEnd();
	else if(n<0||n>length()){
		printf("Invalid Location - There are %d nodes Here\n",length());
	}
	else{
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		struct node *temp = root;
		printf("Enter node data: ");
		scanf("%d",&newnode->data);
		newnode->next = NULL; newnode->pre = NULL;
		while(i<n){
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->next->pre = newnode;
		temp->next = newnode;
		newnode->pre = temp;
		display();
	}
}

void insertNode(){
    int ch;
    while(1){
        printf("1.At beg\n2.At End\n3.Insert After\n4.Move to parent menu\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                InsertAtBeg();
                break;
            }
            case 2:{
                InsertAtEnd();
                break;
            }
            case 3:{
                InsertAfter();
                break;
            }
            case 4:{
                return;
            }
        }
    }
}

void DelAtBeg(){
	struct node *temp = root;
	if(root == NULL){
		printf("There are no nodes to delete\n");
	}
	else if(length() == 1){
		root = NULL;
		free(temp);
	}
	else{
		root = temp->next;
		root->pre = NULL;
		temp->next = NULL;
		free(temp);
	}
	display();
}

void DelAtEnd(){
	struct node *temp = root;
	if(root == NULL){
		printf("There are no nodes to delete\n");
	}
	else if(length() == 1){
		root = NULL;
		free(temp);
	}
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->pre->next = NULL;
		temp->pre = NULL;
		free(temp);
	}
	display();
}

void DelAt(){
	int n;
	printf("Enter the position at which You want to delete a node: ");
	scanf("%d",&n);
	if(n<=0 || n>length()){
		printf("Invalid location - There are only %d node\n",length());
	}
	else if(n==length()) DelAtEnd();
	else if(n==1) DelAtBeg();
	else{
		int i = 1;
		struct node *temp = root;
		while(i<n){
			temp = temp->next;
			i++;
		}
		temp->next->pre = temp->pre;
		temp->pre->next = temp->next;
		temp->next = NULL; temp->pre = NULL;
		free(temp);
		display();
	}
}

void deleteNode(){
    int ch;
    while(1){
        printf("1.At Beg\n2.At End\n3.At Position\n4.Move to parent menu\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                DelAtBeg();
                break;
            }
            case 2:{
                DelAtEnd();
                break;
            }
            case 3:{
                DelAt();
                break;
            }
            case 4:{
                return;
            }
        }
    }
}

void createList(){
	int n,i;
	printf("Enter the number of nodes to be created: ");
	scanf("%d",&n);	
	for(i=0;i<n;i++){
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter node data: ");
		scanf("%d",&newnode->data);
		newnode->pre = NULL; newnode->next = NULL;
		if(root == NULL){
			root = newnode;
		}
		else{
			struct node *temp;
			temp = root;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->pre = temp;
		}
	}
	display();
}

void reverseList()
{
	if (length() == 0)
	{
		printf("No nodes to reverse");
	}
	else
	{
		struct node *current = root, *next = root;

		while(current->next!=NULL)
		{
			current = current->next;
		}
		tail = current;

		printf("Before reversing : ");
		display();
		printf("\n");

		current = root;
		while(current!=NULL)
		{
			next = current->next;
			current->next = current->pre;
			current->pre = next;
			current = next;
		}

		current = root;
		root = tail; 
		tail = current;

		printf("After reversing : ");
		display();
		printf("\n");
	}
}

int main(){
	int ch,len=0;
    printf("Creating Linked List...\n");
    createList();
    while(1){
        printf("1.insert\n2.delete\n3.display\n4.length\n5.Reverse The Linked List\n6.exit\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                insertNode();
                break;
            }
            case 2:{
                deleteNode();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                len = length();
                printf("Length is %d\n",len);
                break;
            }
			case 5:
			{
				reverseList();
				break;
			}
            case 6:{
                exit(0);
            }
        }
    }
}
