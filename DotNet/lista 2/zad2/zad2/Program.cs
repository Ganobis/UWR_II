using System;

namespace zad2
{
    class BinaryTreeNode<T>
    {
        private class Node<T>
        {
            public Node<T> left;
            public Node<T> right;
            public T data;
            
            public Node(T data)
            {
                left = null;
                right = null;
                this.data = data;
            }

            public String Write_Tree()
            {
                String left = "";
                if (this.left != null) 
                    left = this.left.Write_Tree();

                String right = "";
                if (this.right != null) 
                    right = this.right.Write_Tree();

                return "(" + left + " " + data + " " + right + ")";

            }

            public String DFS_without()
            {
                String left = "";
                if (this.left != null)
                    left = this.left.DFS_without();

                String right = "";
                if (this.right != null)
                    right = this.right.DFS_without();

                return data + " " + left + " " + right;
            }

            private int depth()
            {
                int d_left = 0, d_right = 0;

                if (left != null)
                    d_left = 1 + left.depth();

                if (right != null)
                    d_right = 1 + right.depth(); 

                if (d_left > d_right)
                    return d_left;
                else return d_right;
            }

            private String show_level(int x)
            {
                String ret = "";
                if (x == 0)
                    ret += data;
                else
                {
                    String l = "";
                    String r = "";
                    if(left != null)
                        l = left.show_level(x - 1);
                    if (right != null)
                        r = right.show_level(x - 1);
                    ret = l + " " + r;
                }
                return ret;
            }
            public String BFS_without()
            {
                String ret = "";
                ret += data;
                for(int i = 1; i < depth() + 1; i++)
                {
                    ret += " " + show_level(i);
                }
                return ret;
            }
        }

        private Node<T> root;

        public void insert(T data)
        {
            if(root == null)
            {
                root = new Node<T>(data);
            }
            else
            {
                Node<T> son = root;

                while (son != null)
                {
                    if(Convert.ToInt32(data).CompareTo(Convert.ToInt32(son.data)) > 0)
                    {
                        if (son.right == null)
                            break;
                        son = son.right;
                    }
                    else
                    {
                        if (son.left == null)
                            break;
                        son = son.left;
                    }
                }
                Node<T> n = new Node<T>(data);
                if (Convert.ToInt32(data).CompareTo(Convert.ToInt32(son.data)) > 0)
                {
                    son.right = n;
                }
                else
                {
                    son.left = n;
                }
            }
        }

        public String Write_Tree()
        {
            if (root != null)
            {
                return root.Write_Tree();
            }
            else return "EMPTY!";
        }

        public String DFS_without()
        {
            if (root != null)
            {
                return root.DFS_without();
            }
            else return "EMPTY!";
        }

        public String BFS_without()
        {
            if (root != null)
            {
                return root.BFS_without();
            }
            else return "EMPTY!";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTreeNode<int> tree = new BinaryTreeNode<int>();
            Console.WriteLine(tree.Write_Tree());
            tree.insert(5);
            tree.insert(3);
            tree.insert(4);
            tree.insert(9);
            tree.insert(1);
            tree.insert(0);
            tree.insert(2);
            Console.WriteLine(tree.Write_Tree());
            Console.WriteLine(tree.DFS_without());
            Console.WriteLine(tree.BFS_without());

            BinaryTreeNode<String> tree2 = new BinaryTreeNode<String>();
            tree2.insert("222");
            tree2.insert("111");
            tree2.insert("333");
            tree2.insert("000");
            Console.WriteLine(tree2.Write_Tree());
            Console.WriteLine(tree2.DFS_without());
            Console.WriteLine(tree2.BFS_without());
        }
    }
}
