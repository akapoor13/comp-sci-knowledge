class BST:
    def __init__(self, data, left=None, right=None):
        self.val = data
        self.left = left
        self.right = right


def unique_bst_generator(n):
    # Problem 95
    def generate_trees(start, end):
        if start > end:
            return [None]

        all_trees = []
        for i in range(start, end+1):
            left_trees = generate_trees(start, i-1)
            right_trees = generate_trees(i+1, end)

            for l in left_trees:
                for r in right_trees:
                    all_trees.append(BST(i, l, r))

        return all_trees

    if (n <= 0):
        return []
    else:
        return generate_trees(1, n)


def unique_bst_num(n):
    # Problem 96
    return 1
