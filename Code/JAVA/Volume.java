
public class Volume {
    class Shapes3D {
        static int totalShapes = 0;

        Shapes3D(){
            totalShapes++;
        }

        double getVolume(){
            return 0.0;
        }
    }

    // Cuboid class
    class Cuboid extends Shapes3D{
        private double length, width, height;

        Cuboid(double length, double width, double height){
            super();
            this.length = length;
            this.width = width;
            this.height = height;
        }

        double getVolume(){
            return length * width * height;
        }
    }

    // Cylinder class
    class Cylinder extends Shapes3D{
        private double radius, height;

        Cylinder(double radius, double height){
            super();
            this.radius = radius;
            this.height = height;
        }

        double getVolume(){
            return Math.PI * radius * radius * height;
        }
    }

    // Sphere Class
    class Sphere extends Shapes3D{
        private double radius;

        Sphere(double radius){
            this.radius = radius;
        }

        double getVolume(){
            return (4.0 / 3.0) * Math.PI * radius * radius * radius;
        }
    }

    public static void main(String[] args) {
        Volume volume = new Volume();

        Shapes3D cuboid = volume.new Cuboid(10, 20, 30);
        Shapes3D cylinder = volume.new Cylinder(30, 50);
        Shapes3D sphere = volume.new Sphere(30);

        System.out.printf("Cuboid Volume: %.2f\n", cuboid.getVolume());
        System.out.printf("Cylinder Volume: %.2f\n", cylinder.getVolume());
        System.out.printf("Sphere Volume: %.2f\n", sphere.getVolume());

        System.out.println("The total number of shapes is: "+Shapes3D.totalShapes);
    }
}
