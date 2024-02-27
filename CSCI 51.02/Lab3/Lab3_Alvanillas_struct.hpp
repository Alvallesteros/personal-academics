using namespace std;

struct IntNode {
    private:
        int Intdata;
        IntNode* nextNode;

    public:

        //Constructor
        IntNode(int i) {
            Intdata = i;
            this->nextNode = nullptr;
        }

        //Contrsuctor with Node
        IntNode(int i, IntNode* node) {
            Intdata = i;
            this->nextNode = node;
        }

        // Getters
        int getData() {
            return Intdata;
        }

        IntNode* getNextNode() {
            return nextNode;
        }

        //Setters
        void setData(int i) {
            Intdata = i;
        }

        void setNextNode(IntNode* node) {
            this->nextNode = node;
        }
};

struct LinkedList {
    private:
        IntNode* head;
        IntNode* tail;

    public:
        //Constructors
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void appendNode(IntNode* node) {
            if(this->head == nullptr) {
                this->head = node;
                this->tail = head;
            } else { 
                this->tail = head;
                while(tail->getNextNode() != nullptr) {
                    tail = tail->getNextNode();
                }
                tail->setNextNode(node);
                this->tail = node;
            }
        }

        void traverseList() {
            IntNode* current = head;
            int cnt = 0;
            while(current != nullptr) {
                cout << "Node " << cnt << ": " << current->getData() << " " << endl;
                current = current->getNextNode();
                cnt++;
            }
            delete current;
        }

        //Getters
        IntNode* getHeadNode() {
            return head;
        }

        IntNode* getTailNode() {
            return tail;
        }

        //Setters
        void setHeadNode(IntNode* node) {
            this->head = node;
        }

        void setTailNode(IntNode* node) {
            this->tail = node;
        }
};

struct IntStack {
    private:
        LinkedList* lnklst;

    public:
        IntStack() {
            this->lnklst = new LinkedList();
        }

        //Functions
        void push(IntNode* node) {
            this->lnklst->appendNode(node);
        }

        void traverse() {
            this->lnklst->traverseList();
        }

        IntNode* pop() {
            IntNode* temp = this->lnklst->getHeadNode();
            IntNode* tail = this->lnklst->getTailNode();
            while(temp->getNextNode() != tail) {
                temp = temp->getNextNode();
            }
            temp->setNextNode(nullptr);
            this->lnklst->setTailNode(temp);
            return tail;
        }

        //Getter
        LinkedList* getLinkedList() {
            return this->lnklst;
        }
};