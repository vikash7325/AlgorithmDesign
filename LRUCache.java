/*
 *Implementation of least recently used algorithm
 *Author: Vikash Kumar
 *Language: JAVA 
*/

import java.util.HashMap;
class Node {
	int key;
	int value;
	Node previous;
	Node next;
	
	Node(int key, int value){
		this.key = key;
		this.value = value;
	}
}

class LRU {
	HashMap<Integer, Node> map = new HashMap<Integer, Node>();
	int cacheCapacity;
	Node head = null;
	Node tail = null;
	
	public void setHead(Node node){
		node.next = head;
		node.previous = null;
		
		if (head != null) {
			head.previous = node;
		}
		head = node;
		if (tail == null) {
			tail = head;
		}
	}
	
	public void remove(Node node){
		if (node.previous != null){
			node.previous.next = node.next;
		}
		else {
			head = node.next;
		}
		
		if (node.next != null) {
			node.next.previous = node.previous;
		}
		else {
			tail = node.previous;
		}
	}
	public void set(int key, int value) {
		/*
		 * If page is already present then move the page to the start of the list 
		*/
		if (map.containsKey(key)) {
			Node old = map.get(key);
			old.key = value;
			remove(old);
			setHead(old);
		}
		else {
			Node newNode = new Node(key, value);
			/*
			 * If hash map is full then delete the last node and add the new node 
			 * at the start.
			*/ 
			 if (map.size() >= cacheCapacity){
				 /*
				  * Delete the last node and add the new node at the start
				  */
				 map.remove(tail.key);
				 remove(tail);
				 setHead(newNode);
			 }
			 else {
				 setHead(newNode);
			 }
			 map.put(key, newNode);
		}
	}
}
