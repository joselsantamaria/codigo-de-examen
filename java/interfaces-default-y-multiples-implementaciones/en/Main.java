import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

interface Shape {
    double area();

    String name();

    default String describe() {
        return name() + " area=" + String.format(Locale.ROOT, "%.2f", area());
    }
}

interface Sides {
    int sideCount();
}

class Circle implements Shape {
    private final double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    public double area() {
        return Math.PI * radius * radius;
    }

    public String name() {
        return "Circle";
    }
}

class Rectangle implements Shape, Sides {
    private final double base;
    private final double height;

    Rectangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double area() {
        return base * height;
    }

    public String name() {
        return "Rectangle";
    }

    public int sideCount() {
        return 4;
    }
}

class Square implements Shape, Sides {
    private final double side;

    Square(double side) {
        this.side = side;
    }

    public double area() {
        return side * side;
    }

    public String name() {
        return "Square";
    }

    public int sideCount() {
        return 4;
    }
}

class Triangle implements Shape, Sides {
    private final double base;
    private final double height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double area() {
        return base * height / 2;
    }

    public String name() {
        return "Triangle";
    }

    public int sideCount() {
        return 3;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.ROOT);
        int n = sc.hasNextInt() ? sc.nextInt() : 0;
        List<Shape> shapes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String kind = sc.next();
            switch (kind) {
                case "C" -> shapes.add(new Circle(sc.nextDouble()));
                case "R" -> shapes.add(new Rectangle(sc.nextDouble(), sc.nextDouble()));
                case "S" -> shapes.add(new Square(sc.nextDouble()));
                case "T" -> shapes.add(new Triangle(sc.nextDouble(), sc.nextDouble()));
                default -> throw new IllegalArgumentException("Unknown kind: " + kind);
            }
        }
        double total = 0;
        int withSides = 0;
        for (Shape s : shapes) {
            StringBuilder line = new StringBuilder(s.describe());
            if (s instanceof Sides sd) {
                line.append(" sides=").append(sd.sideCount());
                withSides++;
            }
            System.out.println(line);
            total += s.area();
        }
        System.out.println("total=" + String.format(Locale.ROOT, "%.2f", total) + " withSides=" + withSides);
    }
}
