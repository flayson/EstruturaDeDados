package pilha;

public class Stack {

    private int value;
    private int pos;
    private Stack next;

    public Stack(int value, int pos) {
        this.value = value;
        this.pos = pos;
        this.next = null;
    }

    public Stack(int value, int pos, Stack next) {
        this.value = value;
        this.pos = pos;
        this.next = next;
    }

    public Stack() {
        this.pos = -1;
        this.next = null;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public Stack getNext() {
        return next;
    }

    public void setNext(Stack next) {
        this.next = next;
    }

}
