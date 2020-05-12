#pragma once
#include "def.h"

#include <functional>
#include <list>

namespace nail {

template<typename NodeType>
class Tree;

template<typename NodeType>
struct TreeNode {
	ref<NodeType> data;
	std::list<ref<Tree<NodeType>>> childs;
};

template<typename NodeType>
class Tree {
public:
	enum class TraverseType: std::int8_t{
		Inorder,
		Preorder,
		Postorder
	};
	using NodeRef = ref<TreeNode<NodeType>>;
	using TraverseProcessor = std::function<bool(NodeRef)>;

	bool traverse(TraverseType way, TraverseProcessor& processor){
		if (!_root) {
			return false;
		}

		switch(way) {
			case TraverseType::Inorder:{
				return inorderTraverse(_root, processor);
			}
			case TraverseType::Preorder:{
				return preorderTraverse(_root, processor);
			}
			case TraverseType::Postorder:{
				return postorderTraverse(_root, processor);
			}
			default:
				return false;
		}
	}

private:
	NodeRef _root;

	// bool inorderTraverse(NodeRef node, TraverseProcessor& processor) {
	// 	return false
	// }

	bool preorderTraverse(NodeRef node, TraverseProcessor& processor) {
		if (!node) {
			return false;
		}
		if (!processor(node)) {
			return false;
		}
		
		if (0 < node->childs.size()){
			for (auto& child : node->childs) {
				if (!processor(child)){
					return false;
				}
			}
		}

		return true;
	}

	bool postorderTraverse(NodeRef node, TraverseProcessor& processor){
		if (!node) {
			return false;
		}

		if (0 < node->childs.size()){
			for (auto& child : node->childs) {
				if (!processor(child)){
					return false;
				}
			}
		}

		return processor(node);
	}
};



}