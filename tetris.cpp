#include <stdlib.h> //for the random
#include <iostream>
#include <time.h>

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
		CircularNode* getHead(){
			return head;
		}
		CircularNode* getTail(){
			return tail;
		}
};

class DoubledCircularNode{
	private:
		int data; //ya color ya shape
		DoubledCircularNode *next;
		DoubledCircularNode *prev;
	public:
		
		DoubledCircularNode(int _data,DoubledCircularNode *_next=NULL,DoubledCircularNode *_prev=NULL){
			data=_data;
			next=_next;
			prev=_prev;	
		}
		//getters 
		int getData(){
			return data;
		}
		DoubledCircularNode *getNext(){
			return next;
		}
		DoubledCircularNode *getPrev(){
			return prev;
		}
		
		//setters
		void setDate(int _data){
			data=_data;
		}
		void setNext(DoubledCircularNode *_next){
			next=_next;
		}
		void setPrev(DoubledCircularNode *_prev){
			prev=_prev;
		}
};

class DoubledCircularLinkedList{ //hadi 3la 9bal shapes o colors
	private:
		int currentSize;
		DoubledCircularNode *head;
		DoubledCircularNode *tail;
	public:
		DoubledCircularLinkedList():currentSize(0),head(NULL),tail(NULL){}
		
		void insertFromLeft(int _data){
            DoubledCircularNode* newNode = new DoubledCircularNode(_data);
            if(head==NULL) {
                head = newNode;
                tail = newNode;
                newNode->setNext(newNode); //bach tkun circulaire
            } else {
                newNode->setNext(head);
                head->setPrev(newNode); //hadi 7it raha doubled
                head = newNode;
                tail->setNext(newNode); //bach tkun circulaire
            }
            currentSize++;
        }

        void insertFromRight(int _data){
            DoubledCircularNode* newNode = new DoubledCircularNode(_data);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                newNode->setNext(newNode);//bach tkun circulaire
            } else {
                tail->setNext(newNode);
				newNode->setPrev(tail); //hadi 7it raha doubled
                tail = newNode;
                newNode->setNext(head);//bach tkun circulaire
            }
            currentSize++;
        }
		
			
};

class Game{
	private:
		int score;
		
		Object nextObject;
		
		CircularLinkedList listOfObjects; //all objects are in here
		
		DoubledCircularLinkedList listOfColor1;
		DoubledCircularLinkedList listOfColor2;
		DoubledCircularLinkedList listOfColor3;
		DoubledCircularLinkedList listOfColor4;

		DoubledCircularLinkedList listOfShape1;
		DoubledCircularLinkedList listOfShape2;
		DoubledCircularLinkedList listOfShape3;
		DoubledCircularLinkedList listOfShape4;
		
	public:
		Game():listOfObjects(){
			
		}
		
		//add to the game an object
		void addObjectToRight(Object _object){
			listOfObjects.insertFromRight(_object);
			switch(_object.getColor()){
				case 1:
					
					break;
				case 2:
					
					break;	
				case 3:
					
					break;
				case 4: 
					
					break;
			}
		}
		void addObjectToLeft(Object _object){
			
		}
		
		//See the game in console 
		void showGame(){ 
		    if (listOfObjects.getHead() == NULL) {
		        std::cout << "List is empty" ;
		        return;
		    }
		    CircularNode* temp = listOfObjects.getHead(); 
		    int count = 0;
		    do {
		        std::cout << temp->getObject().getShape() << "," << temp->getObject().getColor() << "\t"; 
			    temp = temp->getNextNode(); 
		        count++;
		    } while (temp != listOfObjects.getHead() && count < listOfObjects.getCurrentSize() ); 
		    
		}
		
		void clearScreen(){
			#ifdef _WIN32
				system("cls");
			#else 
				system("clear");
			#endif
		}
		
		CircularLinkedList& getListOfObjects(){
			return listOfObjects;
		}
		DoubledCircularLinkedList& getListOfColor1(){
			return listOfColor1;
		}
		DoubledCircularLinkedList& getListOfColor2(){
			return listOfColor2;
		}
		DoubledCircularLinkedList& getListOfColor3(){
			return listOfColor3;
		}
		DoubledCircularLinkedList& getListOfColor4(){
			return listOfColor4;
		}
		DoubledCircularLinkedList& getListOfShape1(){
			return listOfShape1;
		}
		DoubledCircularLinkedList& getListOfShape2(){
			return listOfShape2;
		}
		DoubledCircularLinkedList& getListOfShape3(){
			return listOfShape3;
		}
		DoubledCircularLinkedList& getListOfShape4(){
			return listOfShape4;
		}
		
 		
		
};
int main(){
	srand(time(NULL)); //bach kula merra ygeneri lik number jdid sinon hayb9a y3tik nfss ra9m
	Object obj1;
    
    Game game;
    game.getListOfObjects().insertFromLeft(obj1);

	game.showGame();	
	    
    return 0;
}


