/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pilha;

public class App {

    public static void main(String[] args) {
        MyStack mStack = new MyStack(3);
        mStack.push(35);
        mStack.push(75);
        mStack.push(27);
        
        mStack.print();
        mStack.pop();
        mStack.print();
    }
    
}
