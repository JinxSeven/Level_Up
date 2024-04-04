#include <iostream>
#include <random>

int duplicates {0};

class Node {
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BStree {
    private:
        int height {0};
        Node *root;

    public:
        BStree() : root (nullptr) {};

    bool appendTree(int data) {
        Node *newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return true;
        } else {
            Node *temp = root;
            while (true) {
                if (data == temp->data) {
                    duplicates++;
                    return false;
                }
                else if (data < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    void viewTreeRecur(Node *start) {
        if (start == nullptr) {
            return;
        }
        viewTreeRecur(start->left);
        std::cout << start->data << " ";
        viewTreeRecur(start->right);
    }

    void viewTree() {
        viewTreeRecur(root);
        std::cout << "Duplicates: " << duplicates << "\n";
    }
};

int main() {
    std::random_device randDev;
    std::mt19937 gen(randDev());

    std::uniform_int_distribution<int>numSelect(1, 15);

    BStree one;

    for (int x = 0; x < 15; x++) {
        int final = 5 * numSelect(gen);
        one.appendTree(final);
    }

    one.viewTree();
    return 0;
}