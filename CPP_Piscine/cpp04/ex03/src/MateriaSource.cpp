/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:05:39 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 17:56:38 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : numLearned(0) {
	for (int i = 0; i < 4; ++i) {
		learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : numLearned(0) {
	for (int i = 0; i < 4; ++i) {
		if (other.learnedMaterias[i] != NULL) {
			this->learnedMaterias[i] = other.learnedMaterias[i]->clone();
			++numLearned;
		} else {
			this->learnedMaterias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete learnedMaterias[i];
			learnedMaterias[i] = NULL;
		}
		numLearned = 0;

		for (int i = 0; i < 4; ++i) {
			if (other.learnedMaterias[i] != NULL) {
				this->learnedMaterias[i] = other.learnedMaterias[i]->clone();
				++numLearned;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete learnedMaterias[i];
		learnedMaterias[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	if (numLearned < 4 && m != NULL) {
		learnedMaterias[numLearned++] = m->clone();
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i) {
		if (learnedMaterias[i] && learnedMaterias[i]->getType() == type) {
			return learnedMaterias[i]->clone();
		}
	}
	return NULL;
}
