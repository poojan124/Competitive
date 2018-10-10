#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    long long lCount,rCount;
    Node *lChild,*rChild;
    Node()
    {
        lCount=rCount=0;
        lChild=rChild=NULL;
    }
};
long long query(Node *root,long long n,long long k)
{
    if(root == NULL)
        return 0;
    long long res = 0;
    for(long long i=20;i>=0;i--)
    {
        bool ch1=(k>>i) & 1;
        bool ch2=(n>>i) & 1;
        if(ch1)
        {
            if(ch2){
                res+=root->rCount;
                if(root->lChild == NULL)
                    return res;
                root = root->lChild;
            }

            else{
                res+=root->lCount;
                if(root->rChild == NULL)
                    return res;
                root = root->rChild;
            }
        }
        else
        {
            if(ch2){
                if(root->rChild == NULL)
                    return res;
                root= root->rChild;
            }
            else{
                if(root->lChild == NULL)
                    return res;
                root= root->lChild;
            }
        }
    }
    return res;
}
void addBit(Node *root,long long n)
{
    for(long long i=20;i>=0;i--)
    {
        long long x= (n>>i) & 1;

        if(x)
        {
            root->rCount++;
            if(root->rChild == NULL)
                root->rChild = new Node();
            root = root->rChild;
        }
        else
        {
            root->lCount++;
            if(root->lChild == NULL)
                root->lChild = new Node();
            root = root->lChild;
        }
    }
}
int main()
{
    long long n,k;
    scanf("%d%d",&n,&k);
    long long temp,temp1,temp2=0;
    Node *root = new Node();
    addBit(root,0);
    long long total =0;
    for(long long i=0;i<n;i++)
    {
        scanf("%d",&temp);
        temp1= temp2^temp;
        total+=(long long)query(root,temp1,k);
        addBit(root , temp1);
        temp2 = temp1;
    }
    prlong longf("%lld\n",total);
    return 0;
}
