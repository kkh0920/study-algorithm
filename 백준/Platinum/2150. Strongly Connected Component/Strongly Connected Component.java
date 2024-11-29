import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main {
    public static int V, E, sccCount = 0;

    public static boolean[] visited;

    public static List<Integer>[] graph, reverse;

    public static Stack<Integer> stack = new Stack<>();

    public static List<List<Integer>> sccLists = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        /*  1. init  */
        graph = new List[V + 1];
        reverse = new List[V + 1];
        for(int i = 1; i <= V; i++) {
            graph[i] = new LinkedList<>();
            reverse[i] = new LinkedList<>();

        }

        /*  2. input  */
        int A, B;
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            graph[A].add(B);
            reverse[B].add(A);
        }

        /*  3. kosaraju  */
        kosaraju();
    }

    public static void kosaraju() {
        // 1. 순방향 DFS (탐색이 종료되는 노드부터 스택에 삽입)
        visited = new boolean[V + 1];
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }

        // 2. 스택의 상단 요소부터 역방향 DFS (SCC 탐색)
        visited = new boolean[V + 1];
        while(!stack.empty()) {
            List<Integer> scc = new LinkedList<>();
            int node = stack.pop();
            if(!visited[node]) {
                findSCC(node, scc);
                Collections.sort(scc); // 각 SCC 정점을 오름차순 정렬
                sccLists.add(scc);
            } 
        }

        // 3. SCC 리스트 정렬 후 결과 출력
        Collections.sort(sccLists, (a, b) -> {
            return a.get(0) - b.get(0);
        });
        printResult();
    }

    public static void dfs(int node) {
        if(visited[node]) return;
        visited[node] = true;
        for(int next: graph[node]) {
            dfs(next);
        }
        stack.push(node);
    }

    public static void findSCC(int node, List<Integer> scc) {
        if(visited[node]) return;
        visited[node] = true;
        scc.add(node);
        for(int next: reverse[node]) {
            findSCC(next, scc);
        }
    }

    public static void printResult() {
        System.out.println(sccLists.size());
        for(List<Integer> scc: sccLists) {
            for(int node: scc) {
                System.out.print(node + " ");
            }
            System.out.println(-1);
        }
    }
}