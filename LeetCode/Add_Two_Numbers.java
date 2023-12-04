import java.util.*;
public class Add_Two_Numbers {
    public static void main(String[] args) {
        List<Integer> listA = new LinkedList<Integer>();
        List<Integer> listB = new LinkedList<Integer>();
        List<Integer> list_answer = new LinkedList<Integer>();

        listA.add(9);
        listA.add(9);
        listA.add(9);
        listA.add(9);
        listA.add(9);
        listA.add(9);
        listA.add(9);
        listB.add(9);
        listB.add(9);
        listB.add(9);
        listB.add(9);

// listA.add(1);
// listA.add(2);
// listA.add(3);
// listB.add(7);
// listB.add(8);
        Iterator<Integer> it_A = listA.iterator();
        Iterator<Integer> it_B = listB.iterator();
        
        int carry = 0;
        while( carry>0 || it_A.hasNext() || it_B.hasNext()){
            int s = carry;
            if(it_A.hasNext()){
                s += it_A.next();
            }
            if(it_B.hasNext()){
                s += it_B.next();
            }
            if(s>=10){
                list_answer.add(s%10);
                carry = 1;
            }else{
                list_answer.add(s);
                carry = 0;
            }
            System.out.println(Integer.toString(s%10)+" "+ Integer.toString(carry));
        }
        Iterator<Integer> it_answer = list_answer.iterator();
        while(it_answer.hasNext()){
            System.out.print(it_answer.next()+" ");
        }
        return ;
        
    }
}
