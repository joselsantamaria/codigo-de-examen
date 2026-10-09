import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

abstract class Shape {
    public abstract double area();

    public abstract String name();

    protected abstract String dimensions();

    @Override
    public String toString() {
        // Common template: all three calls are resolved by dynamic binding
        return String.format(Locale.ROOT, "%s(%s) area=%.2f", name(), dimensions(), area());
    }
}

class Circle extends Shape {
    private final double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }

    @Override
    public String name() {
        return "Circle";
    }

    @Override
    protected String dimensions() {
        return String.format(Locale.ROOT, "r=%.2f", radius);
    }
}

class Rectangle extends Shape {
    protected final double base;
    protected final double height;

    Rectangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double area() {
        return base * height;
    }

    @Override
    public String name() {
        return "Rectangle";
    }

    @Override
    protected String dimensions() {
        return String.format(Locale.ROOT, "b=%.2f h=%.2f", base, height);
    }
}

class Square extends Rectangle {
    Square(double side) {
        super(side, side);
    }

    // area() is inherited from Rectangle: no need to redefine it
    @Override
    public String name() {
        return "Square";
    }

    @Override
    protected String dimensions() {
        return String.format(Locale.ROOT, "s=%.2f", base);
    }
}

class Triangle extends Shape {
    private final double base;
    private final double height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double area() {
        return base * height / 2.0;
    }

    @Override
    public String name() {
        return "Triangle";
    }

    @Override
    protected String dimensions() {
        return String.format(Locale.ROOT, "b=%.2f h=%.2f", base, height);
    }
}

class ShapeCollection {
    private final List<Shape> elements = new ArrayList<>();

    void add(Shape s) {
        elements.add(s);
    }

    boolean remove(int pos) {
        if (pos < 0 || pos >= elements.size()) {
            return false;
        }
        elements.remove(pos);
        return true;
    }

    void print(PrintWriter out) {
        if (elements.isEmpty()) {
            out.println("(empty)");
            return;
        }
        for (int i = 0; i < elements.size(); i++) {
            out.println(i + ": " + elements.get(i));
        }
    }

    double totalArea() {
        double total = 0.0;
        for (Shape s : elements) {
            total += s.area();
        }
        return total;
    }

    int size() {
        return elements.size();
    }

    Shape largest() {
        Shape best = null;
        for (Shape s : elements) {
            if (best == null || s.area() > best.area()) {
                best = s;
            }
        }
        return best;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        ShapeCollection shapes = new ShapeCollection();
        String line;
        while ((line = in.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) {
                continue;
            }
            String[] p = line.split("\\s+");
            switch (p[0]) {
                case "C" -> shapes.add(new Circle(Double.parseDouble(p[1])));
                case "R" -> shapes.add(new Rectangle(Double.parseDouble(p[1]), Double.parseDouble(p[2])));
                case "S" -> shapes.add(new Square(Double.parseDouble(p[1])));
                case "T" -> shapes.add(new Triangle(Double.parseDouble(p[1]), Double.parseDouble(p[2])));
                case "D" -> {
                    int pos = Integer.parseInt(p[1]);
                    if (!shapes.remove(pos)) {
                        out.println("ERROR position " + pos);
                    }
                }
                case "L" -> shapes.print(out);
                case "A" -> out.println(String.format(Locale.ROOT, "Total: %d shapes, area %.2f",
                        shapes.size(), shapes.totalArea()));
                case "M" -> {
                    Shape m = shapes.largest();
                    out.println("Largest: " + (m == null ? "none" : m));
                }
                default -> {
                    // unknown command: ignored
                }
            }
        }
        out.flush();
    }
}
