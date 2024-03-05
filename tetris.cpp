#include <stdlib.h> //for the random
#include <iostream>
#include <time.h>   // For time()

#define MAX_SIZE 15

class Object{
	private:
		int shape,color;
	
	public: 
		Object(){
			srand(time(NULL)); //bach kula merra ygeneri lik number jdid sinon hayb9a y3tik nfss ra9m
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

class CircularNode{
	private: 
		Object object;
		CircularNode* next;
		
	public:
		CircularNode(){}
		CircularNode(Object _object,CircularNode* _next=NULL){
			object=_object;
			next=_next;
		}
		
		Object getObject(){
			return object;
		}
	
		CircularNode* getNextNode(){
			return next;
		}
	
		void setObeject(Object _object){
			object=_object;
		}
	
		void setNext(CircularNode* _next){
			next=_next;
		}
		
};

class CircularLinkedList{
	private: 
		int currentSize;
		CircularNode* head;
		CircularNode* tail;
	public:
		CircularLinkedList():currentSize(0),head(NULL),tail(NULL){}		
		
		int getCurrentSize(){
        	return currentSize;
    	}

    // Setter for currentSize
    	void setCurrentSize(int _currentSize) {
        	currentSize = _currentSize;
    	}
    	
     void insertFromLeft(Object _object){
            CircularNode* newNode = new CircularNode(_object);
            if(head==NULL) {
                head = newNode;
                tail = newNode;
                newNode->setNext(newNode); //bach tkun circulaire
            } else {
                newNode->setNext(head);
                //head->setPrev(newNode);
                head = newNode;
                tail->setNext(newNode); //bach tkun circulaire
            }
            currentSize++;
        }

        void insertFromRight(Object _object){
            CircularNode* newNode = new CircularNode(_object);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                newNode->setNext(newNode);//bach tkun circulaire
            } else {
                tail->setNext(newNode);
                //newNode->setPrev(tail);
                tail = newNode;
                newNode->setNext(head);//bach tkun circulaire
            }
            currentSize++;
        }
       void displayAllNodes() {
    if (head == NULL) {
        std::cout << "List is empty" ;
        return;
    }
    CircularNode* temp = head; 
    std::cout << "Circular Linked List: ";
    int count = 0;
    do {
        std::cout << temp->getObject().getShape() << "," << temp->getObject().getColor() << "\t"; 
        temp = temp->getNextNode(); 
        count++;
    } while (temp != head && count < currentSize); 
    
}

};

class DoubledLinkedList{
	
};



int main(){
	CircularLinkedList myList;

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


