# Problem Set 4A
# Name: MorningKay
# Collaborators:

from tree import Node # Imports the Node object used to construct trees

# Part A0: Data representation
# Fill out the following variables correctly.
# If correct, the test named test_data_representation should pass.
tree1 = Node(8, Node(2, Node(1), Node(6)), Node(10)) #TODO
tree2 = Node(7, Node(2, Node(1), Node(5, Node(3), Node(6))), Node(9, Node(8), Node(10))) #TODO
tree3 = Node(5, Node(3, Node(2), Node(4)), Node(14, Node(12), Node(21, Node(20), Node(26)))) #TODO

def find_tree_height(tree):
    '''
    Find the height of the given tree
    Input:
        tree: An element of type Node constructing a tree
    Output:
        The integer depth of the tree
    '''
    if tree.left == None and tree.right == None:
        return 0
    elif tree.left == None:
        return 1 + find_tree_height(tree.right)
    elif tree.right == None:
        return 1 + find_tree_height(tree.left)
    else:
        return 1 + max(find_tree_height(tree.left), find_tree_height(tree.right))
    

def is_heap(tree, compare_func):
    '''
    Determines if the tree is a max or min heap depending on compare_func
    Inputs:
        tree: An element of type Node constructing a tree
        compare_func: a function that compares the child node value to the parent node value
            i.e. op(child_value,parent_value) for a max heap would return True if child_value < parent_value and False otherwise
                 op(child_value,parent_value) for a min meap would return True if child_value > parent_value and False otherwise
    Output:
        True if the entire tree satisfies the compare_func function; False otherwise
    '''
    if tree.left == None and tree.right == None:
        # print(f"the node {tree.value} is a leaf")
        return True
    elif tree.left == None:
        # print(f"the node {tree.value}'s left is none")
        if not compare_func(tree.right.value, tree.value):
            return False
        return is_heap(tree.right, compare_func)
    elif tree.right == None:
        # print(f"the node {tree.value}'s right is none")
        if not compare_func(tree.left.value, tree.value):
            return False
        return is_heap(tree.left, compare_func)
    else:
        # print(f"this node {tree.value} has left and right childs")
        if not compare_func(tree.left.value, tree.value) or not compare_func(tree.right.value, tree.value):
            return False
        return is_heap(tree.left, compare_func) and is_heap(tree.right, compare_func)


if __name__ == '__main__':
    # You can use this part for your own testing and debugging purposes.
    # IMPORTANT: Do not erase the pass statement below if you do not add your own code
    
    # print(tr2)
    # print(type(tr2.right.right), tr2.right.right.value)
    # print(is_heap(tr2.right.right, lambda x,y:x>y))
    tr2 = Node(2,Node(3,Node(4),Node(5,Node(6))),Node(7,None,Node(8,Node(9),Node(1))))
    print(is_heap(tr2, lambda x,y:x>y)) # checking the min heap
    pass
