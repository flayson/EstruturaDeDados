package stackVector;

public class App {

    public static void main(String[] args) {
        StackVector stkv = new StackVector(1);

        Stack stk = new Stack(1);
        stk.push(stkv, 5);
        stk.push(stkv, 12);
//        stk.push(stkv, 9);
//        stk.push(stkv, 1);
//        stk.push(stkv, 1);

        stk.printStack(stkv);
    }
}
