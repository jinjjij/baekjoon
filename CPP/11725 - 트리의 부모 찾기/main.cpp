#include <iostream>
#include <vector>


typedef struct _node{
    struct _node* parent;
    int index;
    std::vector<struct _node*> child;
} node;


node* MakeNode(int index){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->index = index;
    newnode->parent = NULL;
}


void FreeNode(node* n){
    for(int i=0;i<n->child.size();i++){
        FreeNode(n->child[i]);
    }
    free(n);
}


typedef struct _pair{
    int x; int y;
} pair;

template <typename T>
class queue {
    
    private:
        typedef struct _qnode{
            T* node;
            struct _qnode* next;
            struct _qnode* prev;
        } qnode;

        
        qnode* front;
        qnode* rear;

        qnode* _makeQnode(T* node){
            qnode* newQnode = (qnode*)malloc(sizeof(qnode));
            newQnode->next = NULL;
            newQnode->prev = NULL;
            newQnode->node = node;
            return newQnode;
        }


    public:
        int size;
        queue(void){
            this->size = 0;
            this->front = NULL;
            this->rear = NULL;
        }
        /*
            put item infront of queue
            if successful -> return size of queue
            if fail -> return error code
        */

        int enQueue(T* node){
            qnode* qnode = _makeQnode(node);

            if(this->size == 0){
                this->front = qnode;
                this->rear = qnode;
            }else{
                qnode->next = this->front;
                qnode->prev = NULL;
                this->front->prev = qnode;
                this->front = qnode;
            }
            size++;
            return size;
        }

        T* deQueue(void){
            qnode* qnode = this->rear;
            size--;
            if(size == 0){
                this->front = NULL;
                this->rear = NULL;
            }else{
                this->rear = qnode->prev;
                this->rear->next = NULL;
            }

            T* node = qnode->node;
            free(qnode);
            return node;
        }

        void ClearQueue(void){
            if(size == 0){
                return;
            }
            qnode* cur = this->front;
            while(cur != NULL){
                qnode* next = cur->next;
                free(cur);
                cur = next;
            }
            this->front = NULL;
            this->rear = NULL;
        }

        void TraverseQueue(void (*func)(T* node)){
            if(size == 0){
                return;
            }
            qnode* cur = this->front;
            while(cur != NULL){
                func(cur->node);
                cur = cur->next;
            }
        }
};


void temp(int* a){
    std::cout << *a << " ";
}


void trav_print(pair* p){
    fprintf(stderr, "(%d, %d) ", p->x, p->y);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    int p, c;

    queue <pair> Q;

    for(int i=1;i<N;i++){
        std::cin >> p >> c;
        pair* newpair = (pair*)malloc(sizeof(pair));
        if(p>c){
            int t = p;
            p = c;
            c = t;
        }
        newpair->x = p;
        newpair->y = c;
        Q.enQueue(newpair);
    }

    pair* cur;
    node** nodearr = (node**)malloc(sizeof(node*) * (N+1));
    for(int i=0;i<N+1;i++){
        nodearr[i] = NULL;
    }
    nodearr[1] = MakeNode(1);

    while(1){
        cur = Q.deQueue();
        fprintf(stderr, "debug : (%d, %d)\n", cur->x, cur->y);
        fprintf(stderr, "trav : (%d) ", Q.size);
        Q.TraverseQueue(trav_print);
        fprintf(stderr, "\n");

        // if x = 1 -> root node;
        // add to root as a child
        if(cur->x == 1){
            fprintf(stderr,"1\n");
            node* newnode = MakeNode(cur->y);
            nodearr[cur->y] = newnode;
            nodearr[1]->child.push_back(newnode);
            free(cur);
        }
        // if x != 1 and pre-existing node
        // -> add as a child
        else if(nodearr[cur->x] != NULL){
            fprintf(stderr,"2\n");
            node* newnode = MakeNode(cur->y);
            nodearr[cur->y] = newnode;
            nodearr[cur->x]->child.push_back(newnode);
            free(cur);
        }else if(nodearr[cur->y] != NULL){
            fprintf(stderr,"3\n");
            node* newnode = MakeNode(cur->x);                       fprintf(stderr,"3-1\n");
            if(nodearr[cur->x]==NULL)   nodearr[cur->x] = newnode;  fprintf(stderr,"3-2\n");
            nodearr[cur->y]->child.push_back(newnode);              fprintf(stderr,"3-3\n");
            free(cur);                                              fprintf(stderr,"3-4\n");
        }
        // if x != 1 and not existing node
        // -> skip (enqueue)
        else{
            fprintf(stderr,"4\n");
            Q.enQueue(cur);
        }
        fprintf(stderr,"pre - breakpoint\n");
        if(Q.size == 0){
            fprintf(stderr,"breakpoint\n");
            break;
        }fprintf(stderr,"post - breakpoint\n");
    }

    fprintf(stderr,"outofloop\n");

    for(int i=1;i<N+1;i++){
        if(nodearr[i] == NULL){
            std::cout << "NULL\n";
        }else{
            std::cout << nodearr[i]->parent->index << "\n";
        }

    }

    FreeNode(nodearr[1]);
    free(nodearr);
    return 0;
}
