import java.util.*;

public class Main {

    // Defining the Animal class
    class Animal implements Comparable<Animal> {
        int age;
        String name;
        int weight;

        public Animal(int age, String name, int weight) {
            this.age = age;
            this.name = name;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "Animal{" + " age= " + age + ", name= " + name + ", weight= " + weight + "}\n";
        }

        @Override
        public int compareTo(Animal o){
            if(this.weight == o.weight){
                return this.name.compareTo(o.name);
            }
            return o.weight > this.weight ? 1 : -1;
        }
    }

    public static void main(String[] args) {
        // Create an instance of the Main class to access the inner Animal class
        Main main = new Main();

        // Create an ArrayList to store Animal objects
        List<Main.Animal> animals = new ArrayList<>();

        // Create and add Animal objects to the ArrayList
        animals.add(main.new Animal(5, "Lion", 190));
        animals.add(main.new Animal(3, "Elephant", 1000));
        animals.add(main.new Animal(2, "Dog", 40));
        animals.add(main.new Animal(1, "Cat", 10));

        // Print the ArrayList
        System.out.println(animals);

        // Collections.sort(animals);
        // animals.sort(new Comparator<Animal>() {
        //     @Override
        //     public int compare(Animal o1, Animal o2) {
        //         return Integer.compare(o1.age, o2.age);  
        //     }
        // });

        animals.sort(( o1, o2)-> {
                return o1.name.compareTo(o2.name);  
            }
        );

        System.out.println(animals);
    }
}
