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
                if (this.left != null) left = this.left.Write_Tree();

                String right = "";
                if (this.right != null) right = this.right.Write_Tree();

                return left + " " + data + " " + right;

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
                    if (data.CompareTo(son.data) > 0)
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
                if ((son.data).CompareTo(data) > 0)
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
            else return "EMPTY";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
