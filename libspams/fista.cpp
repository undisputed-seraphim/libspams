#include "fista.h"

FISTA::regul_t FISTA::regul_from_string(char* regul)
{
	if (strcmp(regul, "l0") == 0) return L0;
	if (strcmp(regul, "l1") == 0) return L1;
	if (strcmp(regul, "l2") == 0) return RIDGE;
	if (strcmp(regul, "linf") == 0) return LINF;
	if (strcmp(regul, "l2-not-squared") == 0) return L2;
	if (strcmp(regul, "log-dc") == 0) return LOG_DC;
	if (strcmp(regul, "l1-constraint") == 0) return L1CONSTRAINT;
	if (strcmp(regul, "elastic-net") == 0) return ELASTICNET;
	if (strcmp(regul, "fused-lasso") == 0) return FUSEDLASSO;
	if (strcmp(regul, "group-lasso-l2") == 0) return GROUPLASSO_L2;
	if (strcmp(regul, "group-lasso-linf") == 0) return GROUPLASSO_LINF;
	if (strcmp(regul, "sparse-group-lasso-l2") == 0) return GROUPLASSO_L2_L1;
	if (strcmp(regul, "sparse-group-lasso-linf") == 0) return GROUPLASSO_LINF_L1;
	if (strcmp(regul, "l1l2") == 0) return L1L2;
	if (strcmp(regul, "l1linf") == 0) return L1LINF;
	if (strcmp(regul, "l1l2+l1") == 0) return L1L2_L1;
	if (strcmp(regul, "l1linf+l1") == 0) return L1LINF_L1;
	if (strcmp(regul, "tree-l0") == 0) return TREE_L0;
	if (strcmp(regul, "tree-l2") == 0) return TREE_L2;
	if (strcmp(regul, "tree-linf") == 0) return TREE_LINF;
	if (strcmp(regul, "graph") == 0) return GRAPH;
	if (strcmp(regul, "graph-ridge") == 0) return GRAPH_RIDGE;
	if (strcmp(regul, "graph-l2") == 0) return GRAPH_L2;
	if (strcmp(regul, "multi-task-tree") == 0) return TREEMULT;
	if (strcmp(regul, "multi-task-graph") == 0) return GRAPHMULT;
	if (strcmp(regul, "l1linf-row-column") == 0) return L1LINFCR;
	if (strcmp(regul, "trace-norm") == 0) return TRACE_NORM;
	if (strcmp(regul, "trace-norm-vec") == 0) return TRACE_NORM_VEC;
	if (strcmp(regul, "rank") == 0) return RANK;
	if (strcmp(regul, "rank-vec") == 0) return RANK_VEC;
	if (strcmp(regul, "graph-path-l0") == 0) return GRAPH_PATH_L0;
	if (strcmp(regul, "graph-path-conv") == 0) return GRAPH_PATH_CONV;
	if (strcmp(regul, "none") == 0) return NONE;
	return INCORRECT_REG;
}

FISTA::regul_t FISTA::regul_from_string(const char* regul)
{
	for (unsigned int i = 0; i < NBREGUL; i++)
		if (strcmp(regul, regul_table[i].name) == 0) return regul_table[i].regul;
	return FISTA::INCORRECT_REG;
}

FISTA::loss_t FISTA::loss_from_string(char* loss)
{
	if (strcmp(loss, "square") == 0) return SQUARE;
	if (strcmp(loss, "square-missing") == 0) return SQUARE_MISSING;
	if (strcmp(loss, "logistic") == 0) return LOG;
	if (strcmp(loss, "poisson") == 0) return POISSON;
	if (strcmp(loss, "weighted-logistic") == 0) return LOGWEIGHT;
	if (strcmp(loss, "hinge") == 0) return HINGE;
	if (strcmp(loss, "multi-logistic") == 0) return MULTILOG;
	if (strcmp(loss, "cur") == 0) return CUR;
	return INCORRECT_LOSS;
}

void FISTA::print_loss(const loss_t& loss)
{
	switch (loss) {
	case SQUARE: cout << "Square loss" << endl; break;
	case SQUARE_MISSING: cout << "Square loss with missing data" << endl; break;
	case LOG: cout << "Logistic loss" << endl; break;
	case LOGWEIGHT: cout << "Weighted Logistic loss" << endl; break;
	case HINGE: cout << "Hinge loss" << endl; break;
	case MULTILOG: cout << "Multiclass logistic Loss" << endl; break;
	case POISSON: cout << "Modified Poisson loss" << endl; break;
	case CUR: cout << "CUR decomposition" << endl; break;
	default: cerr << "Not implemented" << endl;
	}
}

bool FISTA::loss_for_matrices(const loss_t& loss)
{
	return loss == MULTILOG || loss == CUR;
}

void FISTA::print_regul(const regul_t& regul)
{
	switch (regul) {
	case L0: cout << "L0 regularization" << endl; break;
	case L1: cout << "L1 regularization" << endl; break;
	case RIDGE: cout << "L2-squared regularization" << endl; break;
	case L2: cout << "L2-not-squared regularization" << endl; break;
	case LOG_DC: cout << "reweighted-l1 regularization" << endl; break;
	case L1CONSTRAINT: cout << "L1 constraint regularization" << endl; break;
	case LINF: cout << "Linf regularization" << endl; break;
	case ELASTICNET: cout << "Elastic-net regularization" << endl; break;
	case FUSEDLASSO: cout << "Fused Lasso or total variation regularization" << endl; break;
	case GROUPLASSO_L2: cout << "Group Lasso L2" << endl; break;
	case GROUPLASSO_LINF: cout << "Group Lasso LINF" << endl; break;
	case GROUPLASSO_L2_L1: cout << "Group Lasso L2 + L1" << endl; break;
	case GROUPLASSO_LINF_L1: cout << "Group Lasso LINF + L1" << endl; break;
	case L1L2: cout << "L1L2 regularization" << endl; break;
	case L1LINF: cout << "L1LINF regularization" << endl; break;
	case TRACE_NORM: cout << "Trace Norm regularization" << endl; break;
	case TRACE_NORM_VEC: cout << "Trace Norm regularization for vectors" << endl; break;
	case RANK: cout << "Rank regularization" << endl; break;
	case RANK_VEC: cout << "Rank regularization for vectors" << endl; break;
	case L1L2_L1: cout << "L1L2 regularization + L1" << endl; break;
	case L1LINF_L1: cout << "L1LINF regularization + L1" << endl; break;
	case TREE_L0: cout << "Tree-L0 regularization" << endl; break;
	case TREE_L2: cout << "Tree-L2 regularization" << endl; break;
	case TREE_LINF: cout << "Tree-Linf regularization" << endl; break;
	case GRAPH: cout << "Graph regularization" << endl; break;
	case GRAPH_RIDGE: cout << "Graph+ridge regularization" << endl; break;
	case GRAPH_L2: cout << "Graph regularization with l2" << endl; break;
	case TREEMULT: cout << "multitask tree regularization" << endl; break;
	case GRAPHMULT: cout << "multitask graph regularization" << endl; break;
	case L1LINFCR: cout << "L1LINF regularization on rows and columns" << endl; break;
	case GRAPH_PATH_L0: cout << "Graph path non-convex regularization" << endl; break;
	case GRAPH_PATH_CONV: cout << "Graph path convex regularization" << endl; break;
	case NONE: cout << "No regularization" << endl; break;
	default: cerr << "Not implemented" << endl;
	}
}

bool FISTA::regul_for_matrices(const regul_t& regul)
{
	return regul == L1L2 || regul == L1LINF || regul == L1L2_L1 || regul == L1LINF_L1
		|| regul == TREEMULT || regul == GRAPHMULT || regul == L1LINFCR ||
		regul == TRACE_NORM || regul == RANK;
}

void FISTA::regul_error(char *buffer, int bufsize, const char *message)
{
	int n1 = strlen(message);
	int size = n1;
	if (n1 < bufsize) {
		// calculate size
		for (unsigned int i = 0; i < NBREGUL; i++)
			size += strlen(regul_table[i].name) + 1;
	}
	if (size >= bufsize) {
		n1 = bufsize - 1;
		strncpy(buffer, "Invalid regularization\n", n1);
	} else {
		strncpy(buffer, message, n1);
		for (unsigned int i = 0; i < NBREGUL; i++) {
			int k = strlen(regul_table[i].name);
			strncpy(&buffer[n1], regul_table[i].name, k);
			buffer[n1 + k] = ' ';
			n1 += k + 1;
		}
		buffer[n1 - 1] = '\n';
	}
	buffer[n1] = 0;
	return;
}