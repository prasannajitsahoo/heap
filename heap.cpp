#include<iostream>
using namespace std;
//class Heap
class Heap{
	public:
	//pointer to array elements
	int *hArr;
	//maximum no of elements
	int mSize;
	//current size of array
	int cSize;
	//constructor
	Heap(int mSize){
		//create a new array
		hArr=new int[mSize]; 
		this->mSize=mSize;
		cSize=-1;
	}		
	//to get parent
	int parent(int i){return (i-1)/2;}
	//make left
	int leftchild(int i){return 2*i+1;}
	//make right
	int rightchild(int i){return 2*i+2;}
	//function that swaps the values
	void swap(int &a,int &b){
		int t=a;
		a=b;
		b=t;
	}	
	//insert
	void insert(int value){
		cSize++;
		//if it is the first element
		if(cSize==0){hArr[cSize]=value;}
		else if(cSize==mSize) cout<<"There is no space to store."<<endl;
		else{
			//first insert at last
			hArr[cSize]=value;
			//find the value which is just smaller than this
			//compare for prop 2
			prop2compare(cSize);
		}
	}
		//prop2compare function that compares with the parent and swaps if needed
		void prop2compare(int i){
			//stoping condition
			//cout<<i<<"-,"<<endl;
			if(i==0) return;
			//it does in the way like if the parent is bigger than this child then it swaps
			else if(hArr[(i-1)/2]>hArr[i]) {
				swap(hArr[(i-1)/2],hArr[i]);
				//do recursion
				prop2compare((i-1)/2);
			}
			else return;
		}
		//MinHeapify function that swap with the child having minimum value
		void MinHeapify(int i){
			//stoping condition
			if(i>cSize) return;
			else if(hArr[i]<hArr[2*i+1] and hArr[i]<hArr[2*i+2]) return;
			else if(2*i+1>cSize) return;
			else if(2*i+2>cSize and 2*i+1<=cSize) swap(hArr[i],hArr[2*i+1]); 
	
			else if(hArr[2*i+1]>hArr[2*i+2]) {
				swap(hArr[2*i+2],hArr[i]);
				MinHeapify(2*i+2);
			}
			else {
				swap(hArr[2*i+1],hArr[i]);
				MinHeapify(2*i+1);
			}
		}
		//getMin function that returns the value of the minimum
		int getMin(){
			return hArr[0];
		}
		//extract_min function that deletes the minimum function 
		int extract_min(){
			return Delete(0);
		}
	//display function that displays the values
	void display(){
		for(int i=0;i<=cSize;i++){
			cout<<hArr[i]<<"->";
		}
		cout<<"NULL"<<endl;
	}
	//Delete function that deletes the value at that position
	int Delete(int a){
		if(a>cSize) cout<<"This position is not avialable"<<endl;
		else{
			int b=hArr[a];
			//if it is the the last element
			if(a==cSize) cSize--;
			else{
				//swap the values
				swap(hArr[a],hArr[cSize]);
				cSize--;
				MinHeapify(a);
			}
			return b;		
		}
	}
	//when the value of an element is decreased at a given index
	void decreaseKey(int i,int new_value){
		//if the given value is greater than the older value
		if(hArr[i]<new_value) cout<<"The given value is greater than the older value."<<endl;
		else{
			hArr[i]=new_value;
			prop2compare(i);
		}
	}
	//destructor
	~Heap(){
		delete hArr;
	}
};
//define main
int main(){
	Heap h(15);
	for(int i=10;i>0;i--){
		h.insert(i);	
	}
	h.display();
	h.extract_min();
	cout<<"After deleteting the root."<<endl;
	h.display();
	h.Delete(5);
	cout<<"After deleting the element in the 6th position."<<endl;
	h.display();
	cout<<"After decreasing the element in the 6th position."<<endl;
	h.decreaseKey(5,1);
	h.display();
	return 0;
}