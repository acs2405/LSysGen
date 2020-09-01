
#include "Rule.h"


namespace lsysgen {

template<typename T>
const weight_t Rule<T>::WEIGHT_ALWAYS = -1.0;
template<typename T>
const weight_t Rule<T>::WEIGHT_UNSET = 1.0;

template<typename T>
Rule<T>::Rule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside):
			tag(tag), weight(weight), lctx(lctx), lside(lside), rctx(rctx), rside(rside) {}

template<typename T>
Rule<T>::~Rule() {
	delete lctx;
	delete lside;
	delete rctx;
	delete rside;
}

template<typename T>
char Rule<T>::leftChar() const {
	return this->lside->content()->element();
}

template<typename T>
std::string Rule<T>::toString() {
	err("Shouldn't be in this function (Rule<T>::toString())");
	return "";
}

template<typename T>
std::list<Parameter*>* Rule<T>::params() {
	return this->lside->content()->params;
}

template<typename T>
LSysDParser::ExpressionContext* Rule<T>::cond() {
	return this->lside->content()->cond;
}

template<typename T>
bool Rule<T>::isProductionRule() const {return false;}

template<typename T>
std::string Rule<T>::toStringBase(std::string arrow) {
	std::string slctx = "", srctx = "";
	if (lctx != nullptr)
		slctx = lctx->toString() + "<";
	if (rctx != nullptr)
		srctx = ">" + rctx->toString();
	return slctx + this->lside->toString() + srctx + " " + arrow + " " + this->rside->toString();
}

template<typename T>
ProductionRule<T>::ProductionRule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside):
			Rule<T>(tag, weight, lctx, lside, rctx, rside) {}

template<typename T>
bool ProductionRule<T>::isProductionRule() const {return true;}

template<typename T>
std::string ProductionRule<T>::toString() {
	return Rule<T>::toStringBase("->");
}

template<typename T>
CodingRule<T>::CodingRule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside):
			Rule<T>(tag, weight, lctx, lside, rctx, rside) {}

template<typename T>
bool CodingRule<T>::isProductionRule() const {return false;}

template<typename T>
std::string CodingRule<T>::toString() {
	return Rule<T>::toStringBase("=>");
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Rule<T>& r) {
	return os << r.toString() << std::endl;
}



template class Rule<char>;
template class ProductionRule<char>;
template class CodingRule<char>;

}
