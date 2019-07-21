/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:40:46 by vokrut            #+#    #+#             */
/*   Updated: 2019/07/21 12:41:11 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void calculate_max(Node *root, int current_height, int *max_height) {
        //Check if current height greater than maximum height
        if (current_height > *max_height)
            *max_height = current_height;
        //Go left side
        if (root->left)
            calculate_max(root->left, current_height + 1, max_height);
        //Go right side
        if (root->right)
            calculate_max(root->right, current_height + 1, max_height);
    }
    int height(Node* root) {
        int max_height = 0;
        
        //If tree does not exist
        if (!root)
            return -1;
        //Calculate maximum height using recursion
        calculate_max(root, 0, &max_height);
        return max_height;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}
