/*
 BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 THIS ASSIGNMENT.
 */

/* Author: Yifan Yao.740 */
struct Cost {
	/* line 4 - 7 */
	float wholesalePrice;
	float retailPrice;
	int wholesaleQuantity;
	int retailQuantity;
};

struct Data {
	/* line 1 - 3 */
	char item[50];
	char department[30];
	int stockNumber;
	/* line 4 - 7 */
	struct Cost pricing;
};

typedef struct Node {
	/* line 1 - 7 */
	struct Data grocery_item;
	struct Node *next;
} Node;

void readInput(char *ip, Node **list_head);
void insertNode(Node **list_head_ptr, Node *newNodePtr);
unsigned int menuSelection();
void deleteNode(Node **list_head_ptr, int stockNumber);
int checkDuplicateStock(Node **list_head_ptr, Node *newNodePtr);

void totalRevenue_1(Node **list_head_ptr);
void totalWholesaleCost_2(Node **list_head_ptr);
void totalWholesaleInvestment_3(Node **list_head_ptr);
void totalProfit_4(Node **list_head_ptr);
void totalGroceryItemsSold_5(Node **list_head_ptr);
void averageProfit_6(Node **list_head_ptr);
void printInStockItems_7(Node **list_head_ptr);
void printOutStockItems_8(Node **list_head_ptr);
void printByDepartment_9(Node **list_head_ptr);
void addGroceryItem_10(Node **list_head_ptr);
void deleteGroceryItem_11(Node **list_head_ptr);

void fileOutput_12(char *op, Node **list_head);
