// 141_创建哈夫曼树.cpp : 定义控制台应用程序的入口点。
//

#include <stdafx.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


//定义一个数据类型别名
typedef int ElemType;

//定义二叉树结构
typedef struct BTreeNode
{
    int data;
    BTreeNode *left, *right;
}BTreeNode;

//创建哈夫曼树
BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    BTreeNode **b, *q;
    q = nullptr;
    b = (BTreeNode**)malloc(n * sizeof(BTreeNode));

    for (i = 0; i < n; i++)
    {
        b[i] = (BTreeNode*)malloc(sizeof(BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = nullptr;
    }

    for (i = 1; i < n; i++)
    {
        cout << "i=" << i << endl;
        int k1 = -1, k2;
        for (j = 0; j < n; j++)
        {
            if (b[j] != nullptr&&k1 == -1)
            {
                k1 = j;
                cout << "k1=j:" << k1 << endl;
                continue;
            }

            if (b[j] != nullptr)
            {
                k2 = j;
                cout << "k2=j:" << k2 << endl;
                break;
            }

        }
        cout << "***********1**************" << endl;

        for (j = k2; j < n; j++)
        {
            if (b[j] != nullptr)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                    cout << b[j]->data << ";" << b[k2]->data << ";k2=k1:" << k2 << "k1==j:" << k1 << endl;
                }
                else if (b[j]->data < b[k2]->data)
                {
                    cout << b[j]->data << ";" << b[k2]->data << ";k2=j:" << j<< endl;
                    k2 = j;

                }
            }

        }
        cout << "****创建节点****" << endl;

        q = (BTreeNode*)malloc(sizeof(BTreeNode));
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];
        cout << "q->data:" << q->data << ";b[k1]->data" << b[k1]->data << ";b[k2]->data" << b[k2]->data << endl;
        b[k1] = q;
        b[k2] = nullptr;

    }

    free(b);
    return q;
}

int main()
{
    int a[4] = { 7,5,2,4 };
    CreateHuffman(a, 4);
    return 0;
}
