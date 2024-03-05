#include <stdlib.h> //for the random
#include <iostream>
#define MAX_SIZE 15

class Object{
	private:
		int shape,color;
	
	public: 
		Object(){
			shape=rand() % 4;
			color=rand() % 4;
		}
		
		//getter setters
		
		int getShape(){
			return shape;
		}
		int getColor(){
			return color;
		}
		
		void setShape(int _shape){
			shape=_shape;
		}
		void setColor(int _color){
			color=_color;
		}
};

class Node{
	private: 
		Object object;
		Node* prev;
		Node* next;
		
	public:
		Node(){}
		Node(Object _object,Node* _prev=NULL,Node* _next=NULL){
			object=_object;
			prev=_prev;
			next=_next;
		}
		
		Object getObject(){
			return object;
		}
		Node* getPrevNode(){
			return prev;
		}
		Node* getNextNode(){
			return next;
		}
	
		void setObeject(Object _object){
			object=_object;
		}
		void setPrev(Node* _prev){
			prev=_prev;
		}
		void setNext(Node* _next){
			next=_next;
		}
		
};

class SingleLinkedList{
	private: 
		int currentSize;
		Node* head;
		Node* tail;
	public:
		SingleLinkedList():currentSize(0),head(NULL),tail(NULL){}		
		
		int getCurrentSize(){
        	return currentSize;
    	}

    // Setter for currentSize
    	void setCurrentSize(int _currentSize) {
        	currentSize = _currentSize;
    	}
    	
     void insertFromLeft(Object _object){
            Node* newNode = new Node(_object);
            if(head==NULL) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->setNext(head);
                //head->setPrev(newNode);
                head = newNode;
            }
            currentSize++;
        }

        void insertFromRight(Object _object){
            Node* newNode = new Node(_object);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->setNext(newNode);
                //newNode->setPrev(tail);
                tail = newNode;
            }
            currentSize++;
        }
        void displayAllNodes() {
   			Node* currentNode = head;
    		while (currentNode != NULL) {
        std::cout << "Shape: " << currentNode->getObject().getShape() << ", Color: " << currentNode->getObject().getColor() << std::endl;
        currentNode = currentNode->getNextNode();
    }
}

};

int main(){
	SingleLinkedList myList;

	//dkhl mn lisr    
    Object obj1, obj2, obj3;
    myList.insertFromLeft(obj1);
    myList.insertFromLeft(obj2);
    myList.insertFromLeft(obj3);
    
    //dkhl mn limn
    Object obj4, obj5, obj6;
    myList.insertFromRight(obj4);
    myList.insertFromRight(obj5);
    myList.insertFromRight(obj6);
    
    myList.displayAllNodes();
    return 0;
}


