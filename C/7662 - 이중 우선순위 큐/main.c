// https://www.acmicpc.net/problem/7662 - 이중 우선순위 큐

/*

문제
이중 우선순위 큐(dual priority queue)는 전형적인 우선순위 큐처럼 데이터를 삽입, 삭제할 수 있는 자료 구조이다.
전형적인 큐와의 차이점은 데이터를 삭제할 때 연산(operation) 명령에 따라 
우선순위가 가장 높은 데이터 또는 가장 낮은 데이터 중 하나를 삭제하는 점이다. 
이중 우선순위 큐를 위해선 두 가지 연산이 사용되는데,
하나는 데이터를 삽입하는 연산이고 다른 하나는 데이터를 삭제하는 연산이다.
데이터를 삭제하는 연산은 또 두 가지로 구분되는데 하나는 우선순위가 가장 높은 것을 삭제하기 위한 것이고
다른 하나는 우선순위가 가장 낮은 것을 삭제하기 위한 것이다. 

정수만 저장하는 이중 우선순위 큐 Q가 있다고 가정하자. Q에 저장된 각 정수의 값 자체를 우선순위라고 간주하자. 

Q에 적용될 일련의 연산이 주어질 때 이를 처리한 후 최종적으로 
Q에 저장된 데이터 중 최댓값과 최솟값을 출력하는 프로그램을 작성하라.

입력
입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다. 
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다. 
이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다. 
‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다. 동일한 정수가 삽입될 수 있음을 참고하기 바란다. 
‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, 
‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다. 
최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.

만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다. Q에 저장될 모든 정수는 32-비트 정수이다. 

출력
출력은 표준출력을 사용한다. 각 테스트 데이터에 대해, 
모든 연산을 처리한 후 Q에 남아 있는 값 중 최댓값과 최솟값을 출력하라.
두 값은 한 줄에 출력하되 하나의 공백으로 구분하라. 만약 Q가 비어있다면 ‘EMPTY’를 출력하라.

*/


#include <stdio.h>
#include <stdlib.h>


int T;      // 입력 데이터의 수를 나타내는 정수 T
int k;      // Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)


// AVL tree structures / functions
typedef struct _node{
    int data;
    int height;
    struct _node* left;
    struct _node* right;
} Node;


typedef struct _tree{
    Node* root;
} Tree;


Node* createNode(int data);
Tree* createTree(void);

void AVLdelete(Tree* tree, Node* pre, Node* delnode);
void AVLinsert(Tree* tree, int data);

void destroyNode(Node* node);
void destroyTree(Tree* tree);


Node* _findMinandPre(Node* node, Node** pre);
Node* _findMaxandPre(Node* node, Node** pre);

void traverse(Tree* tree);

int main(void)
{
    FILE* readMod;

    readMod = stdin;

    // test
    readMod = fopen("input.txt", "rt");

    fscanf(readMod, "%d", &T);


    for(int t=0; t<T; t++){
        
        Tree* tree = createTree();

        fscanf(readMod, "%d", &k);

        
        char inputC;
        int inputI;

        for(int i=0;i<k;i++){
            fscanf(readMod, " %c %d", &inputC, &inputI);
            printf("\n>> %c : %d <<\n", inputC, inputI);

            if(inputC == 'I'){
                AVLinsert(tree, inputI);
            }

            if(inputC == 'D' && inputI == 1){       // 최댓값 삭제
                Node* temppre = NULL;
                Node* targetNode = _findMaxandPre(tree->root,&temppre);
                if(targetNode != NULL){
                    AVLdelete(tree, temppre, targetNode);
                }else{
                    if(tree->root != NULL){
                        printf("Error in (D 1)\n");
                    }
                }
            }

            if(inputC == 'D' && inputI == -1){      // 최솟값 삭제
                Node* temppre = NULL;
                Node* targetNode = _findMinandPre(tree->root, &temppre);


                if(targetNode != NULL){
                    AVLdelete(tree, temppre, targetNode);
                }else{
                    if(tree->root != NULL){
                        printf("Error in (D -1)\n");
                    }
                }
            }
            
            traverse(tree);
        }

        destroyTree(tree);
    }

    // test
    fclose(readMod);

    return 0;
}


Node* createNode(int data)
{
    Node* newnode = malloc(sizeof(Node));
    newnode->data   = data;
    newnode->height = 0;
    newnode->left   = NULL;
    newnode->right  = NULL;

    return newnode;
}


Tree* createTree(void)
{
    Tree* newTree = malloc(sizeof(Tree));
    newTree->root = NULL;

    return newTree;
}


Node* _srch(Node* node, Node** pre, int key)
{
    if(node->data == key){
        return node;
    }else if(node->left != NULL){
        *pre = node;
        return _srch(node->left, pre, key);
    }else if(node->right != NULL){
        *pre = node;
        return _srch(node->right,pre, key);
    }else{
        return NULL;
    }
}


Node* search(Tree* tree, Node** pre, int key)
{
    if(tree->root == NULL)
        return NULL;
    
    *pre = NULL;
    return _srch(tree->root, pre, key);
}


Node* _findMinandPre(Node* node, Node** pre){
    if(node->left != NULL){
        *pre = node;
        return _findMinandPre(node->left, pre);
    }else{
        return node;
    }
}


Node* _findMaxandPre(Node* node, Node** pre){
    if(node->right != NULL){
        *pre = node;
        return _findMaxandPre(node->right, pre);
    }else{
        return node;
    }
}


void AVLdelete(Tree* tree, Node* pre, Node* delnode)
{
    Node* replaceNode = NULL;
    
    if(delnode->left != NULL)
    {                               // left subtree's max value

        Node* leftMax;
        Node* MaxPre;

        leftMax = _findMaxandPre(delnode, &MaxPre);

        MaxPre->right = leftMax->left;
        leftMax->left = NULL;

        replaceNode = leftMax;
    }
    else if(delnode->right != NULL)
    {                                // right subtree's min value

        Node* rightMin;
        Node* MinPre;

        rightMin = _findMinandPre(delnode, &MinPre);

        MinPre->left = rightMin->right;
        rightMin->right = NULL;

        replaceNode = rightMin;
    }
    else{                            // root
        replaceNode = NULL;
    }


    if(pre != NULL){
        if(pre->left == delnode){
            pre->left = replaceNode;
            free(delnode);
        }else if(pre->right == delnode){
            pre->right = replaceNode;
            free(delnode);
        }else{
            printf("error");
        }
    }

}


void _insert(Node* node, Node* newNode)
{
    newNode->height ++;
    if(node->data <= newNode->data){
        if(node->right == NULL){
            node->right = newNode;
        }
        else{
            _insert(node->right, newNode);
        }
    }else{
        if(node->left == NULL){
            node->left = newNode;
        }
        else{
            _insert(node->left, newNode);
        }
    }
}   


void AVLinsert(Tree* tree, int data)
{
    Node* newnode = createNode(data);
    if(tree->root != NULL){
        _insert(tree->root, newnode);
    }  
    else{
        tree->root = newnode;
    }
}


void destroyNode(Node* node)
{
    if(node->left != NULL)
        destroyNode(node->left);

    if(node->right != NULL)
        destroyNode(node->right);
    
    free(node);
}


void destroyTree(Tree* tree)
{
    if(tree->root != NULL)
        destroyNode(tree->root);
    
    free(tree);
}


void _traverse(Node* node, int level){
    if(node->right != NULL){
        _traverse(node->right, level + 1);
    }

    for(int i=0;i<level;i++)    printf("\t");
    printf("%d(%d)\n", node->data, node->height);

    if(node->left != NULL){
        _traverse(node->left, level + 1);
    }
}


void traverse(Tree* tree)
{
    // right -> mid -> left
    printf("// traverse //\n");
    if(tree->root != NULL){
        _traverse(tree->root, 0);
    }
}