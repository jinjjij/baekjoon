// https://www.acmicpc.net/problem/7662 - 이중 우선순위 큐


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