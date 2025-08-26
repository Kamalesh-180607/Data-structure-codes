//BINARY SEARCH TREE IMPLEMENTATION
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
Node* Insert(Node *T,int val)
{
    if(!T)
    {
        Node* newnode=new Node(val);
        T=newnode;
    }
    else if(val<T->data)
    T->left=Insert(T->left,val);
    
    else if(val>T->data)
    T->right=Insert(T->right,val);
    
    return T;
}
Node* Findmin(Node* T)
{
   if(!T)
   {
      return NULL;
   }
   if(!T->left)
   return T;
   
  // else
   return Findmin(T->left);
}
Node* Findmax(Node* T)
{
   if(!T)
   {
      return NULL;
   }
   if(!T->right)
   return T;
   
  // else 
   return Findmax(T->right);
}
Node* Delete(Node* T,int key)
{
    if(key< T->data)
    T->left=Delete(T->left,key);
    else if(key>T->data)
    T->right=Delete(T->right,key);
    else
    {
       if(!T->left && !T->right)
       {
         delete T;
         return NULL;
       }
       else if(T->left==NULL)
       {
         Node* temp=T->right;
         delete T;
         return temp;
       }
       else if(T->right==NULL)
       {
         Node *temp=T->left;
         delete T;
         return temp;
       }
       Node *temp=Findmin(T->right);
       T->data=temp->data;
       Delete(T->right,temp->data);
    }
    return T;
}
void Inorder(Node *T)
{
   if(T!=NULL)
   {
   Inorder(T->left);
   cout<<T->data<<"  ";
   Inorder(T->right);
   }
}
void Preorder(Node *T)
{
   if(T!=NULL)
   {
   cout<<T->data<<"  ";
   Preorder(T->left);
   Preorder(T->right);
   }
}
void Postorder(Node *T)
{
   if(T!=NULL)
   {
   Postorder(T->left);
   Postorder(T->right);
   cout<<T->data<<"  ";
   }
}
int main()
{
   int c;
   int key;
   Node *T=NULL;
   do
   {
   cout<<endl;
   cout<<"1. Insertion"<<endl;
   cout<<"2. Deletion"<<endl;
   cout<<"3. Minimum Element"<<endl;
   cout<<"4. Maximum Element"<<endl;
   cout<<"5. Inorder Display"<<endl;
   cout<<"6. Preorder Display"<<endl;
   cout<<"7. Postorder Display"<<endl;
   cout<<"8. Exit"<<endl;
   cin>>c;
   switch(c)
   {
      case 1:
      cout<<"Enter key value to insert: ";
      cin>>key;
      T=Insert(T,key);
      break;
      
      case 2:
      cout<<"Enter key to delete: ";
      cin>>key;
      T=Delete(T,key);
      break;
      
      case 3:
      //Node *mi=Findmin(T);
      cout<<"Minimum element: "<<Findmin(T)->data;
      break;
      
      case 4:
      //Node *Ma=Findmax(T);
      cout<<"Maximum element: "<<Findmax(T)->data;
      break;
      
      case 5:
      Inorder(T);
      break;
      
      case 6:
      Preorder(T);
      break;
      
      case 7:
      Postorder(T);
      break;
      
      case 8:
      cout<<"Exited!!";
      break;
      
      default:
      cout<<"Enter valid choice"<<endl;
    }
    }while(c!=8);
    
}
