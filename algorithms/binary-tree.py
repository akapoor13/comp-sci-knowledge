class Binary_Tree:
    def __init__(self, data, left=None, right=None):
        self.val = data
        self.left = left
        self.right = right


def inorder_traversal_recursive(root):
    # Problem 94
    if (root == None):
        return []
    else:
        return inorder_traversal_recursive(root.left) + [root.val] + inorder_traversal_recursive(root.right)


def inorder_traversal_iterative(root):
    # Problem 94
    result = []
    stack = []
    curr = root

    while(curr != None or len(stack) != 0):
        while(curr):
            stack.append(curr)
            curr = curr.left

        curr = stack.pop()
        result.append(curr.val)
        curr = stack.right

    return result
