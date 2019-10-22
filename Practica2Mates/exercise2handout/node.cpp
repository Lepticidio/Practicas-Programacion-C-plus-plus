#include "Node.h"
#include "maths_funcs.h"

Node::Node()
	:parent(0)
{ ; }

void Node::init() { 
	position = vec3(0, 0, 0);
	rotation = versor(0,0,0,1);
	scale = vec3(1,1,1);

	localMatrix = identity_mat4();
	worldMatrix = identity_mat4();
	localInverseMatrix = identity_mat4();
	worldInverseMatrix = identity_mat4();
}

void Node::addChild(Node& node) { 
	node.parent = this;
	children.push_back(&node);
}

void Node::removeChild(Node& node) { 
	auto it = std::find(children.begin(), children.end(), &node);
	if (it != children.end()) {
		node.parent = nullptr;
		children.erase(it);
	}
}

void  Node::updateLocal() 
{ 
	//localMatrix = T*R*S;
	mat4 R = quat_to_mat4(rotation);// rotate_x_deg(localMatrix, rotation.x);
	//R = rotate_y_deg(R, rotation.y);
	//R = rotate_z_deg(R, rotation.z);
	mat4 T = translate(identity_mat4(), position);
	mat4 S = scaler(identity_mat4(), scale);

	localMatrix = T * R * S;

	vec3 invScale = { 1.f / scale.x, 1.f / scale.y, 1.f / scale.z };
	mat4 invS = scaler(identity_mat4(), invScale);

	mat4 invT = translate(identity_mat4(), position*(-1.f));
	mat4 invR = transpose(R);



	//localInverseMatrix = Sinv*transpose(R)*Tinv;
	localInverseMatrix = invS *invR * invT;
}

void  Node::updateHierarchy()
{
	updateLocal();
	mat4 parentMatrix = identity_mat4();
	mat4 parentInverseMatrix = identity_mat4();
	if (parent!= nullptr) {
		parentMatrix = (*parent).worldMatrix;
		parentInverseMatrix = (*parent).worldInverseMatrix;
	}
	worldMatrix = parentMatrix*localMatrix;
	worldInverseMatrix = parentInverseMatrix*localInverseMatrix;

	for (size_t i = 0; i < children.size(); ++i) {
		Node* child = children[i];
		if (child != nullptr) {
			(*child).updateHierarchy();
		}
	}
}
