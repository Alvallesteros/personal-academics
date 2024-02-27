#include <iostream>
#include "Lab3_Alvanillas_struct.hpp"
using namespace std;

int main(void) {
    IntNode* node1 = new IntNode(5);
    IntNode* node2 = new IntNode(8);
    IntNode* node3 = new IntNode(10);
    IntNode* node4 = new IntNode(165);

    cout << "Created List" << endl;
    LinkedList* lst = new LinkedList();
    // lst->traverseList(); // Traverse Empty List (ERROR)

    //Append Nodes
    lst->appendNode(node1);
    lst->appendNode(node2);
    lst->appendNode(node3);
    cout << "Added Three Nodes: " << endl;
    lst->traverseList();
    lst->appendNode(node4);
    lst->appendNode(new IntNode(23));
    lst->appendNode(new IntNode(50));
    cout << "Added Three More Nodes: " << endl;
    lst->traverseList();

    cout << endl << endl;
    cout << "Created Stack" << endl;
    IntStack* stk = new IntStack();
    for(int i=0; i < 20; i += 2) {
        stk->push(new IntNode(i));
    }

    stk->traverse();

    cout << "First Pop: " << stk->pop()->getData() << endl << endl; 
    stk->traverse();
    cout << "Second Pop: " << stk->pop()->getData() << endl; 
    cout << "Third Pop: " << stk->pop()->getData() << endl; 
    cout << "Fourth Pop: " << stk->pop()->getData() << endl << endl;

    stk->traverse(); 

}