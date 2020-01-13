#pragma once
#include <iostream>
#include <queue>
template<class W>
struct HuffmanTreeNode{
    HuffmanTreeNode(const W weight = W())
    :left(nullptr)
    ,right(nullptr)
    ,_weight(weight)
    {}
    HuffmanTreeNode<W>* left;
    HuffmanTreeNode<W>* right;
    W _weight;
};
template<class W>
class HuffmanTreeCreat{
    typedef HuffmanTreeNode<W> Node;
    HuffmanTreeCreat()
        :_pRoot(nullptr)
    {}
    void CreatTree(const vector<>)
    private:
    Node* _pRoot;   
};
