#include "BST.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    pair<int, int> p1 = pair<int, int>(5, 0);
    pair<int, int> p2 = pair<int, int>(7, 0);
    pair<int, int> p3 = pair<int, int>(6, 0);
    TreeNode<pair<int, int>> n1 = TreeNode<pair<int, int>>(p1);
    TreeNode<pair<int, int>> n2 = TreeNode<pair<int, int>>(p2);
    TreeNode<pair<int, int>> n3 = TreeNode<pair<int, int>>(p3, &n1, &n2);
    BST<int, int> t = BST<int, int>(&n3);
    pair <int, int> *answer = t.Get(6);
    if (answer)
        cout << answer->first << endl;
    else
        cout << 0 << endl;
    return 0;
}
