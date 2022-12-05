#pragma once

#ifndef DICE_H
#define DICE_H

#include <vector>

class Dice {
	void uni_dis();
	void man_inp();
	void get_pr();
	void get_size();
public:
	std::vector<double> pr;
	std::size_t N;
	Dice();
	Dice(std::size_t n, std::vector<double> prob);
	void print();
	void get_die();
};

class Node {
public:
	std::size_t sum;
	double prob;

	Node(std::size_t sum = 0, double prob = 0.0) {
		this->sum = sum;
		this->prob = prob;
	}

	void print();
};

class Result {
	std::vector<Node> result;
	std::size_t size;
public:
	Result();
	void add(Node to_add);
	void print();
	void exp_res(Result& res);
	std::size_t max_sum();
};

void comparison(Result one, Result two);

class Set {
	std::vector<Dice> set;
	std::size_t size;

	void rec_sum(std::size_t sum, double pr, Result& res, std::size_t die_num);
public:
	Set();
	void add(Dice d);
	void pop_back();
	void sum(Result& res);
	void print();
};

#endif