import java.util.Scanner;

interface Playable {
    void play();
    void pause();
    void stop();
}

class AudioFile implements Playable {
    private String title;

    public AudioFile(String title) {
        this.title = title;
    }

    public void play() {
        System.out.println("Playing audio: " + title);
    }

    public void pause() {
        System.out.println("Pausing audio: " + title);
    }

    public void stop() {
        System.out.println("Stopping audio: " + title);
    }
}

class VideoFile implements Playable {
    private String title;

    public VideoFile(String title) {
        this.title = title;
    }

    public void play() {
        System.out.println("Playing video: " + title);
    }

    public void pause() {
        System.out.println("Pausing video: " + title);
    }

    public void stop() {
        System.out.println("Stopping video: " + title);
    }
}

class Podcast implements Playable {
    private String title;

    public Podcast(String title) {
        this.title = title;
    }

    public void play() {
        System.out.println("Playing podcast: " + title);
    }

    public void pause() {
        System.out.println("Pausing podcast: " + title);
    }

    public void stop() {
        System.out.println("Stopping podcast: " + title);
    }
}

public class MediaPlayer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Playable media = null;

        while (true) {
            System.out.println("\n--- Media Player ---");
            System.out.println("1. Play Audio");
            System.out.println("2. Play Video");
            System.out.println("3. Play Podcast");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            if (choice == 4) break;

            System.out.print("Enter title: ");
            String title = sc.nextLine();

            switch (choice) {
                case 1:
                    media = new AudioFile(title);
                    break;
                case 2:
                    media = new VideoFile(title);
                    break;
                case 3:
                    media = new Podcast(title);
                    break;
                default:
                    System.out.println("Invalid choice!");
                    continue;
            }

            media.play();
            System.out.println("1. Pause\n2. Stop\n3. Continue");
            System.out.print("Choose action: ");
            int action = sc.nextInt();
            sc.nextLine();

            switch (action) {
                case 1:
                    media.pause();
                    break;
                case 2:
                    media.stop();
                    break;
                case 3:
                    media.play();
                    break;
                default:
                    System.out.println("Invalid action!");
            }
        }

        System.out.println("Exiting Media Player...");
        sc.close();
    }
}
