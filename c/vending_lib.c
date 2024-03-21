#include "vending_lib.h"

const char *prodDesc[NUM_PRODUCTS] =
        {"Hershey's Milk Chocolate Bar 1.55oz", "Lays Classic Chips 13oz",
         "Orbit Chewing Gum 15 sticks", "Pepsi Soda 20oz Bottle"};


void stockMachine(Product availableProducts[])
{
    FILE *file = fopen("products.csv", "r");
    char buffer[100];
    char *token;
    int itemID;

    while (fgets(buffer, sizeof(buffer), file))
    {
        token = strtok(buffer, ",");
        itemID = atoi(token);
        availableProducts[itemID].productType = itemID;
        token = strtok(NULL, ",");
        availableProducts[itemID].price = atof(token);
        token = strtok(NULL, ",");
        availableProducts[itemID].quantityInStock = atoi(token);
    }

}

void displayProducts(Product availableProducts[])
{
    printf("\nCode | Product Description                 |"
           " Available Quantity | Unit Price\n");
    printf("_____|_____________________________________|"
           " ___________________|________\n");
    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        printf("%-4d | %-35s | %-18d | %-10.2lf\n",
               availableProducts[i].productType,
               prodDesc[i], availableProducts[i].quantityInStock,
               availableProducts[i].price);
    }
}


int getProduct()
{
    int productID = ABORT;
    while (!(productID >= 0 && productID < NUM_PRODUCTS))
    {
        printf("\nInput the code of the product you want to purchase: ");
        scanf(" %d", &productID);

        if (!(productID >= 0 && productID < NUM_PRODUCTS))
        {
            printf("Invalid Input! Please try again.\n");
        }
    }

    return productID;
}

int getQuantity(int productCode, Product availableProducts[])
{
    int quantity = ABORT;

    while (!(quantity > 0 && quantity
            <= availableProducts[productCode].quantityInStock))
    {
        printf("Input the quantity of the product: ");
        scanf(" %d", &quantity);

        if (quantity <= 0)
        {
            printf("Input valid quantity\n");
        } else if (quantity > availableProducts[productCode].quantityInStock)
        {
            printf("We do not have enough stock. "
                   "Please input smaller quantity.\n");
        }
    }

    return quantity;
}

CartItem selectItem(Product selProduct,
                    Product availableProducts[], int quantity)
{
    CartItem curCartItem;
    curCartItem.selProduct = selProduct;
    curCartItem.quantity = quantity;
    availableProducts[selProduct.productType].quantityInStock -= quantity;

    return curCartItem;
}

bool addToCart(CartItem curCartItem, ShoppingCart *cart)
{
    if (cart->totalItems > MAX_NUM_PRODUCTS)
    {
        return false;
    }

    cart->shoppingCart[cart->totalItems] = curCartItem;
    cart->totalItems++;
    cart->totalCost += (curCartItem.quantity) * (curCartItem.selProduct.price);
    return true;
}

void cancelPurchase(ShoppingCart *cart, Product availableProducts[])
{
    for (int i = 0; i < cart->totalItems; i++)
    {
        availableProducts[(cart->shoppingCart[i]).
        selProduct.productType].quantityInStock
        += cart->shoppingCart[i].quantity;
    }
    cart->totalCost = 0;
    cart->totalItems = 0;
}

void generateBill(ShoppingCart *cart)
{
    printf(" Product                                 | Unit Price |"
           " Product Total\n");
    printf("-----------------------------------------|------------|"
           "--------------\n");

    for (int i = 0; i < cart->totalItems; i++)
    {
        printf("%2d x %-35s | %2d x %-5.2lf | %-13.2lf\n",
               cart->shoppingCart[i].quantity,
               prodDesc[cart->shoppingCart[i].selProduct.productType],
               cart->shoppingCart[i].quantity,
               cart->shoppingCart[i].selProduct.price,
               (cart->shoppingCart[i].selProduct.price *
               cart->shoppingCart[i].quantity));
    }
    printf("Order Total: %.2f\n", cart->totalCost);
}

// NOTE FOR GRADERS: I antecipate some students to add the shopping cart as an 
// argument for this function
// bool pay(float totalCost, ShoppingCart *cart)
bool pay(float totalCost)
{
    int paymentType = ABORT;
    int creditCard = ABORT;
    int contactless = ABORT;
    float paymentAmount = 0.0;
    float change = ABORT;
    float serviceFee = 0;

    while (!(paymentType >= 0 && paymentType < 3))
    {
        printf("Input 0 for Cash, 1 for Credit card, 2 for Contactless: ");
        scanf(" %d", &paymentType);
        if (paymentType == '\n')
        {
            return false;
        } else if (!(paymentType >= 0 && paymentType < 3))
        {
            printf("Input valid choice for payment.\n");
        }
    }

    switch (paymentType)
    {
        case CASH:
            while (change < 0)
            {
                printf("\nInput the payment amount: ");
                scanf(" %f", &paymentAmount);
                change = paymentAmount - totalCost;
                if (change < 0)
                {
                    printf("Insufficient payment amount.\n");
                }
            }
            // NOTE FOR GRADERS: I anticipate some students calling the 
            // generateBill to print the output as it is on Canvas page
            //generateBill(cart);
            printf("___\n");
            printf("Paid by: Cash\n");
            break;
        case CREDIT:

            while (!(creditCard <= AMERICAN_EXPRESS && creditCard >= MASTERCARD))
            {
                printf("\nInput 0 for MasterCard, 1 for Visa, 2 for Discover,"
                       " and 3 for American Express: ");
                scanf(" %d", &creditCard);
                if (!(creditCard <= AMERICAN_EXPRESS && creditCard >= MASTERCARD))
                    printf("Invalid option. Please select again.\n");
            }

            serviceFee = CREDIT_FEE * totalCost;
            change = 0;
            paymentAmount = (totalCost + serviceFee);
            printf("___\n");
            switch (creditCard)
            {
                case MASTERCARD:
                    printf("Paid by: Credit Card (MasterCard)\n");
                    break;
                case VISA:
                    printf("Paid by: Credit Card (Visa)\n");
                    break;
                case DISCOVER:
                    printf("Paid by: Credit Card (Discover)\n");
                    break;
                case AMERICAN_EXPRESS:
                    printf("Paid by: Credit Card (American Express)\n");
                    break;
            }
            break;
        case CONTACTLESS:
            while (!(contactless <= CONTACTLESS && contactless >= CASH))
            {
                printf("\nInput 0 for Google Wallet and 1 for Apple Pay: ");
                scanf(" %d", &contactless);
                if (!(contactless <= CONTACTLESS && contactless >= CASH))
                    printf("Invalid option. Please select again.\n");
            }

            while (change < 0)
            {
                serviceFee = CONTACTLESS_FEE * totalCost;
                change = 0;
                paymentAmount = (totalCost + serviceFee);
                if (change < 0)
                {
                    printf("Insufficient payment amount.\n");
                }
            }
            printf("___\n");
            switch (contactless)
            {
                case GOOGLE_WALLET:
                    printf("Paid by: Contactless Payment (Google Wallet)\n");
                    break;
                case APPLE_PAY:
                    printf("Paid by: Contactless Payment (Apple Pay)\n");
                    break;
            }
            break;
    }

    printf("Service Fee: %.2f\n", serviceFee);
    printf("Paid Amount: %.2f\n", paymentAmount);
    printf("Change:%.2f\n\n", change);
    return true;
}