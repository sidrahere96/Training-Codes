#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int a)
    {
        data=a;
        left=NULL;
        right=NULL;
    }
};

class BST
{
    Node* root;
    public:
    
    BST()
    {
        root=NULL;
    }
    
    Node* create(int a)
    {
        return new Node(a);
    }

    void insert(int b)
    {
        if(root==NULL)
        {
            root=create(b);
            return;
        }
            
        Node* temp=root;
        
        while(true)
        {    
            if(b<temp->data)
            {
                if(temp->left)
                    temp=temp->left;
                else
                {
                    temp->left=create(b);
                    break;
                }
            }
            
            else
            {
                if(temp->right)
                    temp=temp->right;
                else
                {
                    temp->right=create(b);
                    break;
                }
            }
        }
    }

    void inorder(Node* node) // travel tree recursively
    { 
        if (node==nullptr) return;
        inorder(node->left);
	    cout << node->data << " ";
        inorder(node->right);
    }

    void inorderTraversal() 
    {
        inorder(root);
        cout << endl;
    }

    void remove(int a)
    {
        Node* parent=NULL;
        Node* current=root;

        while(current!=NULL && current->data!=a)   //FOR FINDING THE NODE THAT IS TO BE DELETED
        {
            parent=current;
            if(a<current->data)
                current=current->left;
            else
                current=current->right;
        }

        if(current==NULL)
        {
            cout<<"\nVALUE NOT FOUND!";
            return;
        }

        if(current->left==NULL && current->right==NULL)  //FOR DELETING ELEMENT HAS NO CHILD
        {
            if(current==root)
                root=NULL;
            else if(parent->left==current)
                parent->left=NULL;
            else
                parent->right=NULL;
            delete current;
        }


        else if(current->left==NULL || current->right==NULL)  //FOR DELETING ELEMENT HAS ONE CHILD
        {
            Node* child=(current->left!=NULL)?current->left:current->right;

            if(root==current)
                root=child;
            else if(parent->left==current)
                parent->left=child;
            else
                parent->right=child;
            delete current;
        }

        
        else        //FOR DELETING ELEMENT HAS TWO CHILD
        {
            Node* successorParent=current;
            Node* successor=current->right;

            while(successor->left!=NULL)
            {
                successorParent=successor;
                successor=successor->left;
            }

            current->data=successor->data;

            if(successorParent->left==successor)
                successor->left=successor->right;
            else
                successorParent->right=successor->right;
            delete successor;
        }
    }
};

int main()
{
    BST o;
    
    int a;
    
    do
    {
        cout<<"\n\nWHAT DO YOU WANT TO DO?";
        cout<<"\n1.ADD ELEMENT\n2.REMOVE ELEMENT\n3.DISPLAY BINARY SEARCH TREE\n4.EXIT";
        cout<<"\nSELECTION:";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"ENTER ELEMENT TO INSERT:";
                int b;
                cin>>b;
                o.insert(b);
                break;
            }
            case 2:
            {
                cout<<"ENTER ELEMENT TO DELETE:";
                int b;
                cin>>b;
                o.remove(b);
                cout<<"NOW ELEMENTS ARE:\n\t\t";
                o.inorderTraversal();
                break;
            }

            case 3:
            {
                cout<<"ELEMENTS BINARY SEARCH TREE:\n\t\t";
                o.inorderTraversal();
                break;
            }

            case 4:
                cout<<"EXITED";
                break;

            default:
                cout<<"INAVLID CHOICE!";
        }
    }while(a!=4);
    return 0;
}