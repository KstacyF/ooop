#include <iostream>
#include "dice.h"

void Dice::get_size() {
	std::cout << "Enter the number of sides (2, 4, 6, 8, 10, 12 or 20): ";
	std::cin >> N;
	while (N != 2 && N != 4 && N != 6 && N != 8 && N != 10 && N != 12 && N != 20) {
		std::cout << "Error. Enter the correct number of sides: ";
		std::cin >> N;
	}
	std::cout << "\n";
}

void Dice::uni_dis() {
	for (std::size_t i = 0; i < N; i++) {
		double a = 1.0 / N;
		pr.push_back(a);
	}
}

void Dice::man_inp() {
	std::size_t i;
	double s = 0.0;
	std::cout << "The sum of probabilities must be equal to 1! If not, you should start again\n\n";
	do {
		for (i = 0; i < N; i++) {
			std::cout << "Side " << i + 1 << " probability (0-1): ";
			double a;
			std::cin >> a;
			s += a;
			pr.push_back(a);
		}
		if (s != 1.0) std::cout << "\nTry again!\n\n";
	} while (s != 1.0);
	std::cout << "\n";
}

void Dice::get_pr() {
	std::cout << "Use uniform distribution (1) or manual input (2). ";
	int choice;
	do {
		std::cout << "Enter (1) or (2): ";
		std::cin >> choice;
	} while (choice != 1 && choice != 2);
	std::cout << "\n";
	switch (choice) {
	case 1:
		uni_dis();
		break;
	case 2:
		man_inp();
		break;
	}
}

Dice::Dice() {
	N = 0;
	pr = {};
}

Dice::Dice(std::size_t n, std::vector<double> prob) {
	if (prob.size() != n) {
		std::cout << "Number of sides and probabilities are not the same";
		N = 0;
		pr = {};
		return;
	}
	N = n;
	for (int i = 0; i < n; i++)
		pr.push_back(prob[i]);
}

void Dice::get_die() {
	get_size();
	get_pr();
}

void Dice::print() {
	std::size_t i;
	for (i = 0; i < N; i++) {
		std::cout << "Side " << i + 1 << ", probability: " << pr[i] << "\n";
	}
	std::cout << "\n";
}

void Node::print() {
	std::cout << "Sum is " << sum << ", probability is " << prob * 100 << "%\n";
}

Result::Result() {
	result = {};
	size = 0;
}

void Result::add(Node to_add) {
	result.push_back(to_add);
	size++;
}

void Result::print() {
	if (result.empty()) {
		std::cout << "Error! Set is probably empty\n\n";
		return;
	}
	for (std::size_t i = 0; i < size; i++) result[i].print();
	std::cout << "\n";
}

void Result::exp_res(Result& res) {
	if (result.empty()) {
		return;
	}
	Node* in_res = new Node;
	in_res->prob = 0.00;
	in_res->sum = 0;
	double max_pr = 0.00;
	for (std::size_t i = 0; i < size; i++) {
		if (result[i].prob > max_pr) max_pr = result[i].prob;
	}
	for (std::size_t i = 0; i < size; i++) {
		if (result[i].prob == max_pr) {
			in_res->prob = max_pr;
			in_res->sum = result[i].sum;
			res.add(*in_res);
		}
	}
}

std::size_t Result::max_sum() {
	std::size_t max = 0;
	if (result.empty()) return max;
	for (std::size_t i = 0; i < size; i++) {
		if (result[i].sum > max) max = result[i].sum;
	}
	return max;
}

void comparison(Result one, Result two) {
	Result c1; one.exp_res(c1);
	Result c2; two.exp_res(c2);
	std::cout << "Expected sum(s), result 1:\n";
	c1.print();
	std::cout << "Expected sum(s), result 2:\n";
	c2.print();
	std::size_t max1 = c1.max_sum(), max2 = c2.max_sum();
	std::cout << "Max expected sum 1 -- " << max1 << ", sum 2 -- " << max2 << "\n\n";
}

Set::Set() {
	size = 0;
	set = {};
}

void Set::add(Dice d) {
	set.push_back(d);
	size++;
}

void Set::pop_back() {
	if (set.empty()) return;
	set.pop_back();
	size--;
}

void Set::rec_sum(std::size_t sum, double pr, Result& res, std::size_t die_num) {
	for (std::size_t a = 0; a < set[die_num].N; a++) {
		if (set[die_num].pr[a] != 0) {
			sum += a + 1;
			pr *= set[die_num].pr[a];
			if (die_num + 1 < size) {
				die_num++;
				rec_sum(sum, pr, res, die_num);
				die_num--;
			}
			else {
				res.add({ sum, pr });
			}
			sum -= a + 1;
			pr /= set[die_num].pr[a];
		}
	}
}

void Set::sum(Result& res) {
	std::size_t s = 0, i = 0;
	double p = 1.0;
	if (!set.empty()) {
		rec_sum(s, p, res, i);
	}
	else {
		std::cout << "Set is empty\n\n";
	}
}

void Set::print() {
	if (set.empty()) {
		std::cout << "Set is empty\n\n";
		return;
	}
	std::size_t i = 0;
	while (i < size) {
		std::cout << "Dice " << i + 1 << ":\n";
		set[i].print();
		i++;
	}
}