#include "vending_lib.h"

int main()
{
    ShoppingCart cart;
    Product availableProducts[NUM_PRODUCTS];
    int productType;
    int quantity;
    CartItem curCartItem;
    int userChoice = CONTINUE;

    stockMachine(availableProducts);
    puts("Welcome to the vending Machine");
    puts("--------------------------------");

    while(userChoice == CONTINUE)
    {
        displayProducts(availableProducts);
        productType = getProduct();

        if (productType == ABORT)
        {
            printf("Thank you for shopping with us!\n");
            return 0;
        }

        quantity = getQuantity(productType, availableProducts);
        if (quantity == ABORT)
        {
            printf("Thank you for shopping with us!\n");
            return 0;
        }

        curCartItem = selectItem(availableProducts[productType],
                                 availableProducts, quantity);
        if (!addToCart(curCartItem, &cart))
        {
            printf("Your shopping cart is full! we cannot add this item\n");
        }

        // Out of bounds initialization
        userChoice = CHECK_OUT+1;
        if (cart.totalItems == MAX_NUM_PRODUCTS)
        {
            while(!(userChoice ==1 || userChoice == -1))
            {
                printf("\nInput 1 to Check out and -1 to Cancel: ");
                scanf("%d", &userChoice);
                if (!(userChoice ==1 || userChoice == -1))
                {
                    printf("Invalid option. Please try again!: ");
                }
            }
        }else
        {
            while(!(userChoice >=-1 && userChoice <= 1))
            {
                printf("\nInput 0 to continue, 1 to Check out and"
                       " -1 to Cancel: ");
                scanf("%d", &userChoice);
                if (!(userChoice >=-1 && userChoice <= 1))
                {
                    printf("Invalid option. Please try again!\n");
                }
            }

        }

        if(userChoice == CANCEL)
        {
            cancelPurchase(&cart,availableProducts);
            printf("Thank you for shopping with us!");
            return 0;

        }else if (userChoice == CHECK_OUT)
        {
            generateBill(&cart);
            printf("\nConfirm is the selected products are valid. "
                   "Input 1 for Yes or any other key for No: ");

            if(userChoice == 1 && scanf("%d",&userChoice))
            {
                userChoice = ABORT;
                while(!(userChoice >=0 && userChoice <=1))
                {
                    printf("\nInput 0 to Pay and 1 to Exit: ");
                    scanf(" %d",&userChoice);
                    if (!(userChoice >=0 && userChoice <=1))
                    {
                        printf("Invalid input. Please try again!\n");
                    }
                }
                    puts("");
                if (userChoice == PAY)
                {
                    if (pay(cart.totalCost))
                    {
                        printf("Thank you for shopping with us!\n");
                        puts("You are authorized to retrieve your products.");
                        return 0;
                    }
                    else
                    {
                        puts("Your payment failed.");
                        printf("Thank you for shopping with us!\n");
                        return 0;

                    }
                }else if (userChoice == EXIT)
                {
                    cancelPurchase(&cart,availableProducts);
                    printf("Thank you for shopping with us!\n");
                    return 0;

                }
            }else
            {
                printf("Thank you for shopping with us!\n");
                return 0;
            }
        }
        userChoice= CONTINUE;
    }

    return 0;
}