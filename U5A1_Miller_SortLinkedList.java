import java.util.*;
import java.util.Scanner;

public class U5A1_Miller_SortLinkedList {

    
    public static void main(String[] args) {
        
        System.out.println("Miller's Copy");
        
        
        Scanner scan = new Scanner(System.in);
        LinkedList<String> linked = new LinkedList<>();
        
        System.out.println("Enter 3 collections of course codes one collection " +
                            "per line: ");
         
        int count = 0;
        outer:
        while(linked.isEmpty()) {
            count++;
            linked.addAll(Arrays.asList(scan.nextLine().split(" ")));
            
            linked.sort(Comparator.naturalOrder());
            
 
            switch (linked.size()) {
                case 4:
                    {
                        ListIterator<String> listIterator = linked.listIterator();
                        while(listIterator.hasNext()) {
                            
                            System.out.println("Size: " + linked.size() + " Sorted: " +
                                    listIterator.next() + " " + listIterator.next() + " " +
                                    listIterator.next() + " " + listIterator.next());
                            
                            
                            System.out.println();
                            
                            linked.clear();
                            
                            
                        } ///break;
                        break;
                    }
                case 2:
                    {
                        ListIterator<String> listIterator = linked.listIterator();
                        while(listIterator.hasNext()) {
                            
                            System.out.println("Size: " + linked.size() + " Sorted: " +
                                    listIterator.next() + " " + listIterator.next() + " ");
                            
                            
                            System.out.println();
                            
                            linked.clear();
                        }       break;
                    }
                case 1:
                    {
                        ListIterator<String> listIterator = linked.listIterator();
                        while(listIterator.hasNext()) {
                            
                            System.out.println("Size: " + linked.size() + " Sorted: " +
                                    listIterator.next() + " ");
                            
                            
                            System.out.println();
                            
                            linked.clear();
                            break outer;
                        }       break;
                    }
                default:
                    break;
            }
        }
    }         
}


