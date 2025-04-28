pra1==    Consider a telephone book database with N clients. Implement a hash table to quickly look up a client's telephone 
number, using two collision handling techniques and compare them based on the number of comparisons required 
to find a set of telephone numbers.  
(Telephone Book Database)

class Person:
    def __init__(self):
        self.name = ""
        self.telephone_number = 0

    def set_data(self):
        self.name = input("Enter name: ")
        self.telephone_number = int(input("Enter telephone number: "))

    def display_data(self):
        print(f"Name: {self.name}")
        print(f"Telephone number: {self.telephone_number}")


def hash_key(key, size):
    return key % size


class HashTableLinearProbing:
    def __init__(self, size=10):
        self.ht = [None] * size
        self.size = size
        self.comparison = [0] * size
        

    def insert_data(self, person):
        comp=0
        index = hash_key(person.telephone_number, self.size)
        if self.ht[index] is None:
            comp+=1
            self.ht[index] = person
            self.comparison[index]=comp
            print(f"Name: {person.name} entered with telephone num: {person.telephone_number} with comparison {comp}")
        else:
            comp=1
            while self.ht[index] is not None:
                comp+=1
                index =(index+1)%self.size
            self.ht[index] = person
            self.comparison[index]=comp
            print(f"Name: {person.name} entered with telephone num: {person.telephone_number} with comparison {comp}")

    def search_data(self, telephone):
        index = hash_key(telephone, self.size)
        original_index = index
        i = 0
        while self.ht[index] is not None:
            if self.ht[index].telephone_number == telephone:
                print(f"Number {telephone} found with name {self.ht[index].name} at Index: {index}")
                return True
            i += 1
            index = (index + i) % self.size
            if index == original_index:
                print(f"Number {telephone} not found in the hash table.")
                return False
        print(f"Number {telephone} not found in the hash table.")
        return False

    def delete_data(self, telephone):
        index = hash_key(telephone, self.size)
        original_index = index
        i = 0
        while self.ht[index] is not None:
            if self.ht[index].telephone_number == telephone:
                self.ht[index] = None
                return True
            i += 1
            index = (index + i) % self.size
            if index == original_index:
                print(f"Number {telephone} not found in the hash table.")
                return False
        print(f"Number {telephone} not found in the hash table.")
        return False

    def display(self):
        print(f"Index\t| Name: \t\t| Telephone Number:      |Comparisons")
        for i in range(self.size):
            if self.ht[i] is not None:
                print(f"{i}\t| {self.ht[i].name} \t|  {self.ht[i].telephone_number}     |{self.comparison[i]}")
            else:
                print(f"{i}\t| Empty")


class HashTableQuadraticProbing:
    def __init__(self, size=10):
        self.ht = [None] * size
        self.size = size
        self.comparison = [0] * size
        

    def insert_data(self, person):
        comp=0
        index = hash_key(person.telephone_number, self.size)
        original_index = index
        if self.ht[index] is None:
            comp+=1
            self.ht[index] = person
            self.comparison[index]=comp
            print(f"Name: {person.name} entered with telephone num: {person.telephone_number} with comparison {comp}")
        else:
            comp=1
            i=1
            while self.ht[index] is not None:
                comp+=1
                index =(original_index+i*i)%self.size
                i=i+1
            self.ht[index] = person
            self.comparison[index]=comp
            print(f"Name: {person.name} entered with telephone num: {person.telephone_number} with comparison {comp}")

    def search_data(self, telephone):
        index = hash_key(telephone, self.size)
        original_index = index
        i = 0
        while self.ht[index] is not None:
            if self.ht[index].telephone_number == telephone:
                print(f"Number {telephone} found with name {self.ht[index].name} at Index: {index}")
                return True
            i += 1
            index = (original_index + i*i) % self.size
            if index == original_index:
                print(f"Number {telephone} not found in the hash table.")
                return False
        print(f"Number {telephone} not found in the hash table.")
        return False

    def delete_data(self, telephone):
        index = hash_key(telephone, self.size)
        original_index = index
        i = 0
        while self.ht[index] is not None:
            if self.ht[index].telephone_number == telephone:
                self.ht[index] = None
                return True
            i += 1
            index = (index + i*i) % self.size
            if index == original_index:
                print(f"Number {telephone} not found in the hash table.")
                return False
        print(f"Number {telephone} not found in the hash table.")
        return False

    def display(self):
        print(f"Index\t| Name: \t\t| Telephone Number:      |Comparisons")
        for i in range(self.size):
            if self.ht[i] is not None:
                print(f"{i}\t| {self.ht[i].name} \t|  {self.ht[i].telephone_number}     |{self.comparison[i]}")
            else:
                print(f"{i}\t| Empty")

def main():
    running = True
    while running:
        print("----------------------------------------------------------")
        print("1. Linear Probing\n2. Quadratic Probing\n3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            h1 = HashTableLinearProbing(10)
            running1 = True
            while running1:
                print("----------------------------------------------------------")
                print("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit")
                choice1 = int(input("Enter your choice: "))

                if choice1 == 1:
                    n = int(input("Enter number of persons: "))
                    for _ in range(n):
                        person = Person()
                        person.set_data()
                        h1.insert_data(person)
                elif choice1 == 2:
                    telenum = int(input("Enter telephone number to search: "))
                    if not h1.search_data(telenum):
                        print("Not Found")
                elif choice1 == 3:
                    telenum = int(input("Enter telephone number to delete: "))
                    if not h1.delete_data(telenum):
                        print("Not Found")
                elif choice1 == 4:
                    h1.display()
                elif choice1 == 5:
                    running1 = False
                else:
                    print("Enter valid choice.")
        elif choice == 2:
            h2 = HashTableQuadraticProbing(10)
            running1 = True
            while running1:
                print("----------------------------------------------------------")
                print("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit")
                choice1 = int(input("Enter your choice: "))

                if choice1 == 1:
                    n = int(input("Enter number of persons: "))
                    for _ in range(n):
                        person = Person()
                        person.set_data()
                        h2.insert_data(person)
                elif choice1 == 2:
                    telenum = int(input("Enter telephone number to search: "))
                    if not h2.search_data(telenum):
                        print("Not Found")
                elif choice1 == 3:
                    telenum = int(input("Enter telephone number to delete: "))
                    if not h2.delete_data(telenum):
                        print("Not Found")
                elif choice1 == 4:
                    h2.display()
                elif choice1 == 5:
                    running1 = False
                else:
                    print("Enter valid choice.")
        elif choice == 3:
            running = False
        else:
            print("Please enter valid choice.")


if __name__ == "__main__":
    main()
-----------------------------------------------------------------------------------------------------------------

  PRA 2:-
  MAX = 10  # Define maximum size for the hash table

class WOChain:
    def __init__(self):
        self.a = [[-1, -1] for _ in range(MAX)]  # Initialize the hash table with -1
    
    def hash_key(self, num):
        key = num % 10
        return key
    
    def chain(self, key, num):
        flag = False
        count = sum(1 for i in self.a if i[0] != -1)  # Count number of filled slots
        
        if count == MAX:
            print("\nHash Table Is Full")
            self.display()
            exit(1)
        
        if self.a[key][0] == -1:
            self.a[key][0] = num
        else:
            ch = self.a[key][1]  # Get the chain index
            if ch == -1:
                # Linear probing in the table if the chain is not yet established
                for i in range(key + 1, MAX):
                    if self.a[i][0] == -1:
                        self.a[i][0] = num
                        self.a[key][1] = i
                        flag = True
                        break
            
            # If there are already numbers in the chain, traverse it to find the next empty slot
            else:
                while self.a[ch][0] != -1 and self.a[ch][1] != -1:
                    ch = self.a[ch][1]
                
                for i in range(ch + 1, MAX):
                    if self.a[i][0] == -1:
                        self.a[i][0] = num
                        self.a[ch][1] = i
                        flag = True
                        break
                
                # If no slot found, search from the beginning of the array
                if not flag:
                    if ch == -1:
                        for i in range(0, key):
                            if self.a[i][0] == -1:
                                self.a[i][0] = num
                                self.a[key][1] = i
                                flag = True
                                break
                    
                    else:
                        while self.a[ch][0] != -1 and self.a[ch][1] != -1:
                            ch = self.a[ch][1]
                        
                        for i in range(ch + 1, key):
                            if self.a[i][0] == -1:
                                self.a[i][0] = num
                                self.a[ch][1] = i
                                flag = True
                                break
    
    def display(self):
        print("\nThe Hash Table is...")
        for i in range(MAX):
            print(f"  {i} {self.a[i][0]} {self.a[i][1]}")

# Main function to drive the program
def main():
    h = WOChain()
    
    n=int(input("\n Number of elements you want to insert into HT"))
    if n<=MAX:
    	for i in range(0,n):
        	num = int(input("\nEnter The Number: "))
        	key = h.hash_key(num)
        	h.chain(key, num)
    
    	h.display()
    else:
    	print("hash table size=10");

if __name__ == "__main__":
    main()
  -------------------------------------------------------------------------------------------------------------------
PRA 3:-
  #include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;         
    Node* nextSibling;   
    Node* firstChild;    
    
    
    Node(string value)
     {
        data = value;
        nextSibling = nullptr;
        firstChild = nullptr;
    }
};


void insertChild(Node* parent, string childData)
{
    Node* child = new Node(childData);
    if (!parent->firstChild)
    {
        parent->firstChild = child;  
    } 
    else
    {
        Node* temp = parent->firstChild;
        while (temp->nextSibling)
        {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void displayTree(Node* node, int level = 0) {
    if (node == nullptr) return;
       for (int i = 0; i < level; i++)
    {
        cout << "\t";
    
    cout <<i<< node->data << endl;
    }

    displayTree(node->firstChild, level + 1);
    displayTree(node->nextSibling, level);
}


void deleteTree(Node* node)
 {
    if (node == nullptr) return;

    deleteTree(node->firstChild);

    deleteTree(node->nextSibling);

    delete node;
}

int main()
{
    string bookTitle;
    cout << "Enter the title of the book: ";
    getline(cin, bookTitle);

    Node* book = new Node(bookTitle);
    int numChapters;
    cout << "Enter the number of chapters in the book: ";
    cin >> numChapters;
    cin.ignore();  

    for (int i = 0; i < numChapters; i++)
     {
        string chapterTitle;
        cout << "Enter the title of chapter " << (i + 1) << ": ";
        getline(cin, chapterTitle);

        insertChild(book, chapterTitle);

        int numSections;
        cout << "Enter the number of sections in chapter " << chapterTitle << ": ";
        cin >> numSections;
       // cin.ignore();precedance 


        Node* chapterNode = book->firstChild;
        while (chapterNode) {
            if (chapterNode->data == chapterTitle)
             {
                for (int j = 0; j < numSections; j++)
                 {// section
                    string sectionTitle;
                    cout << "Enter the title of section " << (j + 1) << " in chapter " << chapterTitle << ": ";
                    getline(cin, sectionTitle);

                    
                    insertChild(chapterNode, sectionTitle);

                    int numSubsections;
                    cout << "Enter the number of subsections in section " << sectionTitle << ": ";
                    cin >> numSubsections;
                    cin.ignore();  
                    //subsection
                    Node* sectionNode = chapterNode->firstChild;
                    while (sectionNode)
                    {
                        if (sectionNode->data == sectionTitle)
                        {
                            for (int k = 0; k < numSubsections; k++)
                            {
                                string subsectionTitle;
                                cout << "Enter the title of subsection " << (k + 1) << " in section " << sectionTitle << ": ";
                                getline(cin, subsectionTitle);

                             insertChild(sectionNode, subsectionTitle);
                            }
                            break;
                        }
                        sectionNode = sectionNode->nextSibling;
                    }
                }
                break;
            }
            chapterNode = chapterNode->nextSibling;
        }
    }

    // Display the book structure
    cout << "\nBook structure:\n";
    displayTree(book);

    //   deleteTree(book);

    return 0;
}
  ------------------------------------------------------------------------------------------------------------------

PRA4 ;- Create a binary search tree from an empty tree by inserting values in a given order. Then, perform operations like 
inserting a new node, finding the number of nodes in the longest path, finding the minimum data value, swapping 
left and right pointers, and searching for a value.\ 
(Binary Search Tree) 


#include<iostream>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }

    friend class BST;
};
class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }
    node* insert(node* n, int value)
    {
        if (n == nullptr)
        {
            return new node(value); 
        }
        if (value < n->data)
        {
            n->left = insert(n->left, value);  
        }
        else
        {
            n->right = insert(n->right, value); 
        }
        return n; 
    }
   void insertAtRoot(int value) {
        root = insert(root, value); 
    }
    void inorder(node* n)
    {
        if (n == nullptr) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
    void display()
    {
        inorder(root);
        cout << endl;
    }
    int longestPath(node* n)
    {
        if (n == nullptr)
        {
            return 0;  
        }
        int leftHeight = longestPath(n->left);  
        int rightHeight = longestPath(n->right); 

        return max(leftHeight, rightHeight) + 1;  
    }
    int getLongestPath()
    {
        return longestPath(root);  
    }
    int findMinValue(node* n)
    {
        if (n == nullptr)
        {
            cout << "Tree is empty!" << endl;
            return -1;  
        }
        while (n->left != nullptr)
        {
            n = n->left;  
        }
        return n->data;
    }
    int getMinValue()
    {
        return findMinValue(root); 
    }
    void swapChildren(node* n)
    {
        if (n == nullptr) return;

        node* temp = n->left;
        n->left = n->right;
        n->right = temp;
        swapChildren(n->left);
        swapChildren(n->right);
    }
    void swapChildrenFromRoot()
    {
        swapChildren(root); 
    }
    bool search(node* n, int value)
     {
        if (n == nullptr) 
        {
            return false;  
        }
        if (n->data == value) 
        {
            return true;  
        }
        if (value < n->data)
        {
            return search(n->left, value);  
        } 
        else
        {
            return search(n->right, value); 
        }
    }
    bool searchFromRoot(int value) 
    {
        return search(root, value);  
    }
};
int main() 
{
    BST tree;
    int no, value;
    cout << "Enter number of nodes to insert into BST: ";
    cin >> no;
    cout << "Enter values to insert: ";
    for (int i = 0; i < no; i++)
    {
        cin >> value;
        tree.insertAtRoot(value);
    }
    cout << "BST in-order traversal: ";
    tree.display();
    cout << "Longest path from root (height): " << tree.getLongestPath() << endl;
    cout << "Minimum value in the tree: " << tree.getMinValue() << endl;
    tree.swapChildrenFromRoot();
    cout << "BST after swapping left and right children: ";
    tree.display();
    cout << "Enter value to search: ";
    cin >> value;
    if (tree.searchFromRoot(value))
    {
         cout << "Value " << value << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << value << " not found in the tree." << endl;
    }
    return 0;
}
  ------------------------------------------------------------------------------------------------------------------
PRA5 :-Construct an expression tree from a given prefix expression and traverse it using post order traversal (non
recursive). Then, delete the entire tree. 
(Expression Tree Construction) 


#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* newNode(char data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
TreeNode* constructExpressionTree(string prefix) {
    stack<TreeNode*> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c) || isalpha(c)) {
            TreeNode* node = newNode(c);
            s.push(node);
        }
        else {
            TreeNode* node = newNode(c);
            node->left = s.top();
            s.pop();
            node->right = s.top();
            s.pop();
            s.push(node);
        }
    }
    return s.top();
}
void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* lastNodeVisited = NULL;
    while (!s.empty() || root != NULL) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            TreeNode* peekNode = s.top();
            if (peekNode->right != NULL && lastNodeVisited != peekNode->right) root = peekNode->right;
            else {
                cout << peekNode->data << " ";
                lastNodeVisited = peekNode;
                s.pop();
            }
        }
    }
}
void deleteTree(TreeNode* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    int choice;
    string prefix;
    TreeNode* root = NULL;
    do {
        cout << "Menu" << endl;
        cout << "1. Enter prefix expression" << endl;
        cout << "2. Postorder traversal" << endl;
        cout << "3. Delete tree" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter prefix expression: ";
                cin.ignore();
                getline(cin, prefix);
                root = constructExpressionTree(prefix);
                break;
            case 2:
                if (root == NULL) cout << "Tree not constructed yet" << endl;
                else {
                    cout << "Postorder traversal of expression tree: ";
                    postorderTraversal(root);
                    cout << endl;
                }
                break;
            case 3:
                if (root == NULL) cout << "Tree not constructed yet" << endl;
                else {
                    deleteTree(root);
                    root = NULL;
                    cout << "Tree deleted" << endl;
                }
                break;
            case 4:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}
  -----------------------------------------------------------------------------------------------------------------
PRA6:-  Represent a graph using adjacency matrix/list to perform Depth-First Search (DFS) and adjacency list to perform 
Breadth-First Search (BFS). Use a map of the area around a college as the graph, identifying prominent landmarks 
as nodes. 
(Graph Representation Algorithm) 

#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, m, qu[10], front = 0, rear = 0, v, visited[10], visit[10];
int stk[10], top = 0, visit1[10], visited1[10];

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    // Initialize adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost[i][j] = 0;
        }
    }

    // Read edges
    cout << "\nEDGES:\n";
    for (k = 0; k <= m-1; k++) {
        cout << "Enter edge " << k << " (in the format: vertex1 vertex2): ";
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;  // Because the graph is undirected
    }

    // Display adjacency matrix
    cout << "The adjacency matrix of the graph is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    // BFS
    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    cout << "The BFS of the Graph is: \n";
    cout << v << " ";
    visited[v] = 1;
    k = 0;
    while (k < n) {
        for (j = 0; j < n; j++) {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1) {
                visit[j] = 1;
                qu[rear++] = j;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
    cout << endl;

    // DFS
    cout << "Enter initial vertex for DFS: ";
    cin >> v;
    cout << "The DFS of the Graph is: \n";
    cout << v << " ";
    visited1[v] = 1;
    k = 0;
    stk[top++] = v;
    while (k < n) {
        for (j = n - 1; j >= 0; j--) {
            if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1) {
                visit1[j] = 1;
                stk[top++] = j;
            }
        }
        v = stk[--top];
        cout << v << " ";
        k++;
        visit1[v] = 0;
        visited1[v] = 1;
    }
    cout << endl;

    return 0;
}
  -------------------------------------------------------------------------------------------------------------

  PRA7 :-Represent a graph of flight paths between cities, where the cost of an edge is the time or fuel used for the journey. 
Use adjacency list or matrix representation and check if the graph is connected. Justify the storage representation 
used. 
(Flight Path Graph) 


  
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_CITIES = 100;

struct Flight {
    string source;
    string destination;
    int cost;
};
class Graph {
public:
    int adjList[MAX_CITIES][MAX_CITIES];
    int numCities;
    Graph() {
        numCities = 0;
        memset(adjList, 0, sizeof(adjList));
    }
    void addFlight(Flight flight) {
        int sourceIndex = getCityIndex(flight.source);
        int destIndex = getCityIndex(flight.destination);
        adjList[sourceIndex][destIndex] = flight.cost;
    }
    // Check if the graph is connected using BFS
    bool isConnected() {
        bool visited[MAX_CITIES];
        memset(visited, false, sizeof(visited));
        // Start BFS from any vertex
        int start = 0;
        visited[start] = true;
        for (int i = 0; i < numCities; i++) {
            if (adjList[start][i] > 0 && !visited[i]) {
                visited[i] = true;
            }
        }
        for (int i = 1; i < numCities; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

private:
    int getCityIndex(string city) {
        for (int i = 0; i < numCities; i++) {
            if (city == cities[i]) {
                return i;
            }
        }
        cities[numCities] = city;
        numCities++;
        return numCities - 1;
    }
    // Array to store names of cities
    string cities[MAX_CITIES];
};

int main()
{
    Graph g;
    int choice;
    Flight flight;
    do {
        cout << "\n1. Add a flight\n2. Check if graph is connected\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nEnter source city: ";
            cin >> flight.source;
            cout << "Enter destination city: ";
            cin >> flight.destination;
            cout << "Enter cost of flight: ";
            cin >> flight.cost;
            g.addFlight(flight);
            break;
        case 2:
            if (g.isConnected())
                cout << "\nGraph is connected";
            else
                cout << "\nGraph is not connected";
            break;
        case 3:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice";
            break;
        }
    } while (choice != 3);
    return 0;
}
  ---------------------------------------------------------------------------------------------------------
  PRA 8: - Given a sequence of sorted keys with search probabilities, build a binary search tree with the least search cost. 
Consider the access probability for each key. 
(Binary Search Optimization) 


#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void printTree(int root[][MAX], int i, int j, int parent, bool isLeft)
{
    if (i > j)
        return;
    int r = root[i][j];
    if (parent == -1)
        cout << "K" << r << " is the root" << endl;
    else if (isLeft)
        cout << "K" << r << " is the left child of K" << parent << endl;
    else
        cout << "K" << r << " is the right child of K" << parent << endl;
    printTree(root, i, r - 1, r, true);
    printTree(root, r + 1, j, r, false);
}

void optimalBST(float prob[], int n)
{
    float cost[MAX][MAX] = {0};
    int root[MAX][MAX] = {0};

    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = prob[i - 1];
        root[i][i] = i;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            float sum = 0;
            for (int s = i; s <= j; s++)
            {
                sum += prob[s - 1];
            }

            for (int r = i; r <= j; r++)
            {
                float c = 0;
                if (r > i)
                    c += cost[i][r - 1];
                if (r < j)
                    c += cost[r + 1][j];
                c += sum;

                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << "\nMinimum cost of Optimal BST: " << cost[1][n] << endl;
    cout << "Root of the Optimal BST: K" << root[1][n] << endl;
    cout << "\nStructure of Optimal BST:\n";
    printTree(root, 1, n, -1, false);
}

int main()
{
    int n;
    float prob[MAX];

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter probabilities for each key (in sorted order):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> prob[i];
    }

    optimalBST(prob, n);
    return 0;
}
  ----------------------------------------------------------------------------------------------------
 PRA 9:- Create a dictionary that stores keywords and their meanings. Provide facilities for adding, deleting, and updating 
entries, as well as displaying the data in sorted order. Use a height-balanced tree and analyze the complexity of 
finding a keyword. 
(Dictionary Management System) 



#include <iostream>
#include <string>
#include <map>
#include <limits>
using namespace std;
class Dictionary {
public:
    void addKeyword(const string& keyword, const string& meaning) {
        data[keyword] = meaning;
    }
    void deleteKeyword(const string& keyword) {
        data.erase(keyword);
    }
    void updateKeyword(const string& keyword, const string& newMeaning) {
        data[keyword] = newMeaning;
    }
    void displayAscending() const {
        map<string, string>::const_iterator it;
        for (it = data.begin(); it != data.end(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
    }
    void displayDescending() const {
        map<string, string>::const_reverse_iterator it;
        for (it = data.rbegin(); it != data.rend(); ++it) {
            cout << it->first << ": " << it->second << endl;
        }
    }
    int getMaxComparisons(const string& keyword) const {
        int count = 0;
        map<string, string>::const_iterator it;
        for (it = data.begin(); it != data.end(); ++it) {
            ++count;
            if (it->first == keyword) return count;
        }
        return count; // Keyword not found
    }
private:
    map<string, string> data;
};
// Helper functions
void printMenu() {
    cout << "\nDictionary Menu\n"
         << "1. Add keyword\n"
         << "2. Delete keyword\n"
         << "3. Update keyword\n"
         << "4. Display ascending\n"
         << "5. Display descending\n"
         << "6. Find max comparisons\n"
         << "7. Exit\n"
         << "Enter your choice: ";
}
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
string inputLine(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}
int main() {
    Dictionary dict;
    int choice;
    do {
        printMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        clearInputBuffer(); // Clean up newline
        string keyword, meaning;
        switch (choice) {
            case 1:
                keyword = inputLine("Enter keyword: ");
                meaning = inputLine("Enter meaning: ");
                dict.addKeyword(keyword, meaning);
                break;
            case 2:
                keyword = inputLine("Enter keyword to delete: ");
                dict.deleteKeyword(keyword);
                break;
            case 3:
                keyword = inputLine("Enter keyword to update: ");
                meaning = inputLine("Enter new meaning: ");
                dict.updateKeyword(keyword, meaning);
                break;
            case 4:
                cout << "\n--- Dictionary (Ascending Order) ---\n";
                dict.displayAscending();
                break;
            case 5:
                cout << "\n--- Dictionary (Descending Order) ---\n";
                dict.displayDescending();
                break;
            case 6:
                keyword = inputLine("Enter keyword to search: ");
                cout << "Max comparisons for '" << keyword << "': "
                     << dict.getMaxComparisons(keyword) << endl;
                break;
            case 7:
                cout << "Exiting... Goodbye!\n"<<endl;
        }
    }
    while(choice != 7);
    return 0;
}
  ---------------------------------------------------------------------------------------------------------------
  
PRA10:-  Read the marks obtained by students in an online examination and find the maximum and minimum marks using 
a heap data structure. Analyze the algorithm. 
(Marks Sorting Algorithm) 


#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2;// right = 2*i + 2

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;     
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[n], maxHeap[n], minHeap[n];
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        maxHeap[i] = marks[i];
        minHeap[i] = marks[i];
    }
    buildMaxHeap(maxHeap, n);
    buildMinHeap(minHeap, n);
    cout << "\nMaximum marks: " << maxHeap[0] << endl;
    cout << "Minimum marks: " << minHeap[0] << endl;

    return 0;
}
  ---------------------------------------------------------------------------------------------------------------------
   PRA11=      Maintain a student information system using a sequential file, allowing users to add, delete, and display 
information. Handle cases where a student's record does not exist. 
(Student Information System) 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string roll_no, name, division, address;
};

void addStudent() {
    ofstream file("student_data.txt", ios::app);
    Student s;

    cout << "Enter Roll No: ";
    cin >> s.roll_no;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Division: ";
    cin >> s.division;
    cout << "Enter Address: ";
    cin >> s.address;

    file << s.roll_no << "," << s.name << "," << s.division << "," << s.address << endl;
    file.close();

    cout << "Student information added successfully.\n";
}

void deleteStudent() {
    ifstream file("student_data.txt");
    ofstream temp("temp.txt");

    string roll_no;
    bool found = false;
    cout << "Enter Roll No to delete: ";
    cin >> roll_no;

    string line;
    while (getline(file, line)) {
        if (line.find(roll_no) != 0) {
            temp << line << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();
    remove("student_data.txt");
    rename("temp.txt", "student_data.txt");

    if (found) {
        cout << "Student information deleted successfully.\n";
    } else {
        cout << "Student record not found.\n";
    }
}

void displayStudent() {
    ifstream file("student_data.txt");
    string roll_no;
    bool found = false;

    cout << "Enter Roll No to search: ";
    cin >> roll_no;

    string line;
    while (getline(file, line)) {
        if (line.find(roll_no) == 0) {
            cout << "Student Details: " << line << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student record not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- Student Record System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: displayStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 4);

    return 0;
}
  -------------------------------------------------------------------------------------------------------------
PRA12:-  Maintain an employee information system using an index sequential file, allowing users to add, delete, and display 
information. Handle cases where an employee's record does not exist. 
(Employee Data Management)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Employee {
    string id, name, designation;
    float salary;
};

vector<Employee> employees;

void loadEmployees() {
    ifstream file("employee_data.txt");
    string line;
    employees.clear();

    while (getline(file, line)) {
        stringstream ss(line);
        Employee e;
        getline(ss, e.id, ',');
        getline(ss, e.name, ',');
        getline(ss, e.designation, ',');
        ss >> e.salary;
        employees.push_back(e);
    }

    file.close();
}

void saveEmployees() {
    ofstream file("employee_data.txt");

    for (const auto& e : employees) {
        file << e.id << "," << e.name << "," << e.designation << "," << e.salary << endl;
    }

    file.close();
}

void addEmployee() {
    Employee e;

    cout << "Enter Employee ID: ";
    cin >> e.id;

    cout << "Enter Name: ";
    cin >> e.name;

    cout << "Enter Designation: ";
    cin >> e.designation;

    cout << "Enter Salary: ";
    cin >> e.salary;

    employees.push_back(e);

    // Sort employees by ID
    sort(employees.begin(), employees.end(), [](Employee a, Employee b) {
        return a.id < b.id;
    });

    saveEmployees();
    cout << "Employee information added successfully.\n";
}

void deleteEmployee() {
    string empId;
    bool found = false;

    cout << "Enter Employee ID to delete: ";
    cin >> empId;

    auto it = remove_if(employees.begin(), employees.end(), [&](Employee e) {
        return e.id == empId;
    });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        found = true;
    }

    saveEmployees();

    if (found)
        cout << "Employee information deleted successfully.\n";
    else
        cout << "Employee record not found.\n";
}

void displayEmployee() {
    string empId;
    bool found = false;

    cout << "Enter Employee ID to search: ";
    cin >> empId;

    for (const auto& e : employees) {
        if (e.id == empId) {
            cout << "ID: " << e.id
                 << ", Name: " << e.name
                 << ", Designation: " << e.designation
                 << ", Salary: " << e.salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee record not found.\n";
}

int main() {
    loadEmployees();

    int choice;
    do {
        cout << "\n----- Employee Record System -----\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: displayEmployee(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }

    } while (choice != 4);

    return 0;
}
