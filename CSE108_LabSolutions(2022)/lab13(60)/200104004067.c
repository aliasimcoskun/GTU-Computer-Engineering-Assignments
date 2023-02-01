#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char bookname[30];
    char author[30];
    int year;
    struct node *next;
};

struct node *head = NULL;

/*
 * Function: print_nodes
 *
 * It does: it prints the nodes that given in parameter
 *
 *
 *
 * node* root: the node which will be print.
 *
 */
void print_nodes(struct node* root){
    struct node *temple;
    if(root == NULL)  printf("Data couldn't found.\n");
    else{
        temple = root;
        while(temple != NULL){
            printf("    year = %d\n", temple->year);
            printf("    bookname = %s\n", temple->bookname);
            printf("    author = %s\n\n", temple->author);
            temple = temple->next;
        }
    }
}

/*
 * Function: insert_node
 *
 * It does: it adds nodes to struct one by one.
 *
 *
 *
 * node* root: the struct which has nodes.
 *
 *
 * bookname: the name of book that is in the txt.
 *
 * author: the name of author that is in the txt.
 *
 * year: the year of book that is in the txt.
 *
 */
struct node* insert_node(struct node* root, char* bookname, char* author, int year){
    struct node *new_node;
    struct node *temple;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(root==NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root->year = year;
        strcpy(root->bookname,bookname);
        strcpy(root->author,author);
        root->next = NULL;
        return root;
    }
    else{
        new_node->year = year;
        strcpy(new_node->bookname,bookname);
        strcpy(new_node->author,author);
        new_node->next = NULL; 
        temple = root;
        while(root->next != NULL){
            root = root->next;
        } 
        root->next = new_node;
        return temple;
    }
}

/*
 * Function: insert_node
 *
 * It does: it reads the file and adds nodes to struct one by one by calling insert_node.
 *
 *
 *
 * return: it returns root.
 */
struct node * read_file(){
    char bookname[30], author[30];
    int year;
    FILE *fp;
    fp=fopen("source.txt","r");
    struct node * root;
    //root = (struct node*)malloc(sizeof(struct node));
    while(fscanf(fp,"%s",bookname)==1){
        fscanf(fp,"%s",author);
        fscanf(fp,"%d",&year);
        root=insert_node(root,bookname,author,year);
    }
    fclose(fp);
    return root;
}

/*
 * Function: delete_node
 *
 * It does: it deletes the choosen node.
 *
 *
 *
 * node* root: this is the struct from which node is deleted
 *
 *
 * bookname: book name taken from user to delete
 *
 */
struct node* delete_node(struct node* root, char* bookname){
    struct node *temple = root;
    struct node *remove;
    remove = (struct node*)malloc(sizeof(struct node));
    if(strcmp(root->bookname,bookname)==0){ // beginning
        remove=root;
        root = root->next;
        return root;
    }
    else{
        while(temple->next!=NULL){
            if(strcmp(temple->next->bookname,bookname)==0){
                //if(temple->next!=NULL) {
                //    temple = temple->next;
                //}
                temple->next= temple->next->next;
            }
            else{
                temple = temple->next;
            }
        }
        return root;
    }
    free(remove);
}

int main(){
    struct node *root;
    root=read_file();
    print_nodes(root);
    char delete[30];
    printf("Which book do you want to delete? ");
    scanf("%s", delete);
    root=delete_node(root, delete);
    print_nodes(root);
    return 0;
}