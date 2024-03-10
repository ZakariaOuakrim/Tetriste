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
        
		void deleteNode(CircularNode* delNode){
			if(head==NULL || delNode==NULL){
				return;				
			}
			if(head==delNode){
				head=delNode->getNextNode();
			}
			CircularNode* current = head;
			while (current->getNextNode() != head && current->getNextNode() != delNode) {
				current = current->getNextNode();
			}
			current->setNext(delNode->getNextNode());
			
			delete delNode;
			currentSize--;

		}
		void deleteNodes(CircularNode* delNode){ //delete three Nodes
			deleteNode(delNode->getNextNode()->getNextNode()); //khass nbdaw mnha so we will not lose the adress of the next node
			deleteNode(delNode->getNextNode());
			deleteNode(delNode);
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
        
		void deleteNode(DoubledCircularNode* delNode){
			if(head==NULL || delNode==NULL){
				return;				
			}
			if(head==delNode){
				head=delNode->getNext();
			}
			DoubledCircularNode* current = head;
			while (current->getNext() != head && current->getNext() != delNode) {
				current = current->getNext();
			}
			current->setNext(delNode->getNext());
			current->setPrev(delNode->getPrev());
			
			delete delNode;
			currentSize--;
		}
		
		void deleteNodes(DoubledCircularNode* delNode){ //delete three Nodes
			deleteNode(delNode->getNext()->getNext()); //khass nbdaw mnha so we will not lose the adress of the next node
			deleteNode(delNode->getNext());
			deleteNode(delNode);
		}
		
		void displayNodes() {
	        if (head == NULL) {
	            std::cout << "List is empty." << std::endl;
	            return;
	        }
	
	        DoubledCircularNode* current = head;
	        do {
	            std::cout << current->getData() << " ";
	            current = current->getNext();
	        } while (current != head);
	        std::cout << std::endl;
    	}
		
		DoubledCircularNode* getHead(){
			return head;
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
			int color = _object.getColor();
			int shape = _object.getShape();
			switch(_object.getColor()){ //inserting in the color list
				case 1:
					listOfColor1.insertFromRight(color);
					break;
				case 2:
					listOfColor2.insertFromRight(color);
					break;	
				case 3:
					listOfColor3.insertFromRight(color);
					break;
				case 4: 
					listOfColor4.insertFromRight(color);
					break;
			}
			switch(_object.getShape()){ //inserting in the shape list 
				case 1:
					listOfShape1.insertFromRight(shape);
					break;
				case 2:
					listOfShape2.insertFromRight(shape);
					break;
				case 3:
					listOfShape3.insertFromRight(shape);
					break;
				case 4:
					listOfShape4.insertFromRight(shape);
					break;			
			}
			if(listOfObjects.getCurrentSize() >=3){
				checkStatus();
			}
		}
		
		void addObjectToLeft(Object _object){
			
			listOfObjects.insertFromLeft(_object);	
			int color = _object.getColor();
			int shape = _object.getShape();
			switch(_object.getColor()){ //inserting in the color list
				case 1:
					listOfColor1.insertFromLeft(color);
					break;
				case 2:
					listOfColor2.insertFromLeft(color);
					break;	
				case 3:
					listOfColor3.insertFromLeft(color);
					break;
				case 4: 
					listOfColor4.insertFromLeft(color);
					break;
			};
			switch(_object.getShape()){
					case 1:
					listOfShape1.insertFromLeft(shape);
					break;
				case 2:
					listOfShape2.insertFromLeft(shape);
					break;
				case 3:
					listOfShape3.insertFromLeft(shape);
					break;
				case 4:
					listOfShape4.insertFromLeft(shape);
					break;	
			};
			
			//check 
			if(listOfObjects.getCurrentSize() >=3){
				checkStatus();
			}
		}
		
		//remove 3 colors from a list
		void removeColors(int color){
			switch(color){
				case 1:
					listOfColor1.deleteNodes(listOfColor1.getHead());	
					break;	
				case 2:
					listOfColor2.deleteNodes(listOfColor2.getHead());	
					break;
				case 3:
					listOfColor3.deleteNodes(listOfColor3.getHead());	
					break;
				case 4:
					listOfColor4.deleteNodes(listOfColor4.getHead());	
					break;	
			}
		}
		
		//remove 3 shapes from a list 
		void removeShapes(int shape){
			switch(shape){
				case 1:
					listOfShape1.deleteNodes(listOfShape1.getHead());	
					break;	
				case 2:
					listOfShape2.deleteNodes(listOfShape2.getHead());	
					break;
				case 3:
					listOfShape3.deleteNodes(listOfShape3.getHead());	
					break;
				case 4:
					listOfShape4.deleteNodes(listOfShape4.getHead());	
					break;	
			}
		}
		
		//remove 1 shape from a list
		void removeShape(int shape){
				switch(shape){
				case 1:
					listOfShape1.deleteNode(listOfShape1.getHead());	
					break;	
				case 2:
					listOfShape2.deleteNode(listOfShape2.getHead());	
					break;
				case 3:
					listOfShape3.deleteNode(listOfShape3.getHead());	
					break;
				case 4:
					listOfShape4.deleteNode(listOfShape4.getHead());	
					break;	
			}
		}
		
		//remove 1 color from a list
		void removeColor(int color){
			switch(color){
				case 1:
					listOfColor1.deleteNode(listOfColor1.getHead());	
					break;	
				case 2:
					listOfColor2.deleteNode(listOfColor2.getHead());	
					break;
				case 3:
					listOfColor3.deleteNode(listOfColor3.getHead());	
					break;
				case 4:
					listOfColor4.deleteNode(listOfColor4.getHead());	
					break;	
			}
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
		
		//check if there are 3 shapes or colors next to each other
 		void checkStatus(){ 
 			CircularNode *tmp = listOfObjects.getHead();
		 	CircularNode *tmp2=tmp->getNextNode();
		 	CircularNode *tmp3=tmp2->getNextNode();
			while(tmp->getNextNode()->getNextNode()!=listOfObjects.getHead()){	
				//check ila kano 3 3ndhum nfss shape 
				if(tmp->getObject().getColor()==tmp2->getObject().getColor() && tmp2->getObject().getColor()==tmp3->getObject().getColor()){    
					//remove 3 elements from the list of the color which is specific to the tmp color
					removeColors(tmp->getObject().getColor());
					//now we need to remove the shapes of the objects remaining (7it bima anana msa7na 3la 2assas lcolor ila ana shapes hayb9aw)
					removeShape(tmp->getObject().getShape());					
					removeShape(tmp2->getObject().getShape());
					removeShape(tmp3->getObject().getShape());
										
					listOfObjects.deleteNodes(tmp); //delete from the list of objects, n9do n'optimisiw hadi fi7alat masiftna tmp ot tmp2 o tmp3 bach man7tajuch n9lbo 3lihum
					break; //stop no need to search anymore
				}
				// check ila kano 3 3ndhum nfss shape
				else if(tmp->getObject().getShape()==tmp2->getObject().getShape() && tmp2->getObject().getShape()==tmp3->getObject().getShape()){   
					removeShapes(tmp->getObject().getShape());
					
					removeColor(tmp->getObject().getColor());					
					removeColor(tmp2->getObject().getColor());
					removeColor(tmp3->getObject().getColor());
									
					listOfObjects.deleteNodes(tmp); //delete from the list of objects
					break;
				}
				
				//going to next elements
				tmp=tmp->getNextNode();
				tmp2=tmp->getNextNode();
				tmp3=tmp2->getNextNode();
	 		
			 }
		 }
		
};

int main(){
	srand(time(NULL)); //bach kula merra ygeneri lik number jdid sinon hayb9a y3tik nfss ra9m
	Object obj1,obj2,obj3,obj4;

	
	
		
	Game game;
	game.addObjectToLeft(obj1);
	game.addObjectToLeft(obj2);
	game.addObjectToLeft(obj3);
	game.addObjectToLeft(obj4);
	
	game.showGame();
	game.checkStatus();
	printf("\n");
	game.showGame();
	

	
	   
    return 0;
}


