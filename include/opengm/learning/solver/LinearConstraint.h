#ifndef INFERENCE_LINEAR_CONSTRAINT_H__
#define INFERENCE_LINEAR_CONSTRAINT_H__

#include <map>

#include "Relation.h"

namespace opengm {
namespace learning {
namespace solver {

/**
 * A sparse linear constraint.
 */
class LinearConstraint {

public:

	LinearConstraint();

	void setCoefficient(unsigned int varNum, double coef);

	void setRelation(Relation relation);

	void setValue(double value);

	const std::map<unsigned int, double>& getCoefficients() const;

	const Relation& getRelation() const;

	double getValue() const;

private:

	std::map<unsigned int, double> _coefs;

	Relation _relation;

	double _value;
};

LinearConstraint::LinearConstraint() :
	_relation(LessEqual) {}

void
LinearConstraint::setCoefficient(unsigned int varNum, double coef) {

	if (coef == 0) {

		std::map<unsigned int, double>::iterator i = _coefs.find(varNum);
		if (i != _coefs.end())
			_coefs.erase(_coefs.find(varNum));

	} else {

		_coefs[varNum] = coef;
	}
}

void
LinearConstraint::setRelation(Relation relation) {

	_relation = relation;
}

void
LinearConstraint::setValue(double value) {

	_value = value;
}

const std::map<unsigned int, double>&
LinearConstraint::getCoefficients() const {

	return _coefs;
}

const Relation&
LinearConstraint::getRelation() const {

	return _relation;
}

double
LinearConstraint::getValue() const {

	return _value;
}

}}} // namspace opengm::learning::solver

#endif // INFERENCE_LINEAR_CONSTRAINT_H__

