import java.util.LinkedList;
import java.util.Queue;

public class CompleteBinaryTree{
    static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val){
            this.val = val;
            left = right = null;
        }
    }

    static class CompleteBinary{
        TreeNode root;

        public void insert(int val){
            TreeNode newNode = new TreeNode(val);

            if(root == null){
                root = newNode;
                return;
            }

            LinkedList<TreeNode> queue = new LinkedList<>();
            queue.add(root);

            while(!queue.isEmpty()){
                TreeNode current = queue.poll();

                if(current.left == null){
                    current.left = newNode;
                    return;
                }else{
                    queue.add(current.left);
                }

                if(current.right == null){
                    current.right = newNode;
                    return;
                }else{
                    queue.add(current.right);
                }
            }
        }

        public void levelorder(){
            if(root == null){
                System.out.println("Tree is empty");
                return;
            }

            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);

            while(!queue.isEmpty()){
                TreeNode current = queue.poll();
                System.out.print(current.val + " ");

                if(current.left != null){
                    queue.add(current.left);
                }

                if(current.right != null){
                    queue.add(current.right);
                }
            }
        System.out.println();
        }

        public void lastsum(){
            if(root == null){
                System.out.println(0);
            }

            int sum = 0;
            TreeNode current = root;
            while(current != null){
                sum += current.val;
                current = current.right;
            }

            System.out.println(sum);
        }

        public int minDistance(){
            if(root == null) return 0;

            Queue<TreeNode> q = new LinkedList<>();
            q.add(root);
            q.add(null);
            int res = 1;
            while(!q.isEmpty()){
                TreeNode node = q.poll();
                if(node == null){
                    res++;
                    if(!q.isEmpty()){
                        q.add(null);
                    }
                }else{
                    if(node.left == null && node.right == null) return res;
                    if(node.left != null) q.add(node.left);
                    if(node.right != null) q.add(node.right);
                }
            }
            return res;
        }
    }
    public static void main(String args[]){
        CompleteBinary Tree = new CompleteBinary();
        Tree.insert(1);
        Tree.insert(2);
        Tree.insert(3);
        Tree.insert(4);
        Tree.insert(5);
        Tree.insert(6);
        Tree.insert(7);
        Tree.insert(8);

        Tree.levelorder();
        Tree.lastsum();
        int result = Tree.minDistance();
        System.out.println(result);
    }
}