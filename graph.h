#pragma once
#include <list>
#include <stdexcept>
#include <string>

class NotValidEdgeAjdMatException : std::exception {

	public:
		NotValidEdgeAjdMatException(std::string msg) : message(msg) {}

		virtual const char* what() const noexcept (true) {
			return message.c_str();
		}

		std::string message;
};


class InvalidVeriticesException : std::exception {

	public:
		InvalidVeriticesException(std::string msg) : message(msg) {}

		virtual const char* what() const noexcept (true) {
			return message.c_str();
		}

		std::string message;
};

template<typename T>
class GraphUsingAdjMat {

	public:
		GraphUsingAdjMat(int vertices);
		~GraphUsingAdjMat();
		const int getVerticesCount() const;
		bool addEdge(const int i, const int j);
		bool removeEdge(const int i, const int j);
		bool hasEdge(const int i, const int j) const;
		std::list<int> outEdges(const int i) const;
		std::list<int> inEdges(const int j) const;


	private:
		int vertices;
		int** mat;
};

template<typename T>
GraphUsingAdjMat<T>::GraphUsingAdjMat(int vertices) : vertices(vertices) {

	if(vertices <= 0) {
		throw InvalidVeriticesException("Number of vertices cannot be zero or less than zer0");
	}

	mat = new T*[vertices];
	for(int j = 0; j < vertices; ++j){
		mat[j] = new T[vertices];
	}

	for(int i = 0; i < vertices; ++i) {
		for(int j = 0; j < vertices; ++j) {
			mat[i][j] = 0;
		}
	}	
}


template<typename T>
GraphUsingAdjMat<T>::~GraphUsingAdjMat() {
	
	if(mat != nullptr) {
		for(int j = 0; j < vertices; ++j) {
			delete[] mat[j];
		}

		delete[] mat;
		mat = nullptr;
	}
	vertices = 0;
}

template <typename T>
const int GraphUsingAdjMat<T>::getVerticesCount() const{

	return vertices;
}

template<typename T>
bool GraphUsingAdjMat<T>::addEdge(const int i, const int j) {

	if(i < 0 || i >= vertices || j < 0 || j >= vertices) {
		throw NotValidEdgeAjdMatException("invalid Edge");
	}

	mat[i][j] = 1;

	return true;
}


template<typename T>
bool GraphUsingAdjMat<T>::removeEdge(const int i, const int j) {
	
	if(i < 0 || i >= vertices || j < 0 || j >= vertices) {
		throw NotValidEdgeAjdMatException("invalid Edge");
	}

	mat[i][j] = 0;

	return true;
}


template<typename T>
bool GraphUsingAdjMat<T>::hasEdge(const int i, const int j) const {

	if(i < 0 || i >= vertices || j < 0 || j >= vertices) {
		throw NotValidEdgeAjdMatException("invalid Edge");
	}

	return (mat[i][j] == 1 ? true : false); 
}


template<typename T>
std::list<int> GraphUsingAdjMat<T>::outEdges(const int i) const {

	if(i < 0 || i >= vertices) {
		throw NotValidEdgeAjdMatException("invalid Edge");
	}

	std::list<int> retval;
	for(int j = 0; j < vertices; ++j) {
		if(mat[i][j] == 1) {
			retval.push_back(j);
		}
	}

	return retval;
}


template<typename T>
std::list<int> GraphUsingAdjMat<T>::inEdges(const int j) const {

	if(j < 0 || j >= vertices) {
		throw NotValidEdgeAjdMatException("invalid Edge");
	}

	std::list<int> retval;
	for(int i = 0; i < vertices; ++i) {
		if(mat[i][j] == 1) {
			retval.push_back(i);
		}
	}

	return retval;
}
