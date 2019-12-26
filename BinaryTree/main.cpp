#include <iostream>

using namespace std;
class Employee
{

public:
    int code ;
    Employee *pRight;
    Employee *PLeft;
    Employee()
    {
        code=0;
        pRight=PLeft=NULL;
    }
    Employee(int x)
    {
        code=x;
    }



};
class BinaryTree
{

    Employee *pParent;
    Employee *insert(Employee *pRoot, Employee *data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);
    Employee * deleteT(Employee *pRoot, int key );
    int getHeight(Employee *pRoot);
public :
    BinaryTree(){pParent=NULL;}
    void insertNode(Employee *data);
    Employee *searchTree(int code);
    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
    void deleteNode(int key );
    int getTreeHeight();


};
void BinaryTree::insertNode(Employee *data)
{
    pParent=insert(pParent,data);
    //cout <<"inserted";
}
Employee * BinaryTree::insert(Employee *pRoot, Employee *data)
{
    if(pRoot==NULL)
    {
        data ->PLeft=data->pRight=NULL;
        {
          return data;
        }

    }
    else
    {
        if(data ->code <=pRoot->code)

           {

            pRoot->PLeft=insert(pRoot->PLeft,data);
            }

        else
            pRoot->pRight= insert(pRoot->pRight,data);

         return(pRoot);

    }


}

Employee * BinaryTree::searchTree(int code)
{
   Employee *pRoot;
   pRoot=pParent;
   while(pRoot&&pRoot->code!=code)
   {

     if(code<=pRoot->code)
     {
         pRoot=pRoot->PLeft;
     }

       else
       pRoot=pRoot->pRight;

   }
   return pRoot;


}

 void BinaryTree:: inOrderTraverse (){
inOrder (pParent);
}
void BinaryTree:: inOrder ( Employee * pRoot){
if (pRoot)
{
inOrder(pRoot ->PLeft);
cout<<"Code : "<< pRoot->code<<endl;
inOrder(pRoot ->pRight);
}
}
 void BinaryTree:: preOrderTraverse (){
preOrder (pParent);
}
void BinaryTree:: preOrder( Employee * pRoot){
if (pRoot)
{
cout<<"Code : " << pRoot ->code<<endl;
preOrder(pRoot ->PLeft);
preOrder(pRoot ->pRight);
}
}
void BinaryTree:: postOrderTraverse (){
postOrder (pParent);
}
 void BinaryTree:: postOrder ( Employee * pRoot){
if (pRoot)
{
postOrder(pRoot ->PLeft);
postOrder(pRoot ->pRight);
cout<<"Code : "<< pRoot ->code<<endl;
}
}
int BinaryTree:: getTreeHeight (){
    return getHeight(pParent);
}
int BinaryTree:: getHeight ( Employee * pRoot){
    if (pRoot== NULL)
    return 0;
else
{
    int x= getHeight(pRoot->PLeft);
    int y= getHeight(pRoot->pRight);
if (x>y)
return x+1;
else
return y+1;
}
}
 void BinaryTree:: deleteNode ( int key)
{
      pParent = deleteT(pParent , key);
}
 Employee * BinaryTree:: deleteT ( Employee * pRoot, int key)
 {
// 1. Empty or Not found
    Employee *p,*p2;
    if(!pRoot)
        return pRoot;
    if(pRoot->code == key)
     {
        if(pRoot->PLeft == pRoot->pRight)
        {cout<<"---------------1"<<endl;
            delete pRoot ;
            return NULL;
        }



    else if (pRoot->PLeft == NULL)
        {
            cout<<"---------------2"<<endl;
            p = pRoot->pRight;
            delete pRoot;
            return p;
        }

   else if(pRoot->pRight == NULL)
     {
         cout<<"---------------3"<<endl;
        p = pRoot->PLeft;
        delete pRoot ;
        return p;
     }
  else
    {
        cout<<"---------------4"<<endl;
        p2 = pRoot->pRight;
        p = pRoot->pRight;

        while(p->PLeft)
          p = p->PLeft;

        p->PLeft = pRoot->PLeft;
        delete pRoot;

        return p2;
    }
    }
    if(pRoot->code < key)
        pRoot->pRight = deleteT(pRoot->pRight, key);
    else
       pRoot->PLeft = deleteT(pRoot->PLeft, key);

    return pRoot;


 }

int main()
{
    Employee *e1=new Employee(5);
    Employee *e2=new Employee(4);
    Employee *e3=new Employee(3);
    Employee *e4=new Employee(10);
    Employee *e5=new Employee(15);
    Employee *e7=new Employee(14);
    Employee *e6=new Employee(9);
    BinaryTree s;
    s.insertNode(e1);
    s.insertNode(e2);
    s.insertNode(e3);
    s.insertNode(e4);
    s.insertNode(e5);
    s.insertNode(e6);
    s.insertNode(e7);
    s.deleteNode(10);
    s.inOrderTraverse();
    //Employee *f=s.searchTree(5);

    cout<<"----------------------------"<<endl;
    //s.postOrderTraverse();
    cout<<"----------------------------"<<endl;
    //cout<<f->code<<endl;
    return 0;
}
