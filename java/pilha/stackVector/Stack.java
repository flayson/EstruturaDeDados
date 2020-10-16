package stackVector;

public class Stack {

    private int size;

    public Stack(int size) {
        this.size = size;
    }

    public Boolean isEmpty(StackVector stkV) {
        if (stkV.getPos() < -1) {
            return true;
        }
        return false;
    }

    public Boolean isFull(StackVector stkV) {
        if (stkV.getPos() == getSize() - 1) {
            return true;
        }
        return false;
    }

    public void push(StackVector stkV, Object value) {
        if (isFull(stkV)) {
            System.out.println("Pilha está cheia!");
            return;
        }

        stkV.setPos(stkV.getPos() + 1);
        stkV.getS()[stkV.getPos()] = value;
    }

    public Object pop(StackVector stkV) {
        if (isEmpty(stkV)) {
            System.out.println("Pilha vazia!");
            return null;
        }
        Object obj = stkV.s[stkV.getPos()];
        stkV.getS()[stkV.getPos()] = null;
        stkV.setPos(stkV.getPos() - 1);

        return obj;
    }

    public void printStack(StackVector stkV) {
        if (isEmpty(stkV)) {
            System.out.println("Pilha vazia!");
            return;
        }
        StackVector stkT = new StackVector(getSize());
        Object value;
        int pos = stkV.getPos();

//        for (int i = 0; i < 4; i++) {
//            System.out.println(i + " - " + stkV.getS()[i]);
//        }
//         System.out.println("");

        for (int i = pos; i > -1; i--) {
            value = pop(stkV);
            System.out.println(i + " - " + value);
            push(stkT, value);
        }
//        System.out.println("");
//         for (int i = 0; i < 4; i++) {
//            System.out.println(i + " - " + stkT.getS()[i]);
//        }
        System.out.println("");

        for (int i = pos; i > -1; i--) {
            value = pop(stkT);
//            System.out.println(i + " - " + value);
            push(stkV, value);
        }

    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }
}
