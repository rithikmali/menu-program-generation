#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define print_tab printf("%s",tab_str); //macro to print indentation tabs

//tree struct
struct node
{
	char key[1025];
	struct node* left;
	struct node* right;
};
typedef struct node node_t;

struct tree
{
	node_t *root;
};
typedef struct tree tree_t;

//print a new while loop, creates a new switch inside it
void begin_while_switch(int a)
{

    char tab_str[a+4];
    int i;
    for (i = 0; i < a+1; i++)
        tab_str[i] = '\t';
    tab_str[i] = '\0';
    print_tab;
    printf("a[%d] = 1;\n",a);
    print_tab;
    printf("while(a[%d])\n",a);
    print_tab;
    printf("{\n");
    tab_str[i++] = '\t'; 
    tab_str[i] = '\0';
    print_tab;
    printf("scanf(\"%%d\",&ch1);\n");
    print_tab;
    printf("switch(ch1)\n");
    print_tab;
    printf("{\n");
    print_tab;
    printf("case 0:\n");
    tab_str[i++] = '\t'; 
    tab_str[i] = '\0';
    print_tab;
    printf("a[%d]=0;\n",a);
    print_tab;
    printf("break;\n");
}

//prints the end of while and switch statements
void end_while_switch(int a)
{
    char tab_str[a+4];
    int i;
    for (i = 0; i < a+2; i++)
        tab_str[i] = '\t';
    tab_str[i] = '\0';
    print_tab;
    printf("default:\n");
    tab_str[i++] = '\t'; 
    tab_str[i] = '\0';
    print_tab;
    printf("break;\n"); 
    tab_str[--i] = '\0';
    print_tab;
    printf("}\n");
    tab_str[--i] = '\0';
    print_tab;
    printf("}\n");
    if(a==0)
        return;
    print_tab;
    printf("break;\n");
}

//prints the switch cases for a given node
void switch_case(const node_t *node, int count, int need_break, int level)
{   
    char tab_str[level+3];
    int i;
    for (i = 0; i < level+1; i++)
        tab_str[i] = '\t';
    tab_str[i] = '\0';
    print_tab;
    printf("case %d:\n",count);
    tab_str[i++] = '\t';
    tab_str[i] = '\0';
    print_tab;
    printf("printf(\"%s\\n\");\n",node->key);
    if(!need_break)
        return;
    print_tab;
    printf("break;\n");
}

//makes the while and switch cases, recursively
void disp_r(node_t *root,int count, int level)
{
	if(root == NULL)
		return;
	if(root->left!=NULL)
	{
        if(strcmp(root->key,"\t"))
        {
            switch_case(root,count, 0, level);
        }

        //begin while/switch statements
        begin_while_switch(level);
        
		node_t* temp = root->left;
        count=0;
        
		while(temp)
		{
            ++count;
            if(temp->left==NULL) //if not a parent, print the switch case
            {
                switch_case(temp, count, 1, level);
            }
            else //if its a parent, increase the level and call the function to print its children
            {
                ++level;
                disp_r(temp,count,level);
                --level;
            }

            temp = temp -> right;
    	}

        //end switch/while statements
        end_while_switch(level);
	}
}

//prints the switch/while for the given tree
void disp_tree(tree_t *ptr_tree)
{
	disp_r(ptr_tree -> root,0,0);
}

//returns the node which has parent as its value
node_t* search(node_t *root, char* parent)
{
	if(root == NULL)
		return NULL;
	if(!strcmp(root -> key,parent))
	{
		return root;
	}
	if(search(root->left,parent) != NULL)
		return search(root->left,parent);
	if(search(root->right,parent) != NULL)
		return search(root->right,parent);
	return NULL;
}

//add node to the tree
void add_node(tree_t *ptr_tree, char* parent, char* key)
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	node_t* par;

    strcpy(temp->key, key);
	temp -> left = temp -> right = NULL;

	par = search(ptr_tree -> root,parent);

    if(par -> left == NULL)
        par -> left = temp;
    else
    {
        par = par -> left;
        while(par -> right)
            par = par ->right;
        par -> right = temp;
    }
}

void myfree(node_t* root)
{
    if (root==NULL)
    {
        return;
    }
    myfree(root->left);
    myfree(root->right);
    free(root);
}

//stack struct
struct stack_o
{
    char value[1025];
    struct stack_o* next;
};
typedef struct stack_o stack_o;

struct s_stack 
{
    stack_o* top;
};
typedef struct s_stack s_stack;

//stack functions

//stack pop
void s_push(s_stack* s, char* ch)
{
    stack_o* new_s = (stack_o*)malloc(sizeof(stack_o));
	strcpy(new_s->value,ch);
	new_s->next = s->top;
	s->top = new_s;
}

//stack pop
char* s_pop(s_stack* s)
{
    stack_o* temp = s->top;
	s->top = temp->next;
	char* top_value = (char*)malloc(1025*sizeof(char));
    strcpy(top_value,temp->value);
	free(temp);
	return top_value;
}

int main()
{
    //begin the program
    printf("#include<stdio.h>\n\n");
    printf("int main()\n{\n");
    
    //define required variables
    char parent[1025]; char pch[1025]; char str[1025]; char ch;
    int ptab=0; int ctab=0;
    strcpy(pch,"\t");
    
    //initialize the stack
    s_stack* pstack = (s_stack*)malloc(sizeof(s_stack));
	pstack->top = NULL;
    
    //initialize the tree
    tree_t *t = (tree_t*)malloc(sizeof(tree_t));
    t->root = (node_t*)malloc(sizeof(node_t));

    //for my tree, Im using '\t' as the parent for topmost menu
	strcpy(t->root->key,"\t");
    t->root->left = t->root->right = NULL;
    
    int max_tab = 0;
    int i=0;
    while ((ch = getchar()) != EOF)
    {           
        if(ch != '\t')
        {
            //while ch is not a newline or a tab, keep appending to str
            if (ch!='\n')
            {
                str[i] = ch;
                ++i;
            }
            //if ch is \n, this implies that it has read the whole word, and I append it to the tree
            else
            {
                //I keep track of the max number of tabs here
                if(ctab > max_tab)
                    max_tab = ctab;
                
                //Indicate the end of a word
                str[i] = '\0';

                // If current number of tabs are equal to previous tabs => its a sibling
                // hence I dont change the parent
                if (ptab==ctab)
                {
                    //if no. of tabs are 0 => its in the top most menu
                    if(ctab==0)
                    {
                        strcpy(parent,"\t");
                    }
                }

                //If current number of tabs are greater than the previous tabs => its a child
                //hence I push the previous parent to the stack and make the previous element as the parent
                else if (ctab > ptab)
                {
                    s_push(pstack, parent);
                    strcpy(parent,pch);
                }

                //If current number of tabs are lessser than the previous tabs => its a sibling of the parent of previous element
                //hence I pop element from the stack and make this element as the parent
                else
                {
                    //the number of pops is equal to difference of the tabs
                    for(int k = 0; k<(ptab-ctab); k++)
                    {
                        char* p = s_pop(pstack);
                        strcpy(parent,p);
                        free(p);
                    }
                }
                
                strcpy(pch,str); //set previous str to curr str
                add_node(t,parent,str); //add the node to the tree
                ptab=ctab; //set previous no. of tabs to curr no. of tabs
                ctab=0; //reset the tab counter
                strcpy(str,""); //reset the str
                i=0; //reset
            }    
        }

        //if ch is a tab, increament the curr tab counter
        else
        {
            ++ctab;
        }
    }
    
    //array for while loops
    printf("//changed\n");
    printf("int a[%d];\n",max_tab+1);
    printf("for(int k=0; k < %d; k++)\n",max_tab+1);
    printf("\ta[k] = 1;\n");
    printf("int ch1;\n");

    disp_tree(t); // print the switch cases
    printf("\nreturn 0;\n}\n"); //end the program
    myfree(t->root);
    free(t);
    return 0;
}