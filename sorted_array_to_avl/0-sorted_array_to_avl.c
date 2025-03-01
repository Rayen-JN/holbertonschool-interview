#include "binary_trees.h"

/**
 * binary_tree_node - builds an AVL tree node from an array
 * @parent: parent node
 * @index: index of the current node in the array
 * @array: the array containing the values to be inserted
 *
 * Return: pointer to the created AVL tree node, or NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int index, int *array)
{
    avl_t *new_node = NULL;

    new_node = malloc(sizeof(avl_t));
    if (!new_node)
        return (NULL);

    new_node->left = new_node->right = NULL;
    new_node->n = array[index];
    new_node->parent = parent;

    return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: the sorted array
 * @size: the size of the array
 *
 * Return: pointer to the root of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *new_node = NULL;

    if (!array || !size)
        return (NULL);

    new_node = SortedArrayToAVL(array, 0, size - 1, NULL);
    return (new_node);
}

/**
 * SortedArrayToAVL - recursive function to build an AVL tree from a sorted array
 * @array: the sorted array
 * @start: start index of the current subarray
 * @end: end index of the current subarray
 * @root: parent node for the current subarray
 *
 * Return: pointer to the root of the subtree, or NULL on failure
 */
avl_t *SortedArrayToAVL(int *array, size_t start, size_t end, avl_t *root)
{
    size_t mid;
    avl_t *new_node = NULL;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    new_node = binary_tree_node(root, mid, array);
    if (!new_node)
        return (NULL);

    if (mid != start)
        new_node->left = SortedArrayToAVL(array, start, mid - 1, new_node);

    if (mid != end)
        new_node->right = SortedArrayToAVL(array, mid + 1, end, new_node);

    return (new_node);
}
