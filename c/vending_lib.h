#ifndef VENDING_LIB_H
#define VENDING_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ABORT -1
#define MAX_NUM_PRODUCTS 100
#define CREDIT_FEE 0.02
#define CONTACTLESS_FEE 0.01


//extern const char* prodDesc[NUM_PRODUCTS];

enum productType
{
    CHOCOLATE_BAR,
    CHIPS,
    CHEWING_GUM,
    PEPSI,
    NUM_PRODUCTS
};

enum menu
{
    CONTINUE,
    CHECK_OUT,
    CANCEL= -1
};

enum payment
{
    CASH,
    CREDIT,
    CONTACTLESS
};

enum contactless
{
    GOOGLE_WALLET,
    APPLE_PAY
};

enum creditCard
{
    MASTERCARD,
    VISA,
    DISCOVER,
    AMERICAN_EXPRESS
};

enum choice
{
    PAY,
    EXIT
};

typedef struct product
{
    int productType;
    float price;
    int quantityInStock;
}
Product;

typedef struct cartItem
{
    Product selProduct;
    int quantity;
}
CartItem ;

typedef struct shoppingCart
{
    CartItem shoppingCart[MAX_NUM_PRODUCTS];
    int totalItems;
    float totalCost;
}
ShoppingCart;

extern const char* prodDesc[NUM_PRODUCTS];

void stockMachine(Product availableProducts[]);

void displayProducts(Product availableProducts[]);

int getProduct();

int getQuantity(int productCode, Product availableProducts[]);

CartItem selectItem(Product selProduct, Product availableProducts[],
    int quantity);

bool addToCart(CartItem curCartItem, ShoppingCart*cart);

void cancelPurchase(ShoppingCart* cart, Product availableProducts[]);

void generateBill(ShoppingCart* cart);

// NOTE FOR GRADERS: I anticipate students also passing a ShoppingCart as
// an argument in this function
// bool pay(float totalCost, ShoppingCart *cart);
bool pay(float totalCost);

#endif