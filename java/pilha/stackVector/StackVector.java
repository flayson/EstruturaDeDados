package stackVector;

public class StackVector {

    Object s[];
    int pos;

    public StackVector(int size, int pos) {
        this.s = new Object[size];
        this.pos = pos;
    }

    public StackVector(int size) {
        this.s = new Object[size];
        this.pos = -1;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public Object[] getS() {
        return s;
    }

    public void setS(Object[] s) {
        this.s = s;
    }
}
