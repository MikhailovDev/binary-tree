#include <gtest/gtest.h>

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <type_traits>

#include "../Tree/binary_tree.h"

namespace {
using BinaryTree::BTree;
using std::cout, std::cin, std::endl;
} // namespace

template <typename T>
inline void setAnswer(T& answer) {
    cin >> answer;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void clear() {
    system("clear");
}

inline void printMessage(const char* message) {
    cout << message;
}

template <typename T>
inline void printMessage(const char* message1, T res1, const char* message2) {
    cout << message1 << res1 << message2;
}

template <typename T>
inline void printMessage(const char* message1, T res1, const char* message2,
                         T res2, const char* message3) {
    cout << message1 << res1 << message2 << res2 << message3;
}

void showActions();
void pressEnterMessage();

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    BTree<int> tree;
    char choise {'q'};
    int nmb {};
    do {
        showActions();
        setAnswer(choise);
        choise = std::tolower(choise);
        clear();
        switch (choise) {
            case 'a':
                printMessage("Write an item to insert: ");
                setAnswer(nmb);
                tree.insert(nmb);
                break;
            case 'b':
                printMessage("Write an item to remove: ");
                setAnswer(nmb);
                tree.remove(nmb);
                break;
            case 'c':
                printMessage("Tree before: \n");
                cout << tree;
                tree.clear();
                printMessage("Tree after: \n");
                cout << tree;
                break;
            case 'd': {
                printMessage("Write an item to check: ");
                setAnswer(nmb);
                const int* lookUpRes = tree.lookUp(nmb);
                if (!lookUpRes) {
                    printMessage("Item not found.\n");
                } else {
                    printMessage("Item found.\n");
                }
                break;
            }
            case 'e':
                printMessage("Inorder traverse: \n");
                tree.printInorder();
                break;
            case 'f':
                printMessage("Preorder traverse: \n");
                tree.printPreorder();
                break;
            case 'g':
                printMessage("Postorder traverse: \n");
                tree.printPostorder();
                break;
            case 'h':
                printMessage("Cool traverse: \n");
                cout << tree;
                break;
            case 'i':
                printMessage("Size of the tree: ", tree.getSize(), "\n");
                break;
            case 'j':
                printMessage("Height of the tree: ", tree.getHeight(), "\n");
                break;
            case 'k':
                printMessage("Write an item to get it height: ");
                setAnswer(nmb);
                if (tree.lookUp(nmb)) {
                    printMessage("Height of the item ", nmb,
                                 " is: ", tree.getHeight(nmb), "\n");
                } else {
                    printMessage("Item ", nmb, " not found!\n");
                }
                break;
            case 'l':
                printMessage("Write an item to get it depth: ");
                setAnswer(nmb);
                if (tree.lookUp(nmb)) {
                    printMessage("Depth of the item ", nmb,
                                 " is: ", tree.getDepth(nmb), "\n");
                } else {
                    printMessage("Item ", nmb, " not found!\n");
                }
                break;
            case 'm':
                printMessage("Max depth of the tree: ", tree.getMaxDepth(),
                             "\n");
                break;
            case 'n':
                printMessage("Min depth of the tree: ", tree.getMinDepth(),
                             "\n");
                break;
            case 'o': {
                const int* max = tree.getMax();
                if (max) {
                    printMessage("Max item of the tree: ", *max, "\n");
                } else {
                    printMessage("Tree is empty!\n");
                }
                break;
            }
            case 'p': {
                const int* min = tree.getMin();
                if (min) {
                    printMessage("Min item of the tree: ", *min, "\n");
                } else {
                    printMessage("Tree is empty!\n");
                }
                break;
            }
            case 'r':
                printMessage("Tree is balanced: ");
                printMessage(tree.isBalanced() ? "true\n" : "false\n");
                break;
            case 'q':
                break;
            default:
                printMessage("You wrote incorrect command!\n");
                break;
        }
        pressEnterMessage();
    } while (choise != 'q');

    return RUN_ALL_TESTS();
}

void showActions() {
    printMessage("You can chose one of the following commands: \n");

    printMessage("a - insert item;\n");
    printMessage("b - remove item;\n");
    printMessage("c - clear whole tree;\n");
    printMessage("d - check item;\n\n");
    printMessage("e - print inorder traverse;\n");
    printMessage("f - print preorder traverse;\n");
    printMessage("g - print postorder traverse;\n");
    printMessage("h - print cool traverse;\n\n");
    printMessage("i - get size of the tree;\n");
    printMessage("j - get height of the tree root;\n");
    printMessage("k - get height of the tree item;\n");
    printMessage("l - get depth of the tree item;\n");
    printMessage("m - get max depth of the tree;\n");
    printMessage("n - get min depth of the tree;\n");
    printMessage("o - get max item;\n");
    printMessage("p - get min item;\n\n");
    printMessage("r - check if the tree is balanced;\n\n");
    printMessage("q - quit;\n");

    printMessage("Your choise: ");
}

void pressEnterMessage() {
    cout << "Press Enter to continue." << endl;
    cin.get();
    clear();
}