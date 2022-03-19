// Arup Guha
// Started 6/9/05
// Solution to 2005 World Finals Problem I: Workshops

import java.io.*;
import java.util.*;

public class workshops implements Comparable {

  // Stores information for a single workshop or room.
  private int num_people;
  private int duration;
  private boolean assigned;
  private static int trial_number = 1;

  public static void main(String[] args) throws IOException {

    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    while (processTrial(fin)) {
      trial_number++;
    }

    fin.close();

  }

  // Constructor used for workshop information.
  public workshops(int p, int d) {
    num_people = p;
    duration = d;
    assigned = false;
  }

  // Constructor used for room information.
  public workshops(int p, String t) {

    num_people = p;

    // Convert the time into a duration by subtracting from 2pm.
    StringTokenizer tok = new StringTokenizer(t,":");
    int hr = Integer.parseInt(tok.nextToken());
    int min = Integer.parseInt(tok.nextToken());
    duration = 60*(hr-14)+min;

    assigned = false;
  }

  // Compares to workshops objects. This is written so that each list can
  // be sorted by decreasing order of number of people. For ties, the list
  // is ordered in increasing order of duration.
  public int compareTo(Object other) {

    if (!(other instanceof workshops))
      return 0;

    workshops w = (workshops)other;

    // Compares just based on number of people.
    if (this.num_people > w.num_people)
      return -1;
    else if (this.num_people < w.num_people)
      return 1;

    // Breaks ties using duration.
    if (this.duration < w.duration)
      return -1;
    else if (this.duration > w.duration)
      return 1;

    return 0; // Equal objects!
  }

  public boolean fits(workshops room) {
    return (this.num_people <= room.num_people && 
            this.duration   <= room.duration);
  }

  public static boolean processTrial(BufferedReader fin) throws IOException {

    int w, r;

    // Read in the number of workshops.
    w = Integer.parseInt(fin.readLine().trim());

    // End of file case.
    if (w == 0) return false;

    // Proceed otherwise, reading in information about all of the workshops.
    workshops[] sessions = new workshops[w];
    for (int i=0; i<w; i++) {
      
      StringTokenizer tok = new StringTokenizer(fin.readLine());
      int p = Integer.parseInt(tok.nextToken());
      int d = Integer.parseInt(tok.nextToken());
      sessions[i] = new workshops(p,d);
    }

    // Read in all of the room availability information into an array of rooms.
    r = Integer.parseInt(fin.readLine().trim());
    workshops[] rooms = new workshops[r];
    for (int i=0; i<r; i++) {
      
      StringTokenizer tok = new StringTokenizer(fin.readLine());
      int s = Integer.parseInt(tok.nextToken());
      String t = tok.nextToken();
      rooms[i] = new workshops(s,t);
    }

    doGreedy(sessions, rooms);
    return true;
  }

  public static void doGreedy(workshops[] sessions, workshops[] rooms) {

    Arrays.sort(sessions);
    Arrays.sort(rooms);

    int tents=0, numpeople=0;
    for (int i=0; i<sessions.length; i++) {
      if (!place(i, sessions, rooms)) {
        tents++;
        numpeople += sessions[i].num_people;
      }  
    }

    System.out.println("Trial "+trial_number+":  "+tents+" "+numpeople);
    System.out.println();
  }

  public static boolean place(int cur, workshops[] sessions, 
                                     workshops[] rooms) {

    int best = -1;
    for (int i=0; i<rooms.length; i++) {

      if (sessions[cur].fits(rooms[i])) {

        if (rooms[i].assigned == false) {

          if (best == -1)
            best = i;
          else if (rooms[best].duration > rooms[i].duration)
            best = i;
        }
      }
    }

    if (best == -1) return false;

    sessions[cur].assigned = true;
    rooms[best].assigned = true;

    return true;
  }

}
