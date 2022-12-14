import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    final int Hat_N = (int) 2e5 + 3;
    int n = cin.nextInt(), min = 0;
    int[] v = new int[Hat_N], tar = new int[Hat_N];
    boolean[] app = new boolean[Hat_N];
    app[0] = false;
    for (int i = 1; i < n; ++i) {
      app[i] = false;
      v[i] = cin.nextInt();
      tar[i] = tar[i - 1] + v[i];
      if (tar[i] < min) {
        min = tar[i];
      }
    }
    --min;
    for (int i = 0; i < n; ++i) {
      tar[i] -= min;
      if (tar[i] > n || tar[i] < 1) {
        System.out.println(-1);
        cin.close();
        return;
      }
      app[tar[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
      if (!app[i]) {
        System.out.println(-1);
        cin.close();
        return;
      }
    }
    for (int i = 0; i < n; ++i) {
      System.out.print(tar[i]);
      System.out.print(' ');
    }
    cin.close();
  }
}

/*
 * ###################################################################
 * #.................................................................#
 * #.............#......#............Created.By.RBTree...............#
 * #............#.#....#.#........... Limiting-Factor................#
 * #.............########............................................#
 * #............#........#..##############################...........#
 * #...........#..V........V..#..#........................#..#...#...#
 * #............#........#....#..........###..###..........#..#.#.#..#
 * #............#..X##X..#..#............#....#.#...........#..#...#.#
 * #...........#...N##N...#..#...........###..###..........#.........#
 * #.......MOO..#..@.....#....#.#.#.#...................#.#..........#
 * #.............########.....#.#.#.##############.#.#..#.#..........#
 * #..........................#.#.#.#.............#.#.#.#.#..........#
 * #......#########...........#.#.#.#.................#.#.#..........#
 * #.....#.........#..........#.#.#.#.................#.#.#..........#
 * #.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
 * #.###################......#.#.#.#.................#.#.#..........#
 * #...........................#.#.#...................#.#...........#
 * #.................................................................#
 * ###################################################################
 */