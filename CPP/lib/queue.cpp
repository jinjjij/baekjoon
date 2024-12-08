template <typename T>
class queue {
    
    private:
        typedef struct _qnode{
            T* node;
            struct _qnode* next;
            struct _qnode* prev;
        } qnode;

        int size;
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
        queue(void){
            this->size = 0;
            this->front = NULL;
            this->rear = NULL;
        }

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