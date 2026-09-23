class BrowserHistory {
public:
    struct Node {
        string url;
        Node* prev;
        Node* next;

        Node(string u) {
            url = u;
            prev = NULL;
            next = NULL;
        }
    };

    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

    current->next = newNode;
                  newNode->prev = current;
        current = newNode;
            }
    string back(int steps) {
        while (steps > 0 && current->prev != NULL) {
            current = current->prev;
            steps--;
        }
        return current->url;    }
    string forward(int steps) {
        while (steps > 0 && current->next != NULL) {
        current = current->next;
         steps--;
        }

        return current->url;
    }
};