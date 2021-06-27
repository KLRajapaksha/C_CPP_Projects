#include<iostream>
#include<queue>
using namespace std;

struct node {
   int freq;
   node *leftchild, *rightchild;
};

node *getNode( int f) {
   node *newNode = new node;
   newNode->freq = f;
   newNode->leftchild = NULL;
   newNode->rightchild = NULL;
   return newNode;
}

node *findMinNode(queue<node*>&q1, queue<node*>&q2) {
   node *minNode;
   if(q1.empty()) { //if first queue is empty, delete and return node from second queue
      minNode = q2.front();
      q2.pop();
      return minNode;
   }

   if(q2.empty()) { //if second queue is empty, delete and return node from first queue
      minNode = q1.front();
      q1.pop();
      return minNode;
   }

   if((q1.front()->freq) <= (q2.front()->freq)) { //find smaller from two queues
      minNode = q1.front();
      q1.pop();
      return minNode;
   }else {
      minNode = q2.front();
      q2.pop();
      return minNode;
   }
//////////////////////////////////////////////

////////////////////////////////////////////////////////   
}


node *huffmanTree( int frequency[], int n) {
   node *c0, *c1, *par;
   node *newNode;
   queue<node*> qu1, qu2;

   for(int i = 0; i<n; i++) { //add all node to queue 1
      newNode = getNode( frequency[i]);
      qu1.push(newNode);
   }

   while(!(qu1.empty() && (qu2.size() == 1))) {
      c0 = findMinNode(qu1, qu2); //find two minimum as two child
      c1 = findMinNode(qu1, qu2);
      node *newNode = getNode( c0->freq+c1->freq);

      //intermediate node holds special character
      par = newNode;
      par->leftchild = c0;
      par->rightchild = c1;
      qu2.push(par); //add sub tree into queue 2
   }

   node *retNode = qu2.front();
   qu2.pop();
   return retNode;
}

void getCodes(node *rootNode, int array[], int n) {  //array to store the code
   if(rootNode->leftchild != NULL) {
      array[n] = 0;
      getCodes(rootNode->leftchild, array, n+1);
   }

   if(rootNode->rightchild != NULL) {
      array[n] = 1;
      getCodes(rootNode->rightchild, array, n+1);
   }

   if(rootNode->leftchild == NULL && rootNode->rightchild == NULL) {  // when root is leaf node


      for(int i = 0; i<n; i++)
        cout << array[i];
        cout << endl;
   }
}

void huffmanCodes(int frequency[], int n) {
   node *rootNode = huffmanTree( frequency, n);
   int array[50], top = 0;
   getCodes(rootNode, array, top);
}

int main() {

   int frequency[] = {1,2,3};
   int n =3;
   huffmanCodes( frequency, n);
}


