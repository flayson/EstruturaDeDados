package pilha;

public class MyStack {

    private int size;
    private Stack stack;

    public MyStack(int size) {
        this.size = size;
        this.stack = new Stack();
    }

    public Boolean isFull() {
        if (getStack().getPos() == getSize()) {
            return true;
        }
        return false;
    }

    public Boolean isEmpty() {
        if (getStack().getPos() < -1) {
            return true;
        }
        return false;
    }

    public void push(int value) {
        if (isFull()) {
            System.out.println("Pilha está cheia!");
            return;
        }
        Stack newStk = new Stack(value, 1);
        if (getStack() == null) {
            setStack(newStk);
        } else {
            newStk.setNext(getStack());
            setStack(newStk);
        }
    }

    public int pop() {
        if (isEmpty()) {
            return -1;
        }
        int value = getStack().getValue();
        setStack(getStack().getNext());
        return value;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Pilha Vazia!");
            return;
        }

        MyStack myStkTemp = new MyStack(getSize());

        for (int i = 0; getStack().getNext()!= null; i++) {
            System.out.println(i + " - " + getStack().getValue());
            int value = pop();
            myStkTemp.push(value);
        }

        for (int i = 0; myStkTemp.getStack().getNext() != null; i++) {
            //System.out.println(i + " - " + myStkTemp.getStack().getValue());
            int value = myStkTemp.pop();
            push(value);
        }
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public Stack getStack() {
        return stack;
    }

    public void setStack(Stack stack) {
        this.stack = stack;
    }

}
