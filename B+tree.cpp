#include<bits/stdc++.h>

using namespace std;

 
class btreenode {// Clase nodo

int *key;
int t;
btreenode **c; // Array de punteros hijos
int n;
bool leaf; // Retorna 0 si el el arbol esta vacio
public:

btreenode(int _t, bool _leaf);//constructor
void insertnonfull(int k); // Funcion para insertar una nueva clave
// en el subarbol con nodo imcompleto

void splitchild(int i, btreenode *y);//Funcion que divide un hijo del nodo
void traverse();// Función que recorre el arbol

btreenode *search(int k); // Función para buscar una clave en el arbol

friend class btree;
};

// clase btree
class btree{

btreenode *root; //puntero anodo raiz

int t; 
public:

btree(int _t){
root = NULL;
t = _t; 
}

void traverse(){ // funcion para atravesar el arbool
if (root != NULL)
root->traverse(); 
}

void insert(int k); // Insertar una clave en el nodo
};

btreenode::btreenode(int t1, bool leaf1){
t = t1;
leaf = leaf1;
key = new int[2*t-1];
c = new btreenode *[2*t];
n = 0;
}

void btreenode::traverse(){
int i;
for (i = 0; i < n; i++){
    if (leaf == false)
    c[i]->traverse();
        cout << " " << key[i];
}
if (leaf == false)
    c[i]->traverse();
}

void btree::insert(int k){ // Insertar una clave en el arbol
if (root == NULL){
    root = new btreenode(t, true);
    root->key[0] = k; 
    root->n = 1;
}else{
if (root->n == 2*t-1){
    btreenode *s = new btreenode(t, false);
    s->c[0] = root;
    s->splitchild(0, root);
    int i = 0;
    if (s->key[0] < k)
        i++;
        s->c[i]->insertnonfull(k);
    root = s;
}else 
root->insertnonfull(k);
}}

void btreenode::insertnonfull(int k){

int i = n-1;
if (leaf == true){
while (i >= 0 && key[i] > k)
{
    key[i+1] = key[i];
    i--;
}
    key[i+1] = k;
    n = n+1;
}else 
{
    while (i >= 0 && key[i] > k)
        i--;
if (c[i+1]->n == 2*t-1)
{
splitchild(i+1, c[i+1]);
if (key[i+1] < k)
i++;
}
c[i+1]->insertnonfull(k);
}}

void btreenode::splitchild(int i, btreenode *y)
{
btreenode *z = new btreenode(y->t, y->leaf);
z->n = t - 1;
for (int j = 0; j < t-1; j++)
z->key[j] = y->key[j+t];
if (y->leaf == false)
{

for (int j = 0; j < t; j++)
z->c[j] = y->c[j+t];
}
y->n = t - 1;
for (int j = n; j >= i+1; j--)
c[j+1] = c[j];
c[i+1] = z;

for (int j = n-1; j >= i; j--)
    key[j+1] = key[j];
    key[i] = y->key[t-1];
//Incrementamos el conteo de clave
    n = n + 1;
}

int main(){

btree p(3); // B-Tree con grado 3

p.insert(15);
p.insert(2);
p.insert(25);
p.insert(16);
p.insert(32);
p.insert(30);
p.insert(6);
p.insert(7);

cout << "Recorrido del arbol ";

p.traverse();

return 0;
}