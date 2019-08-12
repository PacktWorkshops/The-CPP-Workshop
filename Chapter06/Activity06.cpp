#include <iostream>
using namespace std;

struct numeric_tree
{
    int value_;
    numeric_tree* left_;
    numeric_tree* right_;
};

numeric_tree* root = nullptr;

void add(int v, numeric_tree** pp)
{
    *pp = new numeric_tree;
    (*pp)->value_ = v;
    (*pp)->left_ = (*pp)->right_ = nullptr;
}

void delete_tree(numeric_tree* item)
{
    if (item == nullptr)
    {
        return;
    }
    else
    {
        delete_tree(item->left_);
        delete_tree(item->right_);
        cout << "deleting " << item->value_ << endl;
        delete item;
    }
}

numeric_tree** find(int v, numeric_tree** pp)
{
    if (*pp == nullptr)
    {
       return pp;
    }
    else if (v < (*pp)->value_)
    {
        return find(v, &((*pp)->left_));
    }
    else
    {
        return find(v, &((*pp)->right_));
    }
}

void print(numeric_tree* item)
{
    if (item == nullptr)
    {
        return;
    }
    else
    {
        print(item->left_);
        cout << item->value_ << " ";
        print(item->right_);
    }
}

int main()
{
    int insert_order[] { 4, 2, 1, 3, 6, 5 };
    for (int i = 0; i < 6; ++i)
    {
        int v = insert_order[i];
        add(v, find(v, &root));
    }
    
    print(root);
    cout << endl;
    
    delete_tree(root);

    return 0;
}

