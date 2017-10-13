# This could go in a config file
REGULAR_PRICE = 2.11
REGULAR_DESCRIPTION = "Regular Coffee"
REGULAR_COFFEE_NAME = "regular"

DECAF_PRICE = 1.51
DECAF_DESCRIPTION = "Decaf Coffee"
DECAF_COFFEE_NAME = "decaf"

ORDER_SEPARATOR = ','
PRODUCT_SEPARATOR = '+'
# this may need a better name
NUMBER_OF_PRODUCTS_SEPARATOR = ' x '

CURRENCY_SIGN = "$"
FINAL_BILL_STRING = "Final bill is {0}{1}"


class Order(object):
    def processOrder(self, orders_string):
        assert isinstance(orders_string, str), "The orders must be in a string"
        final_bill = 0
        # this will split on coma, separating the orders
        beverage_factory = BeverageFactory()
        for order in orders_string.split(ORDER_SEPARATOR):
            # split the number of products (3 x ...),
            # and the actual products ( ... x product1 + product2)
            split_order = order.split(NUMBER_OF_PRODUCTS_SEPARATOR)
            print(split_order)
            num_of_products, products = split_order[0], split_order[1]

            # this can be optimised if we add a Extras clear() method
            extras = Extras()

            for product in products.split(PRODUCT_SEPARATOR):
                print(product.strip())
                product = product.strip()
                # no errors are handled here, if we fail, the input is incorrect,
                # and there's not much we can do about it (from this problem description)
                if extras.isExtra(product):
                    extras.addExtra(product)
                else:
                    coffee = beverage_factory.createBeverage(product)
                    final_bill += coffee.getCost()

            final_bill += extras.getCost()
            final_bill *= int(num_of_products)
        return FINAL_BILL_STRING.format(CURRENCY_SIGN, final_bill)


class Extras(object):
    def __init__(self):
        self._extras = []
        self._extras_prices = {
            'milk': 0.53,
            'sugar': 0.17,
            'cream': 0.73,
            'sprinkles': 0.29,
            'xigua': 0.29
        }

    def isExtra(self, extra):
        return extra in self._extras_prices.keys()

    def addExtra(self, extra):
        # assuming python 3 with the call to .keys
        if extra not in self._extras_prices.keys():
            raise ValueError("{0} is not in the available extras".format(extra))

        self._extras.append(extra)

    def getCost(self):
        """
        :returns: the total cost of *only* the extras
        """
        total_sum = 0
        for extra in self._extras:
            # this should be safe because of the check in addExtra
            total_sum += self._extras_prices[extra]

        return total_sum


class BeverageFactory(object):
    def createBeverage(self, beverage):
        """
        Create beverage if we know how to make a beverage, otherwise raises ValueError

        :param beverage: name of the beverage to be created
        :raises: ValueError if beverage is unknown
        """
        # sanity check
        assert isinstance(beverage, str), "The beverage name MUST be a string"

        if beverage == REGULAR_COFFEE_NAME:
            coffee = RegularCoffee()
        elif beverage == DECAF_COFFEE_NAME:
            coffee = DecafCoffee()
        else:
            raise ValueError("{0} beverage is not a coffee!".format(beverage))

        return coffee

# Not editing the classes below for PART B


class Beverage(object):
    def __init__(self):
        self.coffee_price = None
        self.coffee_description = None

    def getCost(self):
        """
        :returns: The total cost of the coffee + extras
        """
        # I assume we can modify this for part b
        return self.coffee_price

    def getDescription(self):
        return self.coffee_description


class RegularCoffee(Beverage):
    def __init__(self):
        super(RegularCoffee, self).__init__()
        self.coffee_price = REGULAR_PRICE
        self.coffee_description = REGULAR_DESCRIPTION


class DecafCoffee(Beverage):
    def __init__(self):
        super(DecafCoffee, self).__init__()
        self.coffee_price = DECAF_PRICE
        self.coffee_description = DECAF_DESCRIPTION


input_string = "1 x regular + milk + sugar, 1 x decaf + sprinkles, 2 x xigua"
input_string2 = "1 x regular + milk + sugar, 1 x decaf + sprinkles"

order = Order()
print(order.processOrder(input_string))
print(order.processOrder(input_string2))
