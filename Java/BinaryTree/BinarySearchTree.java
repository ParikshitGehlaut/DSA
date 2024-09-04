package BST;

public class BinarySearchTree {
    class Node {
        int val;
        Node right;
        Node left;

        Node(int val) {
            this.val = val;
        }
    }

    public Node insert(Node root, int val) {
        if (root == null) {
            root = new Node(val);
            return root;
        }
        if (root.val < val) {
            root.right = insert(root.right, val);
        } else {
            root.left = insert(root.left, val);
        }
        return root;
    }

    public void inorderTraversal(Node root) {
        if (root == null)
            return;

        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }

    public void preorderTraversal(Node root) {
        if (root == null)
            return;

        System.out.print(root.val + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    public void postorderTraversal(Node root) {
        if (root == null)
            return;

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.val + " ");
    }

    public boolean search(Node root, int key) {
        if (root == null)
            return false;

        if (root.val > key) {
            return search(root.left, key);
        } else if (root.val == key) {
            return true;
        } else {
            return search(root.right, key);
        }
    }

    public Node delete(Node root, int key) {
        if (root == null)
            return null;

        if (root.val < key) {
            root.right = delete(root.right, key);
        } else if (root.val > key) {
            root.left = delete(root.left, key);
        } else {
            // Node with no child
            if (root.right == null && root.left == null)
                return null;
            // Node with only one child
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            // Node with two children: Get the inorder successor (smallest in the right
            // subtree)
            Node IS = InorderSuccessor(root.right);
            root.val = IS.val;
            root.right = delete(root.right, IS.val);
        }
        return root;
    }

    public Node InorderSuccessor(Node root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

    public static void main(String[] args) {
        int[] arr = { 12, 5, 1, 3, 4, 2, 7, 11, 13, 17, 36, 52, 6, 19 };
        Node root = null;

        BinarySearchTree tree = new BinarySearchTree();
        for (int i = 0; i < arr.length; i++) {
            root = tree.insert(root, arr[i]);
        }

        System.out.print("Inorder Traversal: ");
        tree.inorderTraversal(root);
        System.out.println();

        System.out.print("Preorder Traversal: ");
        tree.preorderTraversal(root);
        System.out.println();

        System.out.print("Postorder Traversal: ");
        tree.postorderTraversal(root);
        System.out.println();

        System.out.println("Search 19: " + tree.search(root, 19));

        root = tree.delete(root, 6);
        System.out.print("After deleting 6, Inorder Traversal: ");
        tree.inorderTraversal(root);
        System.out.println();

        root = tree.delete(root, 7);
        System.out.print("After deleting 7, Inorder Traversal: ");
        tree.inorderTraversal(root);
        System.out.println();

        root = tree.delete(root, 52);
        System.out.print("After deleting 52, Inorder Traversal: ");
        tree.inorderTraversal(root);
        System.out.println();

        root = tree.delete(root, 11);
        System.out.print("After deleting 11, Inorder Traversal: ");
        tree.inorderTraversal(root);
        System.out.println();
    }
}
