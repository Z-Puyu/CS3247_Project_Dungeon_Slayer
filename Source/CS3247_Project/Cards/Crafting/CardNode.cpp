// Fill out your copyright notice in the Description page of Project Settings.


#include "CardNode.h"
bool UCardNode::AddSuccessor(UCardNode* Node) {
	if (IsValid(Node->Predecessor) || this->Successors.Contains(Node)) {
		return false;
	}

	Node->Predecessor = this;
	this->Successors.Add(Node);
	return true;
}

bool UCardNode::BreakLinkWith(UCardNode* Node) {
	if (!IsValid(Node)) {
		return false;
	}
		
	if (this->Precedes(Node)) {
		Node->Predecessor = nullptr;
		this->Successors.Remove(Node);
		return true;
	}

	if (this->Succeeds(Node)) {
		this->Predecessor = nullptr;
		Node->Successors.Remove(this);
		return true;
	}
		
	return false;
}

int UCardNode::CountBuildableConnectedNodes() {
	int Count = 0;
	TSet<UCardNode*> Visited = {};
	TQueue<UCardNode*> Queue = {};
	Queue.Enqueue(this);
	UCardNode* Curr;
	while (Queue.Dequeue(Curr)) {
		Visited.Add(Curr);
		if (Curr->IsReadyToCraft()) {
			Count += 1;
		}

		if (IsValid(this->Predecessor) && !Visited.Contains(this->Predecessor)) {
			Queue.Enqueue(this->Predecessor);
		}
        	
		for (auto& Successor : Curr->Successors) {
			if (!Visited.Contains(Successor)) {
				Queue.Enqueue(Successor);
			}
		}
	}
		
	return Count;
}

TArray<UEffectBlock*> UCardNode::Build() {
	if (this->IsTerminal()) {
		return {NewObject<UEffectBlock>(this)->WithImpact(Cast<UCardImpact>(this->Ingredient))};
	}

	TArray<UEffectBlock*> Blocks = {};
	
	if (this->Ingredient->IsA(UCardEnchantment::StaticClass())) {
		UCardEnchantment* Enchantment = Cast<UCardEnchantment>(this->Ingredient);
		for (const auto& Successor : this->Successors) {
			for (const auto& Block : Successor->Build()) {
				Blocks.Add(Block->Append(Enchantment));
			}
		}
		
		return Blocks;
	}

	for (const auto& Successor : this->Successors) {
		Blocks.Append(Successor->Build());
	}
	
	return Blocks;
}

UCardNode* UCardNode::GetRoot() {
	if (!IsValid(this->Predecessor)) {
		return this;
	}

	return this->Predecessor->GetRoot();
}
